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
# define TS_GATE ?
#typedef t_mlx;
#   void put_image(t_mlx, void *, int, int);
*/
#include "../../../libft/ft_math/ft_math.h" /*
# double ft_fabs(double);
*/
/* **************************** [^] INCLUDES [^] **************************** */

void
	draw_gate(t_mlx mlx)
{
	static char		animation;

	if (!mlx->object.gate.active)
	{
		put_image(mlx, mlx->texture_pack.gate[0], \
			mlx->object.gate.x, \
			mlx->object.gate.y);
	}
	else
	{
		if ((mlx->fps % (long long)ft_fabs((20 - \
			((mlx->object.number_of_monsters / 5) + \
			(mlx->object.number_of_barriers / 12)))) == 0) && \
			animation < (TS_GATE - 1))
			animation++;
		put_image(mlx, mlx->texture_pack.gate[animation], \
				mlx->object.gate.x, \
				mlx->object.gate.y);
	}
}
