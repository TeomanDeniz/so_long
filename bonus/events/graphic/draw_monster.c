/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_monster.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 12:30:01 by hdeniz            #+#    #+#             */
/*   Updated: 2023/09/04 12:30:02 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [V] INCLUDES [V] **************************** */
#include "../../so_long.h" /*
# define TS_MONSTER_ANI ?
# define TILE_WIDTH ?
# define TILE_HEIGHT ?
#typedef t_mlx;
#   void put_image(t_mlx, void *, int, int);
*/
#include "../../../libft/ft_math/ft_math.h" /*
# double ft_fabs(double);
# double ft_fmax(double, double);

*/
/* **************************** [^] INCLUDES [^] **************************** */

static inline void	npc_moving(t_mlx mlx, int ecx);

void
	draw_monster(t_mlx mlx)
{
	register int	ecx;
	long long		npc_speed;

	ecx = -1;
	while (++ecx, ecx < mlx->object.number_of_monsters)
	{
		npc_moving(mlx, ecx);
		npc_speed = (long long)(1 + (mlx->object.monster[ecx].movement_speed) \
			* 100.0);
		if (npc_speed <= 1)
			mlx->object.monster[ecx].animation = 0;
		put_image(mlx, \
			mlx->texture_pack.monster[(int)mlx->object.monster[ecx].rotation][\
			(int)mlx->object.monster[ecx].animation], \
			mlx->object.monster[ecx].x, \
			mlx->object.monster[ecx].y);
		if (mlx->fps % (long long)ft_fabs((50LL - \
			((mlx->object.number_of_monsters / 4LL) + \
			(mlx->object.number_of_barriers / 12LL))) - npc_speed) == 0)
			mlx->object.monster[ecx].animation++;
		if (mlx->object.monster[ecx].animation > (TS_MONSTER_ANI - 1))
			mlx->object.monster[ecx].animation = 0;
	}
}

static inline void
	npc_moving(t_mlx mlx, int ecx)
{
	static double	old_x[0XFFFF];
	static double	old_y[0XFFFF];
	double			delta_x;
	double			delta_y;

	old_x[ecx] = 0.0 + old_x[ecx];
	old_y[ecx] = 0.0 + old_y[ecx];
	if (old_x[ecx] == 0.0 || old_x[ecx] == 0.0)
	{
		old_x[ecx] = mlx->object.monster[ecx].x;
		old_y[ecx] = mlx->object.monster[ecx].y;
		return ;
	}
	delta_x = (mlx->object.monster[ecx].x - old_x[ecx]) / TILE_WIDTH;
	delta_y = (mlx->object.monster[ecx].y - old_y[ecx]) / TILE_HEIGHT;
	mlx->object.monster[ecx].movement_speed = \
		ft_fmax(ft_fabs(delta_x), ft_fabs(delta_y));
	old_x[ecx] = mlx->object.monster[ecx].x;
	old_y[ecx] = mlx->object.monster[ecx].y;
}
