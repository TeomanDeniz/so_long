/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:37:54 by hdeniz            #+#    #+#             */
/*   Updated: 2023/08/19 15:37:55 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [V] INCLUDES [V] **************************** */
#include "../../so_long.h" /*
#typedef t_mlx;
#   void mlx_error(t_mlx, char *, char);
#   void *xpm_texture(t_mlx, char *);
#   void load_wall(t_mlx, int *);
#   void load_player(t_mlx, void *[?][?], int *);
#   void load_gate(t_mlx, void *[?], int *);
#   void load_coin(t_mlx, void *[?], int *);
*/
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [V] PROTOTYPES [V] *************************** */
#define FILE_GROUND "./textures/xpm/ground.xpm"
/* *************************** [^] PROTOTYPES [^] *************************** */

void
	load_textures(t_mlx mlx_library)
{
	int	*z;

	z = &(int){0};
	load_player(mlx_library, mlx_library->texture_pack.player, z);
	load_wall(mlx_library, z);
	load_coin(mlx_library, mlx_library->texture_pack.coin, z);
	load_gate(mlx_library, mlx_library->texture_pack.gate, z);
	mlx_library->texture_pack.ground = xpm_texture(mlx_library, FILE_GROUND);
	++*z;
	if (!(mlx_library->texture_pack.ground))
		free_textures(mlx, *z);
	mlx_library->object.player.texture = mlx_library->texture_pack.player[0][0];
	mlx_library->object.gate.texture = mlx_library->texture_pack.gate[0];
}
