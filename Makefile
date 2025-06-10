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

GNL_DIR = external_functions

# Diretório e arquivos fontes
SRCS = main.c so_long.c original_map.c colors.c key_hook.c movement_conditions.c render_map.c
OBJS = $(SRCS:.c=.o)

GNL_SRCS = $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c
GNL_OBJS = $(GNL_SRCS:.c=.o)

# Flags de compilação
CFLAGS = -Wall -Wextra -Werror -Iminilibx-linux -I$(GNL_DIR)

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
$(NAME): $(OBJS) $(GNL_OBJS) $(MLX)
	@$(CC) $(CFLAGS) $(OBJS) $(GNL_OBJS) $(MLX_FLAGS) -o $(NAME)

# Regra para compilar os arquivos .o
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

# Limpeza dos arquivos objetos
clean:
	@rm -f $(OBJS) $(GNL_OBJS)
	@$(MAKE) clean -C $(MLX_DIR)

# Limpeza total, incluindo o binário
fclean: clean
	@rm -f $(NAME)
	@$(MAKE) clean -C $(MLX_DIR)

# Recompilação total
re: fclean all
