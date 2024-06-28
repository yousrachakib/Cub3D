/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajjid <tajjid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:50:24 by tajjid            #+#    #+#             */
/*   Updated: 2023/12/15 16:55:08 by tajjid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	key_press(int key, t_glob *glob)
{
	if (key == ESC)
		exit(0);
	if (key == W_KEY)
		glob->player->walk_direction = 1;
	if (key == S_KEY)
		glob->player->walk_direction = -1;
	if (key == A_KEY)
		glob->player->walk_direction_side = -1;
	if (key == D_KEY)
		glob->player->walk_direction_side = 1;
	if (key == LEFT_ARROW)
		glob->player->turn_direction = -1;
	if (key == RIGHT_ARROW)
		glob->player->turn_direction = 1;
	return (0);
}

int	key_release(int key, t_glob *glob)
{
	if (key == W_KEY)
		glob->player->walk_direction = 0;
	if (key == S_KEY)
		glob->player->walk_direction = 0;
	if (key == A_KEY)
		glob->player->walk_direction_side = 0;
	if (key == D_KEY)
		glob->player->walk_direction_side = 0;
	if (key == LEFT_ARROW)
		glob->player->turn_direction = 0;
	if (key == RIGHT_ARROW)
		glob->player->turn_direction = 0;
	return (0);
}

void	player_movement_strait(t_glob *glob)
{
	double	new_plyr_x;
	double	new_plyr_y;

	new_plyr_x = glob->player->player_x + \
			cos(degreestoradians(glob->player->player_angle)) \
			* glob->player->walk_direction * SPEED;
	new_plyr_y = glob->player->player_y + \
			sin(degreestoradians(glob->player->player_angle)) \
			* glob->player->walk_direction * SPEED;
	if (is_it_a_wall(glob, new_plyr_x + 2, new_plyr_y) == 1
		&& is_it_a_wall(glob, new_plyr_x - 2, new_plyr_y) == 1
		&& is_it_a_wall(glob, new_plyr_x, new_plyr_y + 2) == 1
		&& is_it_a_wall(glob, new_plyr_x, new_plyr_y - 2) == 1)
	{
		glob->player->player_x = new_plyr_x;
		glob->player->player_y = new_plyr_y;
	}
}

void	player_movement_side(t_glob *glob)
{
	double	new_plyr_x;
	double	new_plyr_y;

	new_plyr_x = glob->player->player_x + \
			cos(degreestoradians(glob->player->player_angle + 90)) \
			* glob->player->walk_direction_side * SPEED;
	new_plyr_y = glob->player->player_y + \
			sin(degreestoradians(glob->player->player_angle + 90)) \
			* glob->player->walk_direction_side * SPEED;
	if (is_it_a_wall(glob, new_plyr_x + 2, new_plyr_y) == 1
		&& is_it_a_wall(glob, new_plyr_x - 2, new_plyr_y) == 1
		&& is_it_a_wall(glob, new_plyr_x, new_plyr_y + 2) == 1
		&& is_it_a_wall(glob, new_plyr_x, new_plyr_y - 2) == 1)
	{
		glob->player->player_x = new_plyr_x;
		glob->player->player_y = new_plyr_y;
	}
}

void	player_rotation(t_glob *glob)
{
	glob->player->player_angle
		+= (glob->player->turn_direction * ROTATION_SPEED);
	if (glob->player->player_angle > 360)
		glob->player->player_angle -= 360;
	if (glob->player->player_angle < 0)
		glob->player->player_angle += 360;
}
