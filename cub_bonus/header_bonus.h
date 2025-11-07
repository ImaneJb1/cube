/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khad <nel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:33:31 by nel-khad          #+#    #+#             */
/*   Updated: 2025/11/07 20:09:56 by nel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_BONUS_H
# define HEADER_BONUS_H

# include "../libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>

# define SQUARESIZE 32
# define MINISCAL 0.2

# define NORTH 0
# define SOUTH 1
# define WEST 2
# define EAST 3
# define DOOR 4

# define WIDTH 1500
# define HEIGHT 900
# define FOV 1.0471975512 //60 * (M_PI / 180)

# define RES 4
# define NUM_RAYS WIDTH
# define COLISION_MARG 2
//garbage collector
typedef struct s_mem
{
	void			*ptr;
	struct s_mem	*next;
}					t_mem;

static t_mem		*g_mem_list = NULL;
typedef struct wall_dim
{
	double		wall_height;
	double		top_wall;
	double		bottom_wall;
}				t_dim;

typedef struct s_line
{
	double		dx;
	double		dy;
	double		move_x;
	double		move_y;
	double		x;
	double		y;
	int			i;
}				t_line;

typedef struct s_intrsc
{
	double		first_int_x;
	double		first_int_y;
	double		next_x;
	double		next_y;
}				t_intrsc;

typedef struct s_img
{
	void		*img_ptr;
	char		*img_pxl_ptr;
	void		*floor;
	void		*wall;
	void		*sky;
	int			b_p_p;
	int			endian;
	int			line_len;
}				t_img;

typedef struct player
{
	double		p_x;
	double		p_y;
	char		direction;
	double		view_angle;
	int			move_dir;
	int			rot_dir;
	double		move_speed;
	double		rot_speed;
	double		right_x;
	double		left_y;
}				t_player;

typedef struct ray
{
	int			id;
	double		distance;
	double		rayangle;
	double		ver_walhit_x;
	double		ver_walhit_y;
	double		hor_walhit_x;
	double		hor_walhit_y;
	double		walhit_y;
	double		walhit_x;
	int			is_up;
	int			is_down;
	int			is_left;
	int			is_right;
	int			hit_vertical;
	int			hit_horiz;
	int			wall_dir;
	char		content;
	double		top_wall;
	int			tex_x; // fin ghanbda nrsem t_textures dyal lwall
}				t_ray;

typedef struct t_texture
{
	int			type;

	void		*img_pxl_ptr;
	void		*img_ptr;
	char		*path;
	int			height;
	int			width;
	int			b_p_p;
	int			endian;
	int			line_len;
	double		step;
	double		tex_pos;
}				t_texture;

typedef struct frame
{
	void		*img_ptr;
	void		*pxl_ptr;
	int			height;
	int			width;
	int			b_p_p;
	int			endian;
	int			line_len;
}				t_frame;

typedef struct weapon
{
	t_frame		intro[20];
	t_frame		walking[20];
	t_frame		shooting[5];
}				t_weapon;

typedef struct data
{
	void		*mlx_ptr;
	void		*mlx_win;
	t_player	p;
	t_ray		ray;
	double		door_x;
	double		door_y;
	t_img		img;
	char		**map;
	int			width;
	int			heigth;
	// t_textures
	int			tex_x;
	t_texture	*arr;
	int			floor_color;
	int			ceiling_color;
	int			vertical_hit;
	int			floor_rgb[3];
	int			ceiling_rgb[3];
	t_weapon	weapon;
	int			moving;
	int			shooting;

}				t_data;

//*******mlx***** */
void			reset(t_data *data);
int				press_x(t_data *data);
int				press_key(int keysem, t_data *data);
int				release_key(int keysem, t_data *data);
void			img_pixel_put(t_img *img, int x, int y, int color);
void			hook_init(t_data *data);

//**********randring******** */

