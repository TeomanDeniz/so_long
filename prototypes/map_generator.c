// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void
	ft_free_matrix(char **matrix)
{
	register int	y;

	y = -1;
	while (++y, matrix[y])
		free(matrix[y]);
	free(matrix);
}

typedef union s_cast
{
	const char			*ptr;
	unsigned long long	integer;
}				t_cast;

int
	ft_rand(int min, int max)
{
	static unsigned long	address;
	static int				seed;
	char					pointer[8192];
	t_cast					cast;

	seed = seed + 0;
	if (!seed)
	{
		cast.ptr = &pointer[seed];
		address = cast.integer + \
			((unsigned long long)__TIME__[0] \
			* (unsigned long long)__TIME__[1] \
			+ (unsigned long long)__TIME__[3] \
			* (unsigned long long)__TIME__[4] \
			+ (unsigned long long)__TIME__[6]) \
			* (unsigned long long)__TIME__[7];
	}
	address = (++seed, (address * 1103515245ULL + 12345ULL) & 0X7FFFFFFF);
	return (min + (int)((double)address / (0X7FFFFFFF / (max - min + 1))));
}

int
	ft_strlen(const char *const string)
{
	unsigned int	ecx;

	ecx = 0;
	while (string[ecx])
		++ecx;
	return (ecx);
}

void
	ft_print_matrix(char **matrix)
{
	register int	x;
	register int	y;

	y = -1;
	while (++y, matrix[y])
	{
		x = -1;
		while (++x, matrix[y][x])
			write(1, &matrix[y][x], 1);
		write(1, "\n", 1);
	}
	write(1, "\n", 1);
}

static inline void
	fill_with_ground(char **map, int map_x, int map_y)
{
	register int	x;
	register int	y;

	y = -1;
	while (++y, y < map_y)
	{
		map[y] = (char *)malloc((sizeof(char) * map_x) + 1);
		x = -1;
		while (++x, x < map_x)
			map[y][x] = '0';
		map[y][map_x] = 0;
	}
}

static inline void
	draw_the_walls_around(char **map, int map_y)
{
	register int	x;
	register int	y;
	register int	max;

	max = ft_strlen(map[0]);
	y = -1;
	while (++y, map[y])
	{
		x = -1;
		while (++x, map[y][x])
		{
			if (((y == (map_y - 1)) || (y == 0)) || (x == (max - 1) || x == 0))
				map[y][x] = '1';
		}
	}
}

static inline void
	put_objects(char **map, int map_x, int map_y)
{
	char			object[3];
	register int	ecx;
	register int	x;
	register int	y;

	object[0] = 'C';
	object[1] = 'P';
	object[2] = 'E';
	ecx = 0;
	while (ecx < 3)
	{
		x = ft_rand(1, map_x - 2);
		y = ft_rand(1, map_y - 2);
		if (map[y][x] == '0')
		{
			map[y][x] = object[ecx];
			++ecx;
		}
	}
}

static inline void
	put_walls(char **map)
{
	register int	x;
	register int	y;

	y = -1;
	while (++y, map[y])
	{
		x = -1;
		while (++x, map[y][x])
		{
			if (map[y][x] == '0' && (ft_rand(0, 99) < 10))
				map[y][x] = '1';
			else if (map[y][x] == '0' && (ft_rand(0, 99) < 1))
				map[y][x] = 'C';
		}
	}
}

int
	main(void)
{
	register int	map_x;
	register int	map_y;
	char **map;

	map_x = ft_rand(10, 30);
	map_y = ft_rand(10, 30);
	printf("x = %d y = %d\n", map_x, map_y);
	map = (char **)malloc(sizeof(char *) * map_y + 1);

	fill_with_ground(map, map_x, map_y);
	draw_the_walls_around(map, map_y);
	put_objects(map, map_x, map_y);
	put_walls(map);
	ft_print_matrix(map);
	ft_free_matrix(map);
	return (0);
}