/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajjid <tajjid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 23:33:54 by tajjid            #+#    #+#             */
/*   Updated: 2023/12/12 22:36:58 by tajjid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_strtrim(char *s1, char *set)
{
	size_t	i;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	len = ft_strlen(s1);
	while (s1[i])
	{
		if (!ft_strchr(set, s1[i]))
			break ;
		i++;
	}
	while (len)
	{
		if (!ft_strchr(set, s1[len]))
			break ;
		len--;
	}
	if (i == len)
		return (ft_strdup(""));
	return (ft_substr(s1, i, len - i + 1));
}
