/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:30:25 by hdeniz            #+#    #+#             */
/*   Updated: 2023/08/18 14:30:26 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [V] INCLUDES [V] **************************** */
#include "../so_long.h" /*
# define DEBUG_MAP ?
# define RMG_COIN 1 // %
# define RMG_WALL 10 // %
# define RMG_MAP_MAX_WIDTH ?
# define RMG_MAP_MAX_HEIGHT ?
# define RMG_MAP_MIN_WIDTH ?
# define RMG_MAP_MIN_HEIGHT ?
# define RMG_MAX_TROUBLE ?
#typedef t_mlx;
#   char check_barriers(t_mlx);
#   void mlx_error(t_mlx, char *, char);
*/
#include "../../libft/libft.h" /*
#   void ft_print_matrix(char **);
#    int ft_rand(int, int);
#    int ft_strlen(char *);
*/
#include <stdlib.h> /*
#   void *malloc(int);
*/
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [V] PROTOTYPES [V] *************************** */
static inline void	fill_with_ground(t_mlx mlx_library, int map_x, int map_y);
static inline void	draw_the_walls_around(char **map, int map_y);
static inline void	put_objects(t_mlx mlx_library, int map_x, int map_y);
static inline void	put_walls(t_mlx mlx_library, int map_y);
/* *************************** [^] PROTOTYPES [^] *************************** */

void
	map_generator(t_mlx mlx_library)
{
	register int	map_x;
	register int	map_y;
	register int	trouble_shoot;

	trouble_shoot = 0;
	map_x = ft_rand(RMG_MAP_MIN_WIDTH, RMG_MAP_MAX_WIDTH);
	map_y = ft_rand(RMG_MAP_MIN_HEIGHT, RMG_MAP_MAX_HEIGHT);
	if (map_x < 5 || map_y < 5)
		mlx_error(mlx_library, "RMG values are made an oopsie!\n", 0);
	mlx_library->map = (char **)malloc(sizeof(char *) * (map_y + 1));
	if (!mlx_library->map)
		mlx_error(mlx_library, "Map allocate failed.\n", 0);
	while (trouble_shoot < RMG_MAX_TROUBLE)
	{
		fill_with_ground(mlx_library, map_x, map_y);
		draw_the_walls_around(mlx_library->map, map_y);
		put_objects(mlx_library, map_x, map_y);
		put_walls(mlx_library, map_y);
		if (check_barriers(mlx_library))
			return ;
		++trouble_shoot;
	}
	mlx_error(mlx_library, "Random map can not created!\n", 1);
}

static inline void
	fill_with_ground(t_mlx mlx_library, int map_x, int map_y)
{
	register int	x;
	register int	y;

	y = -1;
	while (++y, y < map_y)
	{
		mlx_library->map[y] = (char *)malloc((sizeof(char) * (map_x + 1)));
		if (!mlx_library->map[y])
			mlx_error(mlx_library, "Map layer allocation error \n", 1);
		x = -1;
		while (++x, x < map_x)
			mlx_library->map[y][x] = '0';
		mlx_library->map[y][x] = 0;
	}
	mlx_library->map[y] = ((void *)0);
	if (DEBUG_MAP)
		ft_print_matrix(mlx_library->map);
}

static inline void
	draw_the_walls_around(char **map, int map_y)
{
	register int	x;
	register int	y;
	register int	max;

	max = ft_strlen(map[0]);
	y = -1;
	while (++y, y < map_y)
	{
		x = -1;
		while (++x, map[y][x])
		{
			if (((y == (map_y - 1)) || (y == 0)) || (x == (max - 1) || x == 0))
				map[y][x] = '1';
		}
	}
	if (DEBUG_MAP)
		ft_print_matrix(map);
}

static inline void
	put_objects(t_mlx mlx_library, int map_x, int map_y)
{
	char			object[4];
	register int	ecx;
	register int	x;
	register int	y;

	object[0] = 'C';
	object[1] = 'P';
	object[2] = 'E';
	object[3] = 0;
	ecx = 0;
	mlx_library->coins = 1;
	while (object[ecx])
	{
		x = ft_rand(1, map_x - 2);
		y = ft_rand(1, map_y - 2);
		if (mlx_library->map[y][x] == '0')
		{
			mlx_library->map[y][x] = object[ecx];
			++ecx;
		}
	}
	if (DEBUG_MAP)
		ft_print_matrix(mlx_library->map);
}

static inline void
	put_walls(t_mlx mlx_library, int map_y)
{
	register int	x;
	register int	y;

	y = -1;
	while (++y, y < map_y)
	{
		x = -1;
		while (++x, mlx_library->map[y][x])
		{
			if (mlx_library->map[y][x] == '0' && (ft_rand(0, 99) < RMG_WALL))
				mlx_library->map[y][x] = '1';
			if (mlx_library->map[y][x] == '0' && (ft_rand(0, 99) < RMG_COIN))
			{
				mlx_library->coins += 1;
				mlx_library->map[y][x] = 'C';
			}
		}
	}
	if (DEBUG_MAP)
		ft_print_matrix(mlx_library->map);
}
