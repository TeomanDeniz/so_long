/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_item.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 12:29:43 by hdeniz            #+#    #+#             */
/*   Updated: 2023/09/04 12:29:44 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [V] INCLUDES [V] **************************** */
#include "../../so_long.h" /*
#typedef t_mlx;
*/
/* **************************** [^] INCLUDES [^] **************************** */

void
	draw_item(t_mlx mlx)
{
	static int		coins;
	register int	ecx;

	coins = 0 + coins;
	if (!coins)
		coins = mlx->coins;
	ecx = -1;
	while (++ecx, ecx < coins)
	{
		if (mlx->object.coin[ecx].active)
			put_image(mlx, mlx->texture_pack.coin[0], \
				mlx->object.coin[ecx].x, \
				mlx->object.coin[ecx].y);
	}
}
