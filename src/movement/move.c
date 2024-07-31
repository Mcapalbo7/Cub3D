/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcapalbo < mcapalbo@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 18:26:46 by mcapalbo          #+#    #+#             */
/*   Updated: 2024/07/31 19:06:04 by mcapalbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	move_forward(t_game_data *game)
{
	double	new_x;
	double	new_y;

	new_x = game->map.player_x + game->map.dir_x * MOVE_SPEED;
	new_y = game->map.player_y + game->map.dir_y * MOVE_SPEED;
	update_pos_no_obstacle(game, new_x, new_y);
}

void	move_backward(t_game_data *game)
{
	double	new_x;
	double	new_y;

	new_x = game->map.player_x - game->map.dir_x * MOVE_SPEED;
	new_y = game->map.player_y - game->map.dir_y * MOVE_SPEED;
	update_pos_no_obstacle(game, new_x, new_y);
}

void	move_left(t_game_data *game)
{
	double	new_x;
	double	new_y;

	new_x = game->map.player_x + game->map.dir_y * MOVE_SPEED;
	new_y = game->map.player_y - game->map.dir_x * MOVE_SPEED;
	update_pos_no_obstacle(game, new_x, new_y);
}

void	move_right(t_game_data *game)
{
	double	new_x;
	double	new_y;

	new_x = game->map.player_x - game->map.dir_y * MOVE_SPEED;
	new_y = game->map.player_y + game->map.dir_x * MOVE_SPEED;
	update_pos_no_obstacle(game, new_x, new_y);
}

void	update_player_pos(t_game_data *game)
{
	if (game->map.move.forward)
		move_forward(game);
	if (game->map.move.backward)
		move_backward(game);
	if (game->map.move.left)
		move_left(game);
	if (game->map.move.right)
		move_right(game);
	if (game->map.move.rotate_left)
		perform_rotation(game, -1);
	if (game->map.move.rotate_right)
		perform_rotation(game, 1);
}
