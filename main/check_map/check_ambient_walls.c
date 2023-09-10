/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ambient_walls.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 15:25:51 by hdeniz            #+#    #+#             */
/*   Updated: 2023/08/16 15:25:54 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [V] INCLUDES [V] **************************** */
#include "../so_long.h" /*
#typedef t_mlx;
#   void mlx_error(t_mlx, char *, char);
*/
#include "../../libft/libft.h" /*
#    int ft_putnbr(const char *const);
*/
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [V] PROTOTYPES [V] *************************** */
static inline int	check_the_wall(int y, int limit, t_mlx mlx_library);
/* *************************** [^] PROTOTYPES [^] *************************** */

void
	check_ambient_walls(t_mlx mlx_library)
{
	register int			ecx;
	register unsigned int	last_wall;

	last_wall = 0;
	while (mlx_library->map[last_wall])
		++last_wall;
	ecx = -1;
	while (++ecx, mlx_library->map[ecx])
		if (check_the_wall(ecx, last_wall, mlx_library))
			mlx_error(mlx_library, "A wall should surrender the map!\n", 1);
}

static inline int
	check_the_wall(int y, int limit, t_mlx mlx_library)
{
	register int	ecx;

	ecx = -1;
	while (++ecx, mlx_library->map[y][ecx])
	{
		if ((y == 0 || y == limit) && mlx_library->map[y][ecx] != '1')
			return (1);
		else if (mlx_library->map[y][ecx] != '1' && \
			(ecx == 0 || ecx == (ft_strlen(mlx_library->map[y]) - 1)))
			return (1);
	}
	return (0);
}
