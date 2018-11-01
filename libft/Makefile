# *************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 18:26:26 by smokhtar          #+#    #+#              #
#    Updated: 2018/03/02 17:42:36 by smokhtar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

SRC_NAME =ft_islower\
		ft_conv_base\
		ft_isupper\
		ft_putfile\
		ft_puttable_int\
		ft_strjoinfree\
		ft_puttable\
		ft_lstmap\
		ft_lstadd\
		ft_lstiter\
		ft_lstdel\
		ft_lstdelone\
		ft_lstnew\
		ft_strsplit\
		ft_memmove\
		ft_memchr\
		ft_memcmp\
		ft_memccpy\
		ft_memcpy\
		ft_strnstr\
		ft_strstr\
		ft_strmapi\
		ft_strlcat\
		ft_strncat\
		ft_strcat\
		ft_putendl\
		ft_strrchr\
		ft_strtrim\
		ft_putchar_fd\
	   	ft_putstr_fd\
	   	ft_putstr_nl\
		ft_putendl_fd\
		ft_putnbr_fd\
		ft_tolower\
		ft_toupper\
		ft_isprint\
		ft_isascii\
		ft_isalnum\
		ft_isdigit\
		ft_isalpha\
		ft_itoa\
		ft_putnbr\
		ft_nbrlen\
		ft_atoi\
		ft_bzero\
		ft_putchar\
		ft_strcmp\
		ft_strequ\
		ft_strlen\
		ft_strnequ\
		ft_memalloc\
		ft_putstr\
		ft_strcpy\
		ft_striter\
		ft_strmap\
		ft_strnew\
		ft_memdel\
		ft_strchr\
		ft_strdel\
		ft_striteri\
		ft_strncmp\
		ft_strsub\
		ft_memset\
		ft_strclr\
		ft_strdup\
		ft_strjoin\
		ft_strncpy\
		ft_tablen\
		ft_tabdel\
		ft_error\
		get_next_line\

src = $(addsuffix .c, $(SRC_NAME))

object = $(addsuffix .o, $(SRC_NAME))

head = .

flag = -Wall -Werror -Wextra 

all: $(NAME) 

$(NAME):
	gcc -c $(flag) $(src) -I$(head)
	ar rcs libft.a $(object)

clean:
	rm -f $(object)

fclean: clean
	rm -f libft.a

re : fclean all
