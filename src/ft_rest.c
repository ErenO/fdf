/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 10:49:01 by eozdek            #+#    #+#             */
/*   Updated: 2016/04/30 20:01:43 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error(char *str)
{
	write(2, str, ft_strlen(str));
	write(1, "\n", 1);
	exit(0);
}

int		words(char *s, t_env *e)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	(void)e;
	while (s[i])
	{
		while (s[i] == ' ')
			i++;
		if (s[i] != ' ' && s[i])
		{
			while (s[i] != ' ' && s[i])
				i++;
			j++;
		}
	}
	return (j);
}

void	ft_handle_line(t_env *e, char **tab)
{
	int		i;
	int		j;
	int		n;
	char	**tab1;

	i = 0;
	e->bat = (int**)malloc(sizeof(int*) * (e->l));
	while (i < e->l)
	{
		n = words(tab[i], e);
		j = 0;
		tab1 = ft_strsplit(tab[i], ' ');
		e->bat[i] = (int *)malloc(sizeof(int) * (n));
		while (j < n)
		{
			e->bat[i][j] = ft_atoi(tab1[j]);
			j++;
		}
		if ((i > 0 && j == e->c) || i == 0)
			e->c = j;
		else
			error("Found wrong line length. Exiting.");
		i++;
	}
}

void	ft_draw_line(t_env *e)
{
	int i;
	int j;

	i = 0;
	j = 0;
	e->y1 = 0;
	e->y2 = 0;
	while (i < e->l)
	{
		e->x1 = 0;
		e->x2 = e->zoom;
		j = 0;
		while (j < e->c - 1)
		{
			draw(e, i, j, 1);
			e->x1 = e->x1 + e->zoom;
			e->x2 = e->x2 + e->zoom;
			j++;
		}
		e->y1 = e->y1 + e->zoom;
		e->y2 = e->y2 + e->zoom;
		i++;
	}
}

void	ft_draw_column(t_env *e)
{
	int i;
	int j;

	i = 0;
	j = 0;
	e->x1 = 0;
	e->x2 = 0;
	while (i < e->c)
	{
		j = 0;
		e->y1 = 0;
		e->y2 = e->zoom;
		while (j < e->l - 1)
		{
			draw(e, i, j, 2);
			e->y1 = e->y1 + e->zoom;
			e->y2 = e->y2 + e->zoom;
			j++;
		}
		e->x1 = e->x1 + e->zoom;
		e->x2 = e->x2 + e->zoom;
		i++;
	}
}
