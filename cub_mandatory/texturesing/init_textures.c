/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 19:15:58 by ijoubair          #+#    #+#             */
/*   Updated: 2025/11/01 19:17:19 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

image    *init_text_arr(void *mlx_ptr, image **arr, int size)
{
    int i;

    i = 0;
    *arr = malloc(sizeof(image) * size);
    fill_image_arr(mlx_ptr, arr);
    return(*arr);
}

void    fill_image_arr(void *mlx_ptr, image **arr)
{
    int i;
    char *path[5];

    path[0] = (*text_func())->no;
    path[1] = (*text_func())->so;
    path[2] = (*text_func())->we;
    path[3] = (*text_func())->ea;
    path[4] = (*text_func())->door;
    i = 0;
    while(i < 5)
    {
        (*arr)[i].type = i;
        (*arr)[i].path = path[i];
        if(access(path[i], O_RDONLY) < 0)
        {
            printf("error11\n");
            break;
        }
        (*arr)[i].img_ptr = mlx_xpm_file_to_image(mlx_ptr, path[i], &(*arr)[i].width, &(*arr)[i].height);
        (*arr)[i].img_pxl_ptr = mlx_get_data_addr((*arr)[i].img_ptr, &(*arr)[i].b_p_p,&(*arr)[i].line_len, &(*arr)[i].endian);
        i++;
    }
    
}

int render_door(t_data *data, double x, double y, char c)
{
    int grid_x;
    int grid_y;
    
    grid_x = floor(x  / SQUARESIZE);
	grid_y = floor(y / SQUARESIZE);
    if( c == 'h')
    {
        if(data->map[grid_y][grid_x] == 'D' || data->map[grid_y - 1][grid_x] == 'D')
        return(1);
    }
    else if( c == 'v')
    {
        if(data->map[grid_y][grid_x] == 'D' || data->map[grid_y][grid_x - 1] == 'D')
        return(1);
    }
    // if(data->map[grid_y][grid_x] == 'P')
    //     return(1); 
    return(0);
}

int    get_textures_type(t_data *data)
{

    if(data->vertical_hit)
    {
        if(data->p.p_x > data->ray.walhit_x)
            return(EAST);
        else
            return(WEST);
    }
    else
    {
        if(data->p.p_y > data->ray.walhit_y)
            return(NORTH);
        else
            return(SOUTH);
    }
}

void set_tex_x(t_data *data, int type)
{
    double wall_x;

    if(data->vertical_hit == 0)
    {                                                                                                                                
        wall_x = fmod(data->ray.walhit_x , SQUARESIZE);
    }
    else
    {
        wall_x = fmod(data->ray.walhit_y, SQUARESIZE);
    }
    data->tex_x = (wall_x / SQUARESIZE) * data->arr[type].width;
}



void  set_step(double wall_height, image *texture)
{
    texture->step = (double)texture->height / wall_height;
}

void set_tex_pos(double top_wall, image *texture)
{
    if (top_wall < 0)
        texture->tex_pos = (-top_wall) * texture->step;
    else
        texture->tex_pos = 0;
}


void    render_3d( t_data *data)
{
    int     (type), (y);
    double  (distance_proj_plane), (wall_height), (top_wall), (bottom_wall);

    distance_proj_plane = (WIDTH / 2) / tan(FOV / 2);
	wall_height = ((SQUARESIZE ) / data->ray.distance) * distance_proj_plane;
	top_wall = (HEIGHT / 2) - (wall_height / 2);
	data->ray.top_wall = top_wall;
	if(top_wall < 0)
        top_wall = 0;
	bottom_wall = (HEIGHT / 2) + (wall_height / 2);
	if(bottom_wall >= HEIGHT)
        bottom_wall = HEIGHT - 1;
    if(bottom_wall < top_wall)
        bottom_wall = top_wall;
    type = get_textures_type(data);
    set_tex_x(data, type);
    set_step(wall_height, &data->arr[type]);
    y = 0;
    while (y < HEIGHT)
    {
        if (y < top_wall)
            my_img_pixel_put(data, &data->img, data->ray.id, y, data->ceiling_color);
        else if (y >= top_wall && y <= bottom_wall)
        {
            draw_textured_wall(data, &data->arr[type],data->ray.top_wall ,bottom_wall);
            y = bottom_wall + 1;
            continue;
        }
        else if(y > bottom_wall)
            my_img_pixel_put(data, &data->img, data->ray.id, y, data->floor_color);
        y++;
    } 
}

void my_img_pixel_put(t_data *data, t_img *img, int x, int y, int color)
{
	int offset;
	if (x < 0 || y < 0 || x >= WIDTH|| y >= HEIGHT)
        return;
	offset = (img->line_len * y) + (x * (img->b_p_p / 8));
	*((unsigned int *)(img->img_pxl_ptr + offset)) = color;
}

void draw_textured_wall(t_data *data, image *texture, double top_wall, double bottom_wall)
{
    int y;
    int tex_y;
    int color;

    set_tex_pos(top_wall, texture);
    if(top_wall < 0)
        top_wall = 0;
    for (y = (int)top_wall; y <= (int)bottom_wall; y++)
    {
        tex_y = (int)texture->tex_pos;
        if (tex_y >= texture->height)
            tex_y = texture->height - 1;

        color = *(int *)(texture->img_pxl_ptr + tex_y * texture->line_len + data->tex_x * (texture->b_p_p / 8));
        my_img_pixel_put(data, &data->img, data->ray.id, y, color);
        texture->tex_pos += texture->step;
    }
}

