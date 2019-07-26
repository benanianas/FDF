# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abenani <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/30 19:18:23 by abenani           #+#    #+#              #
#    Updated: 2019/06/24 14:26:29 by abenani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
LIBH = libft.h
FILES = ft_*.c
CFLAG = -Wall -Wextra -Werror

all: $(NAME)
$(NAME):
	@gcc -g $(CFLAG) -c $(FILES) -I $(LIBH)
	@ar rc $(NAME) *.o
clean:
	@rm -f *.o
fclean: clean
	@rm -f $(NAME)
re: fclean all
