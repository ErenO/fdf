/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 07:59:18 by eozdek            #+#    #+#             */
/*   Updated: 2016/04/30 20:21:30 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <math.h>
# include "../libft/includes/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# define H 1000
# define L 1000
# define ABS(v) ((v) < 0 ? -(v) : (v))

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	float		x1;
	float		y1;
	float		x2;
	float		y2;
	int			i;
	int			l;
	float		z;
	int			c;
	float		rotation;
	int			n;
	int			h;
	int			lin;
	int			col;
	int			color_put;
	int			v;
	int			color;
	float		zoom;
	int			*ret;
	int			**bat;
	float		kekette;
}				t_env;

void			handle_color(t_env *e, int x, int y);
void			draw_1(t_env *e, float tab[2], int x, int y);
void			draw_2(t_env *e, float tab[2], int x, int y);
void			ft_rotation(t_env *e, float tab[4]);
void			ft_draw_column(t_env *e);
void			ft_draw_line(t_env *e);
void			ft_draw(t_env *e);
void			error(char *str);
char			**ft_malloc(int j, char **tab);
int				expose_hook(t_env *e);
int				my_key_funct(int keycode, t_env *e);
int				mouse_hook(int button, int x, int y, t_env *e);
void			ft_read(int fd, t_env *e, char *av);
int				words(char *s, t_env *e);
void			draw(t_env *e, int i, int j, int c);
void			ft_handle_line(t_env *e, char **tab);

#endif
