/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 14:51:53 by mbraslav          #+#    #+#             */
/*   Updated: 2017/01/12 14:52:32 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

static	int		min_size(t_list *list)
{
	int		len;
	int		size;
	t_list	*listcpy;

	len = 0;
	size = 2;
	listcpy = list;
	while (listcpy != NULL)
	{
		listcpy = listcpy->next;
		len++;
	}
	while (size * size < len * 4)
		size++;
	return (size);
}

static char		**map_init(int size)
{
	char	**map;
	int		i;

	i = 0;
	map = (char **)malloc(sizeof(char *) * size + 1);
	while (i < size)
	{
		map[i] = ft_strnew(size);
		ft_memset(map[i], '.', size);
		i++;
	}
	map[i] = NULL;
	return (map);
}

static char		**delete_figure(t_list *list, char **map, int size)
{
	int i;
	int j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			if (map[i][j] == list->letter)
				map[i][j] = '.';
		}
	}
	return (map);
}

int				solve(t_list *list, char **map, int size)
{
	int		i;
	int		j;
	int		cord[2];
	t_list	*new_list;

	i = -1;
	while (++i < size)
	{
		if (list == NULL)
			return (1);
		j = -1;
		while (++j < size)
		{
			cord[0] = j;
			cord[1] = i;
			if (place_figure(map, size, cord, list))
			{
				new_list = list->next;
				if (solve(new_list, map, size))
					return (1);
				map = delete_figure(list, map, size);
			}
		}
	}
	return (0);
}

char			**pre_solve(t_list *list, int size)
{
	char **map;

	size = min_size(list);
	map = map_init(size);
	while (!solve(list, map, size))
	{
		size = size + 1;
		map = map_init(size);
	}
	return (map);
}
