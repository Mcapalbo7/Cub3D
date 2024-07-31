/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcapalbo < mcapalbo@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 12:18:20 by mla-mona          #+#    #+#             */
/*   Updated: 2024/07/31 18:53:09 by mcapalbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include <math.h>

# define EVENTKEYPRESS 2
# define EVENTKEYRELEASE 3
# define EVENT_CLOSE 17

# define MASKKEYPRESS 1//(1L << 0)
# define MASKKEYRELEASE 2//(1L << 1)
# define MASK_CLOSE 131072//(1L << 17)

# define KEY_ESC 53
# define KEY_ESC_ALT 65307
# define KEY_W 13
# define KEY_W_ALT 119
# define KEY_S 1
# define KEY_S_ALT 115
# define KEY_A 0
# define KEY_A_ALT 97
# define KEY_D 2
# define KEY_D_ALT 100

# define KEY_LEFT_ARROW 123
# define KEY_LEFT_ARROW_ALT 65361
# define KEY_RIGHT_ARROW 124
# define KEY_RIGHT_ARROW_ALT 65363

# define MOVE_SPEED 0.01
# define ROT_SPEED 0.02
# define DELTA 0.03

# define BUFFER_SIZE 1000

typedef struct s_color
{
	int	red;
	int	green;
	int	blue;
}	t_color;

typedef struct s_raycast
{
	int		map_x;
	int		map_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	delta_x;
	double	delta_y;
	double	side_x;
	double	side_y;
	double	wall_dist;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		side;
}	t_raycast;

typedef struct s_movement
{
	int	forward;
	int	backward;
	int	left;
	int	right;
	int	rotate_left;
	int	rotate_right;
}	t_movement;

typedef struct s_texture_img
{
	void	*img;
	void	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_texture_img;

typedef struct s_texture
{
	t_texture_img	*no;
	t_texture_img	*so;
	t_texture_img	*we;
	t_texture_img	*ea;
}	t_texture;

typedef struct s_mlx_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_mlx_img;

typedef struct s_map_data
{
	char		**map;
	char		*no_path;
	char		*so_path;
	char		*we_path;
	char		*ea_path;
	t_color		ceiling_color;
	t_color		floor_color;
	char		**map_options;
	char		**map_coords;
	int			facing_dir;
	double		player_x;
	double		player_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	t_movement	move;
}	t_map_data;

typedef struct s_game_data
{
	void			*mlx;
	void			*window;
	int				win_width;
	int				win_height;
	t_map_data		map;
	t_raycast		ray;
	void			*img_ptr;
	int				*img_data;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	t_texture		*texture;
	t_texture_img	*current_tex;
	t_mlx_img		img;
}	t_game_data;

void	initialize_map(t_map_data *map);
void	init_texture(t_game_data *game);
void	init_player_move(t_game_data *game);
void	reset_raycast(t_raycast *ray, t_map_data *map);
void	draw_wall(t_game_data *game, int x, t_raycast ray, int tex_x);
void	draw_ceiling(t_game_data *game, int x, int draw_start);
void	draw_floor(t_game_data *game, int x, int draw_end);
void	get_texture_index(t_game_data *game, t_raycast *ray);
int		calculate_texture_x(t_raycast *ray, t_game_data *game);
void	prepare_img(t_game_data *game);
void	render_image(t_game_data *game);
void	set_pixel(t_game_data *game, int x, int y, int color);
int		is_space_string(char *str);
int		matrix_length(char **matrix);
int		is_space_inside(char *str);
int		get_type(char *str);
void	remove_newline(char **map);
char	*extract_path(char *str);
void	free_matrix(char **matrix);
void	free_memory(t_game_data *game);
void	parse_rgb(char *str, t_color *color);
int		convert_color_to_int(t_color color);
int		check_wall_bord(int x, int y, char **matrix);
int		validate_floor_line(char **matrix, size_t last);
int		get_first_char(char *str);
int		check_last_line(char *last, char *prev);
int		validate_map_row(char **matrix, int x, int y);
int		verify_wall(char **matrix);
int		locate_player(char **matrix, t_map_data *map);
int		validate_map(char *path, t_map_data *map);
int		check_extension(char *path);
int		does_map_exist(char *path, t_map_data *map);
void	set_player_orientation(char direction, t_map_data *map, int x, int y);
int		create_map_options(t_map_data *map);
int		parse_param(char **options, t_map_data *map);
int		perform_raycasting(t_game_data *game);
int		handle_key_press(int key, t_game_data *game);
int		handle_key_release(int key, t_game_data *game);
void	update_player_pos(t_game_data *game);
void	update_pos_no_obstacle(t_game_data *game, double next_x, double next_y);
void	perform_rotation(t_game_data *game, int direction);
int		close_game(t_game_data *game);
void	reset_color(t_color *color);
char	*get_next_line(int fd);
int		check_extension2(t_map_data*map);
int		check_characters(char **mat);
int		map_size(char **map);

#endif
