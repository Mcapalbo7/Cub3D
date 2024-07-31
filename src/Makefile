# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcapalbo < mcapalbo@student.42roma.it>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/29 12:26:32 by mla-mona          #+#    #+#              #
#    Updated: 2024/07/31 19:02:01 by mcapalbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = cub3D

LIBFT_PATH = libft/
LIBFT = $(LIBFT_PATH)libft.a
MLX_PATH = minilibx-linux/
MLX = $(MLX_PATH)libmlx.a

SRC = $(wildcard main.c init.c \
		movement/*.c \
		parsing/*.c \
		raycasting/*.c \
		rendering/*.c \
		utils/*.c)

OBJ = $(SRC:.c=.o)

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -g

LDFLAGS = -L$(MLX_PATH) -lmlx -lXext -lX11 -lm

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJ)
	make -C $(MLX_PATH)
	make -C $(LIBFT_PATH)
	$(CC) $(OBJ) $(LIBFT) $(MLX) $(LDFLAGS) -o $(NAME)

all: $(NAME)

clean:
	make clean -C $(MLX_PATH)
	make clean -C $(LIBFT_PATH)
	$(RM) $(OBJ)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re