# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/15 17:34:08 by smokhtar          #+#    #+#              #
#    Updated: 2018/09/12 18:06:23 by smokhtar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

name = ft_ls

flag = -Wall -Werror -Wextra 

fz = -fsanitize=address

file = ft_ls\
		parseur\
		read_dir\
		start_print\
		my_list\
		check_file\
		inser_sort\
		print_l\
		inser_sort2


Src = $(addprefix src/, $(file))

src = $(addsuffix .c, $(Src))

obj = $(addsuffix .o, $(file))

lib =  libft/libft.a

inc = -Iinclude -Ilibft

object = $(addsuffix .o, $(Src))

all: $(name)

$(name) :
	make -C libft/
	gcc -o $(name) $(lib) $(src) $(inc) $(flag) $(fz)

e : 
	touch ft_ls
	rm ft_ls
	gcc -o $(name) $(lib) $(src) $(inc) $(flag) $(fz)

f : 
	touch ft_ls
	rm ft_ls
	gcc -o $(name) $(lib) $(src) $(inc) $(flag)

clean :
	make -C libft/ clean
	rm -rf $(obj)

fclean : clean
	make -C libft/ fclean
	touch $(name)
	rm $(name)

re : fclean all