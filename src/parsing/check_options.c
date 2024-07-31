/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcapalbo < mcapalbo@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 15:26:22 by mcapalbo          #+#    #+#             */
/*   Updated: 2024/07/31 19:05:45 by mcapalbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	check_param(t_map_data *map)
{
	if (!map->no_path || !map->so_path || !map->ea_path || !map->we_path)
		return (0);
	if (access(map->we_path, F_OK) == -1 || access(map->ea_path, F_OK) == -1
		|| access(map->so_path, F_OK) == -1
		|| access(map->no_path, F_OK) == -1)
		return (0);
	if (check_extension2(map) == 1)
		return (0);
	if (map->ceiling_color.blue < 0 || map->ceiling_color.blue > 255
		|| map->ceiling_color.red < 0 || map->ceiling_color.red > 255
		|| map->ceiling_color.green < 0 || map->ceiling_color.green > 255)
		return (0);
	if (map->floor_color.blue < 0 || map->floor_color.blue > 255
		|| map->floor_color.red < 0 || map->floor_color.red > 255
		|| map->floor_color.green < 0 || map->floor_color.green > 255)
		return (0);
	return (1);
}

int	parse_param(char **options, t_map_data *map)
{
	int	i;

	i = 0;
	while (options[i] != NULL)
	{
		if (ft_strnstr(options[i], "NO", 100) != NULL)
			map->no_path = extract_path(options[i]);
		else if (ft_strnstr(options[i], "SO", 100) != NULL)
			map->so_path = extract_path(options[i]);
		else if (ft_strnstr(options[i], "WE", 100) != NULL)
			map->we_path = extract_path(options[i]);
		else if (ft_strnstr(options[i], "EA", 100) != NULL)
			map->ea_path = extract_path(options[i]);
		else if (ft_strnstr(options[i], "F", 100) != NULL)
			parse_rgb(options[i], &map->floor_color);
		else if (ft_strnstr(options[i], "C", 100) != NULL)
			parse_rgb(options[i], &map->ceiling_color);
		i++;
	}
	if (!check_param(map))
		return (0);
	return (1);
}

int	create_map_options(t_map_data *map)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (map->map[i])
	{
		if (get_type(map->map[i]) == 0)
			y++;
		i++;
	}
	map->map_options = malloc(sizeof(char *) * (y + 1));
	i = 0;
	y = 0;
	while ((map->map[i]) && (get_type(map->map[i]) == 0
			|| is_space_string(map->map[i])))
	{
		if (!is_space_string(map->map[i]))
			map->map_options[y++] = ft_strdup(map->map[i]);
		i++;
	}
	map->map_options[y] = NULL;
	if (!parse_param(map->map_options, map))
		return (0);
	return (1);
}
