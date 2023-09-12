/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:08:41 by hdeniz            #+#    #+#             */
/*   Updated: 2023/09/04 13:08:43 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [V] INCLUDES [V] **************************** */
#include "../../so_long.h" /*
#typedef t_mlx;
*/
#include "../../../minilibx/mlx.h" /*
#    int mlx_put_image_to_window(void *, void *, void *, int, int);
*/
/* **************************** [^] INCLUDES [^] **************************** */

void
	put_image(t_mlx mlx_library, void *image, int x, int y)
{
	mlx_put_image_to_window(mlx_library->mlx, mlx_library->window, image, x, y);
}
