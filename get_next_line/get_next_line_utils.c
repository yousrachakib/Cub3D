/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajjid <tajjid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:32:43 by tajjid            #+#    #+#             */
/*   Updated: 2023/10/11 14:05:16 by tajjid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr_gnl(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (char) c)
			return ((char *) &s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strdup_gnl(char *s1)
{
	size_t	i;
	size_t	lent;
	char	*str;

	i = 0;
	lent = ft_strlen(s1);
	str = malloc((lent + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (i < lent)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*ptr;
	int		i;
	int		j;

	if (!s1)
		s1 = ft_strdup_gnl("");
	i = 0;
	j = 0;
	ptr = malloc((ft_strlen(s1) + ft_strlen(s2)) + 1 * sizeof(char));
	if (!ptr)
		return (NULL);
	while (s1 && s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
		ptr[i++] = s2[j++];
	ptr[i] = '\0';
	if (ptr[0] == '\0')
		return (free(ptr), free(s1), NULL);
	return (free(s1), ptr);
}

char	*ft_substr_gnl(char *s, unsigned int start, size_t len)
{
	size_t		i;
	size_t		k;
	char		*ptr;

	if (!s)
		return (NULL);
	i = 0;
	k = 0;
	while (s[start + k] != '\0' && k < len)
		k++;
	ptr = malloc ((k + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (k)
	{
		ptr[i] = s[start + i];
		i++;
		k--;
	}
	ptr[i] = '\0';
	return (ptr);
}
