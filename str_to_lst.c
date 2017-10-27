/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 14:53:04 by mbraslav          #+#    #+#             */
/*   Updated: 2017/01/12 14:53:07 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

static	void	split_str(char *figure, const char *str)
{
	char	*s;
	int		i;

	i = 0;
	s = (char *)str;
	while (i < 16)
	{
		if (*s != '\n')
			*(figure + i++) = *s;
		s++;
	}
}

static t_list	*lstnew(const char *str)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (list == NULL)
		exit_msg();
	list->figure[16] = '\0';
	split_str(list->figure, str);
	list->next = NULL;
	return (list);
}

t_list			*str_to_lst(const char *str)
{
	t_list	*list;
	t_list	*last;
	char	*s;

	s = (char *)str;
	list = lstnew(s);
	last = list;
	while (*(s + 20) != '\0')
	{
		s += 21;
		last->next = lstnew(s);
		last = last->next;
	}
	add_coords(list);
	return (list);
}
