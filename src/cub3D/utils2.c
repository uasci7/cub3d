/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyazici <muyazici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:36:57 by muyazici          #+#    #+#             */
/*   Updated: 2023/10/31 12:36:58 by muyazici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

float	to_radian(float angle)
{
	return (angle * M_PI / 180);
}

int	sign(float x)
{
	if (x > 0)
		return (1);
	else if (x < 0)
		return (-1);
	return (0);
}

void	line_draw(t_ray *r)
{
	while (r->line.start_x != r->line.end_x || r->line.start_y != r->line.end_y)
	{
		img_pix_put(&r->render.img, r->line.start_x, r->line.start_y, 0x0000ff);
		r->line.start_x += r->line.delta.x;
		r->line.start_y += r->line.delta.y;
	}
}

void	setup_ray(t_ray *r, int i)
{
	r->camera_x = 2 * i / r->res.x - 1;
	r->ray_dir.x = r->direction.x - r->plane.x * r->camera_x;
	r->ray_dir.y = r->direction.y - r->plane.y * r->camera_x;
	r->in_map.x = (int)(r->pos.x);
	r->in_map.y = (int)(r->pos.y);
	r->delta_dist.x = fabs(1 / r->ray_dir.x);
	r->delta_dist.y = fabs(1 / r->ray_dir.y);
	r->hit = 0;
}
