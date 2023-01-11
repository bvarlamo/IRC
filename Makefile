
CXX = c++
CXXFLAGS = -Werror -Wall -Wextra -std=c++98 -pedantic-errors

NAME = ircserv

CLASSES = \
	Server.cpp	\
	Client.cpp	\
	Channel.cpp \
	Message.cpp \
	Comms.cpp \
	ServerResponse.cpp
 
SRCS = \
	main.cpp \
	$(addprefix srcs/,$(CLASSES))

HEADERS = $(patsubst %.cpp,%.hpp,$(addprefix srcs/,$(CLASSES)))

all: $(NAME)

bonus: bot

clean:
	$(RM) -f $(NAME)

fclean: clean botfclean
	$(RM) -f bot

re: fclean all

$(NAME): $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRCS) -I./srcs -o $@

# for bonus 
bot: 
	$(MAKE) -C ./bonus
	cp ./bonus/bot .

botfclean:
	$(MAKE) -C ./bonus fclean

botre:
	$(MAKE) -C ./bonus re

.PHONY: all clean fclean re test bot botfclean botre
