/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:21:00 by hdeniz            #+#    #+#             */
/*   Updated: 2023/08/08 17:21:02 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [V] INCLUDES [V] **************************** */
#include "../../libft/libft.h" /*
#    int ft_strlen(const char *const);
#   void ft_free_matrix(char **);
*/
#include "../so_long.h" /*
#typedef t_mlx;
#   void free_textures(t_mlx, void ***, int, int[2]);
#   void free_objects(t_mlx);
*/
#include <stdlib.h> /*
# define EXIT_FAILURE 1
#   void free(void *);
#   void exit(int);
*/
#include <unistd.h> /*
#ssize_t write(int, const void *, size_t);
*/
#include "../../minilibx/mlx.h" /*
#    int mlx_destroy_window(void *, void *);
#    int mlx_destroy_image(mlx_ptr_t *, mlx_img_list_t *);
*/
/* **************************** [^] INCLUDES [^] **************************** */

void
	mlx_error(t_mlx mlx, char *error_message, char mode)
{
	write(1, error_message, ft_strlen(error_message));
	if (mode >= 1 && mlx->map)
		ft_free_matrix(mlx->map);
	if (mode == 2)
	{
		free(mlx->mlx->font->buffer);
		free(mlx->mlx->font);
		free(mlx->mlx);
	}
	if (mode >= 3)
		mlx_destroy_window(mlx->mlx, mlx->window);
	if (mode >= 4)
		free_textures(mlx, 0);
	if (mode >= 5)
		free_objects(mlx);
	exit(EXIT_FAILURE);
}
