/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 06:10:58 by eozdek            #+#    #+#             */
/*   Updated: 2016/04/30 20:39:12 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	**ft_malloc(int j, char **tab)
{
	tab = (char **)malloc(sizeof(char *) * j);
	return (tab);
}

void	ft_read(int fd, t_env *e, char *av)
{
	int		i;
	int		j;
	char	*line;
	char	**tab;

	i = 0;
	j = 0;
	e->l = 0;
	line = NULL;
	tab = NULL;
	while (get_next_line(fd, &line) == 1)
		e->l++;
	close(fd);
	if ((fd = open(av, O_RDONLY)) == -1)
		error("Open failed");
	tab = ft_malloc(e->l, tab);
	i = 0;
	while (get_next_line(fd, &line) == 1)
	{
		tab[i] = ft_strdup(line);
		free(line);
		line = NULL;
		i++;
	}
	ft_handle_line(e, tab);
}

void	ft_rotation(t_env *e, float tab[4])
{
	float k;
	float tab1[2];

	if (e->rotation != 0)
	{
		k = tab[0];
		tab[0] = -((tab[2] * sin(e->rotation) - k * cos(e->rotation)));
		tab[2] = (k * sin(e->rotation)) + (tab[2] * cos(e->rotation));
		k = tab[1];
		tab[1] = -((tab[3] * sin(e->rotation) - k * cos(e->rotation)));
		tab[3] = (k * sin(e->rotation)) + (tab[3] * cos(e->rotation));
	}
	tab1[0] = (tab[1] - tab[0]);
	tab1[1] = (tab[3] - tab[2]);
	if (ABS(tab1[0]) > ABS(tab1[1]))
		draw_1(e, tab1, tab[0], tab[2]);
	else
		draw_2(e, tab1, tab[0], tab[2]);
}

void	handle_color(t_env *e, int x, int y)
{
	if (e->z != 0 && e->color_put == 1)
		mlx_pixel_put(e->mlx, e->win, x, y, 0x34d252);
	else if (e->z != 0 && e->color_put == 2)
		mlx_pixel_put(e->mlx, e->win, x, y, 0x379470);
	else if (e->z != 0 && e->color_put == 3)
	{
		e->color = e->color + 10;
		mlx_pixel_put(e->mlx, e->win, x, y, e->color);
	}
	else if (e->z != 0 && e->color_put == 4)
		mlx_pixel_put(e->mlx, e->win, x, y, 0xc34242);
	else if (e->z != 0 && e->color_put == 5)
		mlx_pixel_put(e->mlx, e->win, x, y, 0x27b0d5);
	else if (e->z != 0)
	{
		mlx_pixel_put(e->mlx, e->win, x, y, 0x27b0d5);
	}
	else
		mlx_pixel_put(e->mlx, e->win, x, y, 0xFFFFFF);
}
