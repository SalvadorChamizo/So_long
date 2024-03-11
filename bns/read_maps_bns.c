/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_maps_bns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:29:10 by schamizo          #+#    #+#             */
/*   Updated: 2024/03/05 13:13:54 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_map_obj	ft_map_objects(t_map *map)
{
	t_map_obj	obj;
	int			i;
	int			j;

	j = 0;
	initialize_obj(&obj);
	while (map)
	{
		i = 0;
		while (map->map[i])
		{
			if (map->map[i] == 'C')
				obj.collect++;
			if (map->map[i] == 'P')
				obj.player++;
			if (map->map[i] == 'E')
				obj.exit++;
			if (map->map[i] == 'X')
				obj.enemies++;
			i++;
		}
		map = map->next;
	}
	return (obj);
}

void	ft_map_add_back(t_game *game, t_map *new)
{
	t_map	*last;

	last = game->map;
	if (!last)
		game->map = new;
	else
	{
		while (last->next)
			last = last->next;
		last->next = new;
	}
}

t_map	*ft_list_map_line(char *map_line)
{
	t_map	*new;

	new = NULL;
	new = malloc(sizeof(t_map));
	if (!new)
		return (NULL);
	if (new)
	{
		new->map = ft_strdup(map_line);
		new->next = NULL;
	}
	return (new);
}

t_game	*find_player(t_game *game)
{
	int		i;
	int		j;

	j = 1;
	game->p.y = 0;
	game->p.x = 0;
	while (j < game->size.y)
	{
		i = 1;
		while (game->matrix[j][i] != '\n')
		{
			if (game->matrix[j][i] == 'P')
			{
				game->p.y = j;
				game->p.x = i;
				return (game);
			}
			i++;
		}
		j++;
	}
	return (game);
}

t_map	*do_map(t_game *game)
{
	t_map	*new_line;
	char	*map_line;
	int		fd;

	new_line = NULL;
	map_line = NULL;
	fd = open(game->path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nMap not found\n");
		return (new_line);
	}
	map_line = get_next_line(fd);
	if (!map_line)
		return (new_line);
	while (map_line)
	{
		new_line = ft_list_map_line(map_line);
		ft_map_add_back(game, new_line);
		free(map_line);
		map_line = get_next_line(fd);
	}
	free(map_line);
	return (game->map);
}
