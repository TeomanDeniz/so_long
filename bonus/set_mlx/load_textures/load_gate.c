/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_gate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:44:09 by hdeniz            #+#    #+#             */
/*   Updated: 2023/09/05 14:44:10 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [V] INCLUDES [V] **************************** */
#include "../../so_long.h" /*
# define TS_GATE ?
#   void mlx_error(t_mlx, char *, char);
#   void *xpm_texture(t_mlx, char *);
#   char check_xpm_file(const char *);
#   void free_textures(t_mlx, int);
#typedef t_mlx;
*/
#include <unistd.h> /*
#ssize_t write(int, const void *, size_t);
*/
#include "../../../libft/libft.h" /*
#   void ft_putnbr(register int number);
*/
/* **************************** [^] INCLUDES [^] **************************** */

void
	load_gate(t_mlx mlx_lib, void *texture[TS_GATE], int *z)
{
	register int	x;

	x = -1;
	while (++x, ++*z, x < TS_GATE)
	{
		texture[x] = xpm_texture(mlx_lib, (char [26]){'.', '/', 't', 'e',
				'x', 't', 'u', 'r', 'e', 's', '/', 'x', 'p', 'm', '/', 'd', 'o',
				'o', 'r', '/', '0' + x, '.', 'x', 'p', 'm', 0});
		if (!(texture[x]))
			free_textures(mlx_lib, *z);
	}
}
