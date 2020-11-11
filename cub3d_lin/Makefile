# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbeach <rbeach@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/10 14:22:17 by rbeach            #+#    #+#              #
#    Updated: 2020/07/30 14:32:02 by rbeach           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D.out

CC = gcc

FLAGS = -Wall -Werror -Wextra

TEST_FLAGS = -o3 -g3

LIBFT_DIR = libft

LIBFT = libft.a

HEADERS = cub3D.h get_next_line.h

HEADER_DIR = includes

S_DIR = src

O_DIR = obj

SRCS = get_next_line.c cub3d.c file_reader.c legend_parser.c rw_opt_pars.c sfc_opt_pars.c map_parser.c mem_free.c map_checker.c cube_graph.c print_objects.c key_handle.c print_rays.c textures.c print_sprite.c utils.c bmp.c struct_memset.c

OBJECTS = $(addprefix $(O_DIR)/,$(SRCS:.c=.o))

MLX_LIB_OBJ = -I/usr/include -Imlx

MLX_LIB = -Lmlx_linux -lmlx_Linux -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(OBJECTS) $(HEADER_DIR)/$(HEADER) libft mlx
	$(CC) -o $(NAME) $(OBJECTS) -I $(HEADER_DIR) -L $(LIBFT_DIR) -lft $(MLX_LIB) -no-pie

$(O_DIR)/%.o: $(S_DIR)/%.c
	@mkdir -p $(O_DIR)
	$(CC) $(TEST_FLAGS) -I$(HEADER_DIR) -I$(LIBFT_DIR) $(MLX_LIB_OBJ) -o $@ -c $<

test: $(OBJECTS) $(HEADER_DIR)/$(HEADER) libft mlx
	$(CC) $(TEST_FLAGS) -o $(NAME) $(OBJECTS) -I $(HEADER_DIR) -L $(LIBFT_DIR) -lft $(MLX_LIB) -no-pie

gdb: test
	gdb --args ./cub3D.out test.cub


libft:
	$(MAKE) -C $(LIBFT_DIR)
	
mlx:
	$(MAKE) -C mlx_linux

clean:
	rm -rf $(O_DIR)
	make clean -C $(LIBFT_DIR)
	make clean -C mlx_linux

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)
	make clean -C mlx_linux

re: fclean all

.PHONY: mlx libft all clean fclean
