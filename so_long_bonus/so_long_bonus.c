/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiski <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 16:07:15 by amiski            #+#    #+#             */
/*   Updated: 2022/05/26 23:31:19 by amiski           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	put_collec(t_mlx *obj, int i, int j)
{
	int static	k;

	if (k <= 70)
		mlx_put_image_to_window(obj->mlx, obj->win,
			obj->collectible, j * 32, i * 32);
	else if (k <= 140)
		mlx_put_image_to_window(obj->mlx, obj->win,
			obj->collectible1, j * 32, i * 32);
	else
		k = 0;
	k++;
}

int	ft_collec(t_mlx *obj)
{
	int	i;
	int	j;

	i = 0;
	if (obj->map.collectibles)
	{
		while (i < obj->map.row)
		{
			j = 0;
			while (j < obj->map.col)
			{
				if (obj->map.data[i][j] == 'C')
					put_collec(obj, i, j);
				j++;
			}
			i++;
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx	obj;

	obj = obj_initialize();
	if (argc != 2)
		ft_exit(0, &obj);
	to_map(argv[1], &obj);
	check_map(&obj);
	generate_game(&obj);
	get_assets(&obj);
	render_game(&obj);
	mlx_loop_hook(obj.mlx, ft_collec, &obj);
	mlx_hook(obj.win, 2, 2L << 0, move, &obj);
	mlx_hook(obj.win, 17, 0L, destroy_notify, &obj);
	mlx_loop(obj.mlx);
}
