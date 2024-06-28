/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajjid <tajjid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:18:54 by tajjid            #+#    #+#             */
/*   Updated: 2023/12/16 14:39:22 by tajjid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define BUFFER_SIZE 5

# include "mlx.h"
# include <math.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>

# define HEIGHT 1080
# define WIDTH 1920
# define TILE_SIZE 32
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
# define W_KEY 13
# define ESC 53
# define LEFT_ARROW 123
# define RIGHT_ARROW 124
# define FORWARD_ARROW 126
# define BACKWARD_ARROW 125
# define SPEED 3
# define ROTATION_SPEED 3
# define WALL_STRIP_WIDTH 1
# define FOV_ANGLE 1.0472
# define NUM_RAYS WIDTH
# define MINIMAP_SCALE 0.2

# define WHITE 0x00FFFFFF
# define BLACK 0x00000000
# define GREY 0x00A9A9A9
# define RED 0x00FF0000
# define PINK 0x00FF00FF
# define PURPLE 0x00800080
# define ORANGE 0x00FFA500
# define YELLOW 0x00FFFF00
# define GREEN 0x0000FF00
# define BLUE 0x000000FF
# define CYAN 0x0000FFFF

typedef struct img_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img_data;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}			t_mlx;

typedef struct s_player_data
{
	double	player_x;
	double	player_y;
	double	player_angle;
	int		turn_direction;
	int		walk_direction;
	int		walk_direction_side;
}			t_player_data;

typedef struct s_map_data
{
	char	*basic_map;
	char	**map;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*floor;
	char	*ceiling;
	int		floor_color;
	int		ceiling_color;
	int		map_width;
	int		map_height;
}			t_map_data;

typedef struct s_ray
{
	double	ray_angle;
	double	distance;
	double	hit_x;
	double	hit_y;
	int		hit_up;
	int		hit_down;
	int		hit_left;
	int		hit_right;
	int		hit_vertical;
	double	firsthori_intersection_y;
	double	firsthori_intersection_x;
	double	firstvert_intersection_y;
	double	firstvert_intersection_x;
}	t_ray;

typedef struct s_horizontal
{
	double	distance_h;
	double	next_htouch_x;
	double	hit_x;
	double	hit_y;
	double	next_htouch_y;
	double	y_step;
	double	x_step;
}	t_horizontal;

typedef struct s_vertical
{
	double	distance_v;
	double	next_vtouch_x;
	double	next_vtouch_y;
	double	hit_x;
	double	hit_y;
	double	y_step;
	double	x_step;
}	t_vertical;

typedef struct s_texture
{
	int				height;
	int				width;
	double			offset_x;
	double			offset_y;
	t_img_data		image;
}			t_texture;

typedef struct s_minimap
{
	t_img_data		image;
	int				size;
	int				map_x;
	int				map_y;
	int				map_end_x;
	int				map_end_y;
}			t_minimap;

typedef struct s_glob
{
	t_player_data	*player;
	t_map_data		*da_map;
	t_mlx			*da_mlx;
	t_img_data		*da_img;
	t_ray			**rays;
	t_horizontal	*h_values;
	t_vertical		*v_values;
	t_texture		*no_texture;
	t_texture		*so_texture;
	t_texture		*we_texture;
	t_texture		*ea_texture;
	t_minimap		*minimap;
}			t_glob;

/*				   Main					*/
void	allocator(t_glob *glob);
void	initializer(t_glob *glovo);
void	initializer_2(t_glob *glovo);
void	free_stuff(t_glob *glob);
void	error_stuff(int error);
void	parsing_stuff(char *map, t_glob *glob);
void	drawing_stuff(t_glob *glob);

/*				 Game tools 			*/
int		game_generator(t_glob *glob);
int		key_press(int key, t_glob *glob);
int		key_release(int key, t_glob *glob);
void	player_movement_strait(t_glob *glob);
void	player_movement_side(t_glob *glob);
int		mouse_motion(int x, int y, t_glob *glob);
int		is_it_a_wall(t_glob *glob, double x, double y);

/*				Minimap	tools			*/
void	minimap_drawer(t_glob *glob);
void	player_drawer(t_glob *glob);
void	squares_drawer(t_glob *glob, int x_d, int y_d);
void	player_rotation(t_glob *glob);
void	my_mlx_pixel_put(t_img_data *data, int x, int y, long int color);

/*				Parsing	tools			*/
void	check_filename(char *str, int option);
void	map_opener(char *map, t_glob *glob);
void	map_checker(t_glob *glob);
void	map_border_checker(t_glob *glob, int i, int j);
void	player_checker(t_glob *glob);
void	check_line(char *line, t_glob *glob);
void	check_line_2(char *line, t_glob *glob);
void	map_filler(int fd, char *reader, t_glob *glob);
char	*map_resizer(char *map, size_t line_lenght);
void	check_f_c(char *str, int flag, t_glob *glob);
void	check_f_c_numbers(char *str, int flag, t_glob *glob);
int		destroy(void);

/*				Libft tools				*/
char	*ft_strchr(char *s, int c);
int		ft_strncmp(char *s1, char *s2, size_t n);
char	*ft_strjoin(char *s1, char *s2, int flag);
char	*ft_substr(char *s, unsigned int start, size_t len);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strtrim(char *s1, char *set);
void	ft_bzero(void *s, size_t n);
char	*ft_strdup(char *s1);
char	**ft_split(char *s, char c);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);

/*			Get_Next_Line tools			*/
char	*get_next_line(int fd);
char	*ft_read(char *save, int fd);
size_t	ft_strlen(char *str);
char	*ft_strchr_gnl(char *s, int c);
char	*ft_strdup_gnl(char *s1);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_substr_gnl(char *s, unsigned int start, size_t len);

/*			   Ray_casting				*/
void	ray_casting(t_glob *glob);
void	ray_initializer(t_ray *ray, double ray_angle);
double	normalize_ray_angle(double ray_angle);
void	horizontal_intersection(t_glob *glob, t_ray *ray);
void	vertical_intersection(t_glob *glob, t_ray *ray);
void	hit_down_or_up(t_ray *ray);
void	hit_right_or_left(t_ray *ray);
double	degreestoradians(double value);
double	distance_between_point(double x1, double x2, double y1, double y2);
void	comparing_distances(t_ray *ray, t_glob *glob);
bool	ray_is_it_a_wall(t_glob *glob, double x, double y);

/*				   Texture				*/
void	textures_checker(t_glob *glob);
void	textures_img(t_glob *glob);
void	textures_addr(t_glob *glob);
void	wall_rendrer(t_glob *glob);
void	wall_drawer(t_glob *glob, int i, double wall_strip_height, \
		t_texture *texture);
void	wall_drawer_checker(t_glob *glob, int i, double distance_proj_plane);
int		get_pixel_color(t_texture *texture, int x, int y);
void	set_color(t_glob *glob, char **colors, int flag);
int		rgb_to_int(int r, int g, int b);

#endif