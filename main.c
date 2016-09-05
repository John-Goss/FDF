/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/31 11:58:30 by jle-quer          #+#    #+#             */
/*   Updated: 2016/09/05 16:17:36 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_new_image(t_mlx *mlx)
{
	t_img	*img;
	void	*data;

	if (!(img = (t_img *)malloc(sizeof(t_img))))
		return ;
	img->endian = 0;
	img->width = mlx->width;
	img->p_img = mlx_new_image(mlx->screen, mlx->width, mlx->height);
	if (!img->p_img)
		return ;
	data = mlx_get_data_addr(img->p_img, &img->bpp, &img->width, &img->endian);
	img->octet = img->bpp / 8;
	img->data = data;
	mlx->mlx_img = img;
	mlx->mlx_img->max_size = img->octet * mlx->width * mlx->height;
}

static t_mlx	*fdf_mlx_init(int width, int height, char *name)
{
	t_mlx	*mlx;

	if (!(mlx = (t_mlx *)malloc(sizeof(t_mlx))))
		return (NULL);
	mlx->width = width;
	mlx->height = height;
	mlx->screen = mlx_init();
	mlx->window = mlx_new_window(mlx->screen, mlx->width, mlx->height, name);
	ft_new_image(mlx);
	return (mlx);
}

int				main(void)
{
	t_mlx		*mlx;

	mlx = NULL;
	mlx = fdf_mlx_init(w_width, w_height, "FDF");
	fdf_hook(mlx);
	mlx_loop(mlx->screen);
	return (0);
}
