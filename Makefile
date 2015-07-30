#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jandreu <jandreu@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/21 21:34:43 by jandreu           #+#    #+#              #
#    Updated: 2015/03/21 21:44:08 by jandreu          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf

SOURCE_C = get_next_line.c \
draw.c \
expose.c \
ft_fdf.c \
window.c

OBJ = $(SOURCE_C:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	@cd libft && $(MAKE)
	@gcc -Wall -Wextra -Werror -I libft/ -L libft -lft -L mini/ -lmlx -framework OpenGL -framework AppKit $(OBJ) -o $(NAME)
	@echo "compilation done";

%.o: %.c
	@gcc -Wall -Wextra -Werror -I. -I./libft -c $< -o $@

clean:
	@cd libft && $(MAKE) $@
	@rm -f $(OBJ)
	@echo "clean done ";

fclean: clean
	@cd libft && $(MAKE) $@
	@rm -f $(NAME)

re: fclean all