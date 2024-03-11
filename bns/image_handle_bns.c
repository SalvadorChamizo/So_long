/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_handle_bns.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:57:24 by schamizo          #+#    #+#             */
/*   Updated: 2024/03/11 12:38:52 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	load_all_texture(t_game *game)
{
	game->img.wall = mlx_load_png("./textures/wall.png");
	if (!game->img.wall)
	{
		ft_printf("Error\nImage not found\n");
		mlx_terminate(game->mlx);
		free_game(game, 1);
		exit (1);
	}
	game->img.floor = mlx_load_png("./textures/green.png");
	game->img.ch = mlx_load_png("./textures/chicken1.png");
	game->img.ch2 = mlx_load_png("./textures/chicken2.png");
	game->img.c = mlx_load_png("./textures/chicken_leg.png");
	game->img.exit = mlx_load_png("./textures/exit_on.png");
	game->img.enemy = mlx_load_png("./textures/enemy.png");
	game->img.sit = mlx_load_png("./textures/chicken_sit.png");
}

void	load_all_img(t_game *game)
{
	game->img.wall_img = mlx_texture_to_image(game->mlx, game->img.wall);
	game->img.floor_img = mlx_texture_to_image(game->mlx, game->img.floor);
	game->img.ch_img = mlx_texture_to_image(game->mlx, game->img.ch);
	game->img.ch_img2 = mlx_texture_to_image(game->mlx, game->img.ch2);
	game->img.c_img = mlx_texture_to_image(game->mlx, game->img.c);
	game->img.e_img = mlx_texture_to_image(game->mlx, game->img.exit);
	game->img.enemy2 = mlx_texture_to_image(game->mlx, game->img.enemy);
	game->img.sit2 = mlx_texture_to_image(game->mlx, game->img.sit);
}

void	each_image(t_game *game, char letter, t_point p)
{
	if (letter == '1' && game->img.wall_img != NULL)
		mlx_image_to_window(game->mlx, game->img.wall_img, p.x * 32, p.y * 32);
	if (letter != '1' && game->img.floor_img != NULL)
		mlx_image_to_window(game->mlx, game->img.floor_img, p.x * 32, p.y * 32);
	if (letter == 'X' && game->img.enemy2 != NULL)
		mlx_image_to_window(game->mlx, game->img.enemy2, p.x * 32, p.y * 32);
	if (letter == 'P' && game->img.ch_img != NULL && game->flag == 0)
	{
		mlx_image_to_window(game->mlx, game->img.ch_img, p.x * 32, p.y * 32);
		game->flag = 1;
	}
	else if (letter == 'P' && game->img.ch_img2 != NULL && game->flag == 1)
	{
		mlx_image_to_window(game->mlx, game->img.ch_img2, p.x * 32, p.y * 32);
		game->flag = 0;
	}
	if (letter == 'C' && game->img.c_img != NULL)
		mlx_image_to_window(game->mlx, game->img.c_img, p.x * 32, p.y * 32);
	if (letter == 'E' && game->img.e_img != NULL)
		mlx_image_to_window(game->mlx, game->img.e_img, p.x * 32, p.y * 32);
}

void	build_map(t_game *game)
{
	t_point	pos;
	int		j;
	int		i;

	j = 0;
	while (j < game->size.y)
	{
		i = 0;
		while (game->matrix[j][i] != '\n' && game->matrix[j][i] != '\0')
		{
			pos.x = i;
			pos.y = j;
			each_image(game, game->matrix[j][i], pos);
			i++;
		}
		j++;
	}
}

void	ft_counter(t_game *game)
{
	char	*moves;
	t_point	p1;

	p1.x = 0;
	p1.y = 0;
	each_image(game, game->matrix[0][0], p1);
	p1.x++;
	each_image(game, game->matrix[0][1], p1);
	p1.x++;
	each_image(game, game->matrix[0][2], p1);
	p1.x++;
	each_image(game, game->matrix[0][2], p1);
	p1.x++;
	each_image(game, game->matrix[0][2], p1);
	moves = ft_itoa(game->moves);
	mlx_put_string(game->mlx, "Moves: ", 10, 10);
	mlx_put_string(game->mlx, moves, 80, 10);
	free(moves);
}
