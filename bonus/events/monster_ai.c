/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_ai.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 18:49:34 by hdeniz            #+#    #+#             */
/*   Updated: 2023/09/03 18:49:35 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [V] INCLUDES [V] **************************** */
#include "../so_long.h" /*
# define SPEED ?
# define SLICE ?
# define MONSTER_SPEED ?
# define PLAYER_WIDTH ?
# define PLAYER_HEIGHT ?
#typedef t_mlx;
*/
#include "../../libft/libft.h" /*
#    int ft_rand(int, int);
*/
#include "../../libft/ft_math/ft_math.h" /*
# double ft_lerp(double, double, double);
*/
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [V] PROTOTYPES [V] *************************** */
static inline char	barrier_hit_yu(t_mlx mlx, int x);
static inline char	barrier_hit_xl(t_mlx mlx, int x);
static inline char	barrier_hit_yd(t_mlx mlx, int x);
static inline char	barrier_hit_xr(t_mlx mlx, int x);
/* *************************** [^] PROTOTYPES [^] *************************** */

void
	monster_ai(t_mlx mlx)
{
	register int	ecx;
	static char		command[0XFFFF];

	ecx = -1;
	while (++ecx, ecx < mlx->object.number_of_monsters)
	{
		command[ecx] = 0 + command[ecx];
		if (ft_rand(0, ecx + 100) == ecx)
			command[ecx] = ft_rand(1, 4);
		if (command[ecx] == 1 && !barrier_hit_yd(mlx, ecx))
			mlx->object.monster[ecx].target_y += MONSTER_SPEED;
		if (command[ecx] == 2 && !barrier_hit_yu(mlx, ecx))
			mlx->object.monster[ecx].target_y -= MONSTER_SPEED;
		if (command[ecx] == 3 && !barrier_hit_xl(mlx, ecx))
			mlx->object.monster[ecx].target_x -= MONSTER_SPEED;
		if (command[ecx] == 4 && !barrier_hit_xr(mlx, ecx))
			mlx->object.monster[ecx].target_x += MONSTER_SPEED;
		mlx->object.monster[ecx].rotation = !!command[ecx] * (command[ecx] - 1);
		mlx->object.monster[ecx].x = ft_lerp(mlx->object.monster[ecx].x, \
			mlx->object.monster[ecx].target_x, SLICE);
		mlx->object.monster[ecx].y = ft_lerp(mlx->object.monster[ecx].y, \
			mlx->object.monster[ecx].target_y, SLICE);
	}
}

static inline char
	barrier_hit_yu(t_mlx mlx, int x)
{
	register int	ecx;
	register double	movement;

	movement = mlx->object.monster[x].target_y;
	ecx = -1;
	while (++ecx, ecx < mlx->object.number_of_barriers)
	{
		if (movement <= mlx->object.barrier[ecx].end_y && \
			(mlx->object.monster[x].y > mlx->object.barrier[ecx].end_y - \
			(MONSTER_SPEED + 1)) && ((mlx->object.monster[x].x + \
			TILE_WIDTH) >= mlx->object.barrier[ecx].start_x && \
			mlx->object.monster[x].x <= mlx->object.barrier[ecx].end_x))
		{
			mlx->object.monster[x].target_y = mlx->object.monster[x].y;
			return (1);
		}
	}
	return (0);
}

static inline char
	barrier_hit_xl(t_mlx mlx, int x)
{
	register int	ecx;
	register double	movement;

	movement = mlx->object.monster[x].target_x;
	ecx = -1;
	while (++ecx, ecx < mlx->object.number_of_barriers)
	{
		if (movement <= mlx->object.barrier[ecx].end_x && \
			(mlx->object.monster[x].x > mlx->object.barrier[ecx].end_x - \
			(MONSTER_SPEED + 1)) && ((mlx->object.monster[x].y + \
			TILE_HEIGHT) >= mlx->object.barrier[ecx].start_y && \
			mlx->object.monster[x].y <= mlx->object.barrier[ecx].end_y))
		{
			mlx->object.monster[x].target_x = mlx->object.monster[x].x;
			return (1);
		}
	}
	return (0);
}

static inline char
	barrier_hit_yd(t_mlx mlx, int x)
{
	register int	ecx;
	register double	movement;

	movement = mlx->object.monster[x].target_y;
	ecx = -1;
	while (++ecx, ecx < mlx->object.number_of_barriers)
	{
		if ((movement + PLAYER_HEIGHT) >= mlx->object.barrier[ecx].start_y && \
			((mlx->object.monster[x].y + PLAYER_HEIGHT) < \
			mlx->object.barrier[ecx].start_y + (MONSTER_SPEED + 1)) && \
			((mlx->object.monster[x].x + PLAYER_WIDTH) >= \
			mlx->object.barrier[ecx].start_x && mlx->object.monster[x].x <= \
			mlx->object.barrier[ecx].end_x))
		{
			mlx->object.monster[x].target_y = mlx->object.monster[x].y;
			return (1);
		}
	}
	return (0);
}

static inline char
	barrier_hit_xr(t_mlx mlx, int x)
{
	register int	ecx;
	register double	movement;

	movement = mlx->object.monster[x].target_x;
	ecx = -1;
	while (++ecx, ecx < mlx->object.number_of_barriers)
	{
		if ((movement + TILE_WIDTH) >= mlx->object.barrier[ecx].start_x && \
			((mlx->object.monster[x].x + TILE_WIDTH) < \
			mlx->object.barrier[ecx].start_x + (MONSTER_SPEED + 1)) && \
			((mlx->object.monster[x].y + TILE_HEIGHT) >= \
			mlx->object.barrier[ecx].start_y && mlx->object.monster[x].y <= \
			mlx->object.barrier[ecx].end_y))
		{
			mlx->object.monster[x].target_x = mlx->object.monster[x].x;
			return (1);
		}
	}
	return (0);
}
