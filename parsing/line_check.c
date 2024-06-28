/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajjid <tajjid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 21:02:58 by tajjid            #+#    #+#             */
/*   Updated: 2023/12/14 00:27:43 by tajjid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_line_3(char *line, t_glob *glob)
{
	if (!ft_strncmp(line, "F ", 2))
	{
		if (glob->da_map->floor)
			error_stuff(10);
		line = ft_strtrim(line + 2, " ");
		check_f_c(line, 1, glob);
		glob->da_map->floor = line;
	}
	else if (!ft_strncmp(line, "C ", 2))
	{
		if (glob->da_map->ceiling)
			error_stuff(10);
		line = ft_strtrim(line + 2, " ");
		check_f_c(line, 2, glob);
		glob->da_map->ceiling = line;
	}
	else
	{
		while (*line == ' ' || *line == '\t')
			line++;
		if (*line != '\0' && *line != '\n')
			error_stuff(11);
	}
}

void	check_line_2(char *line, t_glob *glob)
{
	if (!ft_strncmp(line, "WE ", 3))
	{
		if (glob->da_map->we)
			error_stuff(5);
		line = ft_strtrim(line + 3, " ");
		check_filename(line, 2);
		glob->da_map->we = line;
	}
	else if (!ft_strncmp(line, "EA ", 3))
	{
		if (glob->da_map->ea)
			error_stuff(5);
		line = ft_strtrim(line + 3, " ");
		check_filename(line, 2);
		glob->da_map->ea = line;
	}
	else
		check_line_3(line, glob);
}

void	check_line(char *line, t_glob *glob)
{
	while (*line && (*line == ' ' || *line == '\t'))
		line++;
	if (!ft_strncmp(line, "NO ", 3))
	{
		if (glob->da_map->no)
			error_stuff(5);
		line = ft_strtrim(line + 3, " ");
		check_filename(line, 2);
		glob->da_map->no = line;
	}
	else if (!ft_strncmp(line, "SO ", 3))
	{
		if (glob->da_map->so)
			error_stuff(5);
		line = ft_strtrim(line + 3, " ");
		check_filename(line, 2);
		glob->da_map->so = line;
	}
	else
		check_line_2(line, glob);
}
