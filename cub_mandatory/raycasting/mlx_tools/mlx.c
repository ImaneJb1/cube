#include "../../header.h"


// int mouse_move(int x, int y, t_data *data)
// {
//     int dx = x - data->mouse_last_x; // horizontal movement
//     data->mouse_last_x = x;

//     double rot_speed = 0.003; // adjust sensitivity
//     data->p.view_angle += dx * rot_speed;
//     data->p.view_angle = normlizing(data->p.view_angle);

//     return 0;
// }


void	hook_init(t_data *data)
{
	mlx_hook(data->mlx_win, KeyPress, KeyPressMask, press_key, data);
	// mlx_hook(data->mlx_win, MotionNotify, 0, mouse_move, data);

	// mlx_hook(data->mlx_win, ButtonPress, ButtonPressMask, press_mouse, data);
	mlx_hook(data->mlx_win, DestroyNotify, 0, press_x, data);
	mlx_hook(data->mlx_win, KeyRelease, KeyReleaseMask, release_key, data);
	mlx_loop_hook(data->mlx_ptr, moves_loop, data);
}

void img_pixel_put(t_data *data, t_img *img, int x, int y, int color)
{
	int offset;
	if (x < 0 || y < 0 || x >= WIDTH|| y >= HEIGHT)
        return;
	offset = (img->line_len * y) + (x * (img->b_p_p / 8));
	*((unsigned int *)(img->img_pxl_ptr + offset)) = color;
}
