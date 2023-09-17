/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 14:44:43 by hdeniz            #+#    #+#             */
/*   Updated: 2023/09/11 ??:??:?? by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H 20230912L

/* ******************** [V] CONSTANTS - TEXTURE SIZES [V] ******************* */
# define TS_COIN 6
# define TS_GATE 5
# define TS_PLAYER 4
# define TS_PLAYER_ANI 3
# define TS_MONSTER 4
# define TS_MONSTER_ANI 3
# define TS_WALL 18
# define TS_WALL_ANI 8
/* ******************** [^] CONSTANTS - TEXTURE SIZES [^] ******************* */

/* ********************** [V] CONSTANTS - IMPORTANT [V] ********************* */
# define DEBUG 0
# define DEBUG_PATH_FINDER 0
# define DEBUG_WALL_FINDER 0
# define DEBUG_MAP 0
/* ********************** [^] CONSTANTS - IMPORTANT [^] ********************* */

/* *********************** [V] CONSTANTS - PLAYER [V] *********************** */
# define PLAYER_SPEED 3.0
/* *********************** [^] CONSTANTS - PLAYER [^] *********************** */

/* *********************** [V] CONSTANTS - MONSTER [V] ********************** */
# define MONSTER_SPEED 1.0
/* *********************** [^] CONSTANTS - MONSTER [^] ********************** */

/* ************************ [V] CONSTANTS - SIZES [V] *********************** */
# define TILE_WIDTH 16 // X SIZE
# define TILE_HEIGHT 16 // Y SIZE
# define PLAYER_WIDTH 14 // X SIZE
# define PLAYER_HEIGHT 14 // Y SIZE
/* ************************ [^] CONSTANTS - SIZES [^] *********************** */

/* ******************** [V] CONSTANTS - DEVICE SETUP [V] ******************** */
# define PC_WIDTH 5120 // X SIZE
# define PC_HEIGHT 2880 // Y SIZE
# define SPEED 250
/* ******************** [^] CONSTANTS - DEVICE SETUP [^] ******************** */

/* ********************* [V] CONSTANTS - GAME SETUP [V] ********************* */
# define STONE_IN_SEA_AMOUNT 10 // %
# define SLICE 0.2
/* ********************* [^] CONSTANTS - GAME SETUP [^] ********************* */

/* ************* [V] CONSTANTS - (R)ANDOM (M)AP (G)ENERATOR [V] ************* */
# define RMG_COIN 1 // %
# define RMG_WALL 10 // %
# define RMG_MONSTER 1 // %
# define RMG_MAP_MAX_WIDTH 30
# define RMG_MAP_MAX_HEIGHT 30
# define RMG_MAP_MIN_WIDTH 10
# define RMG_MAP_MIN_HEIGHT 10
# define RMG_MAX_TROUBLE 100
/* ************* [^] CONSTANTS - (R)ANDOM (M)AP (G)ENERATOR [^] ************* */

/* *********************** [V] CONSTANTS - INPUTS [V] *********************** */
# define LETTER_KEY_LEFT 0 // A
# define LETTER_KEY_RIGHT 2 // D
# define LETTER_KEY_UP 13 // W
# define LETTER_KEY_DOWN 1 // S
# define ARROW_KEY_LEFT 123 // <-
# define ARROW_KEY_RIGHT 124 // ->
# define ARROW_KEY_UP 126 // ^
# define ARROW_KEY_DOWN 125 // V
# define KEY_ESC 53 // ESC
/* *********************** [^] CONSTANTS - INPUTS [^] *********************** */

/* *************************** [V] MLX STRUCTS [V] ************************** */
typedef struct s_mlx_img_list
{
	int						width;
	int						height;
	char					*buffer;
	float					vertexes[8];
	struct s_mlx_img_list	*next;
}	t_mlx_img_list;

typedef struct s_mlx_img_ctx
{
	unsigned int			texture;
	unsigned int			vbuffer;
	t_mlx_img_list			*img;
	struct s_mlx_img_ctx	*next;
}	t_mlx_img_ctx;

typedef struct s_mlx_win_list
{
	void					*winid;
	t_mlx_img_ctx			*img_list;
	int						nb_flush;
	int						pixmgt;
	struct s_mlx_win_list	*next;
}	t_mlx_win_list;

