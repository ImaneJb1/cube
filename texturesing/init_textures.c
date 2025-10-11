#include "../header.h"

// Helper: allocate a 2D texture array (int **)
int **allocate_textures(int width, int height)
{
    int **texture;
    int i;

    texture = malloc(sizeof(int *) * height);
    if (!texture)
        return (NULL);
    i = 0;
    while (i < height)
    {
        texture[i] = malloc(sizeof(int) * width);
        if (!texture[i])
            return (NULL);
        i++;
    }
    return (texture);
}

// Helper: copy pixel data from MLX image to our texture array
void fill_textures(int **texture, t_img *img, int width, int height)
{
    int x;
    int y;
    char *pixel;
    int color;

    y = 0;
    while (y < height)
    {
        x = 0;
        while (x < width)
        {
            pixel = img->img_pxl_ptr + (y * img->line_len + x * (img->b_p_p / 8));
            color = *(int *)pixel;
            texture[y][x] = color;
            x++;
        }
        y++;
    }
}

// Load one wall texture
void load_texture_from_path(t_data *data, int index, char *path)
{
    int width;
    int height;
    t_img tmp_img;

    tmp_img.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, path, &width, &height);
    if (!tmp_img.img_ptr)
    {
        printf("Error loading texture: %s\n", path);
        exit(1);
    }

    tmp_img.img_pxl_ptr = mlx_get_data_addr(tmp_img.img_ptr, &tmp_img.b_p_p,&tmp_img.line_len, &tmp_img.endian); //textel buffer

    data->textures[index] = allocate_textures(width, height);
    if (!data->textures[index])
    {
        printf("Memory allocation failed for texture: %s\n", path);
        exit(1);
    }

    fill_textures(data->textures[index], &tmp_img, width, height);

    data->textures_w[index] = width;
    data->textures_h[index] = height;

    mlx_destroy_image(data->mlx_ptr, tmp_img.img_ptr);
}

// Load all wall textures (NO, SO, WE, EA)
void load_all_textures(t_data *data)
{
    // order: 0 = NO, 1 = SO, 2 = WE, 3 = EA
    char *paths[4] = {
        "textures/north.xpm",
        "textures/south.xpm",
        "textures/west.xpm",
        "textures/east.xpm"
    };

    for (int i = 0; i < 4; i++)
        load_texture_from_path(data, i, paths[i]);
}
