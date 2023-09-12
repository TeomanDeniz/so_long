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
# define TS_COIN ?
#typedef t_mlx;
#   void put_image(t_mlx, void *, int, int);
*/
#include "../../../libft/ft_math/ft_math.h" /*
# double ft_fabs(double);
*/
/* **************************** [^] INCLUDES [^] **************************** */

void
	draw_item(t_mlx mlx)
{
	static int		coins;
	static char		animation;
	register int	ecx;

	coins = 0 + coins;
	animation = animation + 0;
	if (!coins)
		coins = mlx->coins;
	ecx = -1;
	while (++ecx, ecx < coins)
	{
		if (mlx->object.coin[ecx].active)
			put_image(mlx, mlx->texture_pack.coin[animation], \
				mlx->object.coin[ecx].x, \
				mlx->object.coin[ecx].y);
	}
	if (mlx->fps % (long long)ft_fabs((20LL - \
		((mlx->object.number_of_monsters / 5LL) + \
		(mlx->object.number_of_barriers / 12LL)))) == 0)
		animation++;
	if (animation > (TS_COIN - 1))
		animation = 0;
}
