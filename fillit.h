/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 14:46:28 by mbraslav          #+#    #+#             */
/*   Updated: 2017/01/12 14:46:39 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdio.h>

typedef struct		s_list
{
	char			figure[17];
	int				x[4];
	int				y[4];
	char			letter;
	struct s_list	*next;
}					t_list;

void				ft_putchar(char c);
void				ft_putstr(char const *s);

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memalloc(size_t size);
char				*ft_strnew(size_t size);

int					check_str(const char *str);
t_list				*str_to_lst(const char *str);
void				add_coords(t_list *list);
int					solve(t_list *list, char **map, int size);
void				print_and_free(char **map);
char				**pre_solve(t_list *list, int size);
int					place_figure(char **map, int size, int *cord, t_list *list);

void				exit_msg(void);
void				free_map(char **map);
void				free_lst(t_list *list);

#endif
