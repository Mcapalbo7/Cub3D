/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcapalbo < mcapalbo@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:03:40 by mcapalbo          #+#    #+#             */
/*   Updated: 2024/07/31 19:06:39 by mcapalbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	check_coordinates(char **mat, t_map_data *map)
{
	remove_newline(map->map_coords);
	if (!check_characters(map->map_coords))
		return (printf("Wrong character!\n"), 0);
	if (!locate_player(map->map_coords, map))
		return (printf("Player problem\n"), 0);
	if (map->player_x == -1 || map->player_y == -1)
		return (printf("Player not found!\n"), 0);
	if (!validate_floor_line(mat, matrix_length(mat) - 1))
		return (printf("Problem row, check row\n"), 0);
	if (!verify_wall(mat))
		return (printf("Problem wall, check wall\n"), 0);
	return (1);
}

int	create_coordinates(t_map_data *map)
{
	int		i;
	int		y;
	int		len;
	char	**tmp;

	tmp = map->map;
	i = 0;
	y = 0;
	len = map_size(tmp);
	if (len == -1)
		return (0);
	map->map_coords = malloc(sizeof(char *) * (len + 1));
	while (get_type(*tmp) != 1)
		tmp++;
	while (i < len)
	{
		map->map_coords[y] = ft_strdup(tmp[i]);
		i++;
		y++;
	}
	map->map_coords[y] = NULL;
	if (!check_coordinates(map->map_coords, map))
		return (0);
	return (1);
}

int	map_size(char **map)
{
	int	i;
	int	last;
	int	len;

	last = matrix_length(map) - 1;
	i = 1;
	len = 0;
	while (is_space_inside(map[last]) == 0)
		last--;
	while (map[i] && get_type(map[i]) != 1)
		i++;
	len = last - i + 1;
	if (!map[i])
		return (-1);
	while (map[i] && i <= last)
	{
		if (is_space_inside(map[i]) == -1)
			return (-1);
		i++;
	}
	return (len);
}

int	validate_map(char *path, t_map_data *map)
{
	initialize_map(map);
	if (!check_extension(path))
		return (0);
	if (!does_map_exist(path, map))
		return (0);
	if (!create_map_options(map))
		return (0);
	if (!create_coordinates(map))
		return (0);
	return (1);
}
