/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajjid <tajjid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:14:11 by tajjid            #+#    #+#             */
/*   Updated: 2023/12/16 11:59:49 by tajjid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	map_border_checker(t_glob *glob, int i, int j)
{
	if ((i - 1) < 0 || (i + 1) >= glob->da_map->map_height
		|| (j - 1) < 0 || (j + 1) >= glob->da_map->map_width)
	{
		error_stuff(2);
	}
	if (glob->da_map->map[i - 1][j] == ' '
		|| glob->da_map->map[i + 1][j] == ' '
		|| glob->da_map->map[i][j - 1] == ' '
		|| glob->da_map->map[i][j + 1] == ' ')
	{
		error_stuff(2);
	}
}

void	map_checker(t_glob *glob)
{
	int	i;
	int	j;

	i = 0;
	if (!glob->da_map->map)
		error_stuff(2);
	while (glob->da_map->map[i])
	{
		j = 0;
		while (glob->da_map->map[i][j])
		{
			if (glob->da_map->map[i][j] == '0')
				map_border_checker(glob, i, j);
			j++;
		}
		i++;
	}
}

void	map_opener(char *map, t_glob *glob)
{
	int		fd;
	int		i;
	char	*reader;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		error_stuff(9);
	reader = get_next_line(fd);
	while (reader)
	{
		i = 0;
		while (reader[i] == ' ')
			i++;
		if (reader[i] == '1' || reader[i] == '0')
			return (map_filler(fd, reader, glob));
		check_line(reader, glob);
		free(reader);
		reader = get_next_line(fd);
	}
	free(reader);
	close(fd);
	error_stuff(2);
}
