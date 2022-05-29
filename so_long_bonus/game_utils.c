/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiski <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:23:18 by amiski            #+#    #+#             */
/*   Updated: 2022/05/26 23:23:35 by amiski           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	generate_game(t_mlx *obj)
{
	obj->mlx = mlx_init();
	if (!(obj->mlx))
		ft_exit(3, obj);
	obj->win = mlx_new_window(obj->mlx, HEIGHT * obj->map.col, \
	WIDTH * obj->map.row, "so_long");
}

static void	put_player(t_mlx *obj, int i, int j)
{
	obj->player.x = i;
	obj->player.y = j;
	if (!obj->player.pos)
		mlx_put_image_to_window(obj->mlx, obj->win, obj->player.img_left,
			j * HEIGHT, i * WIDTH);
	else
		mlx_put_image_to_window(obj->mlx, obj->win, obj->player.img_right,
			j * HEIGHT, i * WIDTH);
}

void	put_exit(t_mlx *obj, int i, int j)
{
	if (obj->map.collectibles)
		mlx_put_image_to_window(obj->mlx, obj->win, obj->exit.img_c,
			j * HEIGHT, i * WIDTH);
	else
		mlx_put_image_to_window(obj->mlx, obj->win, obj->exit.img_n_c,
			j * HEIGHT, i * WIDTH);
}

static void	check_render(t_mlx *obj, int i, int j)
{
	if (obj->map.data[i][j] == '1')
		mlx_put_image_to_window(obj->mlx, obj->win, obj->wall,
			j * HEIGHT, i * WIDTH);
	if (obj->map.data[i][j] == '0')
		mlx_put_image_to_window(obj->mlx, obj->win, obj->background,
			j * HEIGHT, i * WIDTH);
	if (obj->map.data[i][j] == 'P')
		put_player(obj, i, j);
	if (obj->map.data[i][j] == 'C')
		mlx_put_image_to_window(obj->mlx, obj->win, obj->collectible,
			j * HEIGHT, i * WIDTH);
	if (obj->map.data[i][j] == 'E')
		put_exit(obj, i, j);
	if (obj->map.data[i][j] == 'X')
		mlx_put_image_to_window(obj->mlx, obj->win, obj->enemy,
			j * HEIGHT, i * WIDTH);
}

void	render_game(t_mlx *obj)
{
	int	i;
	int	j;

	mlx_clear_window(obj->mlx, obj->win);
	i = 0;
	while (i < obj->map.row)
	{
		j = 0;
		while (j < obj->map.col)
		{
			check_render(obj, i, j);
			j++;
		}
		i++;
	}
	mlx_string_put(obj->mlx, obj->win, (obj->map.col / 2) * 32,
		0, 0x0000FF, ft_itoa(obj->moves));
}
