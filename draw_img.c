#include "fdf.h"

void			draw_windows(char *title, int weight, int height, t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, weight, height, title);
}

static void		draw_line_params(t_point *point1, t_point *point2, double *tab)
{
	tab[0] = fabs(point1->x - point2->x);
	tab[1] = point1->x < point2->x ? 1 : -1;
	tab[2] = fabs(point1->y - point2->y);
	tab[3] = point1->y < point2->y ? 1 : -1;
	tab[4] = (tab[0] > tab[2] ? tab[0] : -tab[2]) * 0.5;
}

static void		draw_point(t_point *point, t_mlx *mlx, int color)
{
	int i;

	i = ((int)point->x * 4) + ((int)point->y * mlx->s_line);
	mlx->pixel_img[i] = color;
	mlx->pixel_img[++i] = color >> 8;
	mlx->pixel_img[++i] = color >> 16;
}

static void		draw_line(t_point p1, t_point p2, t_mlx *mlx)
{
	double	tab[6];
	int		state;

	if (!point_out_window(&p1) && !point_out_window(&p2))
		return ;
	draw_line_params(&p1, &p2, tab), state = 1;
	while (state == 1 && !((int)p1.x == (int)p2.x && (int)p1.y == (int)p2.y))
	{
		if (point_out_window(&p1) == 1)
			draw_point(&p1, mlx, get_color(&p1, &p2));
		tab[5] = tab[4];
		state = 0;
		if (tab[5] > -tab[0] && (int)p1.x != (int)p2.x)
		{
			tab[4] -= tab[2];
			p1.x += tab[1];
			state = 1;
		}
		if (tab[5] < tab[2] && (int)p1.y != (int)p2.y)
		{
			tab[4] += tab[0];
			p1.y += tab[3];
			state = 1;
		}
	}
}

void			draw_map(t_mlx *mlx)
{
	int			x;
	int			y;
	t_point		p1;

	y = 0;
	while (y < mlx->map->len)
	{
		x = 0;
		while (x < (mlx->map->lines[y]->len))
		{
			p1 = (*mlx->map->lines[y]->points[x]);
			if (mlx->map->lines[y]->points[x + 1])
				draw_line(p1, (*mlx->map->lines[y]->points[x + 1]), mlx);
			if (mlx->map->lines[y + 1])
				if (mlx->map->lines[y + 1]->points[x] &&
					x <= mlx->map->lines[y + 1]->len)
					draw_line(p1, (*mlx->map->lines[y + 1]->points[x]), mlx);
			x++;
		}
		y++;
	}
}
