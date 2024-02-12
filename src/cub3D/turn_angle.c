/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn_angle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyazici <muyazici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:36:45 by muyazici          #+#    #+#             */
/*   Updated: 2023/10/31 12:36:46 by muyazici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	turn_right(t_game *g)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = g->ray.direction.x;
	old_plane_x = g->ray.plane.x;
	g->ray.direction.x = old_dir_x * cos(TURN_SPEED) - g->ray.direction.y
		* sin(TURN_SPEED);
	g->ray.direction.y = old_dir_x * sin(TURN_SPEED) + g->ray.direction.y
		* cos(TURN_SPEED);
	g->ray.plane.x = old_plane_x * cos(TURN_SPEED) - g->ray.plane.y
		* sin(TURN_SPEED);
	g->ray.plane.y = old_plane_x * sin(TURN_SPEED) + g->ray.plane.y
		* cos(TURN_SPEED);
}

void	turn_left(t_game *g)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = g->ray.direction.x;
	old_plane_x = g->ray.plane.x;
	g->ray.direction.x = old_dir_x * cos(-TURN_SPEED) - g->ray.direction.y
		* sin(-TURN_SPEED);
	g->ray.direction.y = old_dir_x * sin(-TURN_SPEED) + g->ray.direction.y
		* cos(-TURN_SPEED);
	g->ray.plane.x = old_plane_x * cos(-TURN_SPEED) - g->ray.plane.y
		* sin(-TURN_SPEED);
	g->ray.plane.y = old_plane_x * sin(-TURN_SPEED) + g->ray.plane.y
		* cos(-TURN_SPEED);
}

void	turn_angle(t_game *g, int dir)
{
	if (dir == KEY_RIGHT)
		turn_right(g);
	if (dir == KEY_LEFT)
		turn_left(g);
}
