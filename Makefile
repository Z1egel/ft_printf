# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbennis <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 11:37:26 by mbennis           #+#    #+#              #
#    Updated: 2018/12/24 18:06:26 by mbennis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c flags.c casts.c print_c.c print_p.c simple_prints.c

NAME = libftprintf.a

LIBFT_SRC = ./libft/libft.a

all: $(NAME)

$(NAME):
	make -C libft/ fclean && make -C libft/ && gcc -Wall -Wextra -Werror -c $(SRC)
	ar rc $(NAME) *.o libft/*.o
	ranlib $(NAME)

clean:
	/bin/rm -f *.o
	/bin/rm -rf ./libft/*.o

fclean: clean
	/bin/rm -rf $(NAME)
	/bin/rm -rf $(LIBFT_SRC)

re:	fclean all
