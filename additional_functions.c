/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 14:46:11 by mbraslav          #+#    #+#             */
/*   Updated: 2017/01/12 14:46:16 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "fillit.h"

void	exit_msg(void)
{
	write(1, "error\n", 6);
	exit(0);
}

void	free_map(char **map)
{
	int i;

	i = 0;
	while (map[i] != NULL)
		free(map[i++]);
	free(map);
}

void	free_lst(t_list *list)
{
	t_list	*last;
	t_list	*next;

	last = list;
	while (last)
	{
		next = last->next;
		free(last);
		last = next;
	}
	list = NULL;
}
