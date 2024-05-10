NAME		=	divideandconque

SRCS		=	main.cpp Account.cpp Bank.cpp

CC			=	c++

RM			=	rm

CFLAGS		=	-Wall -Werror -Wextra -std=c++98

all:		$(NAME)

$(NAME):	$(SRCS)
			$(CC) $(CFLAGS) -o $(NAME) $(SRCS)

clean:		
			$(RM) -f $(NAME)

fclean:		clean

re:			fclean all

.PHONY:		all clean fclean re