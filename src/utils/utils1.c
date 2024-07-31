/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mla-mona <mla-mona@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:51:40 by mcapalbo          #+#    #+#             */
/*   Updated: 2024/07/29 12:02:24 by mla-mona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	matrix_length(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i] != NULL)
		i++;
	return (i);
}

int	is_space_inside(char *str)
{
	while (*str)
	{
		if (ft_isspace(*str) == 0)
			return (1);
		str++;
	}
	return (0);
}

int	get_type(char *str)
{
	if (str == NULL)
		return (-1);
	while (ft_isspace(*str))
		str++;
	if (ft_isalpha(*str))
		return (0);
	if (ft_isalnum(*str))
		return (1);
	return (-1);
}

void	remove_newline(char **map)
{
	int	len;

	len = 0;
	while (*map != NULL)
	{
		len = ft_strlen(*map) - 1;
		(*map)[len] = '\0';
		map++;
	}
}

void	free_memory(t_game_data *game)
{
	if (game->map.no_path != NULL)
		free(game->map.no_path);
	if (game->map.so_path != NULL)
		free(game->map.so_path);
	if (game->map.we_path != NULL)
		free(game->map.we_path);
	if (game->map.ea_path != NULL)
		free(game->map.ea_path);
	if (game->map.map_coords != NULL)
		free_matrix(game->map.map_coords);
	if (game->map.map != NULL)
		free_matrix(game->map.map);
	if (game->map.map_options != NULL)
		free_matrix(game->map.map_options);
}
