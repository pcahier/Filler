# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcahier <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 15:00:01 by pcahier           #+#    #+#              #
#    Updated: 2018/11/06 08:58:11 by pcahier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_abs.c ft_atoi.c ft_bzero.c ft_caesarcrypt.c ft_charray.c ft_decnumlen.c	\
	  ft_div.c ft_genprinstruc.c ft_initstru.c ft_int_dec.c ft_int_uchar.c			\
	  ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isblank.c ft_iscntrl.c ft_isdigit.c	\
	  ft_isgraph.c ft_islower.c ft_isprint.c ft_ispunct.c ft_isspace.c ft_isupper.c	\
	  ft_isxdigit.c ft_itoa.c ft_itoa_print.c ft_kirbydance.c ft_lstadd.c 			\
	  ft_lstaddend.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c			\
	  ft_lstnew.c ft_memalloc.c ft_memcat.c ft_memccpy.c ft_memchr.c ft_memcmp.c	\
	  ft_memcpy.c ft_memdel.c ft_memfrob.c ft_memmove.c ft_memscanfor.c ft_memset.c	\
	  ft_pointer.c ft_printchar.c ft_printdecnumlen.c ft_printf.c ft_printstring.c	\
	  ft_printstringwchar.c ft_printunsnumlen.c ft_printwchar.c ft_putchar.c		\
	  ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putinttab.c ft_putinttab_fd.c	\
	  ft_putnbr.c ft_putnbr_fd.c ft_putnstr_fd.c ft_putsign.c ft_putstr.c			\
	  ft_putstr_fd.c ft_putstrtab.c ft_putstrtab_fd.c ft_sqrt.c ft_str_is_alpha.c	\
	  ft_stralnumwrdcnt.c ft_strcapitalize.c ft_strcat.c ft_strchr.c ft_strclr.c	\
	  ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c		\
	  ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c				\
	  ft_strlowcase.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c			\
	  ft_strncpy.c ft_strndup.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strpbrk.c	\
	  ft_strrchr.c ft_strrev.c ft_strsplit.c ft_strspn.c ft_strstr.c ft_strsub.c	\
	  ft_strtrim.c ft_strupcase.c ft_tolower.c ft_toupper.c ft_uitoa_print.c		\
	  ft_uitoam_print.c ft_uns_bin.c ft_uns_dec.c ft_uns_hex.c ft_uns_hexmaj.c		\
	  ft_uns_oct.c ft_max.c ft_putnchar.c ft_vfprintf.c ft_wrongconv.c				\
	  get_next_line.c

OBJ = $(SRC:.c=.o)

INC = libft.h ft_printf.h ft_printstru.h get_next_line.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJ) $(INC)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:
	make fclean 
	make all

.PHONY: all clean fclean re
