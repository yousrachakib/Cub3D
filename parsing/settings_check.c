/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajjid <tajjid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 18:46:01 by tajjid            #+#    #+#             */
/*   Updated: 2023/12/13 20:08:01 by tajjid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	rgb_to_int(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	set_color(t_glob *glob, char **colors, int flag)
{
	int	i;
	int	r;
	int	g;
	int	b;

	i = 0;
	r = ft_atoi(colors[0]);
	g = ft_atoi(colors[1]);
	b = ft_atoi(colors[2]);
	if (flag == 1)
		glob->da_map->floor_color = rgb_to_int(r, g, b);
	else if (flag == 2)
		glob->da_map->ceiling_color = rgb_to_int(r, g, b);
	while (colors[i])
	{
		free(colors[i]);
		i++;
	}
	free(colors);
}

void	check_filename(char *str, int option)
{
	int		len;
	char	*checkable;

	if (option == 1)
		checkable = ".cub";
	else
		checkable = ".xpm";
	len = ft_strlen(str);
	if (len < 5)
		error_stuff(2);
	if (ft_strncmp(&str[len - 4], checkable, 4) != 0)
	{
		if (option == 1)
			error_stuff(8);
		else
			error_stuff(4);
	}
}

void	check_f_c_numbers(char *str, int flag, t_glob *glob)
{
	int		i;
	char	**colors;

	(void)flag;
	i = 0;
	colors = ft_split(str, ',');
	while (colors[i])
	{
		if (ft_atoi(colors[i]) > 255 || ft_atoi(colors[i]) < 0)
			error_stuff(6);
		i++;
	}
	if (i != 3)
		error_stuff(6);
	set_color(glob, colors, flag);
}

void	check_f_c(char *str, int flag, t_glob *glob)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (str[i] == ' ')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ',')
		{
			error_stuff(6);
		}
		if (str[i] == ',')
			k++;
		i++;
	}
	if (k != 2)
		error_stuff(6);
	check_f_c_numbers(str, flag, glob);
}
