/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajjid <tajjid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 23:57:52 by tajjid            #+#    #+#             */
/*   Updated: 2023/12/14 10:32:31 by tajjid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	allocator(t_glob *glob)
{
	glob->da_map = malloc(sizeof(t_map_data));
	glob->player = malloc(sizeof(t_player_data));
	glob->da_mlx = malloc(sizeof(t_mlx));
	glob->da_img = malloc(sizeof(t_img_data));
	glob->h_values = malloc(sizeof(t_horizontal));
	glob->v_values = malloc(sizeof(t_vertical));
	glob->minimap = malloc(sizeof(t_minimap));
	if (!glob->da_map || !glob->player || !glob->da_mlx || !glob->da_img
		|| !glob->h_values || !glob->v_values || !glob->minimap)
		error_stuff(3);
	initializer(glob);
}

void	initializer_2(t_glob *glovo)
{
	glovo->h_values->distance_h = 0.0;
	glovo->h_values->next_htouch_x = 0.0;
	glovo->h_values->next_htouch_y = 0.0;
	glovo->h_values->hit_x = 0.0;
	glovo->h_values->hit_y = 0.0;
	glovo->h_values->x_step = 0.0;
	glovo->h_values->y_step = 0.0;
	glovo->v_values->distance_v = 0.0;
	glovo->v_values->hit_x = 0.0;
	glovo->v_values->hit_y = 0.0;
	glovo->v_values->next_vtouch_x = 0.0;
	glovo->v_values->next_vtouch_y = 0.0;
	glovo->v_values->x_step = 0.0;
	glovo->v_values->y_step = 0.0;
}

void	initializer(t_glob *glovo)
{
	glovo->da_img->img = NULL;
	glovo->da_img->addr = NULL;
	glovo->da_img->bits_per_pixel = 0;
	glovo->da_img->line_length = 0;
	glovo->da_img->endian = 0;
	glovo->da_map->no = NULL;
	glovo->da_map->we = NULL;
	glovo->da_map->ea = NULL;
	glovo->da_map->so = NULL;
	glovo->da_map->ceiling = NULL;
	glovo->da_map->floor = NULL;
	glovo->da_map->map = NULL;
	glovo->da_map->basic_map = NULL;
	glovo->player->player_x = 0;
	glovo->player->player_y = 0;
	glovo->player->player_angle = 0;
	glovo->player->turn_direction = 0;
	glovo->player->walk_direction = 0;
	glovo->player->walk_direction_side = 0;
	initializer_2(glovo);
}

void	free_stuff_2(t_glob *glob)
{
	int	i;

	i = 0;
	free(glob->da_map->no);
	free(glob->da_map->we);
	free(glob->da_map->ea);
	free(glob->da_map->so);
	free(glob->da_map->ceiling);
	free(glob->da_map->floor);
	while (glob->da_map->map && glob->da_map->map[i])
	{
		free(glob->da_map->map[i]);
		i++;
	}
	free(glob->da_map->map);
	free(glob->da_map->basic_map);
	free(glob->da_map);
	free(glob->no_texture);
	free(glob->so_texture);
	free(glob->we_texture);
	free(glob->ea_texture);
}

void	free_stuff(t_glob *glob)
{
	if (!glob)
		return ;
	free(glob->player);
	free(glob->h_values);
	free(glob->v_values);
	free(glob->minimap);
	free(glob->da_img->addr);
	free(glob->da_img);
	free(glob->da_mlx);
	free(glob->da_mlx->win);
	free(glob->da_mlx->mlx);
	free_stuff_2(glob);
	free(glob);
}
