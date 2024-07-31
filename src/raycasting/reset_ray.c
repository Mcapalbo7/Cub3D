/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mla-mona <mla-mona@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 18:07:15 by mla-mona          #+#    #+#             */
/*   Updated: 2024/07/26 16:27:59 by mla-mona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	reset_raycast(t_raycast *ray, t_map_data*map)
{
	ray->dir_x = map->dir_x;
	ray->dir_y = map->dir_y;
	ray->plane_x = map->plane_x;
	ray->plane_y = map->plane_y;
	ray->camera_x = 0;
	ray->ray_dir_x = 0;
	ray->ray_dir_y = 0;
	ray->delta_x = 0;
	ray->delta_y = 0;
	ray->side_x = 0;
	ray->side_y = 0;
	ray->map_x = (int)map->player_x;
	ray->map_y = (int)map->player_y;
	ray->wall_dist = 0;
	ray->line_height = 0;
	ray->draw_start = 0;
	ray->draw_end = 0;
}
