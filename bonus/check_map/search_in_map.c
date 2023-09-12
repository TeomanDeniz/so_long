/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_in_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:14:02 by hdeniz            #+#    #+#             */
/*   Updated: 2023/08/22 16:14:03 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int
	search_in_map(char **map, char object, char vector)
{
	register int	x;
	register int	y;

	y = -1;
	while (++y, map[y])
	{
		x = -1;
		while (++x, map[y][x])
			if (map[y][x] == object)
				return (x * (vector == 'X') + y * (vector == 'Y'));
	}
	return (0);
}
