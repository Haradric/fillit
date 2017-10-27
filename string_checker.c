/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 14:53:20 by mbraslav          #+#    #+#             */
/*   Updated: 2017/01/12 14:53:23 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

static	void	rules1and3(const char *str)
{
	int		i;
	int		x;
	char	*s;

	i = 0;
	s = (char *)str;
	while (s[i] != '\0')
	{
		if (i == 20 && ((s[i] == '\0') || (s[i] == '\n')))
		{
			i = 0;
			s += 21;
			continue;
		}
		if (i == 20 && s[i] != '\n')
			exit_msg();
		x = (i % 5) + 1;
		if ((x == 5) && s[i] != '\n')
			exit_msg();
		if ((x != 5) && (s[i] != '#' && s[i] != '.'))
			exit_msg();
		i++;
	}
	if (i != 20)
		exit_msg();
}

static	void	rule2(const char *str)
{
	int		i;
	int		blocks;
	char	*s;

	i = 0;
	blocks = 0;
	s = (char *)str;
	while (s[i] != '\0')
	{
		if (i == 20)
		{
			if (blocks < 4)
				exit_msg();
			i = 0;
			blocks = 0;
			s += 21;
			continue;
		}
		if (s[i] == '#')
			blocks++;
		if (blocks > 4)
			exit_msg();
		i++;
	}
}

static	void	ihate25stringsrule(int i, char *s, int *connections)
{
	if (s[i] == '#' && (i - 5 >= 0) && s[i - 5] == '#')
		*connections += 1;
	if (s[i] == '#' && (i + 5 <= 20) && s[i + 5] == '#')
		*connections += 1;
	if (s[i] == '#' && (i - 1 >= 0) && s[i - 1] == '#')
		*connections += 1;
	if (s[i] == '#' && (i + 1 >= 0) && s[i + 1] == '#')
		*connections += 1;
}

static	void	rule4(const char *str)
{
	int		i;
	int		connections;
	char	*s;

	i = 0;
	connections = 0;
	s = (char *)str;
	while (s[i] != '\0')
	{
		if (i == 20)
		{
			s += i + 1;
			i = 0;
			connections = 0;
			continue;
		}
		while (i < 19)
			ihate25stringsrule(i++, s, &connections);
		(connections == 6 || connections == 8) ? i++ : exit_msg();
	}
}

int				check_str(const char *str)
{
	rules1and3(str);
	rule2(str);
	rule4(str);
	return (1);
}
