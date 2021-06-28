#include "../includes/solong.h"

static  int    check_collision(int direction, t_struct *stru)
{
    int     d_i;
    int     d_j;
    int     which_i;
    int     which_j;

    d_i = 0;
    d_j = 0;
    if (direction == 0)
        d_i = -1;
    else if (direction == 1)
        d_j = 1;
    else if (direction == 2)
        d_i = 1;
    else if (direction == 3)
        d_j = -1;
    which_i = stru->check_flags.pos_i + d_i;
    which_j = stru->check_flags.pos_j + d_j;
    if (stru->map_data.map[which_i][which_j] == '1')
        return (0);
    if (stru->map_data.map[which_i][which_j] == 'C')
    {
        stru->map_data.map[which_i][which_j] = '0';
        stru->check_flags.coin_left--;
    }
    if (stru->map_data.map[which_i][which_j] == 'E')
        return(2);
    return (1);
}

void            move_player(int direction, t_struct *stru)
{
    int ret;

    ret = check_collision(direction, stru);
    if (ret == 1 || ret == 2)
    {
        win_init(stru);
        if (direction == 0)
            stru->check_flags.pos_i--;
        if (direction == 1)
            stru->check_flags.pos_j++;
        if (direction == 2)
           stru->check_flags.pos_i++;
        if (direction == 3)
            stru->check_flags.pos_j--;
        draw(stru, 0, stru->check_flags.pos_i, stru->check_flags.pos_j);
        stru->check_flags.nb_moves++;
        ft_putnbr_fd(stru->check_flags.nb_moves, 1);
        write(1, "\n", 1);
        mlx_put_image_to_window(stru->var_mlx.mlx, stru->var_mlx.win, stru->data.img, 0, 0);
        if (ret == 2 && stru->check_flags.coin_left == 0)
            ft_free(stru);
    }
}