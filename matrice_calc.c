/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice_calc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 16:12:09 by jle-quer          #+#    #+#             */
/*   Updated: 2016/09/07 16:15:20 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	calcul_matrice(t_point *p, t_matrice *m, t_mlx *mlx)
{
	double tmp_x;
	double tmp_y;
	double tmp_z;

	p->x -= mlx->center.x;
	p->y -= mlx->center.y;
	tmp_x = p->x * m->a1 + p->y * m->a2 + p->z * m->a3 + p->s * m->a4;
	tmp_y = p->x * m->b1 + p->y * m->b2 + p->z * m->b3 + p->s * m->b4;
	tmp_z = p->x * m->c1 + p->y * m->c2 + p->z * m->c3 + p->s * m->c4;
	p->z = tmp_z;
	p->y = tmp_y;
	p->x = tmp_x;
	p->x += mlx->center.x;
	p->y += mlx->center.y;
}

static void	calcul_matrice_points(t_matrice *m, t_mlx *mlx)
{
	int x;
	int y;

	y = 0;
	while (y < mlx->map->len)
	{
		x = 0;
		while (x < (mlx->map->lines[y]->len))
		{
			calcul_matrice(mlx->map->lines[y]->points[x], m, mlx);
			x++;
		}
		y++;
	}
}

void		calcul_rotation(t_mlx *mlx, double rot, char axe)
{
	t_matrice *m_rotation;

	if (axe == 'x')
		m_rotation = ft_matrice_rotation_x(rot);
	else if (axe == 'y')
		m_rotation = ft_matrice_rotation_y(rot);
	else
		m_rotation = ft_matrice_rotation_z(rot);
	calcul_matrice_points(m_rotation, mlx);
	free(m_rotation);
}

void		calcul_translation(t_mlx *mlx, double x, double y, double z)
{
	t_matrice *m_translation;

	m_translation = ft_matrice_translation(x, y, z);
	calcul_matrice_points(m_translation, mlx);
	set_center(mlx);
	free(m_translation);
}

void		calcul_scale(t_mlx *mlx, double s)
{
	t_matrice *m_translation;

	m_translation = ft_matrice_scale(s);
	calcul_matrice_points(m_translation, mlx);
	free(m_translation);
}
