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

/* **************************** [V] INCLUDES [V] **************************** */
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

/* *************************** [V] PROTOTYPES [V] *************************** */
static inline void	set_map(t_mlx mlx_library, register int map_fd);
/* *************************** [^] PROTOTYPES [^] *************************** */

void
	check_map(char *argc, t_mlx mlx_library)
{
	register int	map_fd;

	map_fd = check_map_file(argc, mlx_library);
	set_map(mlx_library, map_fd);
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

static inline void
	set_map(t_mlx mlx_library, register int map_fd)
{
	char	*line;
	char	*temp;
	char	*map_out;

	temp = get_next_line(map_fd);
	line = malloc(2 * sizeof(char));
	while (!!temp)
	{
		map_out = ft_strjoin(line, temp);
		if (line)
			free(line);
		free(temp);
		temp = get_next_line(map_fd);
		if (map_out)
			line = ft_strdup(map_out);
		free(map_out);
		map_out = (void *)0;
	}
	free((close(map_fd), temp));
	temp = (void *)0;
	if (!line)
		mlx_error(mlx_library, "Map allocate abort!\n", 0);
	mlx_library->map = ft_split(line, '\n');
	free(line);
	line = (void *)0;
}
