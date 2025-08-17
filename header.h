#ifndef HEADER_H
# define HEADER_H

#include "parsing/libft/libft.h"
#include "parsing/get_next_line/get_next_line.h"
#include <math.h>
# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>

#define SQUARESIZE 32
#define ROWS 10
#define COLMS 10

#define WIDTH ROWS * SQUARESIZE
#define HEIGHT COLMS * SQUARESIZE

#define FOV 60 * (math.p / 180)

#define RES 4
#define NUM_RAYS WIDTH / RES

typedef struct s_img
{
	void	*img_ptr;
	char	*img_pxl_ptr;
	int		b_p_p;
	int		endian;
	int		line_len;
}			t_img;


typedef struct data{
	void *mlx_ptr;
	void *mlx_win;
	int player_x;
	int player_y;
	char p_position;
	int door_x;
	int door_y;
	t_img img;
	char **map;
	
}t_data;


int get_heigth(char *map[]);
int get_width(char *map[]);
int press_x(t_data *data);
void randring_(t_data *data);
int	ft_strcmp(const char *s1, const char *s2);

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
#endif