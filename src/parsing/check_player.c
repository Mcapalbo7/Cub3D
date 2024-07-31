/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcapalbo < mcapalbo@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 15:08:03 by mcapalbo          #+#    #+#             */
/*   Updated: 2024/07/31 19:06:29 by mcapalbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	get_pov_nord_sud(char direction, t_map_data *map)
{
	if (direction == 'S')
	{
		map->dir_x = 0;
		map->dir_y = 1;
		map->plane_x = -0.66;
		map->plane_y = -0;
	}
	if (direction == 'N')
	{
		map->dir_x = 0;
		map->dir_y = -1;
		map->plane_x = 0.66;
		map->plane_y = 0;
	}
}

void	get_pov_est_ovest(char direction, t_map_data *map)
{
	if (direction == 'W')
	{
		map->dir_x = -1;
		map->dir_y = 0;
		map->plane_x = 0;
		map->plane_y = -0.66;
	}
	if (direction == 'E')
	{
		map->dir_x = 1;
		map->dir_y = 0;
		map->plane_x = 0;
		map->plane_y = 0.66;
	}
}

void	set_player_orientation(char direction, t_map_data *map, int x, int y)
{
	if (direction == 'N' || direction == 'S')
		get_pov_nord_sud(direction, map);
	if (direction == 'E' || direction == 'W')
		get_pov_est_ovest(direction, map);
	map->player_x = x + 0.5;
	map->player_y = y + 0.5;
}

int	locate_player(char **mat, t_map_data *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (mat[i])
	{
		j = 0;
		while (mat[i][j])
		{
			if (mat[i][j] == 'N' || mat[i][j] == 'S' ||
				mat[i][j] == 'W' || mat[i][j] == 'E')
			{
				if (map->player_x == -1 && map->player_y == -1)
					set_player_orientation(mat[i][j], map, j, i);
				else
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
