/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajjid <tajjid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:11:04 by tajjid            #+#    #+#             */
/*   Updated: 2023/12/14 15:00:35 by tajjid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	textures_img(t_glob *glob)
{
	glob->no_texture->image.img = mlx_xpm_file_to_image(glob->da_mlx->mlx, \
		glob->da_map->no, &glob->no_texture->width, &glob->no_texture->height);
	glob->we_texture->image.img = mlx_xpm_file_to_image(glob->da_mlx->mlx, \
		glob->da_map->we, &glob->we_texture->width, &glob->we_texture->height);
	glob->so_texture->image.img = mlx_xpm_file_to_image(glob->da_mlx->mlx, \
		glob->da_map->so, &glob->so_texture->width, &glob->so_texture->height);
	glob->ea_texture->image.img = mlx_xpm_file_to_image(glob->da_mlx->mlx, \
		glob->da_map->ea, &glob->ea_texture->width, &glob->ea_texture->height);
	if (!glob->no_texture->image.img || !glob->so_texture->image.img || \
		!glob->we_texture->image.img || !glob->ea_texture->image.img)
		error_stuff(7);
}

void	textures_addr(t_glob *glob)
{
	glob->no_texture->image.addr = mlx_get_data_addr(\
		glob->no_texture->image.img, \
		&glob->no_texture->image.bits_per_pixel, \
		&glob->no_texture->image.line_length, \
		&glob->no_texture->image.endian);
	glob->so_texture->image.addr = mlx_get_data_addr(\
		glob->so_texture->image.img, \
		&glob->so_texture->image.bits_per_pixel, \
		&glob->so_texture->image.line_length, \
		&glob->so_texture->image.endian);
	glob->we_texture->image.addr = mlx_get_data_addr(\
			glob->we_texture->image.img, \
		&glob->we_texture->image.bits_per_pixel, \
		&glob->we_texture->image.line_length, \
		&glob->we_texture->image.endian);
	glob->ea_texture->image.addr = mlx_get_data_addr(\
		glob->ea_texture->image.img, \
		&glob->ea_texture->image.bits_per_pixel, \
		&glob->ea_texture->image.line_length, \
		&glob->ea_texture->image.endian);
	if (!glob->no_texture->image.addr || !glob->so_texture->image.addr || \
		!glob->we_texture->image.addr || !glob->ea_texture->image.addr)
		error_stuff(7);
}

int	get_pixel_color(t_texture *texture, int x, int y)
{
	char			*dst;
	unsigned int	color;

	dst = texture->image.addr + (y * texture->image.line_length + x * 4);
	color = *(unsigned int *)dst;
	return (color);
}

void	textures_checker(t_glob *glob)
{
	glob->no_texture = malloc(sizeof(t_texture));
	glob->so_texture = malloc(sizeof(t_texture));
	glob->we_texture = malloc(sizeof(t_texture));
	glob->ea_texture = malloc(sizeof(t_texture));
	if (!glob->no_texture || !glob->so_texture || \
		!glob->we_texture || !glob->ea_texture)
		error_stuff(3);
	textures_img(glob);
	textures_addr(glob);
}
