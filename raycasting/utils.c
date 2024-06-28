/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 19:06:31 by yochakib          #+#    #+#             */
/*   Updated: 2023/12/10 21:26:21 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	normalize_ray_angle(double ray_angle)
{
	double	angle;

	angle = fmod(ray_angle, (2 * M_PI));
	if (angle < 0)
		angle += (2 * M_PI);
	return (angle);
}

void	hit_down_or_up(t_ray *ray)
{
	ray->hit_down = ray->ray_angle > 0 && ray->ray_angle < M_PI;
	ray->hit_up = !ray->hit_down;
}

void	hit_right_or_left(t_ray *ray)
{
	ray->hit_right = ray->ray_angle < (0.5 * M_PI) || \
	ray->ray_angle > (1.5 * M_PI);
	ray->hit_left = !ray->hit_right;
}

double	degreestoradians(double value)
{
	return (value * (M_PI / 180.0));
}

double	distance_between_point(double x1, double x2, double y1, double y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}
