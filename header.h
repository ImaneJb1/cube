#ifndef HEADER_H
#define HEADER_H
#include "parsing/libft-project/libft.h"
#include <fcntl.h>
#include "parsing/get_next_line/get_next_line.h"
#include <math.h>
# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>

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
	int shift_x;
	int shift_y;
	
	t_img img;
	char **map;
	
}t_data;


int get_heigth(char *map[]);
int get_width(char *map[]);
int press_x(t_data *data);
void randring_(t_data *data);
int	ft_strcmp(const char *s1, const char *s2);

#endif