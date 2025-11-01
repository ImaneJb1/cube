<<<<<<<< HEAD:cub_bonus/raycasting/randring/rander_3d.c
#include "../../header_bonus.h"


========
#include "../header.h"
>>>>>>>> origin/nouss:cub_mandatory/randring/rander_3d.c

void draw_ceiling(t_data *data, double top_wall)
{
	int y;
	
	y = 0;
	while(y < top_wall)
	{
		my_img_pixel_put(data, &data->img, data->ray.id, y, 0x0000ff);
		y++;
	}
}

void draw_floor(t_data *data, double bottom_wall)
{
	int y;
	
	y = HEIGHT;
	while(y > bottom_wall)
	{
		my_img_pixel_put(data, &data->img, data->ray.id, y, 0x00ff00);
		y--;
	}
}

void draw_wall(t_data *data, double top_wall, double bottom_wall)
{
	int y;
	
	y = top_wall;
	while(y < bottom_wall)
	{
		my_img_pixel_put(data, &data->img, data->ray.id, y, 0xffffff);
		y++;
	}
}

// void render_3d(t_data *data)
// {
// 	double distance_proj_plane;
// 	double wall_height;
// 	double top_wall;
// 	double bottom_wall;
// 	int y;

// 	y = 0;
// 	distance_proj_plane = (WIDTH / 2) / tan(FOV / 2);
// 	wall_height = ((SQUARESIZE ) / data->ray.distance) * distance_proj_plane;
// 	top_wall = (HEIGHT / 2) - (wall_height / 2);
// 	data->ray.top_wall = abs(top_wall);
// 	if(top_wall < 0)
// 		top_wall = 0;
// 	bottom_wall = (HEIGHT / 2) + (wall_height / 2);
// 	if(bottom_wall > HEIGHT)
// 		bottom_wall = HEIGHT;
// 	while(y < HEIGHT)
// 	{
// 		if(y < top_wall)
// 			img_pixel_put(data, &data->img, data->ray.id, y, 0x0000ff);
// 		else if(y >= top_wall && y <= bottom_wall)
// 			img_pixel_put(data, &data->img, data->ray.id, y, 0xFF0000);
// 		else if(y > bottom_wall)
// 			img_pixel_put(data, &data->img, data->ray.id, y, 0x000000);
// 		y++;
// 	}
// }
		// img_pixel_put(data, &data->img, data->ray.id, y, 0xff00fff); //
		
