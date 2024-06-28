/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajjid <tajjid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 23:43:58 by tajjid            #+#    #+#             */
/*   Updated: 2023/12/14 14:05:43 by tajjid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_it_a_wall(t_glob *glob, double x, double y)
{
	int	i;
	int	j;

	i = floor(y / TILE_SIZE);
	j = floor(x / TILE_SIZE);
	if ((j > 0 && j < glob->da_map->map_width)
		&& (i > 0 && i < glob->da_map->map_height)
		&& glob->da_map->map[i][j] == '0')
		return (1);
	else if ((j > 0 && j < glob->da_map->map_width)
		&& (i > 0 && i < glob->da_map->map_height)
		&& glob->da_map->map[i][j] == ' ')
		return (2);
	else
		return (0);
}

bool	ray_is_it_a_wall(t_glob *glob, double x, double y)
{
	int	i;
	int	j;

	i = floor(y / TILE_SIZE);
	j = floor(x / TILE_SIZE);
	if ((j > 0 && j < glob->da_map->map_width)
		&& (i > 0 && i < glob->da_map->map_height)
		&& glob->da_map->map[i][j] != '1')
		return (false);
	return (true);
}

int	mouse_motion(int x, int y, t_glob *glob)
{
	double	mouse_x;
	double	mouse_y;

	mouse_x = x;
	mouse_y = y;
	if (mouse_x < WIDTH / 3 && mouse_x > 0 && mouse_y > 0 && mouse_y < HEIGHT)
		glob->player->turn_direction = -1;
	else if (mouse_x > WIDTH / 3 * 2 && mouse_x < WIDTH && \
			mouse_y > 0 && mouse_y < HEIGHT)
		glob->player->turn_direction = 1;
	else
		glob->player->turn_direction = 0;
	return (0);
}
