/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_gate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:08:02 by hdeniz            #+#    #+#             */
/*   Updated: 2023/08/16 13:08:03 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [V] INCLUDES [V] **************************** */
#include "../so_long.h" /*
#typedef t_mlx;
#   void mlx_error(t_mlx, char *, char);
*/
/* **************************** [^] INCLUDES [^] **************************** */

void
	check_gate(t_mlx mlx_library)
{
	register int	ecx1;
	register int	ecx2;
	register int	gate_counter;

	gate_counter = 0;
	ecx1 = -1;
	while (++ecx1, mlx_library->map[ecx1])
	{
		ecx2 = -1;
		while (++ecx2, mlx_library->map[ecx1][ecx2])
			if (mlx_library->map[ecx1][ecx2] == 'E')
				++gate_counter;
	}
	if (!gate_counter)
		mlx_error(mlx_library, "Exit gate not found in the map!\n", 1);
	if (gate_counter != 1)
		mlx_error(mlx_library, "Multiple exit gates found in the map!\n", 1);
}
