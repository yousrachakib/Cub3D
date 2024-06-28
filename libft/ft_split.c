/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 23:50:33 by tajjid            #+#    #+#             */
/*   Updated: 2023/11/20 20:10:57 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	ft_wrdcnt(char *s, char c)
{
	int	i;
	int	wrd;
	int	slen;

	i = 0;
	wrd = 0;
	slen = ft_strlen(s);
	while (i < slen)
	{
		if (s[i] != c)
		{
			wrd++;
			while (i < slen && s[i] != c)
				i++;
		}
		i++;
	}
	return (wrd);
}

static char	*ft_wrdcrt(char *s, int start, int end)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)malloc(((end - start) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (start < end)
	{
		str[i] = s[start];
		start++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	*ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

static	char	**ft_wrdcrtt(char *s, char **ptr, char c)
{
	int		j;
	int		start;
	size_t	end;

	j = 0;
	start = -1;
	end = 0;
	while (end <= ft_strlen(s))
	{
		if (s[end] != c && start < 0)
			start = end;
		else if ((s[end] == c || end == ft_strlen(s)) && start >= 0)
		{
			ptr[j] = ft_wrdcrt(s, start, end);
			if (!ptr[j++])
				return (ft_free(ptr));
			start = -1;
		}
		end++;
	}
	return (ptr);
}

char	**ft_split(char *s, char c)
{
	int		j;
	int		start;
	size_t	end;
	char	**ptr;

	j = 0;
	start = -1;
	end = -1;
	if (!s)
		return (NULL);
	ptr = ft_calloc((ft_wrdcnt(s, c) + 1), sizeof(char *));
	if (!ptr)
		return (NULL);
	return (ft_wrdcrtt(s, ptr, c));
}
