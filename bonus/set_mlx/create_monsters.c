/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_monsters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:42:40 by hdeniz            #+#    #+#             */
/*   Updated: 2023/08/08 17:42:42 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [V] INCLUDES [V] **************************** */
#include "../so_long.h" /*
# define TILE_WIDTH ?
# define TILE_HEIGHT ?
#typedef t_mlx;
#   void mlx_error(t_mlx, char *, char);
#    int count_in_map(char **, char);
*/
#include <stdlib.h> /*
#   void *malloc(int);
*/
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [V] PROTOTYPES [V] *************************** */
static inline void	list_monsters(t_mlx mlx);
static inline void	set_monster(t_mlx mlx, int ecx, int x, int y);
/* *************************** [^] PROTOTYPES [^] *************************** */

void
	create_monsters(t_mlx mlx)
{
	if (count_in_map(mlx->map, 'M'))
	{
		mlx->object.monster = (struct s_monster *)malloc(sizeof(struct \
			s_monster) * (count_in_map(mlx->map, 'M') + 1));
		if (!mlx->object.monster)
			mlx_error(mlx, "Failed to allocate monsters\n", 5);
		list_monsters(mlx);
	}
}

static inline void
	list_monsters(t_mlx mlx)
{
	register int	x;
	register int	y;

	y = -1;
	while (++y, mlx->map[y])
	{
		x = -1;
		while (++x, mlx->map[y][x])
			if (mlx->map[y][x] == 'M')
				set_monster(mlx, mlx->object.number_of_monsters, x, y);
	}
}

static inline void
	set_monster(t_mlx mlx, int ecx, int x, int y)
{
	mlx->object.monster[ecx].x = x * TILE_WIDTH;
	mlx->object.monster[ecx].y = y * TILE_HEIGHT;
	mlx->object.monster[ecx].target_x = (double)mlx->object.monster[ecx].x;
	mlx->object.monster[ecx].target_y = (double)mlx->object.monster[ecx].y;
	mlx->object.monster[ecx].rotation = 0;
	mlx->object.monster[ecx].animation = 0;
	mlx->object.number_of_monsters += 1;
}
