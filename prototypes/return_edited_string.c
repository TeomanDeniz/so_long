#include <stdio.h>

int
	main(void)
{
	register int	x;

	x = -1;
	while (++x, x < 16)
		printf("This is a string -> %s\n",

			(char [32]){
					'.', '/', 't', 'e', 'x', 't', 'u', 'r', 'e', 's', '/', 'x',
					'p', 'm', '/', 'b', 'a', 'r', 'r', 'i', 'e', 'r', '/',
					!!(x / 10) * (48 + x / 10) + !(x / 10) * (48 + x % 10),
					!!(x / 10) * ('0' + x % 10) + !(x / 10) * '/',
					!!(x / 10) * '/' + !(x / 10) * '0',
					!!(x / 10) * '0' + !(x / 10) * '.',
					!!(x / 10) * '.' + !(x / 10) * 'x',
					!!(x / 10) * 'x' + !(x / 10) * 'p',
					!!(x / 10) * 'p' + !(x / 10) * 'm',
					!!(x / 10) * 'm' + 0, 0}

		); // Can count till 99
	return (0);
}
