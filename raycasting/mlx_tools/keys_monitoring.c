#include "../../header.h"


void reset(t_data *data)
{
	data->p.move_dir = 0;
	data->p.rot_dir = 0;
}
static void	which_key(int keysem, t_data *data)
{
	if(keysem == XK_Right)
		data->p.rot_dir = 1;
	if(keysem == XK_Left)
		data->p.rot_dir = -1;
	if(keysem == XK_Up || keysem == XK_w)
		data->p.move_dir = 1;
	if(keysem == XK_Down || keysem == XK_s)
		data->p.move_dir = -1;
	if(keysem == XK_d)
	{
		data->p.step_x = cos(data->p.view_angle + M_PI / 2) * data->p.move_speed;
		data->p.step_y = sin(data->p.view_angle + M_PI / 2) * data->p.move_speed;
	}
	if(keysem == XK_a)
	{
		data->p.step_x = cos(data->p.view_angle - M_PI / 2) * data->p.move_speed;
		data->p.step_y = sin(data->p.view_angle - M_PI / 2) * data->p.move_speed;
	}
}

int press_x(t_data *data)
{
    mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
    mlx_destroy_window(data->mlx_ptr, data->mlx_win);
    mlx_destroy_display(data->mlx_ptr);
    free(data->mlx_ptr);
    exit(0);
    return(0);
}
int	press_key(int keysem, t_data *data)
{
	if (keysem == XK_Escape)
		press_x(data);
	else
		which_key(keysem,data);
	return (0);
}

int release_key(int keysem, t_data *data)
{
	if(keysem == XK_Up || keysem == XK_Down || keysem == XK_s || keysem == XK_w)
		data->p.move_dir = 0;
	if(keysem == XK_Right || keysem == XK_Left)
		data->p.rot_dir = 0;
	if(keysem == XK_d || keysem == XK_a)
	{
		data->p.step_x = 0;
		data->p.step_y = 0;
	}
	return(0);
}