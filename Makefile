# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tajjid <tajjid@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/11 10:13:00 by tajjid            #+#    #+#              #
#    Updated: 2023/12/16 14:39:40 by tajjid           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
NAME_BONUS = cub3d_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror -O3
SRC = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c libft/ft_atoi.c libft/ft_bzero.c libft/ft_calloc.c libft/ft_isdigit.c libft/ft_split.c libft/ft_strchr.c libft/ft_strdup.c \
	libft/ft_strjoin.c libft/ft_strncmp.c libft/ft_strtrim.c libft/ft_substr.c \
	parsing/line_check.c parsing/map_check.c parsing/map_constracting.c parsing/player_check.c parsing/settings_check.c raycasting/cast_all_rays.c raycasting/hori_vert_intersection.c \
	raycasting/utils.c texture/drawing_walls.c texture/minimap.c texture/textures_checker.c tools/allocator.c \
	tools/error_tools.c tools/movement.c tools/movements_2.c cub3d.c
SRC_BONUS = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c libft/ft_atoi.c libft/ft_bzero.c libft/ft_calloc.c libft/ft_isdigit.c libft/ft_split.c libft/ft_strchr.c libft/ft_strdup.c \
	libft/ft_strjoin.c libft/ft_strncmp.c libft/ft_strtrim.c libft/ft_substr.c \
	parsing/line_check.c parsing/map_check.c parsing/map_constracting.c parsing/player_check.c parsing/settings_check.c raycasting/cast_all_rays.c raycasting/hori_vert_intersection.c \
	raycasting/utils.c texture/drawing_walls.c texture/minimap.c texture/textures_checker.c tools/allocator.c \
	tools/error_tools.c tools/movement.c tools/movements_2.c cub3d_bonus.c

OBJS = $(SRC:.c=.o)
OBJS_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)
bonus: $(NAME_BONUS)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -Imlx -lmlx -framework OpenGL -framework AppKit $(OBJS) -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAGS) -Imlx -lmlx -framework OpenGL -framework AppKit $(OBJS_BONUS) -o $(NAME_BONUS)

%.o: %.c cub3d.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)
	@clear

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)
	@clear

re: fclean all bonus
	@clear
