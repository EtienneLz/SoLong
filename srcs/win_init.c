#include "../includes/cube.h"

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = struct->data->addr + (y * struct->data->line_length + x * (struct->data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

/*static void     draw_square(int i, int j)
{
    int     p;
    int     q;

    p = 0;
    while (p <= g_vars.size_case)
    {
        q = 0;
        while (q <= g_vars.size_case)
        {
            if (g_data.map[i][j] == '1')
                my_mlx_pixel_put(&g_data, g_vars.size_case * j + q, g_vars.size_case * i + p, 0x00999999);
            else if (g_data.map[i][j] == '0')
                my_mlx_pixel_put(&g_data, g_vars.size_case * j + q, g_vars.size_case * i + p, 0x00FFFFFF);
            else if (g_data.map[i][j] == ' ')
                my_mlx_pixel_put(&g_data, g_vars.size_case * j + q, g_vars.size_case * i + p, 0x00000000);
            else
                my_mlx_pixel_put(&g_data, g_vars.size_case * j + q, g_vars.size_case * i + p, 0x00FFFFFF);
            q++;
        }
        p++;
    }
}*/

void    draw_player(double d_i, double d_j)
{
    //int p;
    //int q;
    int j;
    int i;

    if (g_check_flags.init_done == 0)
    {
        j = (struct->vars.size_case * struct->check_flags.s_pos_j + struct->var.size_case / 2 - 4);
        i = (struct->vars.size_case * struct->check_flags.s_pos_i + var.size_case / 2 - 4);
        struct->check_flags.pos_i = i + 4;
        struct->check_flags.pos_j = j + 4;
    }
    else
    {
        j = d_j - 4;
        i = d_i - 4;
        struct->g_check_flags.pos_i = d_i;
        struct->g_check_flags.pos_j = d_j;
    }
    printf("%f, %f bloup\n", d_i, d_j);
    /*p = 0;
    while (p <= 9)
    {
        q = 0;
        while (q <= 9)
        {
            my_mlx_pixel_put(&g_data, j + q, i + p, 0x00FF0000);
            q++;
        }
        p++;
    }*/
}

void    win_init(void)
{
    /*int i;
    int j;

    i = 0;*/ 
    struct->data.img = mlx_new_image(struct->var.mlx, g_data.res_x, g_data.res_y);
    struct->data.addr = mlx_get_data_addr(struct->data.img, &g_data.bits_per_pixel, &g_data.line_length, &g_data.endian);
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
    if (struct->check_flags.init_done == 0)
    {
        struct->check_flags.pos_i = struct->var.size_case * struct->check_flags.s_pos_i + struct->var.size_case / 2 - 4;
        struct->check_flags.pos_j = struct->var.size_case * struct->check_flags.s_pos_j + struct->var.size_case / 2 - 4;
        //draw_player(g_check_flags.pos_i, g_check_flags.pos_j);
    }
}