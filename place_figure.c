/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_figure.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 14:48:40 by mbraslav          #+#    #+#             */
/*   Updated: 2017/01/12 14:48:44 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		check(char **map, int size, int *cord, t_list *list)
{
	int	i;
	int	x;
	int	y;
	int	x0;
	int	y0;

	i = 0;
	x0 = cord[0];
	y0 = cord[1];
	while (i < 4)
	{
		x = list->x[i] + x0;
		y = list->y[i] + y0;
		if (x < 0 || y < 0 || x >= size || y >= size)
			return (0);
		if (map[y][x] != '.')
			return (0);
		i++;
	}
	return (1);
}

static void		place(char **map, int *cord, t_list *list)
{
	int	i;
	int	x;
	int	y;
	int	x0;
	int	y0;

	i = 0;
	x0 = cord[0];
	y0 = cord[1];
	while (i < 4)
	{
		x = list->x[i] + x0;
		y = list->y[i] + y0;
		map[y][x] = list->letter;
		i++;
	}
}

int				place_figure(char **map, int size, int *cord, t_list *list)
{
	if (check(map, size, cord, list))
	{
		place(map, cord, list);
		return (1);
	}
	return (0);
}
