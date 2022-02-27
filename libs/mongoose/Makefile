NAME	:=	mongoose.a

CC 		:= 	gcc
FLAGS 	:= 	-Wall -Wextra -Werror
RM		:=	rm -f

SRCS	:= 	mongoose.c
OBJS	:=	$(SRCS:.c=.o)

.c.o:
			$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			ar -rcs $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean: 	clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: 	all clean fclean re