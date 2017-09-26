#include "Daemon_statistics.hpp"

// STATIC ########################################################

// ###############################################################

// CANONICAL #####################################################

Daemon_statistics::Daemon_statistics ( void )
{
	this->initialize();
	return ;
}

Daemon_statistics::Daemon_statistics ( Daemon_statistics const & src )
{
	*this = src;
	return ;
}

Daemon_statistics &				Daemon_statistics::operator=( Daemon_statistics const & rhs )
{
	if (this != &rhs)
	{
		// make stuff
	}
	return (*this);
}

Daemon_statistics::~Daemon_statistics ( void )
{
	return ;
}

// ###############################################################

// OVERLOAD OPERATOR #############################################

std::ostream &				operator<<(std::ostream & o, Daemon_statistics const & i)
{
	(void)i;
	return (o);
}

// ###############################################################

// PUBLIC METHOD #################################################

int		Daemon_statistics::get_number_of_message_received( void )
{
	return (this->number_of_message_received);
}

int		Daemon_statistics::get_number_of_connection_accepted( void )
{
	return (this->number_of_connection_accepted);
}

long	Daemon_statistics::get_start_time( void )
{
	return (this->start_time);
}

long	Daemon_statistics::get_end_time( void )
{
	return (this->end_time);
}

void	Daemon_statistics::set_number_of_message_received( int n )
{
	this->number_of_message_received = n;
}

void	Daemon_statistics::set_number_of_connection_accepted( int n )
{
	this->number_of_connection_accepted = n;
}

void	Daemon_statistics::set_start_time( long time )
{
	this->start_time = time;
}

void	Daemon_statistics::set_end_time( long time )
{
	this->end_time = time;
}


std::string	Daemon_statistics::to_string( void )
{
	/*long n_up_time = this->end_time - this->start_time;
	char uptime[80];
	time_t rawtime;
	struct tm *timeinfo;

	rawtime.tv_usec = n_up_time;
	timeinfo = localtime(&rawtime);
	strftime(uptime,sizeof(uptime),"%d-%m-%Y %I:%M:%S", timeinfo);
	std::string str(uptime);

	std::string s = "Deamon statistics :" << std::endl << "Total received message     : " << this->number_of_message_received << "Total connection accept    : " << this->number_of_connection_accepted << "Deamon total uptime        : " << uptime;
	return (s);*/
	return ("");
}

// ###############################################################

// GETTER METHOD #################################################

// ###############################################################

// SETTER METHOD #################################################

// ###############################################################

// PRIVATE METHOD ################################################

void						Daemon_statistics::initialize( void )
{
	this->number_of_message_received = 0;
	this->number_of_connection_accepted = 0;
	this->start_time = -1;
	this->end_time = -1;
}

// ###############################################################

// EXCEPTION METHOD ##############################################

// ###############################################################

// EXTERNAL ######################################################

// ###############################################################
