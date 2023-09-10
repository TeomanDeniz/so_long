#include <stdio.h>
#define STONE_IN_SEA_AMOUNT 10 // %

/* ******************************* PROTOTYPES ******************************* */
static inline char	set_texture_type2(unsigned char x);
/* ******************************* PROTOTYPES ******************************* */

int	ft_strlen(const char *const string)
{unsigned int	ecx = 0; while (string[ecx]) ++ecx; return (ecx);}
int	ft_matrixrlen(char **matrix)
{int	ecx = 0; while (matrix[ecx]) ++ecx; return (ecx);}
typedef union s_cast
{const char *ptr; unsigned long long integer;}t_cast;
int	ft_rand(int min, int max)
{static unsigned long address; static int seed; char pointer[8192]; t_cast cast; seed = seed + 0; if (!seed) {cast.ptr = &pointer[seed]; address = cast.integer + ((unsigned long long)__TIME__[0] * (unsigned long long)__TIME__[1] + (unsigned long long)__TIME__[3] * (unsigned long long)__TIME__[4] + (unsigned long long)__TIME__[6]) * (unsigned long long)__TIME__[7];} address = (++seed, (address * 1103515245ULL + 12345ULL) & 0X7FFFFFFF); return (min + (int)((double)address / (0X7FFFFFFF / (max - min + 1))));}
void bit_print(unsigned char byte)
{if (byte & 128) printf("1"); else printf("0"); if ((byte << 1) & 128) printf("1"); else printf("0"); if ((byte << 2) & 128) printf("1"); else printf("0"); printf("\n"); if ((byte << 3) & 128) printf("1"); else printf("0"); printf("@"); if ((byte << 4) & 128) printf("1"); else printf("0"); printf("\n"); if ((byte << 5) & 128) printf("1"); else printf("0"); if ((byte << 6) & 128) printf("1"); else printf("0"); if ((byte << 7) & 128) printf("1"); else printf("0"); printf("\n\n");}


static inline unsigned char
	byte_position(char **map, int x, int y)
{
	unsigned char	result;
	int				max_x;
	int				max_y;

	max_x = ft_strlen(*map);
	max_y = ft_matrixrlen(map);
	result = 0U;
	if (map[y - 1][x - 1] == '#' || (x == 0 || y == 0))
		result += 128U;
	if (map[y - 1][x] == '#' || (y == 0))
		result += 64U;
	if (map[y - 1][x + 1] == '#' || (x == max_x || y == 0))
		result += 32U;
	if (map[y][x - 1] == '#' || (x == 0))
		result += 16U;
	if (map[y][x + 1] == '#' || (x == max_x))
		result += 8U;
	if (map[y + 1][x - 1] == '#' || (x == 0 || y == max_y))
		result += 4U;
	if (map[y + 1][x] == '#' || (y == max_y))
		result += 2U;
	if (map[y + 1][x + 1] == '#' || (x == max_x || y == max_y))
		result += 1U;
	return (result);
}

static inline char
	set_texture_type(unsigned char x)
{
	if (x == 255U && (ft_rand(0, 99) > STONE_IN_SEA_AMOUNT))
		return (8);
	if (x == 255U || x == 126U || x == 219U || x == 95U || x == 123U \
		|| x == 222U || x == 250U || x == 94U || x == 91U || x == 122U \
		|| x == 218U || x == 90U)
		return (14);
	if (x == 127U)
		return (3);
	if (x == 223U)
		return (2);
	if (x == 251U)
		return (1);
	if (x == 254U)
		return (0);
	if (x == 208U)
		return (12);
	if (x == 104U)
		return (10);
	if (x == 22U)
		return (6);
	if (x == 11U)
		return (4);
	else
		return (set_texture_type2(x));
}

static inline char
	set_texture_type2(unsigned char x)
{
	if (x == 31U || x == 159U || x == 63U || x == 191U)
		return (5);
	if (x == 107U || x == 235U || x == 111U || x == 239U)
		return (7);
	if (x == 214U || x == 246U || x == 215U || x == 247U)
		return (9);
	if (x == 248U || x == 252U || x == 249U || x == 253U)
		return (11);
	else
		return (13);
}

int
	main(void)
{
	unsigned char   byte;
	char	*map[1000] = {
		"#########",
		"####    #",
		"####### #",
		"#     # #",
		"##### # #",
		"#       #",
		"####### #",
		"#       #",
		"#########"
	};

	byte = byte_position(map, 1, 0);
	bit_print(byte);
	printf("[%d] - %d\n", byte, set_texture_type(byte));

	return (0);
}
