/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:33:41 by hdeniz            #+#    #+#             */
/*   Updated: 2023/08/19 17:33:43 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [V] INCLUDES [V] **************************** */
#include "../../minilibx/mlx.h" /*
#    int mlx_destroy_image(mlx_ptr_t *, mlx_img_list_t *);
*/
#include "../so_long.h" /*
# define TS_COIN ?
# define TS_GATE ?
# define TS_PLAYER ?
# define TS_WALL ?
# define TS_MONSTER ?
#   void mlx_error(t_mlx, char *, char);
#typedef t_mlx;
*/
#include <unistd.h> /*
#ssize_t write(int, const void *, size_t);
*/
#include <stdlib.h> /*
#   void *malloc(int);
*/
#include "../../libft/libft.h" /*
#   void ft_putnbr(register int number);
*/
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [V] PROTOTYPES [V] *************************** */
static inline void	free_textures_directly(t_mlx mlx);
static inline void	free_monster_textures(t_mlx mlx);
static inline void	free_player_textures(t_mlx mlx);
static inline void	free_wall_textures(t_mlx mlx);
/* *************************** [^] PROTOTYPES [^] *************************** */

void
	free_textures(t_mlx mlx_library, int id)
{
	free_textures_directly(mlx_library);
	if (id)
	{
		write(1, "Texture failed to open - ID[", 28);
		ft_putnbr(id);
		mlx_error(mlx_library, "]\n", 3);
	}
}

static inline void
	free_textures_directly(t_mlx mlx)
{
	register int	ebx;

	ebx = -1;
	while (++ebx, ebx < TS_COIN && !!mlx->texture_pack.coin[ebx])
		mlx_destroy_image(mlx->mlx, mlx->texture_pack.coin[ebx]);
	ebx = -1;
	while (++ebx, ebx < TS_GATE && !!mlx->texture_pack.gate[ebx])
		mlx_destroy_image(mlx->mlx, mlx->texture_pack.gate[ebx]);
	if (!!mlx->texture_pack.ground)
		mlx_destroy_image(mlx->mlx, mlx->texture_pack.ground);
	free_monster_textures(mlx);
	free_player_textures(mlx);
	free_wall_textures(mlx);
}

static inline void
	free_monster_textures(t_mlx mlx)
{
	register int	ecx;
	register int	ebx;

	ebx = -1;
	while (++ebx, ebx < TS_MONSTER)
	{
		ecx = -1;
		while (++ecx, !!mlx->texture_pack.monster[ebx][ecx])
		{
			if (!!mlx->texture_pack.monster[ebx][ecx])
			{
				mlx_destroy_image(mlx->mlx, \
					mlx->texture_pack.monster[ebx][ecx]);
				mlx->texture_pack.monster[ebx][ecx] = (void *)0;
			}
		}
	}
}

static inline void
	free_player_textures(t_mlx mlx)
{
	register int	ecx;
	register int	ebx;

	ebx = -1;
	while (++ebx, ebx < TS_PLAYER)
	{
		ecx = -1;
		while (++ecx, !!mlx->texture_pack.player[ebx][ecx])
		{
			if (!!mlx->texture_pack.player[ebx][ecx])
			{
				mlx_destroy_image(mlx->mlx, mlx->texture_pack.player[ebx][ecx]);
				mlx->texture_pack.player[ebx][ecx] = (void *)0;
			}
		}
	}
}

static inline void
	free_wall_textures(t_mlx mlx)
{
	register int	ecx;
	register int	ebx;

	ebx = -1;
	while (++ebx, ebx < TS_WALL)
	{
		ecx = -1;
		while (++ecx, !!mlx->texture_pack.wall[ebx][ecx])
		{
			if (!!mlx->texture_pack.wall[ebx][ecx])
			{
				mlx_destroy_image(mlx->mlx, mlx->texture_pack.wall[ebx][ecx]);
				mlx->texture_pack.wall[ebx][ecx] = (void *)0;
			}
		}
	}
}
