/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 18:50:21 by hdeniz            #+#    #+#             */
/*   Updated: 2023/09/04 12:30:15 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [V] INCLUDES [V] **************************** */
#include "../../minilibx/mlx.h" /*
#    int mlx_string_put(void *, void *, int, int, int, char *);
*/
#include "../so_long.h" /*
# define DEBUG ?
#typedef t_mlx;
*/
#include "../../libft/libft.h" /*
#    int ft_numlen(int);
#   void ft_putnbr(int);
*/
#include <unistd.h> /*
#ssize_t write(int, const void *, size_t);
*/
/* **************************** [^] INCLUDES [^] **************************** */

/* **************************** [V] CONSTANTS [V] *************************** */
#define MESSAGE_COLOR 0XFFFFFF // 0XRRGGBB
#define CHAR_SIZE 8
/* **************************** [^] CONSTANTS [^] *************************** */

/* *************************** [V] PROTOTYPES [V] *************************** */
static inline void	putnbr(t_mlx mlx, int number, int *x);
/* *************************** [^] PROTOTYPES [^] *************************** */

void
	debug(t_mlx mlx)
{
	int	out_size;

	out_size = 1;
	mlx_string_put(mlx->mlx, mlx->window, out_size, \
		CHAR_SIZE, MESSAGE_COLOR, "Steps:");
	out_size += 6 * CHAR_SIZE;
	putnbr(mlx, (int)mlx->steps, &out_size);
	out_size += CHAR_SIZE;
	mlx_string_put(mlx->mlx, mlx->window, out_size, \
		CHAR_SIZE, MESSAGE_COLOR, "Coins:");
	out_size += 6 * CHAR_SIZE;
	putnbr(mlx, (int)mlx->coins, &out_size);
}

static inline void
	putnbr(t_mlx mlx, int number, int *x)
{
	char	character;

	if (number < 0)
		number = (write(1, "-", 1), (number * -1));
	if (number < 10)
	{
		character = number | 0X30;
		mlx_string_put(mlx->mlx, mlx->window, *x, CHAR_SIZE, MESSAGE_COLOR, \
			(char [2]){character, 0});
		*x += CHAR_SIZE;
	}
	if (number > 9)
		(putnbr(mlx, number / 10, x), putnbr(mlx, number % 10, x));
}