typedef struct s_mlx_ptr
{
	void			*appid;
	t_mlx_win_list	*win_list;
	t_mlx_img_list	*img_list;
	void			(*loop_hook)(void *);
	void			*loop_hook_data;
	void			*loop_timer;
	t_mlx_img_list	*font;
	int				main_loop_active;
}	t_mlx_ptr;
/* *************************** [^] MLX STRUCTS [^] ************************** */

/* ***************************** [V] STRUCTS [V] **************************** */
struct s_player {
	double	x;
	double	y;
	double	target_x;
	double	target_y;
	double	movement_speed;
	char	position[4];
	char	rotation;
};

struct s_monster {
	double	x;
	double	y;
	double	target_x;
	double	target_y;
	double	movement_speed;
	char	rotation;
	char	animation;
};

struct s_gate {
	int		x;
	int		y;
	char	active;
};

struct s_coin {
	int		x;
	int		y;
	char	active;
};

struct s_wall {
	int				x;
	int				y;
	unsigned char	byte_position;
	char			texture_type;
};

struct s_barrier {
	int		start_x;
	int		start_y;
	int		end_x;
	int		end_y;
};

struct s_object {
	struct s_player		player;
	struct s_monster	*monster;
	struct s_gate		gate;
	struct s_coin		*coin;
	struct s_wall		*wall;
	struct s_barrier	*barrier;
	int					number_of_barriers;
	int					number_of_walls;
	int					number_of_monsters;
};

struct s_texture_packs {
	void	*coin[TS_COIN];
	void	*gate[TS_GATE];
	void	*player[TS_PLAYER][TS_PLAYER_ANI];
	void	*monster[TS_MONSTER][TS_MONSTER_ANI];
	void	*wall[TS_WALL][TS_WALL_ANI];
	void	*ground;
};

struct s_mlx {
	t_mlx_ptr				*mlx;
	void					*window;
	char					*window_title;
	int						window_width;
	int						window_height;
	char					**map;
	int						coins;
	long long				fps;
	long long				game_speed;
	double					steps;
	struct s_texture_packs	texture_pack;
	struct s_object			object;
};
/* ***************************** [^] STRUCTS [^] **************************** */

/* ***************************** [V] TYPEDEF [V] **************************** */
typedef struct s_mlx	*t_mlx;
/* ***************************** [^] TYPEDEF [^] **************************** */

/* ************************ [V] ./EXIT_FUNCTIONS [V] ************************ */
extern void	mlx_error(t_mlx mlx, char *error_message, char mode);
extern int	close_window(t_mlx mlx);
/* ************************ [^] ./EXIT_FUNCTIONS [^] ************************ */

/* *************************** [V] ./CHECK_MAP [V] ************************** */
extern void	check_map(char *argc, t_mlx mlx_library);
extern int	check_map_file(char *argc, t_mlx mlx_library);
extern void	check_if_rows_equal(t_mlx mlx_library);
extern void	check_coin(t_mlx mlx_library);
extern void	check_gate(t_mlx mlx_library);
extern void	check_player(t_mlx mlx_library);
extern void	check_invalid_entity(t_mlx mlx_library);
extern void	check_if_map_fits(t_mlx mlx_library);
extern void	check_ambient_walls(t_mlx mlx_library);
extern char	check_barriers(t_mlx mlx_library);
extern int	search_in_map(char **map, char object, char vector);
extern int	count_in_map(char **map, char object);
/* *************************** [^] ./CHECK_MAP [^] ************************** */

/* ************************* [V] ./MAP_GENERATOR [V] ************************ */
extern void	map_generator(t_mlx mlx_library);
/* ************************* [^] ./MAP_GENERATOR [^] ************************ */

/* **************************** [V] ./EVENTS [V] **************************** */
extern int	key_down(int key, t_mlx mlx);
extern int	key_up(int key, t_mlx mlx);
extern void	player_position(t_mlx mlx);
extern void	debug(t_mlx mlx);
extern void	game(t_mlx mlx);
extern void	monster_ai(t_mlx mlx);
/* ************************ [V] ./EVENTS/GRAPHIC [V] ************************ */
extern void	draw_background(t_mlx mlx);
extern void	draw_wall(t_mlx mlx);
extern void	draw_item(t_mlx mlx);
extern void	draw_gate(t_mlx mlx);
extern void	draw_player(t_mlx mlx);
extern void	put_image(t_mlx mlx_library, void *image, int x, int y);
extern void	draw_monster(t_mlx mlx);
/* ************************ [^] ./EVENTS/GRAPHIC [^] ************************ */
/* **************************** [^] ./EVENTS [^] **************************** */

