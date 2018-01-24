/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 15:44:01 by eozdek            #+#    #+#             */
/*   Updated: 2016/04/30 20:37:58 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	free_e(t_env *e)
{
	free(e->bat);
}

static void	env_init(t_env *e)
{
	e->l = 0;
	e->i = 0;
	e->n = 0;
	e->zoom = 25;
	e->kekette = 3;
	e->h = 0;
	e->color_put = 0;
	e->x1 = 0;
	e->x2 = 0;
	e->y1 = 0;
	e->col = 0;
	e->lin = 0;
	e->y2 = 0;
	e->z = 0;
	e->v = 0;
	e->rotation = 0;
	e->color = 0xFFFFFF;
}

int			main(int argc, char **argv)
{
	t_env	e;
	int		fd;

	fd = 0;
	env_init(&e);
	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			error("Open failed");
		ft_read(fd, &e, argv[1]);
		e.mlx = mlx_init();
		e.win = mlx_new_window(e.mlx, H, L, "mlx 42");
		mlx_mouse_hook(e.win, mouse_hook, &e);
		mlx_hook(e.win, 2, 0, my_key_funct, &e);
		ft_draw_line(&e);
		ft_draw_column(&e);
		mlx_expose_hook(e.win, expose_hook, &e);
		mlx_loop(e.mlx);
		free_e(&e);
	}
	else
		error("Usage : ./fdf <filename> [ case_size z_size ]");
	return (0);
}
