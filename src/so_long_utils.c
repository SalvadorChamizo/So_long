/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:57:38 by schamizo          #+#    #+#             */
/*   Updated: 2024/03/05 13:35:18 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	start_mlx(t_game *game)
{
	game = find_player(game);
	game->mlx = mlx_init(game->size.x * 32, game->size.y * 32, "so_long", true);
	load_all_texture(game);
	load_all_img(game);
	build_map(game);
	mlx_key_hook(game->mlx, ft_key, game);
	mlx_loop(game->mlx);
}

t_game	**check_tab(t_game	**game, char to_check)
{
	if (to_check == 'C')
	{
		(*game)->obj.collect++;
		(*game)->coins++;
	}
	if (to_check == 'P')
		(*game)->obj.player++;
	if (to_check == 'E')
		(*game)->obj.exit++;
	if (to_check == 'X')
		(*game)->obj.enemies++;
	return (game);
}

t_game	**fill(char **tab, t_point size, t_point cur, t_game **game)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| tab[cur.y][cur.x] == '1' || tab[cur.y][cur.x] == 'F')
		return (game);
	if (tab[cur.y][cur.x] == 'E')
	{
		tab[cur.y][cur.x] = 'F';
		(*game)->obj.exit++;
		return (game);
	}
	game = check_tab(game, tab[cur.y][cur.x]);
	tab[cur.y][cur.x] = 'F';
	game = fill(tab, size, (t_point){cur.x - 1, cur.y}, game);
	game = fill(tab, size, (t_point){cur.x + 1, cur.y}, game);
	game = fill(tab, size, (t_point){cur.x, cur.y - 1}, game);
	game = fill(tab, size, (t_point){cur.x, cur.y + 1}, game);
	return (game);
}

t_game	*flood_fill(t_game *game)
{
	game->obj.collect = 0;
	game->obj.exit = 0;
	game->obj.player = 0;
	game = *fill(game->matrix2, game->size, game->p, &game);
	return (game);
}

int	key_check(t_game *game)
{
	if (game->matrix[game->p.y - 1][game->p.x] != '1'
		&& mlx_is_key_down(game->mlx, MLX_KEY_UP))
		return (1);
	if (game->matrix[game->p.y + 1][game->p.x] != '1'
		&& mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
		return (2);
	if (game->matrix[game->p.y][game->p.x - 1] != '1'
		&& mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		return (3);
	if (game->matrix[game->p.y][game->p.x + 1] != '1'
		&& mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		return (4);
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		return (5);
	return (0);
}
