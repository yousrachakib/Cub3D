/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hori_vert_intersection.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 21:26:40 by yochakib          #+#    #+#             */
/*   Updated: 2023/12/10 21:26:44 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	horizontal_intersection(t_glob *glob, t_ray *ray)
{
	ray->firsthori_intersection_y = \
	floor(glob->player->player_y / TILE_SIZE) * TILE_SIZE;
	if (ray->hit_down)
		ray->firsthori_intersection_y += TILE_SIZE;
	ray->firsthori_intersection_x = glob->player->player_x + \
	(ray->firsthori_intersection_y - glob->player->player_y) / \
	tan(ray->ray_angle);
	glob->h_values->y_step = TILE_SIZE;
	if (ray->hit_up)
		glob->h_values->y_step *= -1;
	glob->h_values->x_step = TILE_SIZE / tan(ray->ray_angle);
	if (ray->hit_left && glob->h_values->x_step > 0)
		glob->h_values->x_step *= -1;
	else if (ray->hit_right && glob->h_values->x_step < 0)
		glob->h_values->x_step *= -1;
}

void	vertical_intersection(t_glob *glob, t_ray *ray)
{
	ray->firstvert_intersection_x = \
	floor(glob->player->player_x / TILE_SIZE) * TILE_SIZE;
	if (ray->hit_right)
		ray->firstvert_intersection_x += TILE_SIZE;
	ray->firstvert_intersection_y = glob->player->player_y + \
	(ray->firstvert_intersection_x - glob->player->player_x) * \
	tan(ray->ray_angle);
	glob->v_values->x_step = TILE_SIZE;
	if (ray->hit_left)
		glob->v_values->x_step *= -1;
	glob->v_values->y_step = TILE_SIZE * tan(ray->ray_angle);
	if (ray->hit_up && glob->v_values->y_step > 0)
		glob->v_values->y_step *= -1;
	else if (ray->hit_down && glob->v_values->y_step < 0)
		glob->v_values->y_step *= -1;
}

void	comparing_distances(t_ray *ray, t_glob *glob)
{
	if (glob->h_values->distance_h > glob->v_values->distance_v)
	{
		ray->distance = glob->v_values->distance_v;
		ray->hit_vertical = 1;
		ray->hit_x = glob->v_values->hit_x;
		ray->hit_y = glob->v_values->hit_y;
		return ;
	}
	ray->distance = glob->h_values->distance_h;
	ray->hit_vertical = 2;
	ray->hit_x = glob->h_values->hit_x;
	ray->hit_y = glob->h_values->hit_y;
}

void	ray_initializer(t_ray *ray, double ray_angle)
{
	ray->ray_angle = normalize_ray_angle(ray_angle);
	ray->distance = 0.0;
	ray->hit_vertical = 0;
	ray->hit_x = 0.0;
	ray->hit_y = 0.0;
	ray->firsthori_intersection_x = 0.0;
	ray->firsthori_intersection_y = 0.0;
	ray->firstvert_intersection_x = 0.0;
	ray->firstvert_intersection_y = 0.0;
	ray->hit_down = 0;
	ray->hit_left = 0;
	ray->hit_right = 0;
	ray->hit_up = 0;
}
