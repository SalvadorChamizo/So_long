/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:21:28 by schamizo          #+#    #+#             */
/*   Updated: 2024/03/05 12:05:36 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_map_size_x(t_map *lst)
{
	int	x;

	x = 0;
	while (lst->map[x] != '\n')
		x++;
	return (x);
}

int	ft_map_size_y(t_map *lst)
{
	int	y;

	y = 0;
	while (lst)
	{
		y++;
		lst = lst->next;
	}
	return (y);
}

char	**do_matrix(t_game *game)
{
	char	**matrix;
	t_map	*temp;
	int		i;

	i = 0;
	temp = game->map;
	matrix = malloc(sizeof(char *) * (game->size.y + 1));
	if (!matrix)
		return (NULL);
	while (game->map)
	{
		matrix[i] = ft_strdup(game->map->map);
		i++;
		game->map = game->map->next;
	}
	game->map = temp;
	return (matrix);
}
