/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_all_rays.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 21:17:04 by yochakib          #+#    #+#             */
/*   Updated: 2023/12/10 21:27:48 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	h_part(t_glob	*glob, int column)
{
	double	tocheck_x;
	double	tocheck_y;

	while (glob->h_values->next_htouch_x >= 0 && \
	glob->h_values->next_htouch_x <= (glob->da_map->map_width * TILE_SIZE) && \
	glob->h_values->next_htouch_y >= 0 && glob->h_values->next_htouch_y \
	<= (glob->da_map->map_height * TILE_SIZE))
	{
		tocheck_x = glob->h_values->next_htouch_x;
		tocheck_y = glob->h_values->next_htouch_y;
		if (glob->rays[column]->hit_up)
			tocheck_y -= 1;
		if (ray_is_it_a_wall(glob, tocheck_x, tocheck_y))
		{
			glob->h_values->hit_x = glob->h_values->next_htouch_x;
			glob->h_values->hit_y = glob->h_values->next_htouch_y;
			glob->h_values->distance_h = \
			distance_between_point(glob->player->player_x, \
			glob->h_values->hit_x, glob->player->player_y, \
			glob->h_values->hit_y);
			break ;
		}
		glob->h_values->next_htouch_x += glob->h_values->x_step;
		glob->h_values->next_htouch_y += glob->h_values->y_step;
	}
}

void	horizontal_cast(int column, t_glob *glob)
{
	hit_down_or_up(glob->rays[column]);
	hit_right_or_left(glob->rays[column]);
	horizontal_intersection(glob, glob->rays[column]);
	glob->h_values->next_htouch_x = \
	glob->rays[column]->firsthori_intersection_x;
	glob->h_values->next_htouch_y = \
	glob->rays[column]->firsthori_intersection_y;
	glob->h_values->distance_h = INFINITY;
	h_part(glob, column);
}

void	v_part(t_glob	*glob, int column)
{
	double	tocheck_x;
	double	tocheck_y;

	while (glob->v_values->next_vtouch_x >= 0 && \
	glob->v_values->next_vtouch_x <= (glob->da_map->map_width * TILE_SIZE) && \
	glob->v_values->next_vtouch_y >= 0 && glob->v_values->next_vtouch_y \
	<= (glob->da_map->map_height * TILE_SIZE))
	{
		tocheck_x = glob->v_values->next_vtouch_x;
		tocheck_y = glob->v_values->next_vtouch_y;
		if (glob->rays[column]->hit_left)
			tocheck_x -= 1;
		if (ray_is_it_a_wall(glob, tocheck_x, tocheck_y))
		{
			glob->v_values->hit_x = glob->v_values->next_vtouch_x;
			glob->v_values->hit_y = glob->v_values->next_vtouch_y;
			glob->v_values->distance_v = \
			distance_between_point(glob->player->player_x, \
			glob->v_values->hit_x, glob->player->player_y, \
			glob->v_values->hit_y);
			break ;
		}
		glob->v_values->next_vtouch_x += glob->v_values->x_step;
		glob->v_values->next_vtouch_y += glob->v_values->y_step;
	}
}

void	vertical_cast(int column, t_glob *glob)
{
	hit_down_or_up(glob->rays[column]);
	hit_right_or_left(glob->rays[column]);
	vertical_intersection(glob, glob->rays[column]);
	glob->v_values->next_vtouch_x = \
	glob->rays[column]->firstvert_intersection_x;
	glob->v_values->next_vtouch_y = \
	glob->rays[column]->firstvert_intersection_y;
	glob->v_values->distance_v = INFINITY;
	v_part(glob, column);
}

void	ray_casting(t_glob *glob)
{
	int			column_id;
	double		ray_angle;

	column_id = 0;
	ray_angle = degreestoradians(\
	glob->player->player_angle) - (FOV_ANGLE / 2.0);
	glob->rays = ft_calloc(sizeof(t_ray *), (NUM_RAYS + 1));
	while (column_id < NUM_RAYS)
	{
		glob->rays[column_id] = malloc(sizeof(t_ray));
		if (!glob->rays[column_id])
			exit(1);
		ray_initializer(glob->rays[column_id], ray_angle);
		horizontal_cast(column_id, glob);
		vertical_cast(column_id, glob);
		comparing_distances(glob->rays[column_id], glob);
		ray_angle += (FOV_ANGLE / NUM_RAYS);
		column_id++;
	}
}
