/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajjid <tajjid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:26:25 by tajjid            #+#    #+#             */
/*   Updated: 2023/12/15 16:36:36 by tajjid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	my_mlx_pixel_put(t_img_data *data, int x, int y, long int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

void	player_drawer(t_glob *glob)
{
	my_mlx_pixel_put(glob->da_img, glob->minimap->size / 2, \
			glob->minimap->size / 2, YELLOW);
	my_mlx_pixel_put(glob->da_img, glob->minimap->size / 2 + 1, \
			glob->minimap->size / 2, YELLOW);
	my_mlx_pixel_put(glob->da_img, glob->minimap->size / 2 + 2, \
			glob->minimap->size / 2, YELLOW);
	my_mlx_pixel_put(glob->da_img, glob->minimap->size / 2 - 1, \
			glob->minimap->size / 2, YELLOW);
	my_mlx_pixel_put(glob->da_img, glob->minimap->size / 2 - 2, \
			glob->minimap->size / 2, YELLOW);
	my_mlx_pixel_put(glob->da_img, glob->minimap->size / 2, \
			glob->minimap->size / 2 + 1, YELLOW);
	my_mlx_pixel_put(glob->da_img, glob->minimap->size / 2, \
			glob->minimap->size / 2 - 1, YELLOW);
	my_mlx_pixel_put(glob->da_img, glob->minimap->size / 2, \
			glob->minimap->size / 2 + 2, YELLOW);
	my_mlx_pixel_put(glob->da_img, glob->minimap->size / 2, \
			glob->minimap->size / 2 - 2, YELLOW);
}

void	squares_drawer(t_glob *glob, int x_d, int y_d)
{
	if (is_it_a_wall(glob, glob->minimap->map_x, glob->minimap->map_y) == 0)
		my_mlx_pixel_put(glob->da_img, x_d, y_d, WHITE);
	else if (is_it_a_wall(glob, glob->minimap->map_x, \
			glob->minimap->map_y) == 1)
		my_mlx_pixel_put(glob->da_img, x_d, y_d, BLACK);
	else if (is_it_a_wall(glob, glob->minimap->map_x, \
			glob->minimap->map_y) == 2)
		my_mlx_pixel_put(glob->da_img, x_d, y_d, GREY);
}

void	minimap_drawer(t_glob *glob)
{
	int	x_d;
	int	y_d;

	x_d = 0;
	y_d = 0;
	glob->minimap->size = 200;
	glob->minimap->map_x = glob->player->player_x - (glob->minimap->size / 2);
	glob->minimap->map_y = glob->player->player_y - (glob->minimap->size / 2);
	glob->minimap->map_end_x = glob->minimap->map_x + glob->minimap->size;
	glob->minimap->map_end_y = glob->minimap->map_y + glob->minimap->size;
	while (glob->minimap->map_y < glob->minimap->map_end_y)
	{
		glob->minimap->map_x = glob->player->player_x \
			- (glob->minimap->size / 2);
		x_d = 0;
		while (glob->minimap->map_x < glob->minimap->map_end_x)
		{
			squares_drawer(glob, x_d, y_d);
			glob->minimap->map_x++;
			x_d++;
		}
		glob->minimap->map_y++;
		y_d++;
	}
	player_drawer(glob);
}
