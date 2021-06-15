/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouchez <elouchez@stud.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 16:01:45 by elouchez          #+#    #+#             */
/*   Updated: 2021/06/15 16:46:32 by elouchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



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
    //printf("%d, %d\n", which_i, which_j);
 
    which_i = stru->check_flags.pos_i + d_i;
    which_j = stru->check_flags.pos_j + d_j;
    printf("%d, %d\n", which_i, which_j);
    if (stru->map_data.map[which_i][which_j] == '1')
        return (0);

    return (1);
}

void            move_player(int direction, t_struct *stru)
{
    if (direction == 0)
            return ;
    
    if (check_collision(direction, &stru))
    {
        win_init(&stru);
        if (direction == 0)
            draw_player(stru->check_flags.pos_i - 1, stru->check_flags.pos_j, &stru);
        if (direction == 1)
            draw_player(stru->check_flags.pos_i, stru->check_flags.pos_j + 1, &stru);
        if (direction == 2)
            draw_player(stru->check_flags.pos_i + 1, stru->check_flags.pos_j, &stru);
        if (direction == 3)
            draw_player(stru->check_flags.pos_i, stru->check_flags.pos_j - 1, &stru);          
        mlx_put_image_to_window(stru->var_mlx.mlx, stru->var_mlx.win, stru->data.img, 0, 0);
    }
}