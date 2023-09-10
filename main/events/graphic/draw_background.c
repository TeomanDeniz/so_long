/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 12:20:59 by hdeniz            #+#    #+#             */
/*   Updated: 2023/09/04 12:21:00 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [V] INCLUDES [V] **************************** */
#include "../../so_long.h" /*
# define TILE_WIDTH ?
# define TILE_HEIGHT ?
#typedef t_mlx;
*/
/* **************************** [^] INCLUDES [^] **************************** */

void
	draw_background(t_mlx mlx)
{
	register int	x;
	register int	y;

	y = -1;
	while (++y, mlx->map[y])
	{
		x = -1;
		while (++x, mlx->map[y][x])
			put_image(mlx, mlx->texture_pack.ground, \
				x * TILE_WIDTH, \
				y * TILE_HEIGHT);
	}
}
