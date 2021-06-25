#include "../includes/solong.h"

static int     key_pressed(int keycode, t_struct *stru)
{
    if (keycode == 65307)
        ft_free(stru);
    if (keycode == UP)
        move_player(0, stru);
    if (keycode == DOWN)
        move_player(2, stru);
    if (keycode == LEFT)
        move_player(3, stru);
    if (keycode == RIGHT)
        move_player(1, stru);
    return (0);
}

void            input_loop(t_struct *stru)
{
    stru->var_mlx.win = mlx_new_window(stru->var_mlx.mlx, stru->data.res_x, stru->data.res_y, "tHe BIndInG oF iSaAC : ANTiBIrtH");
    win_init(stru);

    ft_putnbr_fd(stru->check_flags.nb_moves, 1);
    write(1, "\n", 1);
    mlx_put_image_to_window(stru->var_mlx.mlx, stru->var_mlx.win, stru->data.img, 0, 0);
    mlx_hook(stru->var_mlx.win, 33, 1L << 17, ft_free, stru);
    mlx_hook(stru->var_mlx.win, 2, 1L<<0, key_pressed, stru);
    mlx_loop(stru->var_mlx.mlx);
}