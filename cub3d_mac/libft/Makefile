# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbeach <rbeach@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/10 14:22:17 by rbeach            #+#    #+#              #
#    Updated: 2020/07/28 12:51:37 by rbeach           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

FLAGS = -Wall -Werror -Wextra

HEADER = libft.h

HEADER_DIR = .

S_DIR = .

O_DIR = obj

SRCS = ft_memset.c\
ft_bzero.c\
ft_memcpy.c\
ft_memccpy.c\
ft_memmove.c\
ft_memchr.c\
ft_memcmp.c\
ft_strlen.c\
ft_strlcpy.c\
ft_strlcat.c\
ft_strchr.c\
ft_strrchr.c\
ft_strnstr.c\
ft_strncmp.c\
ft_atoi.c\
ft_isalpha.c\
ft_isdigit.c\
ft_isalnum.c\
ft_isascii.c\
ft_isprint.c\
ft_toupper.c\
ft_tolower.c\
ft_calloc.c\
ft_strdup.c\
ft_substr.c\
ft_strjoin.c\
ft_strtrim.c\
ft_split.c\
ft_itoa.c\
ft_strmapi.c\
ft_putchar_fd.c\
ft_putstr_fd.c\
ft_putendl_fd.c\
ft_putnbr_fd.c\
ft_itoagr.c\
ft_strlower.c\
ft_strcatchr.c\
ft_symclone.c\
ft_strlens.c

BONUS_SRCS = ft_lstnew.c\
ft_lstadd_front.c\
ft_lstsize.c\
ft_lstlast.c\
ft_lstadd_back.c\
ft_lstdelone.c\
ft_lstclear.c\
ft_lstiter.c\
ft_lstmap.c

OBJECTS = $(addprefix $(O_DIR)/,$(SRCS:.c=.o))

BONUS_OBJECTS = $(addprefix $(O_DIR)/,$(BONUS_SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJECTS) $(HEADER_DIR)/$(HEADER)
	ar rcs $(NAME) $(OBJECTS)

$(O_DIR)/%.o: $(S_DIR)/%.c
	@mkdir -p $(O_DIR)
	$(CC) $(FLAGS) -I $(HEADER_DIR) -o $@ -c $<

clean:
	rm -rf $(O_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(OBJECTS) $(BONUS_OBJECTS)
	ar rcs $(NAME) $(OBJECTS) $(BONUS_OBJECTS)

.PHONY: all clean fclean re
