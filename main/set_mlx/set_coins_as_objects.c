/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_coins_as_objects.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:41:04 by hdeniz            #+#    #+#             */
/*   Updated: 2023/08/22 17:41:05 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [V] INCLUDES [V] **************************** */
#include "../so_long.h" /*
# define TILE_WIDTH ?
# define TILE_HEIGHT ?
# struct s_coin;
#typedef t_mlx;
#   void mlx_error(t_mlx, char *, char);
*/
#include <stdlib.h> /*
#   void *malloc(int);
*/
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [V] PROTOTYPES [V] *************************** */
static inline void	do_event(t_mlx mlx_library, int ecx, int x, int y);
/* *************************** [^] PROTOTYPES [^] *************************** */

void
	set_coins_as_objects(t_mlx mlx_library)
{
	register int			x;
	register int			y;
	register unsigned int	ecx;

	mlx_library->object.coin = (struct s_coin *) malloc(mlx_library->coins * \
		(sizeof(struct s_coin) + 1));
	if (!(mlx_library->object.coin))
		mlx_error(mlx_library, " ERROR - Coins allocate error\n", 4);
	y = -1;
	ecx = 0;
	while (++y, mlx_library->map[y])
	{
		x = -1;
		while (++x, mlx_library->map[y][x])
		{
			if (mlx_library->map[y][x] == 'C')
			{
				do_event(mlx_library, ecx, x, y);
				++ecx;
			}
		}
	}
}

static inline void
	do_event(t_mlx mlx_library, int ecx, int x, int y)
{
	mlx_library->object.coin[ecx].active = 1;
	mlx_library->object.coin[ecx].x = x * TILE_WIDTH;
	mlx_library->object.coin[ecx].y = y * TILE_HEIGHT;
}
