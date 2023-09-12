/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 12:30:01 by hdeniz            #+#    #+#             */
/*   Updated: 2023/09/04 12:30:02 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [V] INCLUDES [V] **************************** */
#include "../../so_long.h" /*
#typedef t_mlx;
#   void put_image(t_mlx, void *, int, int);
*/
/* **************************** [^] INCLUDES [^] **************************** */

void
	draw_player(t_mlx mlx)
{
	put_image(mlx, mlx->texture_pack.player[\
		(int)mlx->object.player.rotation][0], \
		mlx->object.player.x, \
		mlx->object.player.y);
}
