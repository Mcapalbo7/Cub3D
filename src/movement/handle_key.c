/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcapalbo < mcapalbo@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 18:26:46 by mcapalbo          #+#    #+#             */
/*   Updated: 2024/07/31 19:05:56 by mcapalbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	free_memory_mlx(t_game_data *game)
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
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}

void	destroy_all_textures(t_game_data *game)
{
	mlx_destroy_image(game->mlx, game->texture->no->img);
	mlx_destroy_image(game->mlx, game->texture->so->img);
	mlx_destroy_image(game->mlx, game->texture->we->img);
	mlx_destroy_image(game->mlx, game->texture->ea->img);
	free(game->texture->no);
	free(game->texture->so);
	free(game->texture->we);
	free(game->texture->ea);
	free(game->texture);
}

int	close_game(t_game_data *game)
{
	destroy_all_textures(game);
	mlx_destroy_window(game->mlx, game->window);
	mlx_loop_end(game->mlx);
	free_memory_mlx(game);
	exit(0);
}

int	handle_key_press(int key, t_game_data *game)
{
	if (key == KEY_ESC || key == KEY_ESC_ALT)
		close_game(game);
	if (key == KEY_W || key == KEY_W_ALT)
		game->map.move.forward = 1;
	else if (key == KEY_S || key == KEY_S_ALT)
		game->map.move.backward = 1;
	else if (key == KEY_A || key == KEY_A_ALT)
		game->map.move.left = 1;
	else if (key == KEY_D || key == KEY_D_ALT)
		game->map.move.right = 1;
	else if (key == KEY_LEFT_ARROW || key == KEY_LEFT_ARROW_ALT)
		game->map.move.rotate_left = 1;
	else if (key == KEY_RIGHT_ARROW || key == KEY_RIGHT_ARROW_ALT)
		game->map.move.rotate_right = 1;
	return (0);
}

int	handle_key_release(int key, t_game_data *game)
{
	if (key == KEY_W || key == KEY_W_ALT)
		game->map.move.forward = 0;
	else if (key == KEY_S || key == KEY_S_ALT)
		game->map.move.backward = 0;
	else if (key == KEY_A || key == KEY_A_ALT)
		game->map.move.left = 0;
	else if (key == KEY_D || key == KEY_D_ALT)
		game->map.move.right = 0;
	else if (key == KEY_LEFT_ARROW || key == KEY_LEFT_ARROW_ALT)
		game->map.move.rotate_left = 0;
	else if (key == KEY_RIGHT_ARROW || key == KEY_RIGHT_ARROW_ALT)
		game->map.move.rotate_right = 0;
	return (0);
}
