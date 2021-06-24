#include "../includes/solong.h"

void            my_mlx_pixel_put(t_struct *stru, int x, int y, int color)
{
    char    *dst;
    dst = stru->data.addr + (y * stru->data.line_length + x * (stru->data.bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

static void     draw_square(int i, int j, t_struct *stru)
{
    int     p;
    int     q;

    //printf("i = %d, j = %d\n", i , j);
    p = 0;
    while (p <= stru->var_mlx.size_case)
    {
        q = 0;
        while (q <= stru->var_mlx.size_case)
        {
            if (stru->map_data.map[i][j] == '1')
                my_mlx_pixel_put(stru, stru->var_mlx.size_case * j + q, stru->var_mlx.size_case * i + p, 0x00999999);
            else if (stru->map_data.map[i][j] == '0')
                my_mlx_pixel_put(stru, stru->var_mlx.size_case * j + q, stru->var_mlx.size_case * i + p, 0x00FFFFFF);
            else if (stru->map_data.map[i][j] == ' ')
                my_mlx_pixel_put(stru, stru->var_mlx.size_case * j + q, stru->var_mlx.size_case * i + p, 0x00000000);
            else if (stru->map_data.map[i][j] == 'E')
                my_mlx_pixel_put(stru, stru->var_mlx.size_case * j + q, stru->var_mlx.size_case * i + p, 0x0000FF0F);
            else if (stru->map_data.map[i][j] == 'C')
                my_mlx_pixel_put(stru, stru->var_mlx.size_case * j + q, stru->var_mlx.size_case * i + p, 0x00FFFF00);
            else
                my_mlx_pixel_put(stru, stru->var_mlx.size_case * j + q, stru->var_mlx.size_case * i + p, 0x00FFFFFF);
            q++;
        }
        p++;
    }
}

void    draw_player(int pos_i, int pos_j, t_struct *stru)
{
    int p;
    int q;

    stru->check_flags.pos_i = pos_i;
    stru->check_flags.pos_j = pos_j;

    //printf("%d, %d bloup\n", pos_i, pos_j);
    p = 0;
    while (p < stru->var_mlx.size_case)
    {
        q = 0;
        while (q < stru->var_mlx.size_case)
        {
            my_mlx_pixel_put(stru, stru->var_mlx.size_case * pos_j + q, stru->var_mlx.size_case * pos_i + p, 0x00FF0000);
            q++;
        }
        p++;
    }
}

void    win_init(t_struct *stru)
{
    int i;
    int j;

    i = 0; 
    stru->data.img = mlx_new_image(stru->var_mlx.mlx, stru->data.res_x, stru->data.res_y);
    stru->data.addr = mlx_get_data_addr(stru->data.img, &stru->data.bits_per_pixel, &stru->data.line_length, &stru->data.endian);
    while (stru->map_data.map[i])
    {
        j = 0;
        while (stru->map_data.map[i][j])
        {
            draw_square(i, j, stru);
            j++;
        }
        i++;
    }
    if (stru->check_flags.init_done == 0)
    {
        stru->check_flags.pos_i = stru->check_flags.s_pos_i;
        stru->check_flags.pos_j = stru->check_flags.s_pos_j;
        draw_player(stru->check_flags.pos_i, stru->check_flags.pos_j, stru);
    }
}