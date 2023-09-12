/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_monster.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:43:44 by hdeniz            #+#    #+#             */
/*   Updated: 2023/09/05 14:43:45 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [V] INCLUDES [V] **************************** */
#include "../../so_long.h" /*
# define TS_MONSTER ?
# define TS_MONSTER_ANI ?
#   void free_textures(t_mlx, int);
#   void *xpm_texture(t_mlx, char *);
#typedef t_mlx;
*/
/* **************************** [^] INCLUDES [^] **************************** */

void
	load_monster(t_mlx mlx, void *img[TS_MONSTER][TS_MONSTER_ANI], int *z)
{
	register int	y;
	register int	x;

	y = -1;
	while (++y, y < TS_MONSTER)
	{
		x = -1;
		while (++x, ++*z, x < TS_MONSTER_ANI)
		{
			img[y][x] = xpm_texture(mlx, (char [29]){'.', '/', 't', 'e',
					'x', 't', 'u', 'r', 'e', 's', '/', 'x', 'p', 'm', '/', 'e',
					'n', 'e', 'm', 'y', '/',
					(y == 0) * 'd' + (y == 1) * 'u'
					+ (y == 2) * 'l' + (y == 3) * 'r',
					'/', '0' + x, '.', 'x', 'p', 'm', 0});
			if (!img[y][x])
				free_textures(mlx, *z);
		}
	}
}
