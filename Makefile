# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/10 16:38:18 by asydykna          #+#    #+#              #
#    Updated: 2021/03/11 20:29:25 by asydykna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ./source/ft*.c

OBJ = ft*.o

CC = gcc

CFLAGS = -Wall -Wextra -Werror -c

RM = rm -f

LIBFT_PATH = ./libft

INCLUDES=./includes

all: $(NAME)

$(NAME):
	$(MAKE) -C $(LIBFT_PATH)
	$(CC) -g $(CFLAGS) $(SRC) -I$(INCLUDES)
	ar rcs $(NAME) $(OBJ) $(LIBFT_PATH)/*.o

clean:
	$(RM) $(OBJ)
	make clean -C $(LIBFT_PATH)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re