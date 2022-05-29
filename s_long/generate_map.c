/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiski <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 16:14:41 by amiski            #+#    #+#             */
/*   Updated: 2022/05/21 16:18:34 by amiski           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_file(char *file, t_mlx *obj)
{
	int		i;
	int		len;
	char	*ber;

	ber = ".ber";
	i = 3;
	len = ft_strlen(file) - 1;
	while (i >= 0)
	{
		if (file[len] != ber[i])
			ft_exit(1, obj);
		i--;
		len--;
	}
}

static void	checklen(char *line, t_mlx *obj)
{
	int	len;

	len = ft_strlen(line);
	if (ft_strchr(line, '\n'))
		len--;
	if (len != obj->map.col)
		ft_exit(2, obj);
}

static void	add_line(t_mlx *obj, char *line)
{
	char	**map;
	size_t	i;

	i = 0;
	obj->map.row = obj->map.row + 1;
	map = malloc(sizeof(char *) * (obj->map.row + 1));
	if (!map)
		ft_exit(2, obj);
	while (obj->map.data[i])
	{
		map[i] = obj->map.data[i];
		i++;
	}
	map[i] = line;
	map[i + 1] = NULL;
	free(obj->map.data);
	obj->map.data = map;
}

void	to_map(char *file, t_mlx *obj)
{
	int		fd;
	char	*line;

	check_file(file, obj);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_exit(1, obj);
	line = get_next_line(fd);
	if (!line)
		ft_exit(2, obj);
	obj->map.col = ft_strlen(line) -1;
	while (line)
	{
		checklen(line, obj);
		add_line(obj, line);
		line = get_next_line(fd);
	}
	close(fd);
}
