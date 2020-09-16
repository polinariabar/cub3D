/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 17:31:42 by leweathe          #+#    #+#             */
/*   Updated: 2020/06/29 18:28:16 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>

# define PI 3.1415926

/*
** PARSING PART STRUCTURES
*/
typedef struct		s_textures
{
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*s;
}					t_textures;

typedef struct		s_map_params
{
	int				resolution[3];
	int				floor[2];
	int				ceilling[2];
}					t_map_params;

/*
** GRAPHIC PART STRUCTURES
*/

typedef struct		s_image
{
	void			*img_ptr;
	char			*img_addr;
	int				width;
	int				height;
	int				bpp;
	int				line_length;
	int				endian;
}					t_image;

typedef struct		s_player
{
	float			x_pos;
	float			y_pos;
	float			dx;
	float			dy;
	long double		angle;
	float			cos_angle;
	float			sin_angle;
}					t_player;

typedef struct		s_ray_params
{
	float			ray_angle;
	float			vert_len;
	float			hor_len;
	float			length;
	float			actual_wall_height;
	float			wall_height;
	float			offset;
	int				ray;
}					t_ray_params;

typedef struct		s_sprites
{
	int				x;
	int				y;
	int				act_x;
	int				act_y;
	float			dist;
}					t_sprites;

typedef struct		s_ray
{
	float			x;
	float			y;
	float			x_offset;
	float			y_offset;
	int				map_x;
	int				map_y;
	float			length;
}					t_ray;

typedef struct		s_sprite_conf
{
	float			height;
	float			width;

	int				y_start;
	int				y_end;
	int				x_start;
	int				x_end;

	int				screen_position;
	float			x_cam_pos;
	float			y_cam_pos;

	float			angle;
	float			x_pixel_pos;
	float			y_pixel_pos;

	float			dist;
	float			cosinus;
}					t_sprite_conf;

typedef struct		s_window
{
	void			*mlx;
	void			*win;

	void			*img;
	char			*img_addr;

	int				bits_per_pixel;
	int				line_length;
	int				endian;

	int				x_res;
	int				y_res;
}					t_window;

typedef struct		s_vars
{
	t_window		*window;
	t_player		*player;
	t_image			**texture;
	t_sprites		*sprite;
	int				*sprite_order;
	int				sprite_count;
	int				texture_index;
	int				floor;
	int				ceilling;
	char			**map;
	float			proj_plane;
	float			*lengthes;
	float			vert_ray[3];
	float			hor_ray[3];
}					t_vars;

/*
** ___________________________MAIN FUNCTIONS_____________________________
*/

/*
** INITIALIZATION
** PATH: srcs/init_structures.c
*/
t_textures			*init_textures(void);
t_map_params		*init_params(void);
void				free_textures(t_textures *texture);
int					free_config(char *line, char **parsed_line,
								t_textures *texture, t_map_params *params);

/*
** PARSE FILE
** PATH: srcs/read_config.c set_config.c read_map.c
*/
int					read_configurations(int fd, t_textures *texture,
										t_map_params *params);
int					set_params(char **list, t_map_params *params, char *flag);

int					set_floor(char **list, t_map_params *params, int len);
int					set_resolution(char **list, t_map_params *params, int len);
int					set_textures(char **list, t_textures *texture, char *flag);
int					set_ceilling(char **list, t_map_params *params, int len);

char				**read_map(int fd);
int					check_position(char **map);
int					check_full_map(char **map);

/*
** ERROR MASSEGES
** PATH: srcs/error_massege.c
*/
int					error(char type);

/*
** HELP FUNCTIONS
** PATH: /srcs (all files with ft_*)
*/
int					get_next_line(int fd, char **line);
int					ft_mass_len(char **mass);
int					ft_one_of_them(char c, char *str);
int					ft_one_of_them_mass(char **map, char *set);
int					ft_one_of_them_coord(char **map, char *set, int *x, int *y);
void				ft_free_array(char **arr);
int					ft_create_rgb(int r, int g, int b);
float				ft_straight_len(int x_start, int y_start,
									float x_end, float y_end);
char				**ft_realloc_mass(char **map, char *line);

/*
** ___________________________DRAW FUNCTIONS_____________________________
*/

/*
** START GAME
** PATH: draw_srcs/main_graphic.c
*/
int					main_graphic(t_textures *texture, t_map_params *params,
								char **map, int screenshot);
int					display(t_vars *var);
void				create_win_img(t_vars *var);

/*
** FREE
** PATH: draw_srcs/free_structs.c
*/
void				free_var_window(t_vars *var);
void				free_var_textures(t_vars *var);

/*
** EXIT GAME
** PATH: draw_srcs/exit_game.c
*/
void				exit_game(t_vars *var);
void				if_error_exit(t_textures *name_texture,
					t_map_params *params, char **map, char code);

/*
** INITIALIZATION
** PATH: draw_srcs/init_struct.c
*/
t_player			*init_player_struct(char **map);
t_vars				*init_var_struct(char **map, t_map_params params);
t_window			*init_win_struct(t_map_params params);
t_image				*init_texture(t_vars *var, char *texture_name);
int					init_var_textures(t_vars *var, t_textures *name_texture);

/*
** PRINT FIGURES
** PATH: draw_srcs/print_figures.c
*/
void				print_column(t_vars *var, float *params, int color);
int					get_color_flom_texture(t_vars *var, int numb, int x, int y);
void				print_walls(t_vars *var, float *print_params, float hint);
void				print_pix(t_vars *var, int x_start, int y_start, int color);
void				print_sprite_pix(t_vars *var, t_sprite_conf spr, int y,
									int stripe);

/*
** DRAW
** PATH: draw_srcs/draw.c
*/
void				draw(t_vars *var);
void				draw_column(t_vars *var, float ray_angle, int col);
void				draw_floor_ceilling(t_ray_params ray, t_vars *var);
void				draw_walls(t_ray_params ray, t_vars *var,
								float *print_params);

/*
** RAY CASTING
** PATH: draw_srcs/casting_rays.c correction.c
*/
void				horizontal_ray(t_vars *var, float ray_angle);
void				horizontal_ray_wall(t_vars *var, t_ray *ray);
void				vertical_ray(t_vars *var, float ray_angle);
void				vertical_ray_wall(t_vars *var, t_ray *ray);

float				correction(float length, float player_angle,
								float ray_angle);

/*
** KEY EVENTS
** PATH: draw_srcs/key_events.c movements.c
*/
int					move(int key, t_vars *var);
int					destroy_window(void *param);

void				rotate(t_vars *var, char direction);
void				move_up_down(t_vars *var, char direction);
void				move_left_right(t_vars *var, char direction);

/*
** SPRITES
** PATH: draw_srcs/sprites.c sort_sprites.c
*/
t_sprites			*init_sprites(t_vars *var);
void				count_sprites(t_vars *var);
void				sprite_configs(t_vars *var, t_sprite_conf *spr, int i);
void				draw_sprites(t_vars *var);

void				sort_sprites(t_vars *var);
void				sort_sprites_2(t_vars *var, float *dist);

/*
** SCREENSHOT
*/
void				int_to_char(unsigned char *c, int i);
int					bmp_header(int fd, int h, int w, int padsize);
int					get_color(t_vars *var, int x, int y);
int					draw_screenshot(t_vars *var, int padsize, int fd);
int					make_screenshot(t_vars *var);

#endif
