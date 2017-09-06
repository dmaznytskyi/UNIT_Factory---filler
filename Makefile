# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/02 13:18:17 by dmaznyts          #+#    #+#              #
#    Updated: 2017/09/04 00:12:50 by dmaznyts         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

CC = gcc

LIB = libft/ft_atoi.o libft/ft_bzero.o libft/ft_isalnum.o libft/ft_isalpha.o\
	  libft/ft_isascii.o libft/ft_isdigit.o libft/ft_isprint.o libft/ft_itoa.o\
	  libft/ft_lstadd.o libft/ft_lstdel.o libft/ft_lstdelone.o libft/ft_lstiter.o\
	  libft/ft_lstmap.o libft/ft_lstnew.o libft/ft_memalloc.o libft/ft_memccpy.o\
	  libft/ft_memchr.o libft/ft_memcmp.o libft/ft_memcpy.o libft/ft_memdel.o\
	  libft/ft_memmove.o libft/ft_memset.o libft/ft_putchar.o libft/ft_putchar_fd.o\
	  libft/ft_putendl.o libft/ft_putendl_fd.o libft/ft_putnbr.o libft/ft_putnbr_fd.o\
	  libft/ft_putstr.o libft/ft_putstr_fd.o libft/ft_strcat.o libft/ft_strchr.o\
	  libft/ft_strclr.o libft/ft_strcmp.o libft/ft_strcpy.o libft/ft_strdel.o\
	  libft/ft_strdup.o libft/ft_strequ.o libft/ft_striter.o libft/ft_striteri.o\
	  libft/ft_strjoin.o libft/ft_strlcat.o libft/ft_strlen.o libft/ft_strmap.o\
	  libft/ft_strmapi.o libft/ft_strncat.o libft/ft_strncmp.o libft/ft_strncpy.o\
	  libft/ft_strnequ.o libft/ft_strnew.o libft/ft_strnstr.o libft/ft_strrchr.o\
	  libft/ft_strsplit.o libft/ft_strstr.o libft/ft_strsub.o libft/ft_strtrim.o\
	  libft/ft_tolower.o libft/ft_toupper.o

OBJ = ft_printf.o ft_putstr_until.o ft_cv.o ft_ns.o ft_pf.o ft_pfw.o\
	  ft_pprec.o ft_findallmodifiers.o ft_psm.o	ft_writeout.o\
	  ft_s_small.o ft_s_big.o ft_p_small.o ft_d_small.o ft_d_big.o\
	  ft_i_small.o ft_o_small.o ft_o_big.o ft_u_small.o ft_u_big.o\
	  ft_x_small.o ft_x_big.o ft_c_small.o ft_c_big.o\
	  ft_itoa_base.o ft_isflag.o ft_is_sm.o ft_s_big_extra.o\
	  ft_wstrjoin.o ft_lltoa_base.o ft_sultoa_base.o ft_uitoa_base.o\
	  ft_luitoa_base.o ft_sttoa_base.o ft_imttoa_base.o ft_llltoa_base.o\
	  ft_sitoa_base.o ft_ctoa_base.o ft_luimttoa_base.o ft_usitoa_base.o\
	  ft_uctoa_base.o ft_lusitoa_base.o ft_luctoa_base.o ft_lultoa_base.o\
	  ft_wstrdup.o ft_suimttoa_base.o ft_lsttoa_base.o ft_s_small_extra.o\
	  ft_x_small_extra.o ft_d_small_extra.o ft_o_small_extra.o\
	  ft_s_big_extra2.o ft_s_big_extra3.o ft_s_big_extra4.o\
	  ft_s_big_extra5.o

all: $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -g -c -o $@ $<

$(NAME): $(OBJ) libft/libft.a
	@ar -rc $(NAME) $(OBJ) $(LIB)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJ)
	@make -C libft clean
	
fclean: clean
	@/bin/rm -f $(NAME)
	@make -C libft fclean

libft/libft.a:
	@make -C libft

re: fclean all
