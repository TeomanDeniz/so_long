#include <stdio.h>
#include <unistd.h>

typedef unsigned long long	t_fps;

/*
void
	loop(unsigned long long delay_parameter, unsigned long long slower_parameter)
{
	static unsigned long long	real_time;
	static unsigned long long	old_time;
	static unsigned long long	delay_time;
	static unsigned long long	delay_iterator;
	unsigned long long			delta_time;

	old_time = old_time + 0;
	real_time = real_time + 1LL;
	if (!delta_time)
		delay_time = delay_parameter;
	delta_time = real_time - old_time;
	if (delta_time > delay_time)
	{
		old_time = real_time;
		delay_iterator += delay_iterator + 1LL;
		if (delay_time < delay_parameter)
			write(1, "#", 1);
		delay_time += (slower_parameter * delay_iterator) + delay_parameter;
	}
}
*/

double
	ft_lerp(register double x, register double y, register double f)
{
	return (x + f * (y - x));
}

void
	loop(double target_x, t_fps speed)
{
	static double	x = 0.0;
	static t_fps	fps = 0;
	char			string[20] = {32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32};
	register int	ecx;

	if (fps >= speed)
	{
		x = ft_lerp(x, target_x, 0.1);
		string[(long)x] = '#';
		ecx = -1;
		while (++ecx, ecx < 30)
			write(1, "\b", 1);
		ecx = -1;
		while (++ecx, ecx < 20)
			write(1, &string[ecx], 1);
		fps = 0;
	}
	++fps;
}

int
	main(void)
{
	while (1)
		loop(10, 10000000LL);
	return (0);
}
