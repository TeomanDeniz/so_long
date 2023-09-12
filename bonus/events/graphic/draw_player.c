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
# define TS_PLAYER_ANI ?
#typedef t_mlx;
#   void put_image(t_mlx, void *, int, int);
*/
#include "../../../libft/ft_math/ft_math.h" /*
# double ft_fabs(double);
*/
/* **************************** [^] INCLUDES [^] **************************** */

void
	draw_player(t_mlx mlx)
{
	static char		animation;
	long long		player_speed;

	animation = animation + 0;
	player_speed = (long long)(1 + (mlx->object.player.movement_speed) * 100.0);
	if (player_speed <= 1)
		animation = 0;
	put_image(mlx, \
		mlx->texture_pack.player[\
		(int)mlx->object.player.rotation][(int)animation], \
		mlx->object.player.x, \
		mlx->object.player.y);
	if (mlx->fps % (long long)ft_fabs((50LL - \
		((mlx->object.number_of_monsters / 4LL) + \
		(mlx->object.number_of_barriers / 12LL))) - player_speed) == 0)
		animation++;
	if (animation > (TS_PLAYER_ANI - 1))
		animation = 0;
}
