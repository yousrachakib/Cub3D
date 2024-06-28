/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajjid <tajjid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:59:21 by tajjid            #+#    #+#             */
/*   Updated: 2023/12/14 11:56:12 by tajjid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	error_stuff(int error)
{
	if (error == 1)
		printf("Error:\nInvalid number of arguments\n");
	else if (error == 2)
		printf("Error:\nInvalid map\n");
	else if (error == 3)
		printf("Error:\nMalloc failed\n");
	else if (error == 4)
		printf("Error:\nInvalid texture\n");
	else if (error == 5)
		printf("Error:\nDuplicated texture\n");
	else if (error == 6)
		printf("Error:\nInvalid Floor or Ceiling color\n");
	else if (error == 7)
		printf("Error:\nMlx failed\n");
	else if (error == 8)
		printf("Error:\nThe map file should end with \".cub\"\n");
	else if (error == 9)
		printf("Error:\nInvalid map file\n");
	else if (error == 10)
		printf("Error:\nDuplicated Floor or Ceiling color\n");
	else if (error == 11)
		printf("Error:\nInvalid settings\n");
	else if (error == 12)
		printf("Error:\nPlayer out of map\n");
	exit(1);
}

int	destroy(void)
{
	exit(0);
}
