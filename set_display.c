/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 12:18:26 by jle-quer          #+#    #+#             */
/*   Updated: 2016/09/07 12:43:56 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_center(t_mlx *mlx)
{
	t_point	p;
	int		yl;
	int		xl;

	p = mlx->center;
	yl = mlx->map->len;
	xl = mlx->map->lines[yl - 1]->len;
	p.x = (mlx->map->lines[yl - 1]->points[xl - 1]->x +
			mlx->map->lines[0]->points[0]->x) / 2;
	p.y = (mlx->map->lines[yl - 1]->points[xl - 1]->y +
			mlx->map->lines[0]->points[0]->y) / 2;
	mlx->center = p;
}

void	set_map(t_mlx *mlx)
{
	int		width;
	int		height;
	double	s;

	width = (w_width + 100) / 2;
	height = (w_height + 100) / 2;
}
