#include "../includes/solong.h"

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

static void     draw_square(int i, int j, t_struct *stru)
{
    int     p;
    int     q;

    p = 0;
    while (p <= stru->var_mlx.size_case)
    {
        q = 0;
        while (q <= stru->var_mlx.size_case)
        {
            if (stru->map_data.map[i][j] == '1')
                my_mlx_pixel_put(&stru->data, stru->var_mlx.size_case * j + q, stru->var_mlx.size_case * i + p, 0x00999999);
            else if (stru->map_data.map[i][j] == '0')
                my_mlx_pixel_put(&stru->data, stru->var_mlx.size_case * j + q, stru->var_mlx.size_case * i + p, 0x00FFFFFF);
            else if (stru->map_data.map[i][j] == ' ')
                my_mlx_pixel_put(&stru->data, stru->var_mlx.size_case * j + q, stru->var_mlx.size_case * i + p, 0x00000000);
            else
                my_mlx_pixel_put(&stru->data, stru->var_mlx.size_case * j + q, stru->var_mlx.size_case * i + p, 0x00FFFFFF);
            q++;
        }
        p++;
    }
}

void    draw_player(double d_i, double d_j, t_struct *stru)
{
    int p;
    int q;
    int j;
    int i;

    if (stru->check_flags.init_done == 0)
    {
        j = (stru->var_mlx.size_case * stru->check_flags.s_pos_j + stru->var_mlx.size_case / 2 - 4);
        i = (stru->var_mlx.size_case * stru->check_flags.s_pos_i + stru->var_mlx.size_case / 2 - 4);
        stru->check_flags.pos_i = i + 4;
        stru->check_flags.pos_j = j + 4;
    }
    else
    {
        j = d_j - 4;
        i = d_i - 4;
        stru->check_flags.pos_i = d_i;
        stru->check_flags.pos_j = d_j;
    }
    printf("%f, %f bloup\n", d_i, d_j);
    p = 0;
    while (p <= 9)
    {
        q = 0;
        while (q <= 9)
        {
            my_mlx_pixel_put(&stru->data, j + q, i + p, 0x00FF0000);
            q++;
        }
        p++;
    }
}

void    win_init(t_struct *stru)
{
    /*int i;
    int j;

    i = 0;*/ 
    stru->data.img = mlx_new_image(stru->var_mlx.mlx, stru->data.res_x, stru->data.res_y);
    stru->data.addr = mlx_get_data_addr(stru->data.img, &stru->data.bits_per_pixel, &stru->data.line_length, &stru->data.endian);
    /*while (g_data.map[i])
    {
        j = 0;
        while (g_data.map[i][j])
        {
            draw_square(i, j);
            j++;
        }
        i++;
    }*/
    if (stru->check_flags.init_done == 0)
    {
        stru->check_flags.pos_i = stru->var_mlx.size_case * stru->check_flags.s_pos_i + stru->var_mlx.size_case / 2 - 4;
        stru->check_flags.pos_j = stru->var_mlx.size_case * stru->check_flags.s_pos_j + stru->var_mlx.size_case / 2 - 4;
        //draw_player(g_check_flags.pos_i, g_check_flags.pos_j);
    }
}