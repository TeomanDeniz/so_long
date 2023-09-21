/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:17:14 by hdeniz            #+#    #+#             */
/*   Updated: 2023/08/14 16:17:16 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../so_long.h" /*
#typedef t_mlx;
#    int check_map_file(char *, t_mlx);
#   void mlx_error(t_mlx, char *, char);
#   void check_if_rows_equal(t_mlx);
#   void check_gate(t_mlx);
#   void check_player(t_mlx);
#   void check_coin(t_mlx);
#   void check_invalid_entity(t_mlx);
#   void check_if_map_fits(t_mlx);
#   void check_ambient_walls(t_mlx);
#   char check_barriers(t_mlx);
*/
#include "../../libft/libft.h" /*
#    int ft_strlen(const char *const);
#   char *get_next_line(int);
#   char *ft_strjoin(char const *, const char *);
#   char **ft_split(char const *, char);
*/
#include <stdlib.h> /*
#   void free(void *);
*/
#include <unistd.h> /*
#    int close(int);
*/
/* **************************** [^] INCLUDES [^] **************************** */

/* **************************** [v] CONSTANTS [v] *************************** */
#define NEWLINE_ERROR "There is an extra new line at the middle of the map!\n"
/* **************************** [^] CONSTANTS [^] *************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
static void	set_map(t_mlx mlx_library, register int map_fd);
static char	*map_joinner(int map_fd);
static int	check_breaker(char *map_out);
/* *************************** [^] PROTOTYPES [^] *************************** */

void
	check_map(char *argc, t_mlx mlx_library)
{
	register int	map_fd;

	map_fd = check_map_file(argc, mlx_library);
	set_map(mlx_library, map_fd);
	close(map_fd);
	check_if_rows_equal(mlx_library);
	check_if_map_fits(mlx_library);
	check_gate(mlx_library);
	check_player(mlx_library);
	check_coin(mlx_library);
	check_invalid_entity(mlx_library);
	check_ambient_walls(mlx_library);
	if (!check_barriers(mlx_library))
		mlx_error(mlx_library, "This map is impossible to pass!\n", 1);
}

static void
	set_map(t_mlx mlx_library, register int map_fd)
{
	char	*map_out;

	map_out = map_joinner(map_fd);
	if (check_breaker(map_out))
	{
		map_out = (free(map_out), (void *)0);
		mlx_error(mlx_library, NEWLINE_ERROR, 0);
	}
	if (!map_out)
		mlx_error(mlx_library, "Map allocate abort!\n", 0);
	mlx_library->map = ft_split(map_out, '\n');
	if (map_out)
		map_out = (free(map_out), (void *)0);
}

static char
	*map_joinner(int map_fd)
{
	char	*temp1;
	char	*temp2;
	char	*map_out;

	temp2 = get_next_line(map_fd);
	map_out = (char [2]){0, 0};
	while (!!temp2)
	{
		temp1 = ft_strjoin(map_out, temp2);
		if (map_out[0])
			map_out = (free(map_out), (void *)0);
		if (!!temp2)
			free(temp2);
		temp2 = get_next_line(map_fd);
		if (!!temp1)
			map_out = ft_strdup(temp1);
		if (!!temp1)
			temp1 = (free(temp1), (void *)0);
	}
	if (temp2)
		temp2 = (free(temp2), (void *)0);
	return (map_out);
}

static int
	check_breaker(char *map_out)
{
	register int	ecx;
	register int	line_size;
	register char	only_newline;

	ecx = -1;
	line_size = 0;
	only_newline = 0;
	while (++ecx, map_out[ecx])
	{
		line_size = 0;
		while (map_out[line_size + ecx] != '\n' && !!map_out[line_size + ecx])
			++line_size;
		if (line_size == 0)
			only_newline = 1;
		if (!!line_size && only_newline)
			return (1);
		ecx += line_size;
	}
	return (0);
}
