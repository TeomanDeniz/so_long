/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_down.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:03:17 by hdeniz            #+#    #+#             */
/*   Updated: 2023/08/14 17:03:18 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [V] INCLUDES [V] **************************** */
#include "../so_long.h" /*
# define KEY_ESC 53
# define LETTER_KEY_LEFT 0
# define LETTER_KEY_RIGHT 2
# define LETTER_KEY_UP 13
# define LETTER_KEY_DOWN 1
# define ARROW_KEY_LEFT 123
# define ARROW_KEY_RIGHT 124
# define ARROW_KEY_UP 126
# define ARROW_KEY_DOWN 125
#   void close_window(t_mlx);
#typedef t_mlx;
*/
/* **************************** [^] INCLUDES [^] **************************** */

int
	key_down(int key, t_mlx mlx)
{
	if (key == KEY_ESC)
		close_window(mlx);
	if ((key == LETTER_KEY_DOWN || key == ARROW_KEY_DOWN))
		mlx->object.player.position[0] = 1;
	if ((key == LETTER_KEY_UP || key == ARROW_KEY_UP))
		mlx->object.player.position[1] = 1;
	if ((key == LETTER_KEY_LEFT || key == ARROW_KEY_LEFT))
		mlx->object.player.position[2] = 1;
	if ((key == LETTER_KEY_RIGHT || key == ARROW_KEY_RIGHT))
		mlx->object.player.position[3] = 1;
	return (0);
}
