/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 15:46:30 by eozdek            #+#    #+#             */
/*   Updated: 2016/04/30 20:27:25 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_key1(int keycode, t_env *e)
{
	if (keycode == 88)
	{
		e->kekette = 3;
		e->rotation = 0;
		e->zoom = 25;
	}
	if (keycode == 83)
		e->color_put = 1;
	if (keycode == 84)
		e->color_put = 2;
	if (keycode == 85)
		e->color_put = 3;
	if (keycode == 86)
		e->color_put = 4;
	if (keycode == 87)
		e->color_put = 5;
	e->zoom = (keycode == 89) ? 5 : e->zoom;
	e->rotation = (keycode == 89) ? 0 : e->rotation;
	e->kekette = (keycode == 89) ? 1 : e->kekette;
}

static void	ft_key(int keycode, t_env *e)
{
	e->i++;
	if (e->i % 2 == 1 && keycode == 49)
	{
		mlx_string_put(e->mlx, e->win, 10, 10, 0xFF0000, "Menu :");
		mlx_string_put(e->mlx, e->win, 10, 30,
		0x1d7e94, "=: Augmenter la hauteur");
		mlx_string_put(e->mlx, e->win, 10, 50,
		0x1d7e94, "/: Baisser la hauteur");
		mlx_string_put(e->mlx, e->win, 10, 70, 0x1d7e94, "+: Zoomer");
		mlx_string_put(e->mlx, e->win, 10, 90, 0x1d7e94, "-: Dezoomer");
		mlx_string_put(e->mlx, e->win, 10, 110, 0x1d7e94,
		"Haut-Bas-Gauche-Droite: Deplacement");
		mlx_string_put(e->mlx, e->win, 10, 130, 0x1d7e94,
			"NUM 1-2-3-4: Choix de la couleur");
		mlx_string_put(e->mlx, e->win, 10, 150, 0x1d7e94,
			"6: Position rapprochee");
		mlx_string_put(e->mlx, e->win, 10, 170, 0x1d7e94,
			"7: Position basique");
		mlx_string_put(e->mlx, e->win, 10, 190, 0x1d7e94, "8: Hauteur a zero");
		mlx_string_put(e->mlx, e->win, 10, 210, 0x1d7e94, "9: Rotation a zero");
		mlx_string_put(e->mlx, e->win, 10, 230, 0x1d7e94,
		"Clic gauche-droit: rotation");
	}
}

int			my_key_funct(int keycode, t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	if (keycode == 53)
		exit(0);
	e->zoom += keycode == 69 ? 1 : 0;
	e->zoom -= keycode == 78 ? 1 : 0;
	e->kekette += keycode == 81 ? 1 : 0;
	e->kekette -= keycode == 75 ? 1 : 0;
	e->rotation = (keycode == 92) ? 0 : e->rotation;
	e->kekette = (keycode == 91) ? 0 : e->kekette;
	e->h -= (keycode == 123) ? 10 : 0;
	e->h += (keycode == 124) ? 10 : 0;
	e->v -= (keycode == 126) ? 10 : 0;
	e->v += (keycode == 125) ? 10 : 0;
	ft_key(keycode, e);
	ft_key1(keycode, e);
	ft_draw_line(e);
	ft_draw_column(e);
	return (0);
}

int			mouse_hook(int button, int x, int y, t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	(void)e;
	if (button == 1)
	{
		e->rotation = (e->rotation - (M_PI / 40));
	}
	if (button == 2)
	{
		e->rotation = (e->rotation + (M_PI / 40));
	}
	(void)x;
	(void)y;
	ft_draw_line(e);
	ft_draw_column(e);
	return (0);
}

int			expose_hook(t_env *e)
{
	ft_draw_line(e);
	ft_draw_column(e);
	return (0);
}
