/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 11:27:10 by jle-quer          #+#    #+#             */
/*   Updated: 2016/09/07 12:06:49 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_points(char *line, int nb_line, t_point ***array_points)
{
	char	**array_str;
	t_point	*a_point;
	int		i;

	array_str = ft_strsplit(line, ' ');
	i = 0;
	while (array_str[i] != 0)
		i++;
	if (!((*array_points) = (t_point**)malloc(sizeof(t_point) * i)))
		return (0);
	i = 0;
	while (array_str[i] != 0)
	{
		a_point = (t_point*)malloc(sizeof(t_point));
		a_point->x = i * SIZE_W;
		a_point->y = nb_line * SIZE_H;
		a_point->z = ft_atoi(array_str[i]);
		a_point->s = 1;
		a_point->z_color = a_point->z;
		(*array_points)[i] = a_point;
		i++;
	}
	return (i);
}

static int	map_line(char *map)
{
	int		fd;
	int		nb_lines;
	char	buff;

	fd = 0;
	nb_lines = 0;
	if ((fd = open(map, O_RDONLY)) < 0)
		ft_error(3);
	while (read(fd, &buff, 1))
	{
		if (buff == '\n')
			nb_lines++;
	}
	close(fd);
	return (nb_lines);
}

t_map		*parse_map(char **av, int fd)
{
	char	*line;
	int		nb_line;
	t_map	*map;
	t_line	*line_map;
	t_point	**array_points;

	nb_line = 0;
	if (!(map = (t_map*)malloc(sizeof(t_map))) ||
			!(map->lines = (t_line**)malloc(sizeof(t_line) * map_line(av[1]))))
		return (NULL);
	map->len = 0;
	if ((fd = open(av[1], O_RDONLY)) > 0)
	{
		while ((get_next_line(fd, &line)) > 0)
		{
			if (!(line_map = (t_line*)malloc(sizeof(t_line))))
				return (NULL);
			line_map->len = ft_points(line, nb_line, &array_points);
			line_map->points = array_points;
			map->lines[nb_line] = line_map;
			nb_line++;
		}
		map->len = nb_line;
	}
	return (map);
}
