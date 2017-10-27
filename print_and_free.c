/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_and_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 14:48:54 by mbraslav          #+#    #+#             */
/*   Updated: 2017/01/12 14:48:57 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_and_free(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		ft_putstr(map[i++]);
		ft_putchar('\n');
	}
	free_map(map);
}
