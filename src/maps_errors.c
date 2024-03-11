/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:37:43 by schamizo          #+#    #+#             */
/*   Updated: 2024/03/05 15:03:57 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_rectangle(t_game *game)
{
	int	i;
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (game->matrix[j][k] != '\n')
		k++;
	while (j < game->size.y)
	{
		i = 0;
		while (game->matrix[j][i] != '\n' && game->matrix[j][i] != '\0')
		{
			if (game->matrix[j][i] != '0' && game->matrix[j][i] != '1'
				&& game->matrix[j][i] != 'P' && game->matrix[j][i] != 'C'
				&& game->matrix[j][i] != 'E')
				return (1);
			i++;
		}
		if (k != i)
			return (1);
		j++;
	}
	return (0);
}

int	check_borders(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (j < game->size.y)
	{
		i = 0;
		while (game->matrix[j][i] != '\n' && game->matrix[j][i] != '\0')
		{
			if (j == 0 && game->matrix[j][i] != '1')
				return (1);
			if (j == game->size.y - 1 && game->matrix[j][i] != '1')
				return (1);
			if (j != 0 && (i == 0 || i == game->size.x - 1)
				&& game->matrix[j][i] != '1')
				return (1);
			if (j != game->size.y - 1 && (i == 0 || i == game->size.x - 1)
				&& game->matrix[j][i] != '1')
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

int	check_objects(t_map_obj	checked, t_map_obj objects)
{
	if (checked.collect != objects.collect)
		return (1);
	if (checked.exit != objects.exit)
		return (1);
	if (checked.player != objects.player)
		return (1);
	return (0);
}

int	check_nbr_objects(t_map_obj objects)
{
	if (objects.player != 1)
		return (1);
	if (objects.exit != 1)
		return (1);
	if (objects.collect < 1)
		return (1);
	return (0);
}

int	check_errors(t_game *game, t_map_obj objects)
{
	int		flag;

	flag = -1;
	if (check_borders(game) == 1)
		flag = 1;
	if (check_rectangle(game) == 1)
		flag = 1;
	if (check_objects(game->obj, objects) == 1)
		flag = 1;
	if (check_nbr_objects(objects) == 1)
		flag = 1;
	if (flag == 1)
	{
		(write(2, "Error\nThe map is wrong\n", 23));
		return (1);
	}
	return (0);
}
