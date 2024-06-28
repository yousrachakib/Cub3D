/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajjid <tajjid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 21:22:22 by tajjid            #+#    #+#             */
/*   Updated: 2023/10/11 15:56:20 by tajjid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_read(char *save, int fd)
{
	char	*buffer;
	int		red;

	red = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr_gnl(save, '\n') && red != 0)
	{
		red = read(fd, buffer, BUFFER_SIZE);
		if (red == -1)
			return (free(buffer), free(save), NULL);
		buffer[red] = '\0';
		save = ft_strjoin_gnl(save, buffer);
	}
	return (free(buffer), save);
}

char	*get_next_line(int fd)
{
	int			i;
	static char	*save;
	char		*line;
	char		*temp;

	if (fd < 0 || fd > 10240 || BUFFER_SIZE <= 0)
		return (NULL);
	save = ft_read(save, fd);
	if (!save)
		return (NULL);
	i = 0;
	while (save[i] != '\n' && save[i])
		i++;
	if (save[i] == '\n')
		i++;
	line = ft_substr_gnl(save, 0, i);
	if (line[i - 1] == '\n')
		line[i - 1] = '\0';
	temp = ft_substr_gnl(save, i, ft_strlen(save));
	free(save);
	save = temp;
	return (line);
}
