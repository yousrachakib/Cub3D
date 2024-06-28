/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajjid <tajjid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 00:35:38 by tajjid            #+#    #+#             */
/*   Updated: 2023/12/10 22:05:56 by tajjid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_strdup(char *s1)
{
	size_t	i;
	size_t	ls1;
	char	*ss1;

	if (!s1)
		return (NULL);
	ls1 = ft_strlen (s1);
	i = 0;
	ss1 = malloc(sizeof(char) * ls1 + 1);
	if (!ss1)
		return (NULL);
	while (s1[i])
	{
		ss1[i] = s1[i];
		i++;
	}
	ss1[i] = '\0';
	return (ss1);
}
