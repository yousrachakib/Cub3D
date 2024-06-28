/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajjid <tajjid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:04:49 by tajjid            #+#    #+#             */
/*   Updated: 2023/12/09 18:41:23 by tajjid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	c_f_drawings(t_glob *glob, int i, int j, double top_wall)
{
	if (j < top_wall)
		my_mlx_pixel_put(glob->da_img, i, j, glob->da_map->ceiling_color);
	else
		my_mlx_pixel_put(glob->da_img, i, j, glob->da_map->floor_color);
}

void	ofsset_x_calculator(t_glob *glob, int i, t_texture *texture)
{
	if (glob->rays[i]->hit_vertical == 1)
		texture->offset_x = fmod(glob->rays[i]->hit_y, TILE_SIZE) * \
			(texture->width / TILE_SIZE);
	else if (glob->rays[i]->hit_vertical == 2)
		texture->offset_x = fmod(glob->rays[i]->hit_x, TILE_SIZE) * \
			(texture->width / TILE_SIZE);
}

void	wall_drawer(t_glob *glob, int i, \
					double wall_strip_height, t_texture *texture)
{
	int		j;
	double	top_wall;
	double	bottom_wall;

	j = 0;
	top_wall = (HEIGHT / 2) - (wall_strip_height / 2);
	bottom_wall = (HEIGHT / 2) + (wall_strip_height / 2);
	if (top_wall < 0)
		top_wall = 0;
	if (bottom_wall > HEIGHT)
		bottom_wall = HEIGHT;
	ofsset_x_calculator(glob, i, texture);
	while (j < HEIGHT)
	{
		if (j < top_wall || j >= bottom_wall)
			c_f_drawings(glob, i, j, top_wall);
		else if (j >= top_wall && j < bottom_wall)
		{
			texture->offset_y = (j - ((HEIGHT / 2) - (wall_strip_height / 2))) \
				* ((double)texture->height / wall_strip_height);
			my_mlx_pixel_put(glob->da_img, i, j, \
				get_pixel_color(texture, texture->offset_x, texture->offset_y));
		}
		j++;
	}
}

void	wall_drawer_checker(t_glob *glob, int i, double distance_proj_plane)
{
	double	wall_strip_height;
	double	modified_distance;

	modified_distance = glob->rays[i]->distance * \
			cos(glob->rays[i]->ray_angle - \
			degreestoradians(glob->player->player_angle));
	wall_strip_height = (TILE_SIZE / modified_distance) * \
			distance_proj_plane;
	if (glob->rays[i]->hit_vertical == 2 && glob->rays[i]->hit_up == 1)
		wall_drawer(glob, i, wall_strip_height, glob->no_texture);
	else if (glob->rays[i]->hit_vertical == 2 && \
			glob->rays[i]->hit_down == 1)
		wall_drawer(glob, i, wall_strip_height, glob->so_texture);
	else if (glob->rays[i]->hit_vertical == 1 && \
			glob->rays[i]->hit_left == 1)
		wall_drawer(glob, i, wall_strip_height, glob->we_texture);
	else if (glob->rays[i]->hit_vertical == 1 && \
			glob->rays[i]->hit_right == 1)
		wall_drawer(glob, i, wall_strip_height, glob->ea_texture);
}

void	wall_rendrer(t_glob *glob)
{
	int		i;
	double	distance_proj_plane;

	i = 0;
	distance_proj_plane = (WIDTH / 2) / tan(FOV_ANGLE / 2);
	while (i < NUM_RAYS)
	{
		wall_drawer_checker(glob, i, distance_proj_plane);
		i++;
	}
	i = 0;
	while (glob->rays[i])
	{
		free(glob->rays[i]);
		i++;
	}
	free(glob->rays);
}
