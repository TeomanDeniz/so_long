/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
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
# define PLAYER_SPEED ?
# define PLAYER_WIDTH ?
# define PLAYER_HEIGHT ?
#typedef t_mlx;
*/
#include "../../libft/ft_math/ft_math.h" /*
# double ft_lerp(double, double, double);
*/
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [V] PROTOTYPES [V] *************************** */
static inline char	barrier_hit_yu(t_mlx mlx);
static inline char	barrier_hit_xl(t_mlx mlx);
static inline char	barrier_hit_yd(t_mlx mlx);
static inline char	barrier_hit_xr(t_mlx mlx);
/* *************************** [^] PROTOTYPES [^] *************************** */

void
	player_position(t_mlx mlx)
{
	if (mlx->object.player.position[0] && !barrier_hit_yd(mlx))
		mlx->object.player.target_y += PLAYER_SPEED;
	if (mlx->object.player.position[1] && !barrier_hit_yu(mlx))
		mlx->object.player.target_y -= PLAYER_SPEED;
	if (mlx->object.player.position[2] && !barrier_hit_xl(mlx))
		mlx->object.player.target_x -= PLAYER_SPEED;
	if (mlx->object.player.position[3] && !barrier_hit_xr(mlx))
		mlx->object.player.target_x += PLAYER_SPEED;
	mlx->object.player.x = ft_lerp(mlx->object.player.x, \
		mlx->object.player.target_x, SLICE);
	mlx->object.player.y = ft_lerp(mlx->object.player.y, \
		mlx->object.player.target_y, SLICE);
}

static inline char
	barrier_hit_yu(t_mlx mlx)
{
	register int	ecx;
	register double	movement;

	movement = mlx->object.player.target_y;
	ecx = -1;
	while (++ecx, ecx < mlx->object.number_of_barriers)
	{
		if (movement <= mlx->object.barrier[ecx].end_y && \
			(mlx->object.player.y > mlx->object.barrier[ecx].end_y - \
			(PLAYER_SPEED + 1)) && ((mlx->object.player.x + PLAYER_WIDTH) >= \
			mlx->object.barrier[ecx].start_x && mlx->object.player.x <= \
			mlx->object.barrier[ecx].end_x))
		{
			mlx->object.player.target_y = mlx->object.player.y;
			return (1);
		}
	}
	return (0);
}

static inline char
	barrier_hit_xl(t_mlx mlx)
{
	register int	ecx;
	register double	movement;

	movement = mlx->object.player.target_x;
	ecx = -1;
	while (++ecx, ecx < mlx->object.number_of_barriers)
	{
		if (movement <= mlx->object.barrier[ecx].end_x && \
			(mlx->object.player.x > mlx->object.barrier[ecx].end_x - \
			(PLAYER_SPEED + 1)) && ((mlx->object.player.y + PLAYER_HEIGHT) >= \
			mlx->object.barrier[ecx].start_y && mlx->object.player.y <= \
			mlx->object.barrier[ecx].end_y))
		{
			mlx->object.player.target_x = mlx->object.player.x;
			return (1);
		}
	}
	return (0);
}

static inline char
	barrier_hit_yd(t_mlx mlx)
{
	register int	ecx;
	register double	movement;

	movement = mlx->object.player.target_y;
	ecx = -1;
	while (++ecx, ecx < mlx->object.number_of_barriers)
	{
		if ((movement + PLAYER_HEIGHT) >= mlx->object.barrier[ecx].start_y && \
			((mlx->object.player.y + PLAYER_HEIGHT) < \
			mlx->object.barrier[ecx].start_y + (PLAYER_SPEED + 1)) && \
			((mlx->object.player.x + PLAYER_WIDTH) >= \
			mlx->object.barrier[ecx].start_x && mlx->object.player.x <= \
			mlx->object.barrier[ecx].end_x))
		{
			mlx->object.player.target_y = mlx->object.player.y;
			return (1);
		}
	}
	return (0);
}

static inline char
	barrier_hit_xr(t_mlx mlx)
{
	register int	ecx;
	register double	movement;

	movement = mlx->object.player.target_x;
	ecx = -1;
	while (++ecx, ecx < mlx->object.number_of_barriers)
	{
		if ((movement + PLAYER_WIDTH) >= mlx->object.barrier[ecx].start_x && \
			((mlx->object.player.x + PLAYER_WIDTH) < \
			mlx->object.barrier[ecx].start_x + (PLAYER_SPEED + 1)) && \
			((mlx->object.player.y + PLAYER_HEIGHT) >= \
			mlx->object.barrier[ecx].start_y && mlx->object.player.y <= \
			mlx->object.barrier[ecx].end_y))
		{
			mlx->object.player.target_x = mlx->object.player.x;
			return (1);
		}
	}
	return (0);
}
