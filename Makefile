# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: temil-da <temil-da@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/18 16:53:35 by temil-da          #+#    #+#              #
#    Updated: 2024/05/22 11:30:40 by temil-da         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER = server
NAME_CLIENT = client

NAME_SERVER_BONUS = server_bonus
NAME_CLIENT_BONUS = client_bonus

CFLAGS = -Wall -Wextra -Werror

CC = cc

LIBFT_DIR = utils/libft

LIBFT = $(LIBFT_DIR)/libft.a

SRC_SERVER = server.c
SRC_CLIENT = client.c

SRC_SERVER_BONUS = server_bonus.c
SRC_CLIENT_BONUS = client_bonus.c

OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

OBJ_SERVER_BONUS = $(SRC_SERVER_BONUS:.c=.o)
OBJ_CLIENT_BONUS = $(SRC_CLIENT_BONUS:.c=.o)

RED = \033[0;31m
NC = \033[0m
GREEN = \033[0;32m
YELLOW = \033[1;33m

.PHONY: all clean fclean re compile_msg bonus

all : compile_msg $(LIBFT) $(NAME_SERVER) $(NAME_CLIENT) $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)

compile_msg:
	@echo "$(YELLOW)Compiling source files...$(NC)\n$(GREEN)Done.$(NC)"

$(NAME_SERVER): $(OBJ_SERVER) $(LIBFT)
	@echo "$(YELLOW)Creating $(NAME_SERVER) executable$(NC)"
	@$(CC) $(CFLAGS) -o $(NAME_SERVER) $(OBJ_SERVER) $(LIBFT)
	@echo "$(GREEN)Done.$(NC)"

$(NAME_CLIENT): $(OBJ_CLIENT) $(LIBFT)
	@echo "$(YELLOW)Creating $(NAME_CLIENT) executable$(NC)"
	@$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(OBJ_CLIENT) $(LIBFT)
	@echo "$(GREEN)Done.$(NC)"

$(NAME_SERVER_BONUS): $(OBJ_SERVER_BONUS) $(LIBFT)
	@echo "$(YELLOW)Creating $(NAME_SERVER_BONUS) executable$(NC)"
	@$(CC) $(CFLAGS) -o $(NAME_SERVER_BONUS) $(OBJ_SERVER_BONUS) $(LIBFT)
	@echo "$(GREEN)Done.$(NC)"

$(NAME_CLIENT_BONUS): $(OBJ_CLIENT_BONUS) $(LIBFT)
	@echo "$(YELLOW)Creating $(NAME_CLIENT_BONUS) executable$(NC)"
	@$(CC) $(CFLAGS) -o $(NAME_CLIENT_BONUS) $(OBJ_CLIENT_BONUS) $(LIBFT)
	@echo "$(GREEN)Done.$(NC)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@echo "$(YELLOW)Compiling libft.a source files...$(NC)"
	@$(MAKE) -C $(LIBFT_DIR) >/dev/null 2>&1 && echo "$(GREEN)Done.$(NC)" || (echo "$(RED)Error compiling libft.a$(NC)" && exit 1)

clean:
	@echo "$(YELLOW)Cleaning object files...$(NC)"
	@rm -f $(OBJ_SERVER) $(OBJ_CLIENT) $(OBJ_SERVER_BONUS) $(OBJ_CLIENT_BONUS)
	@echo "$(GREEN)Done.$(NC)"
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean:
	@echo "$(YELLOW)Cleaning object files...$(NC)"
	@rm -f $(OBJ_SERVER) $(OBJ_CLIENT) $(OBJ_SERVER_BONUS) $(OBJ_CLIENT_BONUS)
	@echo "$(GREEN)Done.$(NC)"
	@echo "$(YELLOW)Removing executables...$(NC)"
	@rm -f $(NAME_SERVER) $(NAME_CLIENT) $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)
	@echo "$(GREEN)Done.$(NC)"
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

bonus: compile_msg $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)
