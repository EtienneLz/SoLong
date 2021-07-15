/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouchez <elouchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 18:01:49 by elouchez          #+#    #+#             */
/*   Updated: 2021/07/15 16:47:51 by elouchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

static int	key_pressed(int keycode, t_struct *stru)
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

static void	win_init(t_struct *stru)
{
	int	i;
	int	j;

	texture_init(stru);
	stru->check.pos_i = stru->check.s_pos_i;
	stru->check.pos_j = stru->check.s_pos_j;
	i = 0;
	if (stru->data.img != 0 && stru->check.init_done != 0)
		mlx_destroy_image(stru->var.mlx, stru->data.img);
	stru->data.img = mlx_new_image(stru->var.mlx,
			stru->data.res_x, stru->data.res_y);
	stru->data.addr = mlx_get_data_addr(stru->data.img, &stru->data.bbp,
			&stru->data.line_length, &stru->data.endian);
	while (stru->map_data.map[i])
	{
		j = -1;
		while (stru->map_data.map[i][++j])
			select_square(i, j, stru);
		i++;
	}
	draw(stru, 0, stru->check.pos_i, stru->check.pos_j);
	stru->check.init_done = 1;
}

void	input_loop(t_struct *stru)
{
	if (stru->data.res_x > 1920 || stru->data.res_y > 1080)
		ft_error(stru, "Map invalide\nTaille trop grande\n");
	stru->var.win = mlx_new_window(stru->var.mlx,
			stru->data.res_x, stru->data.res_y, "MINECRAFT");
	win_init(stru);
	ft_putnbr_fd(stru->check.nb_moves, 1);
	write(1, "\n", 1);
	mlx_put_image_to_window(stru->var.mlx,
		stru->var.win, stru->data.img, 0, 0);
	mlx_loop_hook(stru->var.mlx, win_refresh, stru);
	mlx_hook(stru->var.win, 33, 1L << 17, ft_free, stru);
	mlx_hook(stru->var.win, 2, 1L << 0, key_pressed, stru);
	mlx_loop(stru->var.mlx);
}
