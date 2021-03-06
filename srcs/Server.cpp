#include "Server.hpp"

Server::Server (int port)
{
	this->listenPort = port;
	this->statistics = new Daemon_statistics();
}

Server::Server ( Server const & src )
{
	*this = src;
	return ;
}

Server &				Server::operator=( Server const & rhs )
{
	if (this != &rhs)
	{
	}
	return (*this);
}

Server::~Server ( void )
{
	for (int i = 0; i < this->clients.size(); i++)
		delete this->clients[i];
	delete this->statistics;
	return ;
}

std::ostream &				operator<<(std::ostream & o, Server const & i)
{
	(void)i;
	return (o);
}

Daemon_statistics	*Server::get_statistics( void )
{
	return (this->statistics);
}

void Server::waitClients()
{
	int 					fd		= 0;
	socklen_t				length	= sizeof(in);
	int						max_fd	= 0;
	struct sockaddr_in		in;

	while (true)
	{
		if ((fd = accept(this->sock, (struct sockaddr*)&in, &length)) == -1)
			throw ServerCantAcceptSocket();
		this->statistics->set_number_of_connection_accepted(this->statistics->get_number_of_connection_accepted() + 1);
		if (this->clients.size() < 3) { // 3 clients allowed
			this->clients.push_back(new Client(fd, in, this));
		} else {
			Tintin_reporter::instance()->log("A client tried to connect while 3 clients are already online, connection refused");
			close (fd);
		}
	}
}

void Server::removeClient(Client *client)
{
	for (int i = 0; i < this->clients.size(); i++)
	{
		if (this->clients[i] == client) {
			this->clients.erase(this->clients.begin() + i);
			break;
		}
	}
}

void Server::listenInit()
{
	bool opt = true;
	if ((this->sock = socket(AF_INET, SOCK_STREAM, 0)) == -1)
		throw ServerCantCreateSocket();
	this->in.sin_family = AF_INET;
	this->in.sin_addr.s_addr = INADDR_ANY;
	this->in.sin_port = htons(this->listenPort);
	if ((bind(this->sock, (struct sockaddr *)&this->in, \
			sizeof(this->in))) < 0)
		throw ServerCantBindSocket();
	if ((listen(this->sock, 3)) == -1)
		throw ServerCantListenOnSocket();
	Tintin_reporter::instance()->log("Server started on port " + std::to_string(this->listenPort));
	this->statistics->update_start_time();
	this->waitClients();
}

void Server::closeServer( void )
{
	this->statistics->update_end_time();
	Tintin_reporter::instance()->log(this->statistics->to_string());
}
