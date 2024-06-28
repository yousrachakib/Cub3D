/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:19:05 by tajjid            #+#    #+#             */
/*   Updated: 2023/12/15 16:19:22 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	drawing_stuff(t_glob *glob)
{
	glob->da_mlx->mlx = mlx_init();
	if (!glob->da_mlx->mlx)
		error_stuff(7);
	glob->da_mlx->win = mlx_new_window(glob->da_mlx->mlx, \
		WIDTH, HEIGHT, "Cub3d");
	if (!glob->da_mlx->win)
		error_stuff(7);
	glob->da_img->img = mlx_new_image(glob->da_mlx->mlx, WIDTH, HEIGHT);
	if (!glob->da_img->img)
		error_stuff(7);
	glob->da_img->addr = mlx_get_data_addr(glob->da_img->img,
			&glob->da_img->bits_per_pixel, &glob->da_img->line_length,
			&glob->da_img->endian);
	if (!glob->da_img->addr)
		error_stuff(7);
	textures_checker(glob);
	mlx_hook(glob->da_mlx->win, 2, 0, key_press, glob);
	mlx_hook(glob->da_mlx->win, 3, 0, key_release, glob);
	mlx_hook(glob->da_mlx->win, 6, 0, mouse_motion, glob);
	mlx_hook(glob->da_mlx->win, 17, 0, destroy, &glob->da_mlx);
	mlx_loop_hook(glob->da_mlx->mlx, game_generator, glob);
	mlx_loop(glob->da_mlx->mlx);
}

int	game_generator(t_glob *glob)
{
	mlx_clear_window(glob->da_mlx->mlx, glob->da_mlx->win);
	if (glob->player->walk_direction)
		player_movement_strait(glob);
	if (glob->player->walk_direction_side)
		player_movement_side(glob);
	if (glob->player->turn_direction)
		player_rotation(glob);
	ray_casting(glob);
	wall_rendrer(glob);
	minimap_drawer(glob);
	mlx_put_image_to_window(glob->da_mlx->mlx, glob->da_mlx->win, \
	glob->da_img->img, 0, 0);
	return (0);
}

void	ll(void)
{
	system("leaks cub3d");
}

void	parsing_stuff(char *map, t_glob *glob)
{
	map_opener(map, glob);
	map_checker(glob);
	player_checker(glob);
}

int	main(int argc, char **argv)
{
	t_glob	*glob;

	atexit(ll);
	if (argc != 2)
		error_stuff(1);
	check_filename(argv[1], 1);
	glob = malloc(sizeof(t_glob));
	if (!glob)
		error_stuff(3);
	allocator(glob);
	parsing_stuff(argv[1], glob);
	drawing_stuff(glob);
	free_stuff(glob);
}
