/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 14:48:01 by mbraslav          #+#    #+#             */
/*   Updated: 2017/01/12 14:48:05 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "fillit.h"

static size_t	filelen(char *path)
{
	size_t	len;
	char	buf;
	int		fd;

	len = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		exit_msg();
	while (read(fd, &buf, 1))
		len++;
	close(fd);
	return (len);
}

static char		*file_to_str(char *path)
{
	int		fd;
	char	*str;
	size_t	len;

	len = filelen(path);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		exit_msg();
	str = (char *)malloc(len + 1);
	if (str == NULL)
		exit_msg();
	read(fd, str, len);
	*(str + len) = '\0';
	close(fd);
	return (str);
}

int				main(int argc, char **argv)
{
	char	*str;
	t_list	*list;
	int		size;

	size = 0;
	if (argc == 2)
	{
		str = file_to_str(argv[1]);
		check_str(str);
		list = str_to_lst(str);
		free(str);
		print_and_free(pre_solve(list, size));
		free_lst(list);
	}
	else
		ft_putstr("usage: fillit file\n");
	return (0);
}
