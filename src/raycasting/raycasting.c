/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcapalbo < mcapalbo@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:42:16 by mla-mona          #+#    #+#             */
/*   Updated: 2024/07/31 18:56:43 by mcapalbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	dda(t_raycast *rays, t_game_data *game, int step_x, int step_y)
{
	while (1)
	{
		if (rays->side_x < rays->side_y)
		{
			rays->side_x += rays->delta_x;
			rays->map_x += step_x;
			rays->side = 0;
		}
		else
		{
			rays->side_y += rays->delta_y;
			rays->map_y += step_y;
			rays->side = 1;
		}
		if (game->map.map_coords[rays->map_y][rays->map_x] == '1')
			break ;
	}
	if (rays->side == 0)
		rays->wall_dist = rays->side_x - rays->delta_x;
	else
		rays->wall_dist = rays->side_y - rays->delta_y;
}

void	side_dist(t_raycast *rays, t_game_data *game, t_map_data map)
{
	int	step_x;
	int	step_y;

	if (rays->ray_dir_x < 0)
	{
		step_x = -1;
		rays->side_x = (game->map.player_x - rays->map_x) * rays->delta_x;
	}
	else
	{
		step_x = 1;
		rays->side_x = (rays->map_x + 1.0 - map.player_x) * rays->delta_x;
	}
	if (rays->ray_dir_y < 0)
	{
		step_y = -1;
		rays->side_y = (game->map.player_y - rays->map_y) * rays->delta_y;
	}
	else
	{
		step_y = 1;
		rays->side_y = (rays->map_y + 1.0 - map.player_y) * rays->delta_y;
	}
	dda(rays, game, step_x, step_y);
}

void	calc_rays(t_raycast *rays, int x, t_game_data *game)
{
	rays->camera_x = 2 * x / (double)game->win_width - 1;
	rays->ray_dir_x = rays->dir_x + rays->plane_x * rays->camera_x;
	rays->ray_dir_y = rays->dir_y + rays->plane_y * rays->camera_x;
	rays->delta_x = fabs(1 / rays->ray_dir_x);
	rays->delta_y = fabs(1 / rays->ray_dir_y);
	side_dist(rays, game, game->map);
}

void	calc_line_height(t_raycast *rays, t_game_data *game)
{
	rays->line_height = (int)(game->win_height / rays->wall_dist);
	rays->draw_start = -rays->line_height / 2 + game->win_height / 2;
	if (rays->draw_start < 0)
		rays->draw_start = 0;
	rays->draw_end = rays->line_height / 2 + game->win_height / 2;
	if (rays->draw_end >= game->win_height)
		rays->draw_end = game->win_height - 1;
}

int	perform_raycasting(t_game_data *game)
{
	int			x;
	t_raycast	ray;
	int			tex_x;

	ray = game->ray;
	prepare_img(game);
	update_player_pos(game);
	x = 0;
	while (x < game->win_width)
	{
		reset_raycast(&ray, &game->map);
		calc_rays(&ray, x, game);
		calc_line_height(&ray, game);
		get_texture_index(game, &ray);
		tex_x = calculate_texture_x(&ray, game);
		draw_wall(game, x, ray, tex_x);
		draw_ceiling(game, x, ray.draw_start);
		draw_floor(game, x, ray.draw_end);
		x++;
	}
	render_image(game);
	return (0);
}
