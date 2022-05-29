/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiski <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 16:19:07 by amiski            #+#    #+#             */
/*   Updated: 2022/05/21 16:23:43 by amiski           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./gnl/get_next_line.h"
# include"./libft/libft.h"
# include"./printf/ft_printf.h"
# include <fcntl.h>
# include<stdio.h>
# include<mlx.h>

# define HEIGHT 32
# define WIDTH 32

# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2
# define ESC 53

typedef struct s_exit
{
	void	*img_c;
	void	*img_n_c;
}				t_exit;

typedef struct s_player
{
	void	*img_right;
	void	*img_left;
	int		x;
	int		y;
	int		pos;
}				t_player;

typedef struct s_img
{
	void	*data;
	int		width;
	int		height;
}	t_img;

typedef struct s_map
{
	char	**data;
	int		col;
	int		row;
	int		exits;
	int		collectibles;
	int		players;
	int		enemy;
}	t_map;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	t_map		map;
	size_t		width;
	size_t		height;
	size_t		moves;
	t_exit		exit;
	t_player	player;
	t_img		*collectible;
	t_img		*wall;
	t_img		*background;
	t_img		*enemy;

}	t_mlx;

t_mlx	obj_initialize(void);
void	to_map(char *file, t_mlx *objet);
void	check_map(t_mlx *objet);
void	get_assets(t_mlx *obj);
void	generate_game(t_mlx *obj);
void	render_game(t_mlx *obj);
int		move(int key, t_mlx *obj);
int		destroy_notify(t_mlx *obj);
void	ft_exit(int error, t_mlx *obj);
int		destroy_notify(t_mlx *obj);

#endif
