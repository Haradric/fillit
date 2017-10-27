/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_coords.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 14:45:59 by mbraslav          #+#    #+#             */
/*   Updated: 2017/01/12 14:46:03 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

static	void	calc_coords(t_list *list)
{
	int	i;
	int n;
	int	x0;
	int	y0;

	i = -1;
	n = 0;
	list->x[0] = 0;
	list->y[0] = 0;
	while (list->figure[++i] != '\0')
	{
		if (list->figure[i] == '#')
		{
			if (++n == 1)
			{
				x0 = i % 4;
				y0 = i / 4;
			}
			else
			{
				list->x[n - 1] = (i % 4) - x0;
				list->y[n - 1] = (i / 4) - y0;
			}
		}
	}
}

void			add_coords(t_list *list)
{
	t_list	*first;
	t_list	*last;
	char	current_letter;

	current_letter = 'A';
	first = list;
	last = list;
	first->letter = current_letter;
	calc_coords(first);
	while (last->next != NULL)
	{
		last = last->next;
		current_letter += 1;
		last->letter = current_letter;
		calc_coords(last);
	}
}
