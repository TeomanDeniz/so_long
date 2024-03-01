/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 14:40:55 by hdeniz            #+#    #+#             */
/*   Updated: 2023/08/05 14:40:56 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [V] INCLUDES [V] **************************** */
#include "../minilibx/mlx.h" /*
#    int mlx_loop(void *);
#    int mlx_clear_window(void *, void *);
#   void *mlx_new_window(void *, int, int, char const *);
#   void *mlx_new_image(void *, int, int);
#   char *mlx_get_data_addr(void *, int *, int *, int *);
#    int mlx_hook(void *, int, int, int (*f)(), void *);
#    int mlx_destroy_window(void *, void *);
*/
#include "so_long.h" /*
# struct s_mlx;
#   void set_mlx(struct s_mlx *, char **);
#   void check_map(char *, struct s_mlx *);
#    int close_window(struct s_mlx *);
#    int key_down(int, struct s_mlx *);
#    int key_up(int, struct s_mlx *);
#   void mlx_error(t_mlx, char *, char);
#   void map_generator(t_mlx);
#   void game(t_mlx);
#   void player_position(t_mlx);
#   void draw_background(t_mlx);
#   void draw_wall(t_mlx);
#   void draw_item(t_mlx);
#   void draw_gate(t_mlx);
#   void draw_player(t_mlx);
#   void debug(t_mlx);
#typedef t_mlx;
*/
#include <stdlib.h> /*
# define EXIT_FAILURE 1
# define EXIT_SUCCESS 0
#   void free(void *);
#   void exit(int);
*/
#include "../libft/libft.h" /*
#    int ft_strlen(const char *const);
*/
#include <unistd.h> /*
#ssize_t write(int, const void *, size_t);
*/
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [V] PROTOTYPES [V] *************************** */
static inline int	check_argument(register int argc, t_mlx mlx_library);
static inline int	loop(t_mlx mlx_library);
/* *************************** [^] PROTOTYPES [^] *************************** */

int
	main(int argc, char **argv)
{
	struct s_mlx	mlx_library;

	mlx_library = (struct s_mlx){0};
	if (check_argument(argc, &mlx_library))
		if (!mlx_library.map)
			return (EXIT_FAILURE);
	if (!mlx_library.map)
		check_map(argv[1], &mlx_library);
	set_mlx(&mlx_library, argv);
	mlx_loop_hook(mlx_library.mlx, loop, &mlx_library);
	mlx_hook(mlx_library.window, 17, (1L << 0), close_window, &mlx_library);
	mlx_hook(mlx_library.window, 2, 1L << 0, key_down, &mlx_library);
	mlx_hook(mlx_library.window, 3, 1L << 1, key_up, &mlx_library);
	mlx_loop(mlx_library.mlx);
	return (EXIT_SUCCESS);
}

static inline int
	check_argument(register int argc, t_mlx mlx_library)
{
	char	choice;

	if (argc >= 2)
		return (EXIT_SUCCESS);
	write(1, "You didn't input any map in the arguments.\n", 43);
	write(1, "Do you want to generate a random map? (y/n)\n", 44);
	read(1, &choice, 1);
	if (choice == 'y')
		map_generator(mlx_library);
	return (EXIT_FAILURE);
}

static inline int
	loop(t_mlx mlx_library)
{
	if (((mlx_library->fps) % (mlx_library->game_speed)) == 0)
	{
		game(mlx_library);
		player_position(mlx_library);
		draw_background(mlx_library);
		draw_wall(mlx_library);
		draw_item(mlx_library);
		draw_gate(mlx_library);
		draw_player(mlx_library);
		debug(mlx_library);
	}
	if (mlx_library->fps >= 0X100000)
		mlx_library->fps = 1;
	mlx_library->fps++;
	return (0);
}
