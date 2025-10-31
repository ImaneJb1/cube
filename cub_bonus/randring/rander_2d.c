#include "../header.h"

// void draw_circle(t_data *data, int color)
// {
// 	int radius;
// 	double dx;
// 	double dy;
// 	radius = 5;

// 	double y;
// 	double x;
// 	y = data->p.p_y - radius;
// 	while (y <= data->p.p_y + radius)
// 	{
// 		x = data->p.p_x - radius;
// 		while (x <= data->p.p_x + radius)
// 		{
// 			dx = x - data->p.p_x;
// 			dy = y - data->p.p_y;
// 			if (dx*dx + dy*dy <= radius*radius)//check if the point inside
// 				img_pixel_put(data, &data->img, x, y, color);
// 			x++;
// 		}
// 		y++;
// 	}
// }
// void draw_circle_mini(t_data *data, int x, int y, int color)
// {
// 	int radius = 2;
// 	int dy = -radius;
// 	while (dy <= radius)
// 	{
// 		int dx = -radius;
// 		while (dx <= radius)
// 		{
// 			if (dx * dx + dy * dy <= radius * radius)
// 				img_pixel_put(data, &data->img, x + dx, y + dy, color);
// 			dx++;
// 		}
// 		dy++;
// 	}
// }

// void draw_square(t_data *data, double x, double y, int color)
// {
// 	int i;
// 	int j;
// 	j = 0;
// 	i = 0;

// 	while(i < SQUARESIZE / 4)
// 	{
// 		j = 0;
// 		while(j < SQUARESIZE / 4)
// 		{
// 			if(j ==( SQUARESIZE / 4) - 1 || i ==( SQUARESIZE / 4) -1 || i == 0
				// || j == 0)
// 				img_pixel_put(data, &data->img, x + j, y + i, 0x000000);
// 			else
// 				img_pixel_put(data, &data->img, x + j, y + i, color);
// 			j++;
// 		}
// 		i++;
// 	}
// }

// void put_player(t_data *data)
// {
// 	draw_circle_mini(data,200 / 2, 200 / 2 ,0xFF69B4);
// }

// int inside_circle(int radius, double x, double y, t_data *data)
// {
// 	double dx;
// 	double dy;

// 	dx = x - data->p.p_x;
// 	dy = y - data->p.p_y;
// 	if (dx*dx + dy*dy <= radius*radius)//check if the point inside
// 		return(1);
// 	return(0);
// }

// // && inside_circle(50, j * SQUARESIZE, i * SQUARESIZE, data)

// void render_map(t_data *data)
// {

// 	int i;
// 	int j;
// 	int color;

// 	i = 0;
// 	j = 0;
// 	color = -1;
// 	int px;
// 	int py;
// 	double coin_x;
// 	double coin_y;
// 	double tile_x;
// 	double tile_y;

// 	// usleep(10000);
// 	// mlx_clear_window(data->mlx_ptr, data->mlx_win);
// 	coin_x = data->p.p_x - 800 / 2;//mini map size (pixels) * echel de reduction
		// / 2
// 	coin_y = data->p.p_y - 800 / 2;
// 	while(data->map[i])
// 	{
// 		j = 0;
// 		while(data->map[i][j])
// 		{
// 			if(data->map[i][j] == '1')
// 				color = 0xffffff;
// 			else if(data->map[i][j] == '0' || ft_strchr("SNWE",data->map[i][j]))
// 				color = 0x87CEEB;
// 			else if(data->map[i][j] == 'D')
// 				color = 0xFFF000;
// 			tile_x = (j * SQUARESIZE - coin_x) / 4;
// 			tile_y = (i * SQUARESIZE - coin_y) / 4;

// 			if(color > 0 && tile_x < 200 && tile_y < 200 && tile_y >= 0
				// && tile_x >= 0)
// 				draw_square(data, j * SQUARESIZE - coin_x, i * SQUARESIZE
					// - coin_y, color);/
// 			color = -1;
// 			j++;
// 		}
// 		i++;
// 	}
// }

// void rendring_(t_data *data)
// {
// 	mlx_clear_window(data->mlx_ptr, data->mlx_win);
// 	render_map(data);
// 	put_player(data);
// 	cast_allrays(data);
// 	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img.img_ptr, 0,
// 		0);
// 	mlx_do_sync(data->mlx_ptr);
// }

void	draw_circle(t_data *data)
{
	int	radius;
	int	px;
	int	py;
	int	dy;
	int	dx;

	radius = 2;
	px = data->p.p_x * MINISCAL;
	py = data->p.p_y * MINISCAL;
	dy = -radius;
	while (dy <= radius)
	{
		dx = -radius;
		while (dx <= radius)
		{
			if (dx * dx + dy * dy <= radius * radius)
				img_pixel_put(data, &data->img, px + dx, py + dy, 0xFF69B4);
			dx++;
		}
		dy++;
	}
}

// void draw_circle(t_data *data, int color)
// {
// 	int radius;
// 	double dx;
// 	double dy;
// 	radius = 5;

// 	double y;
// 	double x;
// 	y = data->p.p_y * MINISCAL - radius;
// 	while (y <= data->p.p_y * MINISCAL + radius)
// 	{
// 		x = data->p.p_x * MINISCAL - radius;
// 		while (x <= data->p.p_x + radius)
// 		{
// 			dx = x - (data->p.p_x / SQUARESIZE) * MINISCAL;
// 			dy = y - (data->p.p_y / SQUARESIZE) * MINISCAL;
// 			if (dx*dx + dy*dy <= radius*radius)//check if the point inside
// 				img_pixel_put(data, &data->img, x, y, color);
// 			x++;
// 		}
// 		y++;
// 	}

// }

void	draw_square(t_data *data, double x, double y, int color)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < SQUARESIZE * MINISCAL)
	{
		j = 0;
		while (j < SQUARESIZE * MINISCAL)
		{
			if (j == SQUARESIZE * MINISCAL - 1 || i == SQUARESIZE * MINISCAL - 1
				|| i == 0 || j == 0)
				img_pixel_put(data, &data->img, x + j, y + i, 0x000000);
			else
				img_pixel_put(data, &data->img, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

void	put_player(t_data *data)
{
	draw_circle(data);
}

int	inside_circle(int radius, double x, double y, t_data *data)
{
	double	dx;
	double	dy;

	dx = x - data->p.p_x;
	dy = y - data->p.p_y;
	if (dx * dx + dy * dy <= radius * radius) // check if the point inside
		return (1);
	return (0);
}

void	render_map(t_data *data)
{
	int	i;
	int	j;
	int	color;

	i = 0;
	j = 0;
	color = -1;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '1')
				color = 0xffffff;
			else if (data->map[i][j] == '0' || ft_strchr("SNWE",
					data->map[i][j]))
				color = -1;
			if (color > 0)
				draw_square(data, j * SQUARESIZE * MINISCAL, i * SQUARESIZE
					* MINISCAL, color);
			color = -1;
			j++;
		}
		i++;
	}
}

void	rendring_(t_data *data)
{
	// render_map(data);
	// put_player(data);
	cast_allrays(data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img.img_ptr, 0,
		0);
	mlx_do_sync(data->mlx_ptr);
}