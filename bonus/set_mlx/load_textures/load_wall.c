/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:43:51 by hdeniz            #+#    #+#             */
/*   Updated: 2023/09/05 14:43:52 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [V] INCLUDES [V] **************************** */
#include "../../so_long.h" /*
# define TS_WALL ?
# define TS_WALL_ANI ?
#   void free_textures(t_mlx, int);
#   void *xpm_texture(t_mlx, char *);
#typedef t_mlx;
*/
/* **************************** [^] INCLUDES [^] **************************** */

void
	load_wall(t_mlx mlx_lib, int *z)
{
	register int	y;
	register int	x;

	x = 0;
	while (++x, x < TS_WALL)
	{
		y = -1;
		while (++y, ++*z, y < TS_WALL_ANI)
		{
			mlx_lib->texture_pack.wall[x - 1][y] = xpm_texture(mlx_lib, \
					(char [32]){
					'.', '/', 't', 'e', 'x', 't', 'u', 'r', 'e', 's', '/', 'x',
					'p', 'm', '/', 'b', 'a', 'r', 'r', 'i', 'e', 'r', '/',
					!!(x / 10) * (48 + x / 10) + !(x / 10) * (48 + x % 10),
					!!(x / 10) * ('0' + x % 10) + !(x / 10) * '/',
					!!(x / 10) * '/' + !(x / 10) * ('0' + y),
					!!(x / 10) * ('0' + y) + !(x / 10) * '.',
					!!(x / 10) * '.' + !(x / 10) * 'x',
					!!(x / 10) * 'x' + !(x / 10) * 'p',
					!!(x / 10) * 'p' + !(x / 10) * 'm',
					!!(x / 10) * 'm' + 0, 0});
			if (!(mlx_lib->texture_pack.wall[x - 1][y]))
				free_textures(mlx_lib, *z);
		}
	}
}
