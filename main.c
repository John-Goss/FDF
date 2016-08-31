/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/31 11:58:30 by jle-quer          #+#    #+#             */
/*   Updated: 2016/08/31 16:54:50 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fdf.h"

int	key_fcnt(int keycode, t_mlx *param)
{
	printf("Keycode : %d\n", keycode);
	if (keycode == 53)
		exit(0);
	else if (keycode == 0)
		mlx_pixel_put(param->screen, param->window, 300, 300, 0xFFFFFF);
	return (0);
}

int	mouse_fcnt(int button, int x, int y, t_mlx *param)
{
	printf("Button : %d\n", button);
	mlx_pixel_put(param->screen, param->window, x, y, 0xFFFFFF);
	return (0);
}

int	main(void)
{
	t_mlx	*ptr;

	if (!(ptr = malloc(sizeof(t_mlx))))
		return (1);
	ptr->x_max = 1024;
	ptr->y_max = 768;
	ptr->nm_window = "FDF";
	ptr->screen = mlx_init();
	ptr->window = mlx_new_window(ptr->screen, ptr->x_max, ptr->y_max, ptr->nm_window);
	mlx_hook(ptr->window, 1, 1<<8, mouse_fcnt, ptr);
	mlx_loop(ptr->screen);
	return (0);
}
