/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 17:42:38 by hdeniz            #+#    #+#             */
/*   Updated: 2023/08/27 17:42:39 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdio.h>
#include <unistd.h>

/* Compile with

gcc movement.c libmlx.a -Wall -Wextra -Werror -framework OpenGL -framework AppKit

*/

void
	ft_putnbr(register int number)
{
	char	character;

	if (number < 0)
		number = (write(1, "-", 1), (number * -1));
	if (number < 10)
	{
		character = number | 0X30;
		write(1, &character, 1);
	}
	if (number > 9)
		(ft_putnbr(number / 10), ft_putnbr(number % 10));
}

typedef struct s_vars {
	void	*mlx;
	void	*win;
	char	moving[4];
	void	*img;
	int		x;
	int		y;
}	*t_vars;

static inline int	key_up(int keycode, t_vars vars);
static inline int	key_down(int keycode, t_vars vars);

void
	print_status(t_vars vars)
{
	register int	out_size;
	register int	eax;

	out_size = 0;
	eax = vars->x;
	while (++out_size, eax)
		eax /= 10;
	eax = vars->y;
	while (++out_size, eax)
		eax /= 10;
	out_size += 6 + 1;
	eax = -1;
	while (++eax, eax <= out_size)
		write(1, "\b", 1);
	eax = -1;
	while (++eax, eax < out_size)
		write(1, " ", 1);
	eax = -1;
	while (++eax, eax <= out_size)
		write(1, "\b", 1);
	write(1, " x:", 3);
	ft_putnbr(vars->x);
	write(1, " y:", 3);
	ft_putnbr(vars->y);
}

int
	render_loop(t_vars vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->x, vars->y);

	if (vars->moving[0] == 1)
		vars->y -= 1;
	if (vars->moving[1] == 1)
		vars->x -= 1;
	if (vars->moving[2] == 1)
		vars->y += 1;
	if (vars->moving[3] == 1)
		vars->x += 1;
	print_status(vars);
	return (0);
}

int
	main(void)
{
	struct s_vars	vars;

	write(1, "\n", 1);

	vars.moving[0] = 0;
	vars.moving[1] = 0;
	vars.moving[2] = 0;
	vars.moving[3] = 0;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");

	vars.x = 0;
	vars.y = 0;
	vars.img = mlx_xpm_file_to_image(vars.mlx, "./test.xpm", \
		&(int){0}, &(int){0});

	mlx_hook(vars.win, 2, 1L << 0, key_down, &vars);
	mlx_hook(vars.win, 3, 1L << 1, key_up, &vars);

	mlx_loop_hook(vars.mlx, render_loop, &vars);
	mlx_loop(vars.mlx);
}

static inline int
	key_down(int keycode, t_vars vars)
{
	if (keycode == 13)
		vars->moving[0] = 1;
	if (keycode == 0)
		vars->moving[1] = 1;
	if (keycode == 1)
		vars->moving[2] = 1;
	if (keycode == 2)
		vars->moving[3] = 1;
	return (0);
}

static inline int
	key_up(int keycode, t_vars vars)
{
	if (keycode == 13)
		vars->moving[0] = 0;
	if (keycode == 0)
		vars->moving[1] = 0;
	if (keycode == 1)
		vars->moving[2] = 0;
	if (keycode == 2)
		vars->moving[3] = 0;
	return (0);
}