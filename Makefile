# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 16:11:28 by eozdek            #+#    #+#              #
#    Updated: 2016/04/30 18:56:25 by eozdek           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fdf
FILES	= main.c ft_draw.c ft_hook.c ft_read.c ft_rest.c
SRCS	= $(addprefix src/, $(FILES))
OBJS	= $(SRCS:src/%.c=.obj/%.o)
INC		= -I includes -I libft/includes
INC2	= -lmlx -framework OpenGL -framework AppKit
FLAGS	= -Wall -Wextra -Werror
LIB		= -L libft -lft
CC		= gcc

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\033[95m _____   _  __ "
	@echo "\033[95m|  ___|_| |/ _|"
	@echo "\033[95m| |_ / _  | | _ "
	@echo "\033[95m|  _| (_| |  _|"
	@echo "\033[95m|_|  \__,_|_|  "
	@echo "\033[96m by e🏀 zdek\033[97m"
	@echo "\033[91mCompiling 😇\033[97m"
		@make -C libft
		@$(CC) $(FLAGS) $(SRCS) -o $(NAME) $(INC2) $(INC) $(LIB)
		@echo "\033[90mDone 😎\033[97m"
.obj/%.o: src/%.c
	@mkdir -p .obj
	@$(CC) -c $< -o $@ $(FLAGS) $(INC)

clean:
	@echo "\033[92mDeleting 💀\033[97m"
	@rm -rf .obj
	@make clean -C libft
	@echo "\033[96mClean done 😡\033[97m"

fclean: clean
	@echo "\033[92mDeleting 💀\033[97m"
	@make fclean -C libft
	@rm -f $(NAME)
	@rm -rf fdf.dSYM
	@echo "\033[96mFclean Done 👿\033[97m"

re: fclean all

.PHONY: all clean fclean re
