/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_up.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:03:22 by hdeniz            #+#    #+#             */
/*   Updated: 2023/08/14 17:03:23 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [V] INCLUDES [V] **************************** */
#include "../so_long.h" /*
# define LETTER_KEY_LEFT 0
# define LETTER_KEY_RIGHT 2
# define LETTER_KEY_UP 13
# define LETTER_KEY_DOWN 1
# define ARROW_KEY_LEFT 123
# define ARROW_KEY_RIGHT 124
# define ARROW_KEY_UP 126
# define ARROW_KEY_DOWN 125
#typedef t_mlx;
*/
/* **************************** [^] INCLUDES [^] **************************** */

int
	key_up(int key, t_mlx mlx)
{
	if (key == LETTER_KEY_DOWN || key == ARROW_KEY_DOWN)
	{
		mlx->object.player.rotation = 0;
		mlx->object.player.texture = mlx->texture_pack.player[0][0];
		mlx->object.player.position[0] = 0;
	}
	if (key == LETTER_KEY_UP || key == ARROW_KEY_UP)
	{
		mlx->object.player.rotation = 1;
		mlx->object.player.texture = mlx->texture_pack.player[1][0];
		mlx->object.player.position[1] = 0;
	}
	if (key == LETTER_KEY_LEFT || key == ARROW_KEY_LEFT)
	{
		mlx->object.player.rotation = 2;
		mlx->object.player.texture = mlx->texture_pack.player[2][0];
		mlx->object.player.position[2] = 0;
	}
	if (key == LETTER_KEY_RIGHT || key == ARROW_KEY_RIGHT)
	{
		mlx->object.player.rotation = 3;
		mlx->object.player.texture = mlx->texture_pack.player[3][0];
		mlx->object.player.position[3] = 0;
	}
	return (0);
}
