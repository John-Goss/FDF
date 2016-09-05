/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 16:14:46 by jle-quer          #+#    #+#             */
/*   Updated: 2016/09/05 16:18:35 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	key_fcnt(int keycode, t_mlx *param)
{
	(void)param;
	if (keycode == 53)
		exit(0);
	return (0);
}

static int	mouse_fcnt_press(int button, int x, int y, t_mlx *param)
{
	if (button == 1)
	{
		param->bool_button_press = true;
		mlx_pixel_put(param->screen, param->window, x, y, 0xFFFFFF);
	}
	return (0);
}

static int	mouse_fcnt_release(int button, int x, int y, t_mlx *param)
{
	(void)x;
	(void)y;
	if (param->bool_button_press == true && button == 1)
		param->bool_button_press = false;
	return (0);
}

void	fdf_hook(t_mlx *mlx)
{
	mlx_hook(mlx->window, KeyPress, Button1Mask, key_fcnt, mlx);
	mlx_hook(mlx->window, ButtonPress, ButtonPressMask, mouse_fcnt_press, mlx);
	mlx_hook(mlx->window, ButtonRelease, ButtonReleaseMask,
			mouse_fcnt_release, mlx);
}
