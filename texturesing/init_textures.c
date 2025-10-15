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
    char *path[4];

    path[0] = (*text_func())->no;
    path[1] = (*text_func())->so;
    path[2] = (*text_func())->we;
    path[3] = (*text_func())->ea;
    i = 0;
    while(i < 4)
    {
        (*arr)[i].type = i;
        (*arr)[i].path = path[i];
        (*arr)[i].img_ptr = mlx_xpm_file_to_image(mlx_ptr, path[i], &(*arr)[i].width, &(*arr)[i].height);
        (*arr)[i].img_pxl_ptr = mlx_get_data_addr((*arr)[i].img_ptr, &(*arr)[i].b_p_p,&(*arr)[i].line_len, &(*arr)[i].endian);
        i++;
    }
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
            return(SOUTH);
        else
            return(NORTH);
    }
}

void set_tex_x(t_data *data)
{
    double wall_x;

    if(data->ray.hit_vertical)
        wall_x = data->ray.walhit_y - SQUARESIZE * (int)(data->ray.walhit_y / SQUARESIZE);
    else
        wall_x = data->ray.walhit_x - SQUARESIZE * (int)(data->ray.walhit_x / SQUARESIZE);
    data->tex_x = wall_x;
}

void  set_step(double wall_height, image *texture)
{
    texture->step = texture->height / wall_height;
}

void    set_tex_pos(double wall_height, double top_wall, double screen_middle, image *texture)
{
    texture->tex_pos = (top_wall - screen_middle + (wall_height/2) * texture->step);
}

void    render_walls(double wall_height, double top_wall, double screen_middle, t_data *data)
{
    int type;

    type = get_textures_type(data);
    set_tex_x(data);
    set_step(wall_height, data);
    set_tex_pos(wall_height, top_wall, screen_middle, data->arr->path[type]);
    draw_textured_wall();

}
void my_mlx_pixel_put(image *img, int x, int y, int color)
{
    char *dst;

    dst = img->img_pxl_ptr + (y * img->line_len + x * (img->b_p_p / 8));
    *(unsigned int *)dst = color;
}

void    draw_textured_wall(t_data *data, double top_wall, double wall_height, image texture)
{
    int draw_start;
    int draw_end;
    int tex_pos;
    int y; //screen y
    int tex_y;
    double step;
    int color;

    step = texture.step;
    draw_start = (int)top_wall;
    if(draw_start < 0)
        draw_start = 0;
    if(draw_end > HEIGHT)
        draw_end = HEIGHT - 1;
    tex_pos = 0;
    if(top_wall < 0)
        tex_pos = abs(top_wall) * step;
    while(y < draw_end)
    {
        tex_y = (int)tex_pos % texture.height;
        color = *(int *)(texture.img_pxl_ptr + (tex_y * texture.line_len) + (data->tex_x *(texture.b_p_p / 8)));
        my_mlx_pixel_put(data->img.img_pxl_ptr, )
        y++;
    }
}
