#include "../includes/solong.h"



static int     key_pressed(int keycode)
{
    if (keycode == 65307)
        ft_exit();
    if (keycode == UP)
        move_player(-1, 1);
    if (keycode == DOWN)
        move_player(1, 1);
    if (keycode == LEFT)
        move_player(-1, 2);
    if (keycode == RIGHT)
        move_player(1, 2);
    return (0);
}

static int     key_released(int keycode)
{
    if (keycode == UP)
        move_player(0, 0);
    if (keycode == DOWN)
        move_player(0, 0);
    if (keycode == LEFT)
        move_player(0, 0);
    if (keycode == RIGHT)
        move_player(0, 0);
    return (0);
}


void            input_loop(t_struct *stru)
{  
    win_init(stru->var_mlx.mlx);
    stru->check_flags.init_done = 1;
    stru->var_mlx.win = mlx_new_window(stru->var_mlx.mlx, stru->data.res_x, stru->data.res_y, "tHe BIndInG oF iSaAC : ANTiBIrtH");
    mlx_put_image_to_window(stru->var_mlx.mlx, stru->var_mlx.win, stru->data.img, 0, 0);
    mlx_hook(stru->var_mlx.win, 33, 1L << 17, ft_exit, &stru->var_mlx);
    mlx_hook(stru->var_mlx.win, 2, 1L<<0, key_pressed, &stru->var_mlx);
    mlx_hook(stru->var_mlx.win, 3, 1L<<1, key_released, &stru->var_mlx);
    mlx_loop(stru->var_mlx.mlx);
}