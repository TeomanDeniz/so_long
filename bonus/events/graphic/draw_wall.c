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
# define TS_WALL_ANI ?
#typedef t_mlx;
#   void put_image(t_mlx, void *, int, int);
*/
#include "../../../libft/ft_math/ft_math.h" /*
# double ft_fabs(double);
*/
/* **************************** [^] INCLUDES [^] **************************** */

void
	draw_wall(t_mlx mlx)
{
	register int	ecx;
	register int	wall_type;
	static char		animation;

	ecx = -1;
	animation = animation + 0;
	while (++ecx, ecx < mlx->object.number_of_walls)
	{
		wall_type = mlx->object.wall[ecx].texture_type;
		put_image(mlx, mlx->texture_pack.wall[wall_type][(int)animation], \
			mlx->object.wall[ecx].x * TILE_WIDTH, \
			mlx->object.wall[ecx].y * TILE_HEIGHT);
	}
	if ((mlx->fps % (long long)ft_fabs((20LL - \
		((mlx->object.number_of_monsters / 5LL) + \
		(mlx->object.number_of_barriers / 12LL))))) == 0)
		animation++;
	if (animation > (TS_WALL_ANI - 1))
		animation = 0;
}
