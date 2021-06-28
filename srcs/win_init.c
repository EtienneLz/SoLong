#include "../includes/solong.h"

void     draw(t_struct *stru, int w_img, int i, int j)
{
    unsigned int color;
    int     p;
    int     q;

    p = 0;
    while (p <= stru->var_mlx.size_case)
    {
        q = 0;
        while (q <= stru->var_mlx.size_case)
        {
            if (w_img != 5)
            {
                color = mlx_get_pixel(stru, q, p, w_img);
			    if (color != mlx_rgb_to_int(0, 0, 0, 0))
				    my_mlx_pixel_put(stru, stru->var_mlx.size_case * j + q, stru->var_mlx.size_case * i + p, color);
            }
            else
                my_mlx_pixel_put(stru, stru->var_mlx.size_case * j + q, stru->var_mlx.size_case * i + p, 0x00FFFFFF);
            q++;
        }
        p++;
    }
    
}

static void     select_square(int i, int j, t_struct *stru)
{
    if (stru->map_data.map[i][j] == '1')
        draw(stru, 3, i, j);
    else if (stru->map_data.map[i][j] == '0' || stru->map_data.map[i][j] == 'P')
        draw(stru, 2, i, j);
    else if (stru->map_data.map[i][j] == ' ')
        draw(stru, 5, i, j);
    else if (stru->map_data.map[i][j] == 'E')
        draw(stru, 4, i, j);
    else if (stru->map_data.map[i][j] == 'C')
    {
        draw(stru, 2, i, j);
        draw(stru, 1, i, j);
    }
    else
        draw(stru, 5, i, j);
}

static void texture_init(t_struct *stru)
{
    if(!(stru->texture[0].img = mlx_xpm_file_to_image(stru->var_mlx.mlx, "./textures/player.xpm", &(stru->texture[0].width), &(stru->texture[0].height))))
        ft_error(1, stru);
    if(!(stru->texture[1].img = mlx_xpm_file_to_image(stru->var_mlx.mlx, "./textures/coin.xpm", &(stru->texture[1].width), &(stru->texture[1].height))))
        ft_error(2, stru);
    if(!(stru->texture[2].img = mlx_xpm_file_to_image(stru->var_mlx.mlx, "./textures/floor.xpm", &(stru->texture[2].width), &(stru->texture[2].height))))
        ft_error(3, stru);
    if(!(stru->texture[3].img = mlx_xpm_file_to_image(stru->var_mlx.mlx, "./textures/wall.xpm", &(stru->texture[3].width), &(stru->texture[3].height))))
        ft_error(3, stru);
    if(!(stru->texture[4].img = mlx_xpm_file_to_image(stru->var_mlx.mlx, "./textures/end.xpm", &(stru->texture[4].width), &(stru->texture[4].height))))
        ft_error(3, stru);
    stru->texture[0].addr = mlx_get_data_addr(stru->texture[0].img, &stru->texture[0].bits_per_pixel, &stru->texture[0].line_length, &stru->texture[0].endian);
    stru->texture[1].addr = mlx_get_data_addr(stru->texture[1].img, &stru->texture[1].bits_per_pixel, &stru->texture[1].line_length, &stru->texture[1].endian);
    stru->texture[2].addr = mlx_get_data_addr(stru->texture[2].img, &stru->texture[2].bits_per_pixel, &stru->texture[2].line_length, &stru->texture[2].endian);
    stru->texture[3].addr = mlx_get_data_addr(stru->texture[3].img, &stru->texture[3].bits_per_pixel, &stru->texture[3].line_length, &stru->texture[3].endian);
    stru->texture[4].addr = mlx_get_data_addr(stru->texture[4].img, &stru->texture[4].bits_per_pixel, &stru->texture[4].line_length, &stru->texture[4].endian);
}

void    win_init(t_struct *stru)
{
    int i;
    int j;
    if (stru->check_flags.init_done == 0)
        {
            texture_init(stru);
            stru->check_flags.pos_i = stru->check_flags.s_pos_i;
            stru->check_flags.pos_j = stru->check_flags.s_pos_j;
        }
    i = 0; 
    stru->data.img = mlx_new_image(stru->var_mlx.mlx, stru->data.res_x, stru->data.res_y);
    stru->data.addr = mlx_get_data_addr(stru->data.img, &stru->data.bits_per_pixel, &stru->data.line_length, &stru->data.endian);
    while (stru->map_data.map[i])
    {
        j = 0;
        while (stru->map_data.map[i][j])
        {
            select_square(i, j, stru);
            j++;
        }
        i++;
    }
    if (stru->check_flags.init_done == 0)
        {
            draw(stru, 0, stru->check_flags.pos_i, stru->check_flags.pos_j);            
            stru->check_flags.init_done = 1;
        }
}