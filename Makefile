# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abenani <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/18 17:56:38 by abenani           #+#    #+#              #
#    Updated: 2019/07/12 20:18:05 by abenani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
COMPILE = gcc -Wall -Wextra -Werror 
FILES =  srcs/main.c srcs/creating_map.c srcs/save_n_check.c \
		srcs/save_n_check2.c srcs/events.c srcs/tools.c \
		srcs/drawing_line.c srcs/rotations.c libft/libft.a
INCLUDE = /usr/local/include
LIBSNFRAMES = /usr/local/lib -lmlx -framework OpenGL -framework Appkit

$(NAME):
	@cd libft && make
	@$(COMPILE) -I $(INCLUDE) -o $(NAME) $(FILES) -L $(LIBSNFRAMES)

all: $(NAME)

clean:
	@cd libft && make fclean

fclean: clean
	@rm -rf $(NAME)

re: fclean all
