/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:42:40 by hdeniz            #+#    #+#             */
/*   Updated: 2023/08/08 17:42:42 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [V] INCLUDES [V] **************************** */
#include "../../minilibx/mlx.h" /*
#   void *mlx_new_window(void *, int, int, char const *);
#   void *mlx_new_image(void *, int, int);
#   char *mlx_get_data_addr(void *, int *, int *, int *);
*/
#include "../../libft/libft.h" /*
#    int ft_strlen(char *);
#    int ft_matrixrlen(char **);
*/
#include "../so_long.h" /*
# define SPEED ?
# define TILE_WIDTH ?
# define TILE_HEIGHT ?
# define PLAYER_SPEED ?
#typedef t_mlx;
#   void mlx_error(t_mlx, char *, char);
#    int search_in_map(char **, char, char);
#   void set_walls_as_objects(t_mlx);
#   void set_coins_as_objects(t_mlx);
#   void load_textures(t_mlx);
#   void set_map_textures(t_mlx);
#   void create_monsters(t_mlx);
*/
#include <stdlib.h> /*
#   void *malloc(int);
*/
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [V] PROTOTYPES [V] *************************** */
static inline void	create_objects(t_mlx mlx_library);
static inline char	*get_title(char **argv);
static inline int		minus_to_zero(int number);
/* *************************** [^] PROTOTYPES [^] *************************** */

void
	set_mlx(t_mlx mlx_library, char **argv)
{
	mlx_library->fps = 1;
	mlx_library->mlx = mlx_init();
	if (!mlx_library->mlx)
		mlx_error(mlx_library, " ERROR - MLX failed to build\n", 1);
	mlx_library->window_width = TILE_WIDTH * ft_strlen(mlx_library->map[0]);
	mlx_library->window_height = TILE_HEIGHT * ft_matrixrlen(mlx_library->map);
	mlx_library->window_title = get_title(argv);
	mlx_library->window = mlx_new_window(\
		mlx_library->mlx, mlx_library->window_width, \
		mlx_library->window_height, mlx_library->window_title);
	if (!mlx_library->window)
		mlx_error(mlx_library, " ERROR - Window failed to build\n", 2);
	load_textures(mlx_library);
	create_objects(mlx_library);
	set_map_textures(mlx_library);
	mlx_library->steps = 0;
}

static inline char
	*get_title(char **argv)
{
	register int	eax;

	if (!argv[1])
		return ("[Random Map]");
	eax = ft_strlen(argv[1]) - 1;
	while ((eax > 0) && (argv[1][eax] != '/') && (argv[1][eax] != '\\'))
		--eax;
	return (argv[1] + eax + (eax != 0));
}

static inline void
	create_objects(t_mlx mlx_library)
{
	mlx_library->object.number_of_barriers = 0;
	mlx_library->object.number_of_walls = 0;
	mlx_library->object.number_of_monsters = 0;
	mlx_library->object.player.x = search_in_map(mlx_library->map, 'P', 'X') \
		* TILE_WIDTH;
	mlx_library->object.player.y = search_in_map(mlx_library->map, 'P', 'Y') \
		* TILE_HEIGHT;
	mlx_library->object.player.target_x = (double)mlx_library->object.player.x;
	mlx_library->object.player.target_y = (double)mlx_library->object.player.y;
	mlx_library->object.player.position[0] = 0;
	mlx_library->object.player.position[1] = 0;
	mlx_library->object.player.position[2] = 0;
	mlx_library->object.player.position[3] = 0;
	mlx_library->object.player.rotation = 0;
	mlx_library->object.gate.x = search_in_map(mlx_library->map, 'E', 'X') \
		* TILE_WIDTH;
	mlx_library->object.gate.y = search_in_map(mlx_library->map, 'E', 'Y') \
		* TILE_HEIGHT;
	mlx_library->object.gate.active = 0;
	set_coins_as_objects(mlx_library);
	set_walls_as_objects(mlx_library);
	create_monsters(mlx_library);
	mlx_library->game_speed = (minus_to_zero(SPEED - \
		mlx_library->object.number_of_walls) + 8);
}

static inline int
	minus_to_zero(int number)
{
	if (number <= 0)
		return (1);
	return (number);
}
