/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_barriers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:05:36 by hdeniz            #+#    #+#             */
/*   Updated: 2023/08/16 16:05:38 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [V] INCLUDES [V] **************************** */
#include "../so_long.h" /*
# define DEBUG_PATH_FINDER ?
#typedef t_mlx;
#   void mlx_error(t_mlx, char *, char);
#    int search_in_map(char **, char, char);
*/
#include "../../libft/libft.h" /*
#   char **ft_copy_matrix(char **);
#   void ft_free_matrix(char **);
#   void ft_print_matrix(char **);
*/
#include <stdlib.h> /*
#   void *malloc(int);
#   void free(void *);
*/
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [V] PROTOTYPES [V] *************************** */
static inline void	matrix_converter(char **map);
static inline void	maze_checker(char **map, int x, int y);
static inline char	check_if(char **map, char **analyzer, int x, int y);
/* *************************** [^] PROTOTYPES [^] *************************** */

char
	check_barriers(t_mlx mlx_library)
{
	char			**analyzer;
	char			**map;
	register int	x;
	register int	y;

	map = mlx_library->map;
	analyzer = ft_copy_matrix(map);
	if (!analyzer)
		mlx_error(mlx_library, "Allocate error for map matrix\n", 1);
	matrix_converter(analyzer);
	maze_checker(analyzer, search_in_map(map, 'P', 'X'), \
		search_in_map(map, 'P', 'Y'));
	y = -1;
	while (++y, map[y])
	{
		x = -1;
		while (++x, map[y][x])
			if (check_if(map, analyzer, x, y))
				return (0);
	}
	ft_free_matrix(analyzer);
	return (1);
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

/*
if (matrix[y + 1][x])
 ...
 .@.
 .*.

if (matrix[y - 1][x])
 .*.
 .@.
 ...

if (matrix[y][x + 1])
 ...
 .@*
 ...

if (matrix[y][x - 1])
 ...
 *@.
 ...
*/

static inline void
	maze_checker(char **map, int x, int y)
{
	map[y][x] = '.';
	if (map[y + 1][x] == 'E')
		map[y + 1][x] = '1';
	if (map[y - 1][x] == 'E')
		map[y - 1][x] = '1';
	if (map[y][x + 1] == 'E')
		map[y][x + 1] = '1';
	if (map[y][x - 1] == 'E')
		map[y][x - 1] = '1';
	if (DEBUG_PATH_FINDER)
		ft_print_matrix(map);
	if (map[y + 1][x] == ' ')
		maze_checker(map, x, y + 1);
	if (map[y - 1][x] == ' ')
		maze_checker(map, x, y - 1);
	if (map[y][x + 1] == ' ')
		maze_checker(map, x + 1, y);
	if (map[y][x - 1] == ' ')
		maze_checker(map, x - 1, y);
}

static inline char
	check_if(char **map, char **analyzer, int x, int y)
{
	if (map[y][x] == 'E' && analyzer[y][x] == 'E')
		return (1);
	if (map[y][x] == 'C' && analyzer[y][x] == ' ')
		return (1);
	return (0);
}
