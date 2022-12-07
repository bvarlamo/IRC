#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include <string>
#include <vector>
#include <algorithm>
#include <sys/socket.h>
#include "Client.hpp"

class Channel
{
	public:
		Channel(std::string name, Client &c);
		// Channel(const Channel &c);
		~Channel();

		Channel &operator=(const Channel &c);

		int	broadcast(std::string message, int sender);
		int	connect(Client &c);
		int	disconnect(Client &c);
		int	disconnect(std::string nickname);
		int	cmd_kick(std::string nickname);
		// int cmd_mode();
		int	cmd_invite(std::string nickname);
		int	cmd_topic(std::string top);
		int	cmd_names(Client& sender);
		int cmd_who(Client& sender);
		int	add_operator(std::string nick);
		int	delete_operator(std::string nick);

		std::string	get_topic();
		std::string	get_name();

		// bool	is_op(Client &c);
		bool	is_op(std::string nickname);
		bool	is_member(Client &c);
		bool	is_member(std::string nickname);
		bool	can_invite(Client &c);
		bool	can_invite(std::string nickname);

	private:
		std::string						name;
		std::string						owner;
		std::vector<std::string>		operators;
		std::string						topic;
		std::map<std::string, Client*>	clients;
		bool							invite_only;
		std::vector<std::string>		invited_users;
		// bool							is_private;
		// bool							is_secret;
		// bool							op_topic;
		// bool							no_msg;
		// bool							moderated;
		// int								user_limit;
		// std::string						password;

};

#endif // CHANNEL_HPP