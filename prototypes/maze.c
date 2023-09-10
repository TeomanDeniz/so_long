#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void
	print_matrix(char **map)
{
	register int	x;
	register int	y;

	y = -1;
	while (++y, map[y])
	{
		x = -1;
		while (++x, map[y][x])
			write(1, &map[y][x], 1);
		write(1, "\n", 1);
	}
	write(1, "\n", 1);
}

unsigned int
	ft_strlen(const char *const string)
{
	unsigned int	ecx;

	ecx = 0;
	while (string[ecx])
		++ecx;
	return (ecx);
}

void
	matrix_converter(char **map)
{
	register int	y;
	register int	x;

	y = -1;
	while (++y, map[y])
	{
		x = -1;
		while (++x, map[y][x])
		{
			if (map[y][x] == '0')
				map[y][x] = ' ';
			if (map[y][x] == '1')
				map[y][x] = '#';
			if (map[y][x] == 'C')
				map[y][x] = ' ';
		}
	}
}

int
	check_player(char **map, char vector)
{
	register unsigned int	x;
	register unsigned int	y;
	register char			player_found;

	y = 0;
	player_found = 0;
	while (map[y] && !player_found)
	{
		x = 0;
		while (map[y][x] && !player_found)
		{
			if (map[y][x] == 'P')
				player_found = 1;
			x += !player_found;
		}
		y += !player_found;
	}
	if (vector == 'x')
		return (x);
	return (y);
}

void
	maze_checker(char **map, int x, int y)
{
	map[y][x] = '.';
	if (map[y + 1][x] == 'E')
		map[y + 1][x] = '.';
	if (map[y - 1][x] == 'E')
		map[y - 1][x] = '.';
	if (map[y][x + 1] == 'E')
		map[y][x + 1] = '.';
	if (map[y][x - 1] == 'E')
		map[y][x - 1] = '.';
	print_matrix(map);
	if (map[y + 1][x] == ' ')
		maze_checker(map, x, y + 1);
	if (map[y - 1][x] == ' ')
		maze_checker(map, x, y - 1);
	if (map[y][x + 1] == ' ')
		maze_checker(map, x + 1, y);
	if (map[y][x - 1] == ' ')
		maze_checker(map, x - 1, y);
}

static inline void
	free_matrix(char **matrix)
{
	register int	ecx;

	ecx = -1;
	while (++ecx, matrix[ecx])
		free(matrix[ecx]);
	free(matrix);
}

static inline char
	**copy_matrix(char **map)
{
	register int	ecx;
	register int	eax;
	char			**result;

	ecx = 0;
	while (map[ecx])
		++ecx;
	result = (char **)malloc(sizeof(char *) * (ecx + 1));
	if (!result)
		return (NULL);
	ecx = -1;
	while (++ecx, map[ecx])
	{
		result[ecx] = (char *)malloc(sizeof(char) * \
			(ft_strlen(map[0] + 1)));
		if (!result[ecx])
		{
			free(result);
			return (NULL);
		}
		eax = -1;
		while (++eax, map[ecx][eax])
			result[ecx][eax] = map[ecx][eax];
	}
	return (result);
}

int
	labyrinth_ai(char **map, char **analyzer)
{
	register int	x;
	register int	y;

	y = -1;
	while (++y, map[y])
	{
		x = -1;
		while (++x, map[y][x])
		{
			if (map[y][x] == 'E' && analyzer[y][x] == 'E')
				return (0);
		}
	}
	return (1);
}

int
	main(void)
{
	char	**analyzer;
	int		result;
	char	*labyrinth[1000] = {
		"111111111",
		"100000001",
		"101111101",
		"1P0000101",
		"111110101",
		"100000101",
		"111111101",
		"1E0000001",
		"111111111"
	};

	analyzer = copy_matrix(labyrinth);
	matrix_converter(analyzer);
	maze_checker(analyzer, check_player(labyrinth, 'x'), check_player(labyrinth, 'y'));
	result = labyrinth_ai(labyrinth, analyzer);
	if (result)
		write(1, "MAP IS FINISHABLE\n", 18);
	else
		write(1, "MAP IS NOT FINISHABLE\n", 22);
	free_matrix(analyzer);
	return (0);
}