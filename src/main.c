/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcapalbo <mcapalbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 12:02:30 by mla-mona          #+#    #+#             */
/*   Updated: 2024/07/31 16:15:16 by mcapalbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char **argv)
{
	t_game_data	game;
	void		*window;

	window = NULL;
	game = (t_game_data){0};
	if (argc != 2)
		return (write(2, "Input Error!\n", 13), -1);
	if (!validate_map(argv[1], &game.map))
	{
		free_memory(&game);
		return (write(2, "Map Error!\n", 11), -1);
	}
	game.win_width = 720;
	game.win_height = 480;
	game.mlx = mlx_init();
	init_texture(&game);
	init_player_move(&game);
	window = mlx_new_window(game.mlx, game.win_width, game.win_height, "cub3D");
	game.window = window;
	mlx_hook(game.window, EVENTKEYPRESS, MASKKEYPRESS, handle_key_press, &game);
	mlx_hook(game.window, EVENTKEYRELEASE, MASKKEYRELEASE,
		handle_key_release, &game);
	mlx_hook(game.window, EVENT_CLOSE, MASK_CLOSE, close_game, &game);
	mlx_loop_hook(game.mlx, perform_raycasting, &game);
	mlx_loop(game.mlx);
}
