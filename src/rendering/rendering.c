/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcapalbo < mcapalbo@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 17:33:19 by mla-mona          #+#    #+#             */
/*   Updated: 2024/07/31 18:57:19 by mcapalbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	set_pixel(t_game_data *game, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= game->win_width || y < 0 || y >= game->win_height)
		return ;
	dst = game->img.addr + (y * game->img.line_length + x
			* (game->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_ceiling(t_game_data *game, int x, int draw_start)
{
	int	color;
	int	y;

	color = convert_color_to_int(game->map.ceiling_color);
	y = 0;
	while (y < draw_start)
	{
		set_pixel(game, x, y, color);
		y++;
	}
}

void	draw_floor(t_game_data *game, int x, int draw_end)
{
	int	color;
	int	y;

	color = convert_color_to_int(game->map.floor_color);
	y = draw_end;
	while (y < game->win_height)
	{
		set_pixel(game, x, y, color);
		y++;
	}
}

void	draw_wall(t_game_data *game, int x, t_raycast ray, int tex_x)
{
	double	step;
	double	tex_pos;
	int		color;
	int		*texture_data;
	int		tex_y;

	texture_data = (int *)game->current_tex->addr;
	step = 1.0 * game->current_tex->height / ray.line_height;
	tex_pos = (ray.draw_start - game->win_height / 2 + ray.line_height / 2)
		* step;
	while (ray.draw_start < ray.draw_end)
	{
		tex_y = (int)tex_pos & (game->current_tex->height - 1);
		tex_pos += step;
		color = texture_data[game->current_tex->height * tex_y + tex_x];
		if (ray.side == 1)
		{
			color = (color >> 1) & 8355711;
		}
		set_pixel(game, x, ray.draw_start, color);
		ray.draw_start++;
	}
}
