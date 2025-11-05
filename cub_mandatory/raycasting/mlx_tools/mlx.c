#include "../../header.h"

void	hook_init(t_data *data)
{
	mlx_hook(data->mlx_win, KeyPress, KeyPressMask, press_key, data);
	mlx_hook(data->mlx_win, DestroyNotify, 0, press_x, data);
	mlx_hook(data->mlx_win, KeyRelease, KeyReleaseMask, release_key, data);
	mlx_loop_hook(data->mlx_ptr, moves_loop, data);
}

void img_pixel_put(t_data *data, t_img *img, int x, int y, int color)
{
	(void)data;
	int offset;
	if (x < 0 || y < 0 || x >= WIDTH|| y >= HEIGHT)
        return;
	offset = (img->line_len * y) + (x * (img->b_p_p / 8));
	*((unsigned int *)(img->img_pxl_ptr + offset)) = color;
}
