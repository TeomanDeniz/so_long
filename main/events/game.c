/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:39:57 by hdeniz            #+#    #+#             */
/*   Updated: 2023/09/04 13:39:58 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [V] INCLUDES [V] **************************** */
#include "../so_long.h" /*
# define TILE_WIDTH ?
# define TILE_HEIGHT ?
# define PLAYER_WIDTH ?
# define PLAYER_HEIGHT ?
#    int close_window(t_mlx);
#typedef t_mlx;
*/
#include <unistd.h> /*
#ssize_t write(int, const void *, size_t);
*/
#include "../../libft/ft_math/ft_math.h" /*
# double ft_fabs(double);
# double ft_fmax(double, double);
*/
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [V] PROTOTYPES [V] *************************** */
static inline void	check_position_coins(t_mlx mlx);
static inline void	check_position_gate(t_mlx mlx);
static inline void	check_rotation_player(t_mlx mlx, double x, double y);
/* *************************** [^] PROTOTYPES [^] *************************** */

void
	game(t_mlx mlx)
{
	static double	old_x;
	static double	old_y;
	double			delta_x;
	double			delta_y;

	old_x = 0.0 + old_x;
	old_y = 0.0 + old_y;
	if (old_x == 0.0)
		old_x = mlx->object.player.x;
	if (old_x == 0.0)
		old_y = mlx->object.player.y;
	delta_x = (mlx->object.player.x - old_x) / TILE_WIDTH;
	delta_y = (mlx->object.player.y - old_y) / TILE_HEIGHT;
	check_position_coins(mlx);
	check_position_gate(mlx);
	check_rotation_player(mlx, delta_x, delta_y);
	mlx->steps += ft_fmax(ft_fabs(delta_x), ft_fabs(delta_y));
	old_x = mlx->object.player.x;
	old_y = mlx->object.player.y;
}

static inline void
	check_position_coins(t_mlx mlx)
{
	static int		coins;
	register int	ecx;

	coins = 0 + coins;
	if (!coins)
		coins = mlx->coins;
	ecx = -1;
	while (++ecx, ecx < coins)
	{
		if (((mlx->object.player.x <= mlx->object.coin[ecx].x + TILE_WIDTH && \
			mlx->object.player.x + PLAYER_WIDTH >= mlx->object.coin[ecx].x) && \
			(mlx->object.player.y <= mlx->object.coin[ecx].y + TILE_HEIGHT && \
			mlx->object.player.y + PLAYER_HEIGHT >= mlx->object.coin[ecx].y)) \
			&& mlx->object.coin[ecx].active)
		{
			mlx->coins--;
			mlx->object.coin[ecx].active = 0;
		}
	}
}

static inline void
	check_position_gate(t_mlx mlx)
{
	if (mlx->coins)
		return ;
	else if (!mlx->object.gate.active)
		mlx->object.gate.active = 1;
	if (((mlx->object.player.x <= mlx->object.gate.x + TILE_WIDTH && \
		mlx->object.player.x + PLAYER_WIDTH >= mlx->object.gate.x) && \
		(mlx->object.player.y <= mlx->object.gate.y + TILE_HEIGHT && \
		mlx->object.player.y + PLAYER_HEIGHT >= mlx->object.gate.y)) \
		&& mlx->object.gate.active)
	{
		write(1, "\n\n VICTORY!!!\n\n", 15);
		close_window(mlx);
	}
}

static inline void
	check_rotation_player(t_mlx mlx, double x, double y)
{
	if (y > 0.0 && ft_fabs(y) > ft_fabs(x))
		mlx->object.player.rotation = 0;
	if (y < 0.0 && ft_fabs(y) > ft_fabs(x))
		mlx->object.player.rotation = 1;
	if (x < 0.0 && ft_fabs(x) > ft_fabs(y))
		mlx->object.player.rotation = 2;
	if (x > 0.0 && ft_fabs(x) > ft_fabs(y))
		mlx->object.player.rotation = 3;
}
