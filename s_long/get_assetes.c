/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_assetes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiski <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 16:23:50 by amiski            #+#    #+#             */
/*   Updated: 2022/05/21 16:28:01 by amiski           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	get_assets(t_mlx *obj)
{
	int	width;
	int	height;

	obj->wall = mlx_xpm_file_to_image(obj->mlx,
			"./images/wall.xpm", &width, &height);
	obj->background = mlx_xpm_file_to_image(obj->mlx,
			"./images/background.xpm", &width, &height);
	obj->collectible = mlx_xpm_file_to_image(obj->mlx,
			"./images/collec.xpm", &width, &height);
	obj->player.img_left = mlx_xpm_file_to_image(obj->mlx,
			"./images/player.xpm", &width, &height);
	obj->player.img_right = mlx_xpm_file_to_image(obj->mlx,
			"./images/player2.xpm", &width, &height);
	obj->exit.img_c = mlx_xpm_file_to_image(obj->mlx,
			"./images/closed_gate.xpm", &width, &height);
	obj->exit.img_n_c = mlx_xpm_file_to_image(obj->mlx,
			"./images/opened_gate.xpm", &width, &height);
}
