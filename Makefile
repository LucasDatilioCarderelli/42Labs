# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/22 11:49:02 by ldatilio          #+#    #+#              #
#    Updated: 2022/02/24 18:37:09 by ldatilio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN		=	\033[0;32m
RED			=	\033[0;31m
RESET		=	\033[0m

CC			=	gcc

MONGOOSE	=	mongoose/mongoose.a
GNL 		=	get_next_line/get_next_line.a

all:			$(MONGOOSE) $(GNL)
				@echo "$(GREEN)"
				@echo "██╗ ██╗ ██████╗ ██╗         ██╗     ███████╗ "
				@echo "██║ ██║     ██║ ██║        ████╗    ██    ██╗"
				@echo "██████║ ██████║ ██║      ██    ██╗  ██████╔═╝"
				@echo "    ██║ ██╔═══╝ ██║      ████████║  ██    ██╗"
				@echo "    ██║ ██████╗ ███████╗ ██║   ██║  ███████╔╝"
				@echo "    ╚═╝ ╚═════╝ ╚══════╝ ╚═╝   ╚═╝  ╚══════╝ "
				@echo "           Everything is Done!$(RESET)"

$(MONGOOSE):
				make -C ./mongoose/
				@echo "\n $(GREEN)$(MONGOOSE) was created $(RESET)\n"

$(GNL):
				make -C ./get_next_line/
				@echo "\n $(GREEN)$(MONGOOSE) was created $(RESET)\n"

clean:
				@echo "\n $(RED) Removing *.o files $(RESET)\n"
				rm -f $(OBJS) $(OBJS_BONUS)
				make clean -C ./mongoose
				make clean -C ./get_next_line

fclean:			clean
				@echo "\n $(RED) Removing files *.o and *.a files $(RESET)\n"
				rm -f $(NAME) $(NAME_BONUS)
				make fclean -C ./mongoose
				make fclean -C ./get_next_line

re:				fclean all

.PHONY: 		all, clean, fclean, re






# NAME 		= API

# SRC 		= ./src/main.c ./src/mongoose.c

# OBJS 		= $(SRC:.c=.o)

# all: 		$(NAME)

# $(NAME):	$(OBJS)
#     		gcc $(OBJS) -o $(NAME)
#     		@echo "\n$(NAME): $(GREEN)$(NAME) was created $(RESET)\n"

# %.o:		%.c
# 			gcc $(CFLAG) -c $< -o $@
# 			@echo "\n\n$(NAME): $(GREEN)object files were created$(RESET)\n"

# clean:
# 			rm -f $(OBJS)
# 			@echo "$(NAME): $(RED)object files were deleted$(RESET)\n"

# fclean:		clean
# 			rm -f $(NAME)
# 			@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)\n"

# re: 		fclean all

# .PHONY: 	clean fclean re all