/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 12:29:36 by hdeniz            #+#    #+#             */
/*   Updated: 2023/09/04 12:29:37 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [V] INCLUDES [V] **************************** */
#include "../../so_long.h" /*
# define TILE_WIDTH ?
# define TILE_HEIGHT ?
#   void put_image(t_mlx, void *, int, int);
#typedef t_mlx;
*/
/* **************************** [^] INCLUDES [^] **************************** */

void
	draw_wall(t_mlx mlx)
{
	register int	ecx;
	register int	wall_type;

	ecx = -1;
	while (++ecx, ecx < mlx->object.number_of_walls)
	{
		wall_type = mlx->object.wall[ecx].texture_type;
		put_image(mlx, mlx->texture_pack.wall[wall_type][0], \
			mlx->object.wall[ecx].x * TILE_WIDTH, \
			mlx->object.wall[ecx].y * TILE_HEIGHT);
	}
}
