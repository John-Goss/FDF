/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 11:34:27 by jle-quer          #+#    #+#             */
/*   Updated: 2016/09/07 16:26:49 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include "X.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <math.h>

#define w_width 1024
#define w_height 768
#define SIZE_W 20
#define SIZE_H 20

typedef enum		s_bool
{
	false,
	true
}					t_bool;

typedef struct		s_point
{
	double			x;
	double			y;
	double			z;
	double			s;
	int				z_color;
}					t_point;

typedef struct		s_line
{
	t_point			**points;
	int				len;
}					t_line;

typedef struct		s_map
{
	t_line			**lines;
	int				len;
}					t_map;

typedef struct		s_matrice
{
					double a1;
					double a2;
					double a3;
					double a4;
					double b1;
					double b2;
					double b3;
					double b4;
					double c1;
					double c2;
					double c3;
					double c4;
					double d1;
					double d2;
					double d3;
					double d4;
}					t_matrice;

typedef struct		s_img
{
	char			*data;
	void			*p_img;
	int				width;
	int				bpp;
	int				octet;
	int				endian;
	int				max_size;
}					t_img;

typedef struct		s_mlx
{
	char			*nm_window;
	void			*screen;
	void			*window;
	int				width;
	int				height;
	t_point			center;
	t_bool			bool_button_press;
	t_map			*map;
	t_img			*mlx_img;
}					t_mlx;

void		ft_error(int nm_error);
void		fdf_hook(t_mlx *mlx);
void		set_center(t_mlx *mlx);
void		calcul_scale(t_mlx *mlx, double s);
void		calcul_translation(t_mlx *mlx, double x, double y, double z);
void		calcul_rotation(t_mlx *mlx, double rot, char axe);
t_matrice	*ft_matrice_scale(double s);
t_matrice	*ft_matrice_translation(double tx, double ty, double tz);
t_matrice	*ft_matrice_rotation_z(double beta);
t_matrice	*ft_matrice_rotation_y(double beta);
t_matrice	*ft_matrice_rotation_x(double beta);
t_map		*parse_map(char **av, int fd);

#endif
