# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdavis <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/01 16:02:44 by jdavis            #+#    #+#              #
#    Updated: 2021/12/10 16:33:44 by jdavis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	make -C libft/ fclean && make -C libft/
	clang -Wall -Wextra -Werror -I libft/includes -o get_next_line.o -c get_next_line.c
	clang -Wall -Wextra -Werror -I libft/includes -o main.o -c ../main.c
	clang -o test_gnl main.o get_next_line.o -I libft/includes -L libft/ -lft

clean:
	rm -f *.o libft/*.o

fclean: clean
	rm -f test_gnl

re: clean all
	
