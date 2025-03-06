# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arde-jes <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/05 12:23:27 by arde-jes          #+#    #+#              #
#    Updated: 2025/03/05 12:23:29 by arde-jes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nome do programa
NAME = program

# Compilador
CC = cc

# Diretório e arquivos fontes
SRCS = map.c my_mlx_pixel_put.c colors.c get_next_line.c \
		get_next_line_utils.c get_next_line.h
OBJS = $(SRCS:.c=.o)

# Flags de compilação
CFLAGS = -Wall -Wextra -Werror -Iminilibx-linux

# Diretório e biblioteca do mlx
MLX_DIR = ./mlx
MLX = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

# Alvo principal
all: $(MLX) $(NAME)

# Regra para compilar a biblioteca mlx
$(MLX):
	@$(MAKE) -C $(MLX_DIR)

# Regra para compilar a biblioteca libft (caso tenha)

# Regra para compilar o programa final
$(NAME): $(OBJS) $(MLX)
	@$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

# Regra para compilar os arquivos .o
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

# Limpeza dos arquivos objetos
clean:
	@rm -f $(OBJS)
	@$(MAKE) clean -C $(MLX_DIR)

# Limpeza total, incluindo o binário
fclean: clean
	@rm -f $(NAME)
	@$(MAKE) clean -C $(MLX_DIR)

# Recompilação total
re: fclean all
