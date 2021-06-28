#include "../includes/solong.h"

static  int    check_collision(int direction, t_struct *stru)
{
    int     d_i;
    int     d_j;

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
    if (stru->map_data.map[stru->check.pos_i + d_i][stru->check.pos_j + d_j] == '1')
        return (0);
    if (stru->map_data.map[stru->check.pos_i + d_i][stru->check.pos_j + d_j] == 'C')
    {
        stru->map_data.map[stru->check.pos_i + d_i][stru->check.pos_j + d_j] = '0';
        stru->check.coin_left--;
    }
    if (stru->map_data.map[stru->check.pos_i + d_i][stru->check.pos_j + d_j] == 'E')
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
            stru->check.pos_i--;
        if (direction == 1)
            stru->check.pos_j++;
        if (direction == 2)
            stru->check.pos_i++;
        if (direction == 3)
            stru->check.pos_j--;
        draw(stru, 0, stru->check.pos_i, stru->check.pos_j);
        stru->check.nb_moves++;
        ft_putnbr_fd(stru->check.nb_moves, 1);
        write(1, "\n", 1);        
        mlx_put_image_to_window(stru->var_mlx.mlx, stru->var_mlx.win, stru->data.img, 0, 0);
        if (ret == 2 && stru->check.coin_left == 0)
            ft_free(stru); 
    }
}