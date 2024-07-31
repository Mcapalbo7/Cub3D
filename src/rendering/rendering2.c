/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcapalbo < mcapalbo@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 18:14:19 by mla-mona          #+#    #+#             */
/*   Updated: 2024/07/31 18:58:29 by mcapalbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	prepare_img(t_game_data *game)
{
	game->img.img = mlx_new_image(game->mlx, game->win_width,
			game->win_height);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel,
			&game->img.line_length, &game->img.endian);
}

void	render_image(t_game_data *game)
{
	mlx_put_image_to_window(game->mlx, game->window, game->img.img, 0, 0);
	mlx_destroy_image(game->mlx, game->img.img);
}

void	get_texture_index(t_game_data *game, t_raycast *ray)
{
	if (ray->side == 0)
		if (ray->ray_dir_x < 0)
			game->current_tex = game->texture->we;
	else
		game->current_tex = game->texture->ea;
	else
	{
		if (ray->ray_dir_y > 0)
			game->current_tex = game->texture->so;
		else
			game->current_tex = game->texture->no;
	}
}

double	calculate_wall_x(t_raycast *ray, t_game_data *game)
{
	if (ray->side == 0)
	{
		return (game->map.player_y + ray->wall_dist * ray->ray_dir_y);
	}
	else
	{
		return (game->map.player_x + ray->wall_dist * ray->ray_dir_x);
	}
}

int	calculate_texture_x(t_raycast *ray, t_game_data *game)
{
	double	wall_x;
	int		tex_width;
	int		tex_x;

	wall_x = calculate_wall_x(ray, game);
	wall_x -= floor(wall_x);
	tex_width = game->current_tex->width;
	tex_x = (int)(wall_x * (double)tex_width);
	if (ray->side == 0 && ray->ray_dir_x < 0)
	{
		tex_x = tex_width - tex_x - 1;
	}
	if (ray->side == 1 && ray->ray_dir_y > 0)
	{
		tex_x = tex_width - tex_x - 1;
	}
	return (tex_x);
}