void			draw_square(t_data *data, double x, double y, int color);
void			put_player(t_data *data);
void			render_map(t_data *data);
void			rendring_(t_data *data);
void			draw_ceiling(t_data *data, double top_wall);
void			draw_floor(t_data *data, double bottom_wall);
void			draw_wall(t_data *data, double top_wall, double bottom_wall);

//**********colising***********/
int				is_player_wall(t_data *data, char *map[], double x, double y);
int				is_wall(t_data *data, double x, double y, char c);
double			find_hor_inter(t_data *data, double rayangle);
double			find_ver_inter(t_data *data, double rayangle);

//***********initialisation******* */
void			init_player(t_data *data);
int				get_width(char *map[]);
int				get_heigth(char *map[]);
void			init_ray(t_data *data);
void			data_init(t_data *data);

//***********moves**********/
int				moves_loop(t_data *data);
double			normlizing(double angle);

//***********rays*******/
void			cast_ray(t_data *data, double rayangle);
double			calculate_distance(t_data *data, double x_d, double y_d);
void			cast_allrays(t_data *data);

int				ft_strcmp(const char *s1, const char *s2);
void			render_3d(t_data *data);
void			rendring_(t_data *data);
// typedef struct flags
// {
// 	int no;
// 	int so;
// 	int we;
// 	int ea;
// 	int f;
// 	int c;
// }dir_flags;

typedef struct t_config
{
	char		*direction;
	int			flag;
	char		**texture;
	int			*color;
}				t_config;

typedef struct t_textures
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*f;
	char		*c;
	char		*door;
}				t_textures;

// *************** parsing ***************

void			parse_floor_ceiling(char *line, t_config *arr);
void			parse_dir(char *line, t_config *arr);
t_textures		*init_textures(void);
int				fill_textures_map(char *file_name, t_data *data, int fd,
					t_textures **text);
t_config		*init_dir_arr(t_textures *text);
t_config		*init_fc_arr(t_textures *text, t_data *data);
void			check_textures(void);
int				ft_strcmp(const char *s1, const char *s2);
void			create_map_arr(char *string);
int				check_argv(int argc, char **argv);
void			collect_the_map(char *line, int fd);
void			parse_map(void);
void			free_and_exit(int status);
int				open_file(char *file_name);
int				strlen_2d(char **str);
void			parse_player(char char_map, int x, int y);
int				get_hex_color(char *rgb);
void			get_door(t_data *data);
int				parse_map_file(char *file_name, t_data *data);
// global
t_textures		**text_func(void);
char			***the_map(void);
t_data			*data_func(void);
// garbage collector
void			free_all(void);
void			*gc_calloc(size_t count, size_t size);
void			*gc_malloc(size_t size);
void			destroy_weapon(t_data *data);
void			destroy_all(void);
// t_textures
void			set_tex_x(t_data *data, int type);
void			set_step(double wall_height, t_texture *texture);
void			set_tex_pos(double top_wall, t_texture *texture);
void			fill_image_arr(void *mlx_ptr, t_texture **arr, int size);
t_texture		*init_text_arr(void *mlx_ptr, t_texture **arr, int size);
// void load_all_t_textures(t_data *data);
void			draw_textured_wall(t_data *data, t_texture *texture,
					double top_wall, double bottom_wall);
void			my_img_pixel_put(t_data *data, int x, int y, int color);
t_texture		*init_text_arr(void *mlx_ptr, t_texture **arr, int size);
// weapon
void			draw_first_person_intro(t_data *data, t_frame *frames,
					int size);
void			init_weapon_intro(t_data *data);
void			init_weapon_walking(t_data *data);
void			init_weapon_shooting(t_data *data);
void			init_first_person(t_data *data);
void			draw_first_person_walking(t_data *data, t_frame *frames,
					int size);
void			put_frame(t_data *data, t_frame *frame);
int				shooting(int button, int x, int y, void *param);
void			draw_shooting(t_data *data);
int				get_textures_type(t_data *data);
#endif
