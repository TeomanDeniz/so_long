/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement3.c                                        :+:      :+:    :+:   */
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

#define SPEED 250ULL
#define PLAYER_SPEED 5.0
#define SLICE 0.2

/* Compile with

gcc movement3.c libmlx.a -Wall -Wextra -Werror -framework OpenGL -framework AppKit

*/

struct s_barrier {
	int		start_x;
	int		start_y;
	int		end_x;
	int		end_y;
};

typedef struct s_vars {
	void				*mlx;
	void				*win;
	char				moving[4];
	void				*img;
	double				x;
	double				y;
	double				size_x;
	double				size_y;
	double				target_x;
	double				target_y;
	unsigned long long	fps;
	struct s_barrier	*barriers;
	int					number_of_barriers;
}	*t_vars;

static inline int	key_up(int keycode, t_vars vars);
static inline int	key_down(int keycode, t_vars vars);
static inline void	print_status(t_vars vars);

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

double
	ft_lerp(register double x, register double y, register double f)
{
	return (x + f * (y - x));
}

char
	barrier_hit_target(t_vars vars, char direction)
{
	register int	ecx;
	register int	movement;

	if (direction == 'y')
		movement = vars->target_y;
	if (direction == 'x')
		movement = vars->target_x;
	if (direction == 'Y')
		movement = vars->target_y;
	if (direction == 'X')
		movement = vars->target_x;
	ecx = -1;
	while (++ecx, ecx < vars->number_of_barriers)
	{
		if (direction == 'y')
		{
			if (movement <= vars->barriers[ecx].end_y && \
				(vars->y > vars->barriers[ecx].end_y - (PLAYER_SPEED + 1)) && \
				((vars->x + vars->size_x) >= vars->barriers[ecx].start_x && vars->x <= vars->barriers[ecx].end_x))
			{
				vars->target_y = vars->y;
				return (1);
			}
		}
		if (direction == 'x')
		{
			if (movement <= vars->barriers[ecx].end_x && \
				(vars->x > vars->barriers[ecx].end_x - (PLAYER_SPEED + 1)) && \
				((vars->y + vars->size_y) >= vars->barriers[ecx].start_y && vars->y <= vars->barriers[ecx].end_y))
			{
				vars->target_x = vars->x;
				return (1);
			}
		}
		if (direction == 'Y')
		{
			if ((movement + vars->size_y) >= vars->barriers[ecx].start_y && \
				((vars->y + vars->size_y) < vars->barriers[ecx].start_y + (PLAYER_SPEED + 1)) && \
				((vars->x + vars->size_x) >= vars->barriers[ecx].start_x && vars->x <= vars->barriers[ecx].end_x))
			{
				vars->target_y = vars->y;
				return (1);
			}
		}
		if (direction == 'X')
		{
			if ((movement + vars->size_x) >= vars->barriers[ecx].start_x && \
				((vars->x + vars->size_x) < vars->barriers[ecx].start_x + (PLAYER_SPEED + 1)) && \
				((vars->y + vars->size_y) >= vars->barriers[ecx].start_y && vars->y <= vars->barriers[ecx].end_y))
			{
				vars->target_x = vars->x;
				return (1);
			}
		}
	}
	return (0);
}

int
	render_loop(t_vars vars)
{
	if (vars->fps >= SPEED)
	{
		mlx_clear_window(vars->mlx, vars->win);

		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 100, 100);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 132, 100);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 132, 132);

		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 132, 196);

		mlx_put_image_to_window(vars->mlx, vars->win, \
			vars->img, vars->x - 1, vars->y - 1);

		if (vars->moving[0] && !barrier_hit_target(vars, 'y'))
			vars->target_y -= PLAYER_SPEED;
		if (vars->moving[1] && !barrier_hit_target(vars, 'x'))
			vars->target_x -= PLAYER_SPEED;
		if (vars->moving[2] && !barrier_hit_target(vars, 'Y'))
			vars->target_y += PLAYER_SPEED;
		if (vars->moving[3] && !barrier_hit_target(vars, 'X'))
			vars->target_x += PLAYER_SPEED;


		print_status(vars);
		vars->x = ft_lerp(vars->x, vars->target_x, SLICE);
		vars->y = ft_lerp(vars->y, vars->target_y, SLICE);
		vars->fps = 0ULL;
	}
	vars->fps++;
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

	vars.fps = 0;

	vars.barriers = (struct s_barrier *)((struct s_barrier [4]){{100, 100, 164, 132}, {132, 132, 164, 164}, {132, 196, 164, 228}, {0}});
	vars.number_of_barriers = 3;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");

	vars.x = 3.0;
	vars.y = 3.0;
	vars.target_x = 3.0;
	vars.target_y = 3.0;

	vars.size_x = 30;
	vars.size_y = 30;

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

char
	get_number_size(int	number)
{
	char	result;

	result = -1;
	while (++result, number)
		number /= 10;
	return (result);
}

void
	print_status(t_vars vars)
{
	register int	out_size;
	register int	eax;

	out_size = 0;
	eax = (int)vars->x;
	while (++out_size, eax)
		eax /= 10;
	eax = (int)vars->y;
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
	ft_putnbr((int)vars->x);
	write(1, " y:", 3);
	ft_putnbr((int)vars->y);
}