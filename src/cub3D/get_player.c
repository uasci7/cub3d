/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyazici <muyazici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:35:35 by muyazici          #+#    #+#             */
/*   Updated: 2023/10/31 12:35:37 by muyazici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	get_player_pos(t_game *g)
{
	int	i;
	int	j;

	i = -1;
	while (g->rndr.map.map[++i])
	{
		j = -1;
		while (g->rndr.map.map[i][++j])
		{
			if (g->rndr.map.map[i][j] == 'N' || g->rndr.map.map[i][j] == 'S' \
				|| g->rndr.map.map[i][j] == 'E' || g->rndr.map.map[i][j] == 'W')
			{
				g->rndr.map.player_x = j;
				g->rndr.map.player_y = i;
				g->rndr.map.pov_char = g->rndr.map.map[i][j];
				init_direction(g, g->rndr.map.map[i][j]);
				g->rndr.map.map[i][j] = '0';
				return ;
			}
		}
	}
	exit_error(g, "Missing Character!\n");
}
