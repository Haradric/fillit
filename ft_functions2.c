/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 14:47:49 by mbraslav          #+#    #+#             */
/*   Updated: 2017/01/12 14:47:52 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;

	str = (unsigned char *)b;
	while (len--)
		*str++ = (unsigned char)c;
	return (b);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)dst;
	str2 = (unsigned char *)src;
	while (n > 0)
	{
		*str1++ = *str2++;
		n--;
	}
	return (dst);
}

void	*ft_memalloc(size_t size)
{
	void	*p;

	p = malloc(size);
	if (p == NULL)
		return (NULL);
	else
	{
		ft_bzero(p, size);
		return (p);
	}
}

char	*ft_strnew(size_t size)
{
	char	*str;
	char	*res;

	str = ft_memalloc(size + 1);
	if (str == NULL)
		return (NULL);
	res = str;
	*(str + size) = '\0';
	while (*str)
		*str++ = '\0';
	return (res);
}
