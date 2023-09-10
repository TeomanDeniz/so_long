/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:14:28 by hdeniz            #+#    #+#             */
/*   Updated: 2023/08/16 13:14:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [V] INCLUDES [V] **************************** */
#include "../so_long.h" /*
#typedef t_mlx;
#   void mlx_error(t_mlx, char *, char);
*/
/* **************************** [^] INCLUDES [^] **************************** */

void
	check_player(t_mlx mlx_library)
{
	register int	ecx1;
	register int	ecx2;
	register int	player_counter;

	player_counter = 0;
	ecx1 = -1;
	while (++ecx1, mlx_library->map[ecx1])
	{
		ecx2 = -1;
		while (++ecx2, mlx_library->map[ecx1][ecx2])
			if (mlx_library->map[ecx1][ecx2] == 'P')
				++player_counter;
	}
	if (!player_counter)
		mlx_error(mlx_library, "Player not found in the map!\n", 1);
	if (player_counter != 1)
		mlx_error(mlx_library, "Multiple Players found in the map!\n", 1);
}
