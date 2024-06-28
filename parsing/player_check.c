/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajjid <tajjid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:08:47 by tajjid            #+#    #+#             */
/*   Updated: 2023/12/14 11:56:15 by tajjid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_player_inmap(t_glob *glob, int i, int j)
{
	if (i == 0 || j == 0 || !glob->da_map->map[i + 1]
		|| !glob->da_map->map[i - 1]
		|| !glob->da_map->map[i][j + 1]
		|| !glob->da_map->map[i][j - 1]
		|| glob->da_map->map[i + 1][j] == ' '
		|| glob->da_map->map[i - 1][j] == ' '
		|| glob->da_map->map[i][j + 1] == ' '
		|| glob->da_map->map[i][j - 1] == ' ')
		error_stuff(12);
}

void	player_info_set(t_glob *glob, int i, int j)
{
	if (!glob->player->player_x)
		glob->player->player_x = j * TILE_SIZE + (TILE_SIZE / 2);
	if (!glob->player->player_y)
		glob->player->player_y = i * TILE_SIZE + (TILE_SIZE / 2);
	if (glob->da_map->map[i][j] == 'N')
		glob->player->player_angle = 270;
	if (glob->da_map->map[i][j] == 'W')
		glob->player->player_angle = 180;
	if (glob->da_map->map[i][j] == 'S')
		glob->player->player_angle = 90;
	if (glob->da_map->map[i][j] == 'E')
		glob->player->player_angle = 0;
}

void	player_checker(t_glob *glob)
{
	int	i;
	int	j;
	int	players_found;

	i = 0;
	players_found = 0;
	while (glob->da_map->map[i])
	{
		j = 0;
		while (glob->da_map->map[i][j])
		{
			if (ft_strchr("NEWS", glob->da_map->map[i][j]))
			{
				check_player_inmap(glob, i, j);
				players_found++;
				player_info_set(glob, i, j);
				glob->da_map->map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
	if (players_found > 1 || players_found == 0)
		error_stuff(2);
}
