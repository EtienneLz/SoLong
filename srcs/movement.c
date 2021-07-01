/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouchez <elouchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 18:02:01 by elouchez          #+#    #+#             */
/*   Updated: 2021/07/01 18:02:02 by elouchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

static int	check_collision(int direction, t_struct *stru)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (direction == 0)
		i = -1;
	else if (direction == 1)
		j = 1;
	else if (direction == 2)
		i = 1;
	else if (direction == 3)
		j = -1;
	if (stru->map_data.map[stru->check.pos_i + i][stru->check.pos_j + j] == '1')
		return (0);
	if (stru->map_data.map[stru->check.pos_i + i][stru->check.pos_j + j] == 'C')
	{
		stru->map_data.map[stru->check.pos_i + i][stru->check.pos_j + j] = '0';
		stru->check.coin_left--;
	}
	if (stru->map_data.map[stru->check.pos_i + i][stru->check.pos_j + j] == 'E')
		return (2);
	return (1);
}

void	move_player(int direction, t_struct *stru)
{
	int	ret;

	ret = check_collision(direction, stru);
	if (ret == 1 || ret == 2)
	{
		win_refresh(stru);
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
		mlx_put_image_to_window(stru->var.mlx,
			stru->var.win, stru->data.img, 0, 0);
		if (ret == 2 && stru->check.coin_left == 0)
			ft_free(stru);
	}
}
