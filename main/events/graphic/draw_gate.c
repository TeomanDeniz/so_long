/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_gate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 12:29:51 by hdeniz            #+#    #+#             */
/*   Updated: 2023/09/04 12:29:52 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [V] INCLUDES [V] **************************** */
#include "../../so_long.h" /*
#typedef t_mlx;
*/
/* **************************** [^] INCLUDES [^] **************************** */

void
	draw_gate(t_mlx mlx)
{
	if (!mlx->object.gate.active)
	{
		put_image(mlx, mlx->texture_pack.gate[0], \
			mlx->object.gate.x, \
			mlx->object.gate.y);
	}
	else
	{
		put_image(mlx, mlx->texture_pack.gate[4], \
				mlx->object.gate.x, \
				mlx->object.gate.y);
	}
}
