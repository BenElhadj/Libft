# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/07 14:09:16 by bhamdi            #+#    #+#              #
#    Updated: 2018/11/14 19:43:01 by bhamdi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = clang
CFLAGS = -g3 -Werror -Wall -Wextra -flto -O3

SRCS_DIR = srcs/
OBJ_DIR = obj/

SRC = ft_toupper.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_strcpy.c \
	  ft_isprint.c ft_isdigit.c ft_memalloc.c ft_memccpy.c ft_memchr.c \
	  ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar.c ft_atoi.c \
	  ft_putnbr.c ft_putstr.c ft_strcat.c ft_strchr.c ft_strcmp.c ft_bzero.c \
	  ft_strdup.c ft_strlcat.c ft_strlen.c ft_strncat.c ft_strncmp.c \
	  ft_strncpy.c ft_strnstr.c ft_strrchr.c ft_strstr.c ft_tolower.c \
	  ft_itoa.c ft_memdel.c ft_strnew.c ft_strdel.c ft_striter.c ft_strequ.c \
	  ft_strnequ.c ft_striteri.c ft_strjoin.c ft_strmap.c ft_strmapi.c \
	  ft_strsub.c ft_strtrim.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl.c \
	  ft_putendl_fd.c ft_lstdelone.c ft_lstdel.c ft_lstiter.c ft_lstadd.c \
	  ft_lstmap.c ft_lstnew.c ft_strsplit.c ft_putnbr_fd.c ft_strclr.c \
	  ft_ulstr.c ft_last_word.c ft_swap.c ft_strrev.c ft_strlowcase.c \
	  ft_is_prime.c ft_fibonacci.c ft_factorial.c get_next_line.c\
	  ft_lltoa.c ft_intlen.c ft_ulltoa.c\
	  ft_atoll.c ft_lltoa_base_up.c


OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

all : $(NAME)

$(NAME): $(OBJ)
	
	@ar rcs $(NAME) $(OBJ)
	
	@echo "\n\t\033[1;34m$@\tIt's finish\033[0;32m\t\t[ √ ]\033[0m"
	

$(OBJ_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I includes -c $< -o $@

	@echo "\033[1;34m$(NAME_PROJECT)\t\033[1;33mCompilation\t\t\t\033[0;32m[OK]\033[0m\t$@"

.PHONY: clean fclean

clean :
	@rm -f $(OBJ)
	
	@echo "\033[1;34m\n\t\033[1;33mCleaning\tclean obj/\t\033[0;32m[OK]\033[0m"

fclean : clean
	@rm -f $(NAME)
	
	@echo "\033[1;34m\t\033[1;33mCleaning\t$(NAME)\t\t\033[0;32m[OK]\n\033[0m"

re : fclean all
