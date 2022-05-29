/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiski <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:25:24 by amiski            #+#    #+#             */
/*   Updated: 2022/05/26 23:18:52 by amiski           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

static void	move_right(t_mlx *obj, int *count)
{
	int	prow;
	int	pcol;

	prow = obj->player.x;
	pcol = obj->player.y;
	if (obj->map.data[prow][pcol + 1] == 'E')
	{
		if (obj->map.collectibles == 0)
			ft_exit(4, obj);
		return ;
	}
	if (obj->map.data[prow][pcol + 1] == 'X')
		ft_exit(5, obj);
	obj->player.pos = 1;
	*count = 1;
	obj->map.data[prow][pcol] = '0';
	pcol += 1;
	if (obj->map.data[prow][pcol] == 'C')
	{
		obj->map.data[prow][pcol] = '0';
		obj->map.collectibles -= 1;
	}
	obj->map.data [prow][pcol] = 'P';
}

static void	move_left(t_mlx *obj, int *count)
{
	int	prow;
	int	pcol;

	prow = obj->player.x;
	pcol = obj->player.y;
	if (obj->map.data[prow][pcol - 1] == 'E')
	{
		if (obj->map.collectibles == 0)
			ft_exit(4, obj);
		return ;
	}
	if (obj->map.data[prow][pcol - 1] == 'X')
		ft_exit(5, obj);
	obj->player.pos = 0;
	*count = 1;
	obj->map.data[prow][pcol] = '0';
	pcol -= 1;
	if (obj->map.data[prow][pcol] == 'C')
	{
		obj->map.data[prow][pcol] = '0';
		obj->map.collectibles -= 1;
	}
	obj->map.data[prow][pcol] = 'P';
}

static void	move_down(t_mlx *obj, int *count)
{
	int	prow;
	int	pcol;

	prow = obj->player.x;
	pcol = obj->player.y;
	if (obj->map.data[prow + 1][pcol] == 'E')
	{
		if (obj->map.collectibles == 0)
			ft_exit(4, obj);
		return ;
	}
	if (obj->map.data[prow + 1][pcol] == 'X')
		ft_exit(5, obj);
	*count = 1;
	obj->map.data[prow][pcol] = '0';
	prow += 1;
	if (obj->map.data[prow][pcol] == 'C')
	{
		obj->map.data[prow][pcol] = '0';
		obj->map.collectibles -= 1;
	}
	obj->map.data[prow][pcol] = 'P';
}

static void	move_up(t_mlx *obj, int *count)
{
	int	prow;
	int	pcol;

	prow = obj->player.x;
	pcol = obj->player.y;
	if (obj->map.data[prow - 1][pcol] == 'E')
	{
		if (obj->map.collectibles == 0)
			ft_exit(4, obj);
		return ;
	}
	if (obj->map.data[prow - 1][pcol] == 'X')
		ft_exit(5, obj);
	*count = 1;
	obj->map.data[prow][pcol] = '0';
	prow -= 1;
	if (obj->map.data[prow][pcol] == 'C')
	{
		obj->map.data[prow][pcol] = '0';
		obj->map.collectibles -= 1;
	}
	obj->map.data[prow][pcol] = 'P';
}

int	move(int key, t_mlx *obj)
{
	int			count;
	int			prow;
	int			pcol;

	count = 0;
	prow = obj->player.x;
	pcol = obj->player.y;
	if (key == RIGHT && obj->map.data[prow][pcol + 1] != '1')
		move_right(obj, &count);
	if (key == LEFT && obj->map.data[prow][pcol - 1] != '1')
		move_left(obj, &count);
	if (key == DOWN && obj->map.data[prow + 1][pcol] != '1')
		move_down(obj, &count);
	if (key == UP && obj->map.data[prow - 1][pcol] != '1')
		move_up(obj, &count);
	if (key == ESC)
		exit(0);
	if (count)
	{
		obj->moves++;
	}
	render_game(obj);
	return (1);
}
