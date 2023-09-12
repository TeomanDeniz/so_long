/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_coin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:43:57 by hdeniz            #+#    #+#             */
/*   Updated: 2023/09/05 14:44:00 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [V] INCLUDES [V] **************************** */
#include "../../so_long.h" /*
# define TS_COIN ?
#   void free_textures(t_mlx, int);
#   void *xpm_texture(t_mlx, char *);
#typedef t_mlx;
*/
/* **************************** [^] INCLUDES [^] **************************** */

void
	load_coin(t_mlx mlx_lib, void *texture[TS_COIN], int *z)
{
	register int	x;

	x = -1;
	while (++x, ++*z, x < TS_COIN)
	{
		texture[x] = xpm_texture(mlx_lib, (char [26]){'.', '/', 't', 'e',
				'x', 't', 'u', 'r', 'e', 's', '/', 'x', 'p', 'm', '/', 'c', 'o',
				'i', 'n', '/', '0' + x, '.', 'x', 'p', 'm', 0});
		if (!texture[x])
			free_textures(mlx_lib, *z);
	}
}
