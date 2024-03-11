/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_bns.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:22:25 by schamizo          #+#    #+#             */
/*   Updated: 2024/03/05 14:21:49 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	initialize_obj(t_map_obj *objects)
{
	t_map_obj	temp;

	temp = *objects;
	temp.collect = 0;
	temp.player = 0;
	temp.exit = 0;
	temp.enemies = 0;
	*objects = temp;
}

t_game	*init_game(t_game *game)
{
	game->path = NULL;
	game->map = NULL;
	game->matrix = NULL;
	game->p.x = 0;
	game->p.y = 0;
	game->size.y = 0;
	game->size.x = 0;
	game->moves = 0;
	game->c = 0;
	game->coins = 0;
	game->flag = 0;
	game->sit = 0;
	game->mlx = NULL;
	return (game);
}

int	start_map(t_game **game)
{
	t_game	*temp;

	temp = *game;
	temp->map = do_map(temp);
	if (!temp->map)
	{
		free(temp);
		return (1);
	}
	temp->size.y = ft_map_size_y(temp->map);
	temp->size.x = ft_map_size_x(temp->map);
	temp->matrix = do_matrix(temp);
	if (!temp->matrix)
	{
		free_game(temp, 2);
		return (1);
	}
	temp->matrix2 = do_matrix(temp);
	if (!temp->matrix2)
	{
		free_game(temp, 1);
		return (1);
	}
	*game = temp;
	return (0);
}

int	initializes_map(char *path)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (1);
	game = init_game(game);
	game->path = path;
	if (start_map(&game) == 1)
		return (1);
	game = find_player(game);
	game = flood_fill(game);
	game->matrix2 = free_matrix(game->matrix2, game->size.y);
	if (check_errors(game, ft_map_objects(game->map)) == 1)
	{
		free_game(game, 1);
		return (1);
	}
	start_mlx(game);
	free_game(game, 0);
	return (0);
}

void	easter_egg(t_game *game)
{
	t_point	p;

	p.x = game->p.x;
	p.y = game->p.y;
	if (game->sit == 0)
	{
		mlx_image_to_window(game->mlx, game->img.floor_img, p.x * 32, p.y * 32);
		mlx_image_to_window(game->mlx, game->img.sit2, p.x * 32, p.y * 32);
		game->sit = 1;
	}
	else if (game->sit == 1)
	{
		mlx_image_to_window(game->mlx, game->img.floor_img, p.x * 32, p.y * 32);
		mlx_image_to_window(game->mlx, game->img.ch_img, p.x * 32, p.y * 32);
		game->sit = 0;
	}
}
