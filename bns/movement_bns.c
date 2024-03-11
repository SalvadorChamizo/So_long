/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_bns.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:14:32 by schamizo          #+#    #+#             */
/*   Updated: 2024/03/05 11:50:12 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_to_up(t_game *game, int y, int x)
{
	t_point	p;

	p.y = y;
	p.x = x;
	if (game->matrix[y - 1][x] == 'C')
		game->c++;
	else if (game->matrix[y - 1][x] == 'E' && game->c == game->coins)
	{
		mlx_close_window(game->mlx);
		return ;
	}
	else if (game->matrix[y - 1][x] == 'E')
		return ;
	else if (game->matrix[y - 1][x] == 'X')
	{
		mlx_close_window(game->mlx);
		return ;
	}
	game->moves++;
	game->matrix[y][x] = '0';
	game->matrix[y - 1][x] = 'P';
	each_image(game, game->matrix[y][x], p);
	p.y--;
	each_image(game, game->matrix[y - 1][x], p);
}

void	move_to_down(t_game *game, int y, int x)
{
	t_point	p;

	p.y = y;
	p.x = x;
	if (game->matrix[y + 1][x] == 'C')
		game->c++;
	else if (game->matrix[y + 1][x] == 'E' && game->c == game->coins)
	{
		mlx_close_window(game->mlx);
		return ;
	}
	else if (game->matrix[y + 1][x] == 'E')
		return ;
	else if (game->matrix[y + 1][x] == 'X')
	{
		mlx_close_window(game->mlx);
		return ;
	}
	game->moves++;
	game->matrix[y][x] = '0';
	game->matrix[y + 1][x] = 'P';
	each_image(game, game->matrix[y][x], p);
	p.y++;
	each_image(game, game->matrix[y + 1][x], p);
}

void	move_to_left(t_game *game, int y, int x)
{
	t_point	p;

	p.y = y;
	p.x = x;
	if (game->matrix[y][x - 1] == 'C')
		game->c++;
	else if (game->matrix[y][x - 1] == 'E' && game->c == game->coins)
	{
		mlx_close_window(game->mlx);
		return ;
	}
	else if (game->matrix[y][x - 1] == 'E')
		return ;
	else if (game->matrix[y][x - 1] == 'X')
	{
		mlx_close_window(game->mlx);
		return ;
	}
	game->moves++;
	game->matrix[y][x] = '0';
	game->matrix[y][x - 1] = 'P';
	each_image(game, game->matrix[y][x], p);
	p.x--;
	each_image(game, game->matrix[y][x - 1], p);
}

void	move_to_right(t_game *game, int y, int x)
{
	t_point	p;

	p.y = y;
	p.x = x;
	if (game->matrix[y][x + 1] == 'C')
		game->c++;
	else if (game->matrix[y][x + 1] == 'E' && game->c == game->coins)
	{
		mlx_close_window(game->mlx);
		return ;
	}
	else if (game->matrix[y][x + 1] == 'E')
		return ;
	else if (game->matrix[y][x + 1] == 'X')
	{
		mlx_close_window(game->mlx);
		return ;
	}
	game->moves++;
	game->matrix[y][x] = '0';
	game->matrix[y][x + 1] = 'P';
	each_image(game, game->matrix[y][x], p);
	p.x++;
	each_image(game, game->matrix[y][x + 1], p);
}

void	ft_key(struct mlx_key_data key_data, void *param)
{
	t_game	*game;
	t_point	old_pos;

	game = param;
	old_pos = game->p;
	game = find_player(game);
	if (key_data.key == MLX_KEY_UP && key_check(game) == 1)
		move_to_up(game, game->p.y, game->p.x);
	if (key_data.key == MLX_KEY_DOWN && key_check(game) == 2)
		move_to_down(game, game->p.y, game->p.x);
	if (key_data.key == MLX_KEY_LEFT && key_check(game) == 3)
		move_to_left(game, game->p.y, game->p.x);
	if (key_data.key == MLX_KEY_RIGHT && key_check(game) == 4)
		move_to_right(game, game->p.y, game->p.x);
	if (key_data.key == MLX_KEY_ESCAPE && key_check(game) == 5)
	{
		mlx_close_window(game->mlx);
		return ;
	}
	if (key_data.key == MLX_KEY_SPACE && key_check(game) == 6)
		easter_egg(game);
	ft_counter(game);
}
