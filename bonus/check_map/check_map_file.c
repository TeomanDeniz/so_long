/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:15:22 by hdeniz            #+#    #+#             */
/*   Updated: 2023/08/14 16:15:24 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [V] INCLUDES [V] **************************** */
#include "../../libft/libft.h" /*
#    int ft_strlen(const char *const);
*/
#include "../so_long.h" /*
#typedef t_mlx;
#   void mlx_error(t_mlx, char *, char);
*/
#include <fcntl.h> /*
#    int open(char *, int, ...);
# define O_RDONLY 0X0000
*/
/* **************************** [^] INCLUDES [^] **************************** */

int
	check_map_file(char *argc, t_mlx mlx_library)
{
	register int	eax;
	int				map_fd;

	eax = ft_strlen(argc) - 1;
	if (!(argc[eax - 3] == '.' && \
		argc[eax - 2] == 'b' && \
		argc[eax - 1] == 'e' && \
		argc[eax] == 'r'))
		mlx_error(mlx_library, "The file type is not \".ber\".\n", 0);
	map_fd = open(argc, O_RDONLY);
	if (!map_fd || map_fd == -1)
		mlx_error(mlx_library, "The folder is can not opened.\n", 0);
	return (map_fd);
}
