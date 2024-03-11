/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:24:01 by schamizo          #+#    #+#             */
/*   Updated: 2024/03/05 12:50:25 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_stack_clear(t_map **stack)
{
	t_map	*temp;

	if (!stack)
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		free((*stack)->map);
		free(*stack);
		*stack = temp;
	}
	*stack = NULL;
}

char	**free_matrix(char	**matrix, int cont)
{
	int	i;

	i = 0;
	while (i < cont)
	{
		free(matrix[i]);
		matrix[i] = NULL;
		i++;
	}
	free(matrix);
	matrix = NULL;
	return (matrix);
}

void	delete_texture(t_game **game)
{
	mlx_delete_texture((*game)->img.ch);
	(*game)->img.ch = NULL;
	mlx_delete_texture((*game)->img.exit);
	(*game)->img.exit = NULL;
	mlx_delete_texture((*game)->img.c);
	(*game)->img.c = NULL;
	mlx_delete_texture((*game)->img.wall);
	(*game)->img.wall = NULL;
	mlx_delete_texture((*game)->img.floor);
	(*game)->img.floor = NULL;
}

void	delete_image(t_game **game)
{
	mlx_delete_image((*game)->mlx, (*game)->img.ch_img);
	(*game)->img.ch_img = NULL;
	mlx_delete_image((*game)->mlx, (*game)->img.e_img);
	(*game)->img.e_img = NULL;
	mlx_delete_image((*game)->mlx, (*game)->img.c_img);
	(*game)->img.c_img = NULL;
	mlx_delete_image((*game)->mlx, (*game)->img.wall_img);
	(*game)->img.wall_img = NULL;
	mlx_delete_image((*game)->mlx, (*game)->img.floor_img);
	(*game)->img.floor_img = NULL;
}

void	free_game(t_game *game, int error)
{
	if (error == 1)
	{
		game->matrix = free_matrix(game->matrix, game->size.y);
		ft_stack_clear(&game->map);
		free(game);
	}
	if (error == 0)
	{
		game->matrix = free_matrix(game->matrix, game->size.y);
		ft_stack_clear(&game->map);
		delete_texture(&game);
		delete_image(&game);
		mlx_terminate(game->mlx);
		free(game);
	}
	if (error == 2)
	{
		ft_stack_clear(&game->map);
		free(game);
	}
}
