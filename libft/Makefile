# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/11 17:26:56 by qrosa             #+#    #+#              #
#    Updated: 2017/01/23 22:44:32 by yoko             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			=	ft_atoi.c\
				ft_itoa.c\
				ft_bzero.c\
\
				ft_isalnum.c\
				ft_isalnum_var.c\
				ft_isalpha.c\
				ft_isascii.c\
				ft_isdigit.c\
				ft_isnumber.c\
				ft_isprint.c\
				ft_ispace_tab_line.c\
				ft_is_empty_line.c\
				ft_isalnum_line.c\
				ft_isprint_line.c\
				ft_isthischar.c\
				ft_isnthischar.c\
\
				ft_memalloc.c\
				ft_realloc.c\
				ft_memccpy.c\
				ft_memchr.c\
\
				ft_memcmp.c\
				ft_memcpy.c\
				ft_memdel.c\
				ft_memmove.c\
				ft_memset.c\
\
				ft_strlen.c\
				ft_nbrlen.c\
				ft_tablen.c\
\
				ft_putchar.c\
				ft_putchar_fd.c\
				ft_putnbr.c\
				ft_putnbr_fd.c\
\
				ft_putstr.c\
				ft_putstr_fd.c\
				ft_putnstr.c\
\
				ft_putendl.c\
				ft_putendl_fd.c\
				ft_putnendl.c\
\
				ft_putendl_clair.c\
				ft_putendl_clair_fd.c\
\
				ft_put_tab.c\
				ft_put_tab_fd.c\
\
				ft_strcat.c\
				ft_strchr.c\
				ft_strstr.c\
				ft_strclr.c\
\
				ft_strcmp.c\
				ft_strcpy.c\
				ft_strdel.c\
\
				ft_strdup.c\
				ft_strndup.c\
				ft_strdup_endchar.c\
				ft_str_trimndup.c\
				ft_str_trimndup_echap.c\
				ft_strequ.c\
				ft_striter.c\
				ft_striteri.c\
				ft_strjoin.c\
 \
				ft_buff_add_char.c\
\
				ft_strlcat.c\
				ft_strmap.c\
				ft_strmapi.c\
				ft_strncat.c\
\
				ft_strncmp.c\
				ft_strncpy.c\
				ft_strnew.c\
				ft_strnstr.c\
				ft_strrchr.c\
\
				ft_strsplit.c\
\
				ft_free_line.c\
				ft_free_tab.c\
\
				ft_strsub.c\
				ft_strtrim.c\
				ft_tolower.c\
				ft_toupper.c\
				ft_strnequ.c\
\
				ft_lstnew.c\
				ft_lstdelone.c\
				ft_lstdel.c\
				ft_lstadd.c\
				ft_lstiter.c\
				ft_lstmap.c\
 \
				ft_file_exists.c\
				ft_check_typefile.c\
\
				get_next_line.c\
\
				opt_check_options.c\
				opt_exist_letter.c\
				opt_exist_long.c\
				opt_free_end.c\
\
				opt_get_options.c\
				opt_init_env.c\
				opt_is_valid.c\
				opt_parse_arguments.c\
\
				opt_print_error.c\
				opt_save_arg.c\
				opt_check_last_opt.c


OBJ=$(SRC:.c=.o)

# Lib - Includes
INCL		=	includes

# Option - Compilation
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g
NAME		=	libft.a

# Color of Skills
RED			=	\033[0;31m
BLUE		=	\033[1;34m
CYAN		=	\033[0;36m
YELLOW		=	\033[0;33m
GREEN		=	\033[1;32m
NC			=	\033[0m


all: $(NAME)

$(NAME): $(OBJ)
	@echo "${CYAN}-- Compilation LIBFT-SRCS to OBJS = OK ${NC}"
	@echo "${BLUE}-- Linking $(NAME)${NC}"
	@echo "${BLUE}-- ar rc $(NAME)${NC}"
	@ar rc $(NAME) $(OBJ)
	@echo "${BLUE}-- ranlib $(NAME)${NC}"
	@ranlib $(NAME)

%.o : %.c
	@$(CC) -c $^ -o $@ $(CFLAGS) -I $(INCL)

clean:
	@echo "${YELLOW}-- Delete Libft		Objects OK${NC}";
	@rm -rf $(OBJ)

fclean: clean
	@echo "${RED}-- Delete $(NAME)${NC}"
	@rm -rf $(NAME)

re: fclean all clean
