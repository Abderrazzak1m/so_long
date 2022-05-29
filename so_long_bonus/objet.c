/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objet.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiski <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 16:08:57 by amiski            #+#    #+#             */
/*   Updated: 2022/05/21 16:14:04 by amiski           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

static t_map	map_initialize(void)
{
	t_map	map;

	map.data = ft_calloc(1, sizeof(char *));
	map.col = 0;
	map.row = 0;
	map.exits = 0;
	map.collectibles = 0;
	map.players = 0;
	map.enemy = 0;
	return (map);
}

t_mlx	obj_initialize(void)
{
	t_mlx	obj;

	obj.mlx = NULL;
	obj.win = NULL;
	obj.map = map_initialize();
	obj.width = 0;
	obj.height = 0;
	obj.moves = 0;
	obj.enemy = 0;
	obj.exit.img_c = NULL;
	obj.exit.img_n_c = NULL;
	obj.player.img_left = NULL;
	obj.player.img_right = NULL;
	obj.player.pos = 1;
	obj.player.y = 0;
	obj.player.x = 0;
	obj.collectible = NULL;
	obj.collectible1 = NULL;
	obj.background = NULL;
	obj.wall = NULL;
	return (obj);
}
