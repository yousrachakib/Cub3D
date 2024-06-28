/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_constracting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajjid <tajjid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:10:00 by tajjid            #+#    #+#             */
/*   Updated: 2023/12/16 14:36:25 by tajjid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*map_resizer(char *map, size_t line_lenght)
{
	int		i;
	size_t	j;
	char	*new_line;

	i = 0;
	j = 0;
	new_line = malloc(line_lenght + 1);
	if (!new_line)
		error_stuff(3);
	while (map[i] && ft_strchr(" 012NSEW", map[i]))
	{
		new_line[j] = map[i];
		i++;
		j++;
	}
	while (j < line_lenght)
	{
		new_line[j] = ' ';
		j++;
	}
	new_line[j] = '\0';
	free(map);
	return (new_line);
}

void	map_joiner(t_glob *glob, char *reader)
{
	int	i;

	i = 0;
	while (reader[i])
	{
		if (reader[i] && !ft_strchr(" 012NSEW", reader[i]))
			error_stuff(2);
		i++;
	}
	if (!glob->da_map->basic_map)
		glob->da_map->basic_map = ft_strdup("");
	glob->da_map->basic_map = ft_strjoin(glob->da_map->basic_map, reader, 1);
	glob->da_map->basic_map = ft_strjoin(glob->da_map->basic_map, "\n", 1);
	free(reader);
}

void	map_filler(int fd, char *reader, t_glob *glob)
{
	int		i;
	size_t	line_lenght;

	if (!reader || !glob->da_map->no || !glob->da_map->so || !glob->da_map->we
		|| !glob->da_map->ea || !glob->da_map->floor || !glob->da_map->ceiling)
		error_stuff(2);
	line_lenght = 0;
	i = -1;
	while (reader)
	{
		if (reader[0] == '\0')
			error_stuff(2);
		if (ft_strlen(reader) > line_lenght)
			line_lenght = ft_strlen(reader);
		map_joiner(glob, reader);
		reader = get_next_line(fd);
	}
	free(reader);
	close(fd);
	glob->da_map->map_width = line_lenght;
	glob->da_map->map = ft_split(glob->da_map->basic_map, '\n');
	while (glob->da_map->map[++i])
		glob->da_map->map[i] = \
			map_resizer(glob->da_map->map[i], line_lenght);
	glob->da_map->map_height = i;
}