/* *************************** [V] ./SET_MLX [V] **************************** */
extern void	set_mlx(t_mlx mlx_library, char **argv);
extern void	*xpm_texture(t_mlx mlx_library, char *file);
extern void	free_objects(t_mlx mlx);
extern void	set_walls_as_objects(t_mlx mlx_library);
extern void	set_coins_as_objects(t_mlx mlx_library);
extern void	free_textures(t_mlx mlx, int id);
extern void	set_map_textures(t_mlx mlx);
extern void	create_monsters(t_mlx mlx);
/* ********************* [V] ./SET_MLX/LOAD_TEXTURES [V] ******************** */
extern void	load_textures(t_mlx mlx_library);
extern void	load_player(t_mlx mlx, void *img[TS_PLAYER][TS_PLAYER_ANI], int *z);
extern void	load_monster(t_mlx mlx, void *img[TS_MONSTER][TS_MONSTER_ANI], \
	int *z);
extern void	load_wall(t_mlx mlx_lib, int *z);
extern void	load_coin(t_mlx mlx_lib, void *texture[TS_COIN], int *z);
extern void	load_gate(t_mlx mlx_lib, void *texture[TS_GATE], int *z);
/* ********************* [^] ./SET_MLX/LOAD_TEXTURES [^] ******************** */
/* *************************** [^] ./SET_MLX [^] **************************** */

/****************************************************************************\
|*                        MINILIBX EVENT HOOK LIST                          *|
|****************************************************************************|
|*        02 KeyPress       | 14 NoExpose         | 26 CirculateNotify      *|
|*        03 KeyRelease     | 15 VisibilityNotify | 27 CirculateRequest     *|
|*        04 ButtonPress    | 16 CreateNotify     | 28 PropertyNotify       *|
|*        05 ButtonRelease  | 17 DestroyNotify    | 29 SelectionClear       *|
|*        06 MotionNotify   | 18 UnmapNotify      | 30 SelectionRequest     *|
|*        07 EnterNotify    | 19 MapNotify        | 31 SelectionNotify      *|
|*        08 LeaveNotify    | 20 MapRequest       | 32 ColormapNotify       *|
|*        09 FocusIn        | 21 ReparentNotify   | 33 ClientMessage        *|
|*        10 FocusOut       | 22 ConfigureNotify  | 34 MappingNotify        *|
|*        11 KeymapNotify   | 23 ConfigureRequest | 35 GenericEvent         *|
|*        12 Expose         | 24 GravityNotify    | 36 LASTEvent            *|
|*        13 GraphicsExpose | 25 ResizeRequest    |                         *|
\****************************************************************************/

/****************************************************************************\
|*                        MINILIBX MASK HOOK LIST                           *|
|****************************************************************************|
|*         (0L) NoEventMask            | (1L<<12) Button5MotionMask         *|
|*      (1L<<0) KeyPressMask           | (1L<<13) ButtonMotionMask          *|
|*      (1L<<1) KeyReleaseMask         | (1L<<14) KeymapStateMask           *|
|*      (1L<<2) ButtonPressMask        | (1L<<15) ExposureMask              *|
|*      (1L<<3) ButtonReleaseMask      | (1L<<16) VisibilityChangeMask      *|
|*      (1L<<4) EnterWindowMask        | (1L<<17) StructureNotifyMask       *|
|*      (1L<<5) LeaveWindowMask        | (1L<<18) ResizeRedirectMask        *|
|*      (1L<<6) PointerMotionMask      | (1L<<19) SubstructureNotifyMask    *|
|*      (1L<<7) PointerMotionHintMask  | (1L<<20) SubstructureRedirectMask  *|
|*      (1L<<8) Button1MotionMask      | (1L<<21) FocusChangeMask           *|
|*      (1L<<9) Button2MotionMask      | (1L<<22) PropertyChangeMask        *|
|*     (1L<<10) Button3MotionMask      | (1L<<23) ColormapChangeMask        *|
|*     (1L<<11) Button4MotionMask      | (1L<<24) OwnerGrabButtonMask       *|
\****************************************************************************/

#endif /* SO_LONG_H */