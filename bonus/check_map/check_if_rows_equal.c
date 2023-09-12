/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_rows_equal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 20:38:44 by hdeniz            #+#    #+#             */
/*   Updated: 2023/08/14 20:38:45 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [V] INCLUDES [V] **************************** */
#include "../../libft/libft.h" /*
#    int ft_strlen(const char *const);
*/
#include "../so_long.h" /*
#typedef t_mlx;
#   void mlx_error(t_mlx, char *, char);
*/
/* **************************** [^] INCLUDES [^] **************************** */

void
	check_if_rows_equal(t_mlx mlx_library)
{
	register unsigned int	checker;
	register unsigned int	ecx;

	ecx = 0;
	checker = ft_strlen(mlx_library->map[0]);
	while (++ecx, mlx_library->map[ecx])
	{
		if (ft_strlen(mlx_library->map[ecx]) != (signed int)checker)
			mlx_error(mlx_library, "Map is not a rectangle!\n", 1);
	}
}
