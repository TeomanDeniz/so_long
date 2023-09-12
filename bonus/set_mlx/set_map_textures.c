/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:12:46 by hdeniz            #+#    #+#             */
/*   Updated: 2023/08/23 14:12:47 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [V] INCLUDES [V] **************************** */
#include "../so_long.h" /*
# define STONE_IN_SEA_AMOUNT ?
#typedef t_mlx;
*/
#include "../../libft/libft.h" /*
#    int ft_matrixrlen(char **);
#    int ft_strlen(char *);
*/
#include "../../libft/ft_math/ft_math.h" /*
#    int ft_mini(int, int);
*/
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [V] PROTOTYPES [V] *************************** */
static inline unsigned char	byte_position(char **map, int x, int y);
static inline char			set_texture_type(unsigned char x);
static inline char			set_texture_type2(unsigned char x);
static inline int				zer(int input);
/* *************************** [^] PROTOTYPES [^] *************************** */

/*****************************************************************************\
|*                                                                           *|
|*                             12345678 = 1 Byte ---*                        *|
|*                                                  | 1 Byte 8 bits          *|
|*                         *---  123 4 # 5 678  <---*                        *|
|*  Let's think middle is  |                                                 *|
|*  already a wall...      |          123                                    *|
|*                         *------->  4#5  ----*     ###################     *|
|*                                    678      |     #  # ########  E  #     *|
|*                                             |     #     #####  #    #     *|
|*                                    110      |     #  P    ##@     # #     *|
|* For example, we have     *-------  1 0  <---*     #              C  #     *|
|*  a map like that:        |         000            ###################     *|
|* ###################      |                                                *|
|* #  # ########  E  #      *--->  1101 0000 = 208U  ###################     *|
|* #     #####  #    #                               #  # ########  E  #     *|
|* #  P    ###     # #                               #     ###**. #    #     *|
|* #              C  #                               #  P    #*@.    # #     *|
|* ###################                               #        ...   C  #     *|
|*                                                   ###################     *|
|*                                                                           *|
\*****************************************************************************/

void
	set_map_textures(t_mlx mlx)
{
	register int	ecx;

	ecx = -1;
	while (++ecx, mlx->object.number_of_walls > ecx)
	{
		mlx->object.wall[ecx].byte_position = byte_position(mlx->map, \
			mlx->object.wall[ecx].x, mlx->object.wall[ecx].y);
		mlx->object.wall[ecx].texture_type = set_texture_type(\
			mlx->object.wall[ecx].byte_position);
	}
}

static inline unsigned char
	byte_position(char **map, int x, int y)
{
	unsigned char	result;
	int				max_x;
	int				max_y;

	max_x = ft_strlen(*map) - 1;
	max_y = ft_matrixrlen(map) - 1;
	result = 0U;
	if (map[zer(y - 1)][zer(x - 1)] == '1' || (x == 0 || y == 0))
		result += 128U;
	if (map[zer(y - 1)][x] == '1' || (y == 0))
		result += 64U;
	if (map[zer(y - 1)][ft_mini(x + 1, max_x)] == '1' || (x == max_x || y == 0))
		result += 32U;
	if (map[y][zer(x - 1)] == '1' || (x == 0))
		result += 16U;
	if (map[y][ft_mini(x + 1, max_x)] == '1' || (x == max_x))
		result += 8U;
	if (map[ft_mini(y + 1, max_y)][zer(x - 1)] == '1' || (x == 0 || y == max_y))
		result += 4U;
	if (map[ft_mini(y + 1, max_y)][x] == '1' || (y == max_y))
		result += 2U;
	if (map[ft_mini(y + 1, max_y)][ft_mini(x + 1, max_x)] == '1' || \
		(x == max_x || y == max_y))
		result += 1U;
	return (result);
}

static inline char
	set_texture_type(unsigned char x)
{
	if (x == 255U && (ft_rand(0, 99) < STONE_IN_SEA_AMOUNT))
		return (14);
	if (x == 255U)
		return (8);
	if (x == 127U)
		return (3);
	if (x == 223U)
		return (2);
	if (x == 251U)
		return (1);
	if (x == 254U)
		return (0);
	if ((x & 31U) == 31U)
		return (5);
	if ((x & 107U) == 107U)
		return (7);
	if ((x & 214U) == 214U)
		return (9);
	if ((x & 248U) == 248U)
		return (11);
	else
		return (set_texture_type2(x));
}

static inline char
	set_texture_type2(unsigned char x)
{
	if ((x & 219U) == 219U)
		return (16);
	if ((x & 126U) == 126U)
		return (15);
	if ((x & 208U) == 208U)
		return (12);
	if ((x & 104U) == 104U)
		return (10);
	if ((x & 22U) == 22U)
		return (6);
	if ((x & 11U) == 11U)
		return (4);
	else
		return (13);
}

static inline int
	zer(int input)
{
	if (input < 0)
		return (0);
	return (input);
}
