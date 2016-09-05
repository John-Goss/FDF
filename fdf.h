#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include "X.h"
# include <math.h>

#define w_width 1024
#define w_height 768

typedef enum		s_bool
{
	false,
	true
}					t_bool;

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
	t_bool			bool_button_press;
	t_img			*mlx_img;
}					t_mlx;

void	fdf_hook(t_mlx *mlx);

#endif
