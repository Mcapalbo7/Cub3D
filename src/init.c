/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcapalbo < mcapalbo@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:04:07 by mla-mona          #+#    #+#             */
/*   Updated: 2024/07/31 19:08:10 by mcapalbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3D.h"

void	images_addr(t_game_data *game)
{
	game->texture->no->addr = mlx_get_data_addr(
			game->texture->no->img, &game->texture->no->bpp,
			&game->texture->no->line_length, &game->texture->no->endian);
	game->texture->so->addr = mlx_get_data_addr(
			game->texture->so->img, &game->texture->so->bpp,
			&game->texture->so->line_length, &game->texture->so->endian);
	game->texture->we->addr = mlx_get_data_addr(
			game->texture->we->img, &game->texture->we->bpp,
			&game->texture->we->line_length, &game->texture->we->endian);
	game->texture->ea->addr = mlx_get_data_addr(
			game->texture->ea->img, &game->texture->ea->bpp,
			&game->texture->ea->line_length, &game->texture->ea->endian);
}

void	init_texture(t_game_data *game)
{
	game->texture = (t_texture *)ft_calloc(sizeof(t_texture), 1);
	game->texture->no = (t_texture_img *)ft_calloc(sizeof(t_texture_img), 1);
	game->texture->so = (t_texture_img *)ft_calloc(sizeof(t_texture_img), 1);
	game->texture->we = (t_texture_img *)ft_calloc(sizeof(t_texture_img), 1);
	game->texture->ea = (t_texture_img *)ft_calloc(sizeof(t_texture_img), 1);
	game->texture->no->img = mlx_xpm_file_to_image(
			game->mlx, game->map.no_path,
			&game->texture->no->width, &game->texture->no->height);
	game->texture->so->img = mlx_xpm_file_to_image(
			game->mlx, game->map.so_path,
			&game->texture->so->width, &game->texture->so->height);
	game->texture->we->img = mlx_xpm_file_to_image(
			game->mlx, game->map.we_path, &game->texture->we->width,
			&game->texture->we->height);
	game->texture->ea->img = mlx_xpm_file_to_image(
			game->mlx, game->map.ea_path,
			&game->texture->ea->width, &game->texture->ea->height);
	images_addr(game);
}

void	init_player_move(t_game_data *game)
{
	game->map.move.forward = 0;
	game->map.move.backward = 0;
	game->map.move.left = 0;
	game->map.move.right = 0;
	game->map.move.rotate_left = 0;
	game->map.move.rotate_right = 0;
}
