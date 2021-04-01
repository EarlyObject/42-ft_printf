# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/10 16:38:18 by asydykna          #+#    #+#              #
#    Updated: 2021/04/01 16:21:51 by asydykna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = source/ft_count_putchar.c\
		source/ft_mng_flags.c\
		source/ft_mng_input.c\
		source/ft_mng_precision.c\
		source/ft_mng_width.c\
		source/ft_print_c.c\
		source/ft_print_p.c\
		source/ft_print_s.c\
		source/ft_printf.c\
		source/ft_mng_e_minus.c\
		source/ft_mng_format.c\
		source/ft_mng_output.c\
		source/ft_mng_wd_prs.c\
		source/ft_print_and_count.c\
		source/ft_print_d.c\
		source/ft_print_prcnt.c\
		source/ft_print_x.c\

OBJ = ft_count_putchar.o\
		ft_mng_flags.o\
		ft_mng_input.o\
		ft_mng_precision.o\
		ft_mng_width.o\
		ft_print_c.o\
		ft_print_p.o\
		ft_print_s.o\
		ft_printf.o\
		ft_mng_e_minus.o\
		ft_mng_format.o\
		ft_mng_output.o\
		ft_mng_wd_prs.o\
		ft_print_and_count.o\
		ft_print_d.o\
		ft_print_prcnt.o\
		ft_print_x.o\

CC = gcc

CFLAGS = -Wall -Wextra -Werror -c

RM = rm -f

LIBFT_PATH = ./libft

INCLUDES = ./includes

all: $(NAME)

$(NAME):
	$(MAKE) -C $(LIBFT_PATH)
	cp $(LIBFT_PATH)/libft.a $(NAME)
	$(CC) -g $(CFLAGS) $(SRC) -I $(INCLUDES)
	ar rcs $(NAME) ./$(OBJ)

clean:
	$(RM) ./$(OBJ)
	make clean -C $(LIBFT_PATH)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re