# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/22 11:49:02 by ldatilio          #+#    #+#              #
#    Updated: 2022/02/26 17:09:16 by ldatilio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN		=	\033[0;32m
RED			=	\033[0;31m
RESET		=	\033[0m

CC			=	gcc
CFLAG		=	-Wall -Wextra -Werror
LIB			=	-lcurl

RM 			=	rm -f

MONGOOSE	=	mongoose/mongoose.a
GNL 		=	get_next_line/get_next_line.a

SERVER 		=	api_server
CLI 		=	get_log

SERVER_DIR	=	./server/
CLI_DIR		=	./cli/

SERVER_SRC	=	$(addprefix $(SERVER_DIR),	\
				ft_curl.c 					\
				log_message.c 				\
				server.c 					\
				)
CLI_SRC		=	$(addprefix $(CLI_DIR),	\
				cli.c 					\
				show_log.c				\
				)

SERVER_OBJ	=	$(SERVER_SRC:%.c=%.o)
CLI_OBJ		=	$(CLI_SRC:%.c=%.o)

%.o: 			%.c
				$(CC) -c $< -o $@

all:			$(MONGOOSE) $(GNL) $(SERVER) $(CLI)
				@echo "$(GREEN)                                          "
				@echo "                                   ║ ║            "
				@echo "██╗ ██╗ ██████╗ ██╗       ███╗   ██████╗  ██████╗ "
				@echo "██║ ██║     ██║ ██║      █████╗  ██║ ║██╗ ██╔═══╝ "
				@echo "██████║ ██████║ ██║     ██   ██╗ █████╔═╝ ██████╗ "
				@echo "    ██║ ██╔═══╝ ██║     ███████║ ██║ ║██╗     ██║ "
				@echo "    ██║ ██████╗ ██████╗ ██║  ██║ ██████╔╝ ██████║ "
				@echo "    ╚═╝ ╚═════╝ ╚═════╝ ╚═╝  ╚═╝ ╚═║═║═╝  ╚═════╝ "
				@echo "               Everything is Done!        $(RESET)"

$(MONGOOSE):
				@echo "\n $(GREEN) Creating $(MONGOOSE) $(RESET)\n"
				make -C ./mongoose/

$(GNL):
				@echo "\n $(GREEN) Creating $(GNL) $(RESET)\n"
				make -C ./get_next_line/

$(SERVER):		$(SERVER_OBJ)
				$(CC) $(CFLAG) -o $(SERVER) $(SERVER_OBJ) $(MONGOOSE) $(LIB)
				@echo "\n $(GREEN) $(SERVER) was created $(RESET)\n"

$(CLI):			$(CLI_OBJ)
				$(CC) $(CFLAG) -o $(CLI) $(CLI_OBJ) $(GNL) $(LIB)
				@echo "\n $(GREEN) $(CLI) was created $(RESET)\n"

clean:
				@echo "\n $(RED) Removing *.o files $(RESET)\n"
				$(RM) $(SERVER_OBJ) $(CLI_OBJ)
				make clean -C ./mongoose
				make clean -C ./get_next_line

fclean:			clean
				@echo "\n $(RED) Removing files *.o and *.a files $(RESET)\n"
				$(RM) $(SERVER) $(CLI)
				make fclean -C ./mongoose
				make fclean -C ./get_next_line

re:				fclean all

.PHONY: 		all, clean, fclean, re, server
