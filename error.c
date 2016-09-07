/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/31 12:37:04 by jle-quer          #+#    #+#             */
/*   Updated: 2016/09/07 16:23:40 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error(int nm_error)
{
	if (nm_error == 3)
		ft_printf("Error code: %d - Error when open map.\n", nm_error);
	else if (nm_error == 1)
		ft_printf("Error code: %d - Arguments, enter just one map.\n", nm_error);
	else if (nm_error == 2)
		ft_printf("Error code: %d - Invalid map.\n", nm_error);
	else if (nm_error == 4)
		ft_printf("Error code: %d - Invalid alloc.\n", nm_error);
	exit (1);
}
