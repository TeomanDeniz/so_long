/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_coin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:20:00 by hdeniz            #+#    #+#             */
/*   Updated: 2023/08/16 13:20:04 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [V] INCLUDES [V] **************************** */
#include "../so_long.h" /*
#typedef t_mlx;
#   void mlx_error(t_mlx, char *, char);
*/
/* **************************** [^] INCLUDES [^] **************************** */

void
	check_coin(t_mlx mlx_library)
{
	register int	ecx1;
	register int	ecx2;
	register int	coin_counter;

	coin_counter = 0;
	ecx1 = -1;
	while (++ecx1, mlx_library->map[ecx1])
	{
		ecx2 = -1;
		while (++ecx2, mlx_library->map[ecx1][ecx2])
			if (mlx_library->map[ecx1][ecx2] == 'C')
				++coin_counter;
	}
	if (!coin_counter)
		mlx_error(mlx_library, "No coins found in the map!\n", 1);
	mlx_library->coins = coin_counter;
}
