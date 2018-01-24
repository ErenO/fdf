/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 06:20:53 by eozdek            #+#    #+#             */
/*   Updated: 2016/04/30 20:08:05 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			draw_1(t_env *e, float tab[2], int x, int y)
{
	int i;
	int xinc;
	int yinc;
	int cumul;

	i = 1;
	xinc = (tab[0] > 0) ? 1 : -1;
	yinc = (tab[1] > 0) ? 1 : -1;
	tab[0] = ABS(tab[0]);
	tab[1] = ABS(tab[1]);
	cumul = tab[0] / 2;
	while (i <= tab[0])
	{
		x += xinc;
		cumul += tab[1];
		if (cumul >= tab[0])
		{
			cumul -= tab[0];
			y += yinc;
		}
		handle_color(e, x, y);
		i++;
	}
}

void			draw_2(t_env *e, float tab[2], int x, int y)
{
	int i;
	int xinc;
	int yinc;
	int cumul;

	i = 1;
	xinc = (tab[0] > 0) ? 1 : -1;
	yinc = (tab[1] > 0) ? 1 : -1;
	cumul = tab[1] / 2;
	tab[0] = ABS(tab[0]);
	tab[1] = ABS(tab[1]);
	while (i <= tab[1])
	{
		y += yinc;
		cumul += tab[0];
		if (cumul >= tab[1])
		{
			cumul -= tab[1];
			x += xinc;
		}
		handle_color(e, x, y);
		i++;
	}
}

static void		ft_column(t_env *e, float tab[4], int i, int j)
{
	if (j < e->l - 1 && i < e->c)
	{
		e->z = 0.82 * e->bat[j][i] * e->kekette;
		e->z = e->z != 0 ? e->z : (0.82 * e->bat[j + 1][i] * e->kekette);
	}
	e->z = e->kekette == 0 ? 0 : e->z;
	tab[0] = H / 4 + (0.71 * (e->x1 - e->y1)) + e->h;
	tab[1] = H / 4 + (0.71 * (e->x2 - e->y2)) + e->h;
	tab[2] = H / 4 + ((0.41 * (e->x1 + e->y1) - (0.82 * e->bat[j][i]
	* e->kekette))) + e->v;
	tab[3] = H / 4 + ((0.41 * (e->x2 + e->y2) - (0.82 * e->bat[j + 1][i]
	* e->kekette))) + e->v;
	ft_rotation(e, tab);
}

static void		ft_line(t_env *e, float tab[4], int i, int j)
{
	if (i < e->l - 1 && j < e->c)
	{
		e->z = 0.82 * e->bat[i][j + 1];
		e->z = e->z != 0 ? e->z : e->bat[i][j];
	}
	e->z = e->kekette == 0 ? 0 : e->z;
	tab[0] = H / 4 + (0.71 * (e->x1 - e->y1)) + e->h;
	tab[1] = H / 4 + (0.71 * (e->x2 - e->y2)) + e->h;
	tab[2] = H / 4 + ((0.41 * (e->x1 + e->y1) - (0.82 * e->bat[i][j]
	* e->kekette))) + e->v;
	tab[3] = H / 4 + ((0.41 * (e->x2 + e->y2) - (0.82 * e->bat[i][j + 1]
	* e->kekette))) + e->v;
	ft_rotation(e, tab);
}

void			draw(t_env *e, int i, int j, int c)
{
	float tab[4];

	e->z = 0;
	if (c == 1)
	{
		ft_line(e, tab, i, j);
	}
	if (c == 2)
	{
		ft_column(e, tab, i, j);
	}
}
