/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_in_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:10:27 by hdeniz            #+#    #+#             */
/*   Updated: 2023/08/22 17:10:29 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int
	count_in_map(char **map, char object)
{
	register int	x;
	register int	y;
	unsigned int	ecx;

	y = -1;
	ecx = 0;
	while (++y, map[y])
	{
		x = -1;
		while (++x, map[y][x])
			if (map[y][x] == object)
				++ecx;
	}
	return ((signed int)ecx);
}
