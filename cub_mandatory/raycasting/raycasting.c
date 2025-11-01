#include "../header_bonus.h"

void cast_ray(t_data *data, double rayangle)
{
	// draw_line(data,data->p.p_x, data->p.p_y, floor(data->ray.walhit_x), floor(data->ray.walhit_y), 0x000000);
	my_img_pixel_put(data, &data->img, data->ray.walhit_x, data->ray.walhit_y, 0x00ff00);
}

double calculate_distance(t_data *data, double x_d , double y_d)
{
	double dx;
	double dy;

	dx = x_d - data->p.p_x;
	dy = y_d - data->p.p_y;
	return(sqrt(dx * dx + dy * dy));

}

static void ray_direction(t_data *data, double rayangle)
{
	data->ray.rayangle = rayangle;
	if(rayangle >= 0 && rayangle <= M_PI)
		data->ray.is_down = 1;
	data->ray.is_up = !data->ray.is_down;
	if(rayangle <= 0.5 * M_PI || rayangle >= M_PI * 1.5)
		data->ray.is_right = 1;
	data->ray.is_left = !data->ray.is_right;
}

static void set_ray_val(double hor_distance, double ver_distance, t_data *data)
{
	if(hor_distance >= ver_distance)
	{
		data->vertical_hit = 1;
		data->ray.walhit_x = data->ray.ver_walhit_x;
		data->ray.walhit_y = data->ray.ver_walhit_y;
		data->ray.distance = ver_distance * cos(normlizing((data->p.view_angle) - data->ray.rayangle));
	}
	else if(hor_distance < ver_distance)
	{
		data->vertical_hit = 0;
		data->ray.walhit_x = data->ray.hor_walhit_x;
		data->ray.walhit_y = data->ray.hor_walhit_y;
		data->ray.distance = hor_distance * cos(normlizing((data->p.view_angle )- data->ray.rayangle));
	}
}

void cast_allrays(t_data *data)
{
	double rayangle;
	double hor_distance;
	double ver_distance;
	int i;

	i = 0;
	rayangle = data->p.view_angle - (FOV / 2);
	while(i < NUM_RAYS)
	{
		rayangle = normlizing(rayangle);
		ray_direction(data, rayangle);
		data->ray.id = i;
		hor_distance = find_hor_inter(data, rayangle);
		ver_distance = find_ver_inter(data, rayangle);
		set_ray_val(hor_distance, ver_distance, data);
		// cast_ray(data, rayangle);
<<<<<<<< HEAD:cub_bonus/raycasting/raycasting.c
		// printf("ray %d distance = %f  ver_dis %f\n", data->ray.id, data->ray.distance, ver_distance);
		render_3d(data);
========
		render_3d(data); 
>>>>>>>> origin/nouss:cub_mandatory/raycasting/raycasting.c
		init_ray(data);
		rayangle += (double)FOV / (double)NUM_RAYS;
		i++;
	}
}
