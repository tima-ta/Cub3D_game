# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: araqioui <araqioui@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/02 11:59:36 by araqioui          #+#    #+#              #
#    Updated: 2023/06/26 10:24:04 by araqioui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = cc
CFLAGS = -Wall -Werror -Wextra -g #-fsanitize=address
RM = rm -rf
HEADERS = headers/cub3d.h
GNL = utils/get_next_line
MLX = -lmlx -framework OpenGL -framework AppKit
MATH = -lm

SRC = main parsing/reading_map parsing/parse_top_1 parsing/parse_top_2 parsing/parse_top_3\
	$(GNL)/get_next_line $(GNL)/get_next_line_utils \
	utils/utils/memcmp utils/utils/utils utils/utils/split utils/utils/strdup \
	utils/utils/atoi  utils/utils/utils_1 utils/utils/rgb_to_hex \
	utils/utils/my_mlx_pixel_put \
	parsing/parse_bottom parsing/check_chars parsing/check_walls \
	simulation/start simulation/mini_map simulation/move_player simulation/render_rays simulation/hit_point_1 simulation/hit_point_2 simulation/render_walls\

OBJ = $(SRC:=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADERS)
	@ $(CC) $(CFLAGS) ${MLX} $(OBJ) -o $@

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@ $(RM) $(OBJ)

fclean: clean
	@ $(RM) $(NAME)

re: fclean  all

.PHONY: all clean fclean re