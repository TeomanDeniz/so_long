#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/* Compile with

gcc mlx_free_test.c libmlx.a -Wall -Wextra -Werror -framework OpenGL -framework AppKit

*/

typedef struct mlx_img_list_s
{
	int						width;
	int						height;
	char					*buffer;
	float					vertexes[8];
	struct mlx_img_list_s	*next;
}	mlx_img_list_t;

typedef struct mlx_img_ctx_s
{
	unsigned int			texture;
	unsigned int			vbuffer;
	mlx_img_list_t			*img;
	struct mlx_img_ctx_s	*next;
}	mlx_img_ctx_t;

typedef struct mlx_win_list_s
{
	void					*winid;
	mlx_img_ctx_t			*img_list;
	int						nb_flush;
	int						pixmgt;
	struct mlx_win_list_s	*next;
} mlx_win_list_t;

typedef struct mlx_ptr_s
{
	void			*appid;
	mlx_win_list_t	*win_list;
	mlx_img_list_t	*img_list;
	void			(*loop_hook)(void *);
	void			*loop_hook_data;
	void			*loop_timer;
	mlx_img_list_t	*font;
	int				main_loop_active;
}	mlx_ptr_t;

int
	main(void)
{
	mlx_ptr_t		*mlx;
	mlx_img_list_t	*temp_img;
	mlx_win_list_t	*temp_win;
	mlx_img_ctx_t	*temp_ctx;

	mlx = mlx_init();

	temp_img = &(mlx_img_list_t){0};
	temp_win = &(mlx_win_list_t){0};
	temp_ctx = &(mlx_img_ctx_t){0};

	free(mlx->font->buffer);
	mlx->font->buffer = ((void *)0);
	mlx->font->next = ((void *)0);
	free(mlx->font);
	mlx->font = ((void *)0);

	free(mlx);
	mlx = ((void *)0);
	if (mlx)
		printf("1\n");
	return (0);
}

	/*
	mlx->loop_timer = ((void *)0);
	mlx->loop_hook_data = ((void *)0);
	mlx->appid = ((void *)0);

	while (!!mlx->img_list)
	{
		if (!!mlx->img_list->next)
			temp_img = mlx->img_list->next;
		if (!!mlx->img_list->buffer)
		{
			free(mlx->img_list->buffer);
			mlx->img_list->buffer = ((void *)0);
		}
		if (!!temp_img->buffer)
			mlx->img_list = temp_img;
		else
		{
			free(mlx->img_list);
			mlx->img_list = ((void *)0);
		}
	}

	while (!!mlx->font)
	{
		if (!!mlx->font->next)
			temp_img = mlx->font->next;
		if (!!mlx->font->buffer)
		{
			free(mlx->font->buffer);
			mlx->font->buffer = ((void *)0);
		}
		if (!!temp_img->buffer)
			mlx->font = temp_img;
		else
		{
			mlx->font = ((void *)0);
		}
	}


	while (!!mlx->font)
	{
		if (!!mlx->font->next)
			temp_img = mlx->font->next;
		if (!!mlx->font->buffer)
		{
			free(mlx->font->buffer);
			mlx->font->buffer = ((void *)0);
		}
		if (!!temp_img->buffer)
			mlx->font = temp_img;
		else
		{
			free(mlx->font)
			mlx->font = ((void *)0);
		}
	}

	while (mlx->win_list)
	{
		if (mlx->win_list->next)
			temp_win = mlx->win_list->next;

		while (mlx->win_list->img_list)
		{
			if (mlx->win_list->img_list->next)
				temp_ctx = mlx->win_list->img_list->next;

			while (mlx->win_list->img_list)
			{
				if (mlx->win_list->img_list->img->next)
					temp_img = mlx->win_list->img_list->img->next;
				if (mlx->win_list->img_list->img->buffer)
				{
					free(mlx->win_list->img_list->img->buffer);
					mlx->win_list->img_list->img->buffer = ((void *)0);
				}
				free(mlx->win_list->img_list->img);
				if (temp_img)
					mlx->win_list->img_list->img = temp_img;
				else
					mlx->win_list->img_list->img = ((void *)0);
			}
			free(mlx->win_list->img_list);
			if (temp_ctx)
				mlx->win_list->img_list = temp_ctx;
			else
				mlx->win_list->img_list = ((void *)0);
		}
		free(mlx->win_list);
		if (temp_win)
			mlx->win_list = temp_win;
		else
			mlx->win_list = ((void *)0);
	}
	*/
