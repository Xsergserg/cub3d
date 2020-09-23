# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbeach <rbeach@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/10 14:22:17 by rbeach            #+#    #+#              #
#    Updated: 2020/07/28 13:18:40 by rbeach           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D.out

CC = gcc

FLAGS = -Wall -Werror -Wextra

LIBFT_DIR = libft

LIBFT = libft.a

MLX_DIR = mlx

HEADER_DIR = includes

HEADERS = $(HEADER_DIR)/cub3d.h $(HEADER_DIR)/get_next_line.h

S_DIR = src

O_DIR = obj

SRCS = get_next_line.c cub3d.c file_reader.c legend_parser.c rw_opt_pars.c sfc_opt_pars.c map_parser.c mem_free.c map_checker.c cube_graph.c print_objects.c key_handle.c print_rays.c textures.c print_sprite.c utils.c bmp.c struct_memset.c

OBJECTS = $(addprefix $(O_DIR)/,$(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJECTS) $(HEADERS) libft libmlx
	$(CC) -o $(NAME) $(OBJECTS) -I $(HEADER_DIR) -I $(MLX_DIR) -I $(LIBFT_DIR) -L$(LIBFT_DIR) -lft libmlx.dylib -framework OpenGL -framework AppKit

$(O_DIR)/%.o: $(S_DIR)/%.c $(HEADERS)
	@mkdir -p $(O_DIR)
	$(CC) $(FLAGS) -I $(HEADER_DIR) -I $(MLX_DIR) -I $(LIBFT_DIR) -o $@ -c $<

libft:
	$(MAKE) -C $(LIBFT_DIR)

libmlx:
	$(MAKE) -C $(MLX_DIR)
	cp mlx/libmlx.dylib ./

clean:
	rm -rf $(O_DIR)
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)
	rm -f libmlx.dylib


re: fclean all

.PHONY: libft all clean fclean libmlx
