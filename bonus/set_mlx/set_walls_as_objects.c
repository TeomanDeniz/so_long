/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_walls_as_objects.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:35:45 by hdeniz            #+#    #+#             */
/*   Updated: 2023/08/22 17:35:47 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [V] INCLUDES [V] **************************** */
#include "../so_long.h" /*
# define DEBUG_WALL_FINDER ?
# define TILE_WIDTH ?
# define TILE_HEIGHT ?
#typedef t_mlx;
#   void mlx_error(t_mlx, char *, char);
#    int search_in_map(char **, char, char);
#    int count_in_map(char **, char);
*/
#include "../../libft/libft.h" /*
#   char **ft_copy_matrix(char **);
#   void ft_free_matrix(char **);
#   void ft_print_matrix(char **);
*/
#include <stdlib.h> /*
#   void *malloc(int);
*/
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [V] PROTOTYPES [V] *************************** */
static inline void	matrix_converter(char **map);
static inline void	wall_checker(char **map, int x, int y);
static inline void	fill_objects(t_mlx mlx_library, char **map, int x[4]);
static inline void	set_wall_hitboxes(t_mlx mlx_library, char **analyzer);
/* *************************** [^] PROTOTYPES [^] *************************** */

void
	set_walls_as_objects(t_mlx mlx_library)
{
	char			**analyzer;

	analyzer = ft_copy_matrix(mlx_library->map);
	if (!analyzer)
		mlx_error(mlx_library, "Allocate error for map matrix objects\n", 5);
	matrix_converter(analyzer);
	set_wall_hitboxes(mlx_library, analyzer);
	mlx_library->object.barrier = (struct s_barrier *)malloc(sizeof(struct \
		s_barrier) * (count_in_map(analyzer, '1') + 1));
	if (!(mlx_library->object.barrier))
	{
		ft_free_matrix(analyzer);
		mlx_error(mlx_library, "Object barrier allocate error\n", 5);
	}
	mlx_library->object.wall = (struct s_wall *)malloc(sizeof(struct \
		s_wall) * (count_in_map(analyzer, '#') + \
		count_in_map(analyzer, '1') + 1));
	if (!(mlx_library->object.wall))
	{
		ft_free_matrix(analyzer);
		mlx_error(mlx_library, "Object walls allocate error\n", 5);
	}
	fill_objects(mlx_library, analyzer, (int [4]){-1, -1, 0, 0});
	ft_free_matrix(analyzer);
}

static inline void
	matrix_converter(char **map)
{
	register int	y;
	register int	x;

	y = -1;
	while (++y, map[y])
	{
		x = -1;
		while (++x, map[y][x])
		{
			if (map[y][x] == '0')
				map[y][x] = ' ';
			if (map[y][x] == '1')
				map[y][x] = '#';
			if (map[y][x] == 'C')
				map[y][x] = ' ';
		}
	}
}

static inline void
	wall_checker(char **map, int x, int y)
{
	map[y][x] = '.';
	if (map[y + 1][x] == 'E' || (map[y + 1][x] == '#'))
		map[y + 1][x] = '1';
	if (map[y - 1][x] == 'E' || (map[y - 1][x] == '#'))
		map[y - 1][x] = '1';
	if (map[y][x + 1] == 'E' || (map[y][x + 1] == '#'))
		map[y][x + 1] = '1';
	if (map[y][x - 1] == 'E' || (map[y][x - 1] == '#'))
		map[y][x - 1] = '1';
	if (DEBUG_WALL_FINDER)
		ft_print_matrix(map);
	if (map[y + 1][x] == ' ')
		wall_checker(map, x, y + 1);
	if (map[y - 1][x] == ' ')
		wall_checker(map, x, y - 1);
	if (map[y][x + 1] == ' ')
		wall_checker(map, x + 1, y);
	if (map[y][x - 1] == ' ')
		wall_checker(map, x - 1, y);
}

static inline void
	fill_objects(t_mlx mlx_library, char **map, int x[4])
{
	while (++x[1], map[x[1]])
	{
		while (++x[0], map[x[1]][x[0]])
		{
			if (map[x[1]][x[0]] == '#' || map[x[1]][x[0]] == '1')
			{
				mlx_library->object.wall[x[3]].x = x[0];
				mlx_library->object.wall[x[3]].y = x[1];
				mlx_library->object.number_of_walls += (++x[3], 1);
			}
			if (map[x[1]][x[0]] == '1')
			{
				mlx_library->object.barrier[x[2]].start_x = x[0] * TILE_WIDTH;
				mlx_library->object.barrier[x[2]].start_y = x[1] * TILE_HEIGHT;
				mlx_library->object.barrier[x[2]].end_x = \
					(x[0] + 1) * TILE_WIDTH;
				mlx_library->object.barrier[x[2]].end_y = \
					(x[1] + 1) * TILE_HEIGHT;
				mlx_library->object.number_of_barriers += (++x[2], 1);
			}
		}
		x[0] = -1;
	}
}

static inline void
	set_wall_hitboxes(t_mlx mlx_library, char **analyzer)
{
	register int	x;
	register int	y;

	wall_checker(analyzer, search_in_map(mlx_library->map, 'P', 'X'), \
		search_in_map(mlx_library->map, 'P', 'Y'));
	y = -1;
	while (++y, analyzer[y])
	{
		x = -1;
		while (++x, analyzer[y][x])
			if (analyzer[y][x] == 'M')
				wall_checker(analyzer, x, y);
	}
}
