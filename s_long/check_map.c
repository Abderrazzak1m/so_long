/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiski <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 16:02:51 by amiski            #+#    #+#             */
/*   Updated: 2022/05/21 16:06:47 by amiski           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

static void	check_all(char c, t_mlx *objet)
{
	if (c != '1' && c != '0' && c != 'E' && c != 'P' && c != 'C')
		ft_exit(2, objet);
	if (c == 'P')
		objet->map.players += 1;
	if (c == 'C')
		objet->map.collectibles += 1;
	if (c == 'E')
		objet->map.exits += 1;
}

static int	line_is_wall(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

void	check_map(t_mlx *objet)
{
	int	i;
	int	j;

	i = 0;
	if (!line_is_wall(objet->map.data[0])
		|| !line_is_wall(objet->map.data[objet->map.row -1]))
		ft_exit(2, objet);
	while (i < objet->map.row)
	{
		if (objet->map.data[i][0] != '1'
			|| objet->map.data[i][objet->map.col - 1] != '1')
			ft_exit(2, objet);
		j = 0;
		while (j < objet->map.col)
		{
			check_all(objet->map.data[i][j], objet);
			j++;
		}
		i++;
	}
	if (objet->map.players != 1 || objet->map.collectibles < 1
		|| objet->map.exits < 1)
		ft_exit(2, objet);
}
