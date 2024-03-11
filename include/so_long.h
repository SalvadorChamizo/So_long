/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:20:49 by schamizo          #+#    #+#             */
/*   Updated: 2024/03/05 13:33:49 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/*# include "./MLX42/include/MLX42/MLX42_Input.h"
# include "./MLX42/include/MLX42/MLX42_Int.h"*/
# include "../MLX42/include/MLX42/MLX42.h"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/include/libft.h"

typedef struct s_map_obj
{
	int	collect;
	int	exit;
	int	player;
	int	enemies;
	int	walls;
}	t_map_obj;

typedef struct s_img_texture
{
	char			**matrix;
	mlx_t			*mlx;
	mlx_texture_t	*floor;
	mlx_texture_t	*wall;
	mlx_texture_t	*ch;
	mlx_texture_t	*ch2;
	mlx_texture_t	*exit;
	mlx_texture_t	*exit2;
	mlx_texture_t	*c;
	mlx_texture_t	*enemy;
	mlx_texture_t	*sit;
	mlx_image_t		*floor_img;
	mlx_image_t		*wall_img;
	mlx_image_t		*ch_img;
	mlx_image_t		*ch_img2;
	mlx_image_t		*e_img;
	mlx_image_t		*e_img2;
	mlx_image_t		*c_img;
	mlx_image_t		*enemy2;
	mlx_image_t		*sit2;
}	t_img_texture;

typedef struct s_point
{
	int	x;
	int	y;
}		t_point;

typedef struct s_map
{
	char			*map;
	struct s_map	*next;
}	t_map;

typedef struct s_game
{
	t_map			*map;
	t_map_obj		obj;
	char			**matrix;
	char			**matrix2;
	char			*path;
	int				moves;
	int				c;
	int				coins;
	int				flag;
	int				sit;
	t_point			p;
	t_point			size;
	t_img_texture	img;
	mlx_t			*mlx;
}	t_game;

typedef struct s_key_data
{
	int	key;
}	t_key_data;

/* Image Handle */

void		load_all_texture(t_game *game);
void		load_all_img(t_game *game);
void		each_image(t_game *game, char letter, t_point pos);
void		build_map(t_game *game);
void		ft_counter(t_game *game);

/* Initialize */

int			start_map(t_game **game);
void		easter_egg(t_game *game);
int			initializes_map(char *path);
t_game		*init_game(t_game *game);
void		initialize_obj(t_map_obj *objects);

/* Maps Errors */

int			check_rectangle(t_game *game);
int			check_borders(t_game *game);
int			check_objects(t_map_obj	checked, t_map_obj objects);
int			check_nbr_objects(t_map_obj objects);
int			check_errors(t_game *game, t_map_obj objects);

/* Maps Utils */

int			ft_map_size_x(t_map *lst);
int			ft_map_size_y(t_map *lst);
char		**do_matrix(t_game *game);

/* Movement */

void		move_to_up(t_game *game, int y, int x);
void		move_to_down(t_game *game, int y, int x);
void		move_to_left(t_game *game, int y, int x);
void		move_to_right(t_game *game, int y, int x);
void		ft_key(struct mlx_key_data key_data, void *param);

/* Read map */

t_map_obj	ft_map_objects(t_map *matrix);
void		ft_map_add_back(t_game *game, t_map *new);
t_map		*ft_list_map_line(char *map_line);
t_game		*find_player(t_game *game);
t_map		*do_map(t_game *game);

/* So_long_utils */

void		start_mlx(t_game *game);
t_game		**check_tab(t_game **game, char to_check);
t_game		**fill(char **tab, t_point size, t_point cur, t_game **game);
t_game		*flood_fill(t_game *game);
int			key_check(t_game *game);

/* Free Memory */

void		ft_stack_clear(t_map **stack);
char		**free_matrix(char	**matrix, int cont);
void		delete_texture(t_game **game);
void		delete_image(t_game **game);
void		free_game(t_game *game, int error);

#endif