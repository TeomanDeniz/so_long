/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_map_fits.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 15:09:26 by hdeniz            #+#    #+#             */
/*   Updated: 2023/08/16 15:09:27 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [V] INCLUDES [V] **************************** */
#include "../../libft/libft.h" /*
#    int ft_strlen(const char *const);
*/
#include "../so_long.h" /*
# define TILE_WIDTH ?
# define TILE_HEIGHT ?
# define PC_WIDTH ?
# define PC_HEIGHT ?
#typedef t_mlx;
#   void mlx_error(t_mlx, char *, char);
*/
/* **************************** [^] INCLUDES [^] **************************** */

void
	check_if_map_fits(t_mlx mlx_library)
{
	register unsigned int	map_width;
	register unsigned int	map_height;

	map_height = 0;
	map_width = ft_strlen(mlx_library->map[0]);
	while (mlx_library->map[map_height])
		++map_height;
	if ((map_width * TILE_WIDTH) >= PC_WIDTH || \
		(map_height * TILE_HEIGHT) >= PC_HEIGHT)
		mlx_error(mlx_library, "Map is too big for this PC\n", 1);
}
