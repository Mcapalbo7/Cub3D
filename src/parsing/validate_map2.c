/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcapalbo < mcapalbo@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:57:21 by mcapalbo          #+#    #+#             */
/*   Updated: 2024/07/31 19:06:54 by mcapalbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	check_characters(char **mat)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (mat[x])
	{
		y = 0;
		while (mat[x][y])
		{
			if (mat[x][y] != 'N' && mat[x][y] != 'S'
				&& mat[x][y] != 'W' && mat[x][y] != 'E'
				&& mat[x][y] != '1' && mat[x][y] != '0' && mat[x][y] != ' ')
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

int	does_map_exist(char *path, t_map_data *map)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	map->map = malloc(sizeof(char *) * 1000);
	while (i < 1000)
		map->map[i++] = NULL;
	i = 0;
	map->map[i] = get_next_line(fd);
	while (map->map[i])
	{
		i++;
		map->map[i] = get_next_line(fd);
	}
	close(fd);
	return (1);
}

void	initialize_map(t_map_data *map)
{
	map->player_x = -1;
	map->player_y = -1;
	map->ceiling_color.blue = -1;
	map->ceiling_color.green = -1;
	map->ceiling_color.red = -1;
	map->floor_color.blue = -1;
	map->floor_color.green = -1;
	map->floor_color.red = -1;
	map->no_path = NULL;
	map->so_path = NULL;
	map->we_path = NULL;
	map->ea_path = NULL;
	map->map_options = NULL;
	map->map_coords = NULL;
	map->map = NULL;
}

int	check_extension(char *path)
{
	int	len;

	len = ft_strlen(path) - 1;
	if (path[len] != 'b' || path[len -1] != 'u' || path[len - 2] != 'c'
		|| path[len - 3] != '.')
		return (0);
	return (1);
}

int	check_extension2(t_map_data*map)
{
	if (map->ea_path[ft_strlen(map->ea_path) - 1] != 'm'
		|| map->ea_path[ft_strlen(map->ea_path) - 2] != 'p'
		|| map->ea_path[ft_strlen(map->ea_path) - 3] != 'x'
		|| map->ea_path[ft_strlen(map->ea_path) - 4] != '.')
		return (1);
	if (map->we_path[ft_strlen(map->we_path) - 1] != 'm'
		|| map->we_path[ft_strlen(map->we_path) - 2] != 'p'
		|| map->we_path[ft_strlen(map->we_path) - 3] != 'x'
		|| map->we_path[ft_strlen(map->we_path) - 4] != '.')
		return (1);
	if (map->so_path[ft_strlen(map->so_path) - 1] != 'm'
		|| map->so_path[ft_strlen(map->so_path) - 2] != 'p'
		|| map->so_path[ft_strlen(map->so_path) - 3] != 'x'
		|| map->so_path[ft_strlen(map->so_path) - 4] != '.')
		return (1);
	if (map->no_path[ft_strlen(map->no_path) - 1] != 'm'
		|| map->no_path[ft_strlen(map->no_path) - 2] != 'p'
		|| map->no_path[ft_strlen(map->no_path) - 3] != 'x'
		|| map->no_path[ft_strlen(map->no_path) - 4] != '.')
		return (1);
	return (0);
}
