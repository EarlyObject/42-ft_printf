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

#SRC = ./libft/ft*.c ./source/ft*.c
SRC = ./source/ft*.c
#OBJ = $(SRC:.c=.o)
OBJ = ft*.o

CC = gcc

CFLAGS = -Wall -Wextra -Werror -c

RM = rm -f

LIBFT_PATH = ./libft

all: $(NAME)

libft:
	

$(NAME):
	$(MAKE) -C $(LIBFT_PATH)
	$(CC) -g $(CFLAGS) $(SRC)
	ar rcs $(NAME) $(OBJ) $(LIBFT_PATH)/*.o

clean:
	$(RM) $(OBJ)
	$(RM) ./libft/*.o

fclean: clean
	$(RM) $(NAME)

program: all
	$(CC) main.c libftprintf.a

debug:
	$(MAKE) -C $(LIBFT_PATH)
	$(CC) -g $(CFLAGS) $(SRC)
	ar rcs $(NAME) $(OBJ) $(LIBFT_PATH)/*.o
	$(CC) -g main.c libftprintf.a
phony: all clean fclean re