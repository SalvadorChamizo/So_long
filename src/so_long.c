/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:20:15 by schamizo          #+#    #+#             */
/*   Updated: 2024/03/05 12:51:10 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_ber(char	*path)
{
	char	*str;
	int		len;
	int		i;

	str = ".ber";
	len = ft_strlen(path);
	if (len == 11)
		return (1);
	len = len - 4;
	i = 0;
	while (str[i])
	{
		if (path[len + i] != str[i])
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 2)
		ft_printf("Error\nInvalid number of arguments");
	if (argc == 2)
	{
		if (check_ber(argv[1]) == 1)
		{
			ft_printf("Error\nInvalid map format\n");
			return (1);
		}
		i = initializes_map(argv[1]);
		if (i == 1)
			return (1);
	}
	return (0);
}
