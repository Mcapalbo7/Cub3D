/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcapalbo < mcapalbo@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 18:26:46 by mcapalbo          #+#    #+#             */
/*   Updated: 2024/07/31 19:06:13 by mcapalbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	check_collision_y(t_game_data *game, double next_y)
{
	int	current_x;
	int	next_map_y_positive;
	int	next_map_y_negative;

	current_x = (int)game->map.player_x;
	next_map_y_positive = (int)(next_y + DELTA);
	next_map_y_negative = (int)(next_y - DELTA);
	if (game->map.map_coords[next_map_y_positive][current_x] != '1' &&
			game->map.map_coords[next_map_y_negative][current_x] != '1')
	{
		return (0);
	}
	return (1);
}

int	check_collision_x(t_game_data *game, double next_x)
{
	int	current_y;
	int	next_map_x_positive;
	int	next_map_x_negative;

	current_y = (int)game->map.player_y;
	next_map_x_positive = (int)(next_x + DELTA);
	next_map_x_negative = (int)(next_x - DELTA);
	if (game->map.map_coords[current_y][next_map_x_positive] != '1' &&
		game->map.map_coords[current_y][next_map_x_negative] != '1')
	{
		return (0);
	}
	return (1);
}

void	update_pos_no_obstacle(t_game_data *game, double next_x, double next_y)
{
	if (!check_collision_y(game, next_y))
	{
		game->map.player_y = next_y;
	}
	if (!check_collision_x(game, next_x))
	{
		game->map.player_x = next_x;
	}
}

void	perform_rotation(t_game_data *game, int direction)
{
	double	old_plane_x;

	old_plane_x = game->map.dir_x;
	game->map.dir_x = game->map.dir_x * cos(direction * ROT_SPEED)
		- game->map.dir_y * sin(direction * ROT_SPEED);
	game->map.dir_y = old_plane_x * sin(direction * ROT_SPEED)
		+ game->map.dir_y * cos(direction * ROT_SPEED);
	old_plane_x = game->map.plane_x;
	game->map.plane_x = game->map.plane_x * cos(direction * ROT_SPEED)
		- game->map.plane_y * sin(direction * ROT_SPEED);
	game->map.plane_y = old_plane_x * sin(direction * ROT_SPEED)
		+ game->map.plane_y * cos(direction * ROT_SPEED);
}
