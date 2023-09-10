/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:41:20 by hdeniz            #+#    #+#             */
/*   Updated: 2023/08/22 16:41:21 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [V] INCLUDES [V] **************************** */
#include "../so_long.h" /*
#typedef t_mlx;
*/
#include <stdlib.h> /*
#   void free(void *);
*/
/* **************************** [^] INCLUDES [^] **************************** */

void
	free_objects(t_mlx mlx)
{
	if (mlx->object.coin)
	{
		free(mlx->object.coin);
		mlx->object.coin = (void *)0;
	}
	if (mlx->object.wall)
	{
		free(mlx->object.wall);
		mlx->object.wall = (void *)0;
	}
	if (mlx->object.barrier)
	{
		free(mlx->object.barrier);
		mlx->object.barrier = (void *)0;
	}
}
