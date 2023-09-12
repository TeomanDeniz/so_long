/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_invalid_entity.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:26:57 by hdeniz            #+#    #+#             */
/*   Updated: 2023/08/16 13:26:58 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [V] INCLUDES [V] **************************** */
#include "../so_long.h" /*
#typedef t_mlx;
#   void mlx_error(t_mlx, char *, char);
*/
#include <unistd.h> /*
#ssize_t write(int, const void *, size_t);
*/
#include "../../libft/libft.h" /*
#    int ft_putnbr(const char *const);
*/
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [V] PROTOTYPES [V] *************************** */
static inline void	invalid_entity_found(t_mlx mlx_library, int *xy);
/* *************************** [^] PROTOTYPES [^] *************************** */

void
	check_invalid_entity(t_mlx mlx_library)
{
	register int	ecx1;
	register int	ecx2;
	register int	error;

	error = 0;
	ecx1 = -1;
	while (++ecx1, mlx_library->map[ecx1] && !error)
	{
		ecx2 = -1;
		while (++ecx2, mlx_library->map[ecx1][ecx2] && !error)
		{
			if (mlx_library->map[ecx1][ecx2] != 'E' && \
				mlx_library->map[ecx1][ecx2] != 'P' && \
				mlx_library->map[ecx1][ecx2] != 'C' && \
				mlx_library->map[ecx1][ecx2] != '1' && \
				mlx_library->map[ecx1][ecx2] != '0' && \
				mlx_library->map[ecx1][ecx2] != 'M')
				error = 1;
		}
	}
	if (error)
		invalid_entity_found(mlx_library, (int []){ecx1, ecx2});
}

static inline void
	invalid_entity_found(t_mlx mlx_library, int *xy)
{
	write(1, "Found an invalid entity in this map!\n At line:", 46);
	ft_putnbr(xy[0]);
	write(1, " column:", 8);
	ft_putnbr(xy[1]);
	mlx_error(mlx_library, "\n", 1);
}
