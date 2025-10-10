#ifndef HEADER_H
# define HEADER_H

#include "parsing/libft/libft.h"
#include "parsing/get_next_line/get_next_line.h"
#include <math.h>
# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <limits.h>

#define SQUARESIZE 32
#define ROWS 10
#define COLMS 10

#define NORTH 0
#define SOUTH 1
#define WEST  2
#define EAST  3

#define WIDTH 1500
#define HEIGHT 900
#define FOV 60 * (M_PI / 180)

#define RES 4
#define NUM_RAYS WIDTH

typedef struct s_line
{
	double dx;
	double dy;
	double move_x;
	double move_y;
	double D;
	double x;
	double y;
	int i;
}t_line;

typedef struct s_intrsc
{
	double first_int_x;
	double first_int_y;
	double next_x;
	double next_y;
}t_intrsc;

typedef struct s_img
{
	void	*img_ptr;
	char	*img_pxl_ptr;
	void	*floor;
	void	*wall;
	void	*sky;
	int		b_p_p;
	int		endian;
	int		line_len;
}			t_img;

typedef struct player{
	double p_x;
	double p_y;
	char direction;
	double view_angle;
	int move_dir;
	int rot_dir;
	int move_speed;
	double rot_speed;
	double step_x;
	double step_y;
}t_player;

typedef struct ray{
	int id;
	double distance;
	double rayangle;
	double ver_walhit_x;
	double ver_walhit_y;
	double hor_walhit_x;
	double hor_walhit_y;
	double walhit_y;
	double walhit_x;
	int is_up;
	int is_down;
	int is_left;
	int is_right;
	int hit_vertical;
	int hit_horiz;
	int wall_dir;
	char content;
}t_ray;

typedef struct data{
	void *mlx_ptr;
	void *mlx_win;
	t_player p;
	t_ray ray;
	int door_x;
	int door_y;
	t_img img;
	char **map;
	int width;
	int heigth;
	//textures
	unsigned int **textures[4]; // 0=N, 1=S, 2=E, 3=W
    int textures_w[4];
    int textures_h[4];
	int floor_color;
	int	ceiling_color;
	
}t_data;

void init_ray(t_data *data);
int get_heigth(char *map[]);
int get_width(char *map[]);
int press_x(t_data *data);
void rendring_(t_data *data);
int	ft_strcmp(const char *s1, const char *s2);
void render_3d(t_data *data);
void rendring_(t_data *data);

// typedef struct flags
// {
// 	int no;
// 	int so;
// 	int we;
// 	int ea;
// 	int f;
// 	int c;
// }dir_flags;

typedef struct config
{
	char	*direction;
	int		flag;
	char	**texture;
}			config;

typedef struct textures
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
}			textures;

// *************** parsing ***************

void		parse_floor_ceiling(char *line, config *arr);
void		parse_dir(char *line, config *arr);
textures	*init_textures(void);
int			fill_textures_map(char *file_name);
config		*init_dir_arr(textures *text);
config		*init_fc_arr(textures *text);
void		check_textures(void);
int			ft_strcmp(const char *s1, const char *s2);
void		create_map_arr(char *string);
int			check_argv(int argc, char **argv);
void		collect_the_map(char *line, int fd);
void		parse_map(void);
void		free_and_exit(int status);
int			open_file(char *file_name);
int			strlen_2d(char **str);
void	parse_player(char char_map, int x, int y);
// global
textures	**text_func(void);
char		***the_map(void);
t_data		*data_func(void);
// garbage collector
void 		free_all(void);
void		*gc_calloc(size_t count, size_t size);
void		*gc_malloc(size_t size);
//textures
void load_all_textures(t_data *data);
#endif