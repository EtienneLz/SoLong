/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_refresh.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouchez <elouchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 18:02:13 by elouchez          #+#    #+#             */
/*   Updated: 2021/07/06 15:34:19 by elouchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	draw(t_struct *stru, int w_img, int i, int j)
{
	unsigned int	color;
	int				p;
	int				q;

	p = 0;
	while (p < stru->var.size_case)
	{
		q = 0;
		while (q < stru->var.size_case)
		{
			color = mlx_get_pixel(stru, q, p, w_img);
			if (color != mlx_rgb_to_int(0, 255, 255, 255))
				my_mlx_pixel_put(stru, stru->var.size_case * j + q,
					stru->var.size_case * i + p, color);
			q++;
		}
		p++;
	}
}

void	select_square(int i, int j, t_struct *stru)
{
	if (stru->map_data.map[i][j] == '1' || stru->map_data.map[i][j] == ' ')
		draw(stru, 3, i, j);
	else if (stru->map_data.map[i][j] == '0' || stru->map_data.map[i][j] == 'P')
		draw(stru, 2, i, j);
	else if (stru->map_data.map[i][j] == 'E')
		draw(stru, 4, i, j);
	else if (stru->map_data.map[i][j] == 'C')
	{
		draw(stru, 2, i, j);
		draw(stru, 1, i, j);
	}
	else
		draw(stru, 3, i, j);
}

static void	texture_init_2(t_struct *stru)
{
	stru->tex[4].img = mlx_xpm_file_to_image(stru->var.mlx,
			"./textures/end.xpm", &(stru->tex[4].width),
			&(stru->tex[4].height));
	if (stru->tex[4].img == NULL)
		ft_error(stru, "Texture invalide\n");
	stru->tex[0].addr = mlx_get_data_addr(stru->tex[0].img, &stru->tex[0].bbp,
			&stru->tex[0].line_length, &stru->tex[0].endian);
	stru->tex[1].addr = mlx_get_data_addr(stru->tex[1].img, &stru->tex[1].bbp,
			&stru->tex[1].line_length, &stru->tex[1].endian);
	stru->tex[2].addr = mlx_get_data_addr(stru->tex[2].img, &stru->tex[2].bbp,
			&stru->tex[2].line_length, &stru->tex[2].endian);
	stru->tex[3].addr = mlx_get_data_addr(stru->tex[3].img, &stru->tex[3].bbp,
			&stru->tex[3].line_length, &stru->tex[3].endian);
	stru->tex[4].addr = mlx_get_data_addr(stru->tex[4].img, &stru->tex[4].bbp,
			&stru->tex[4].line_length, &stru->tex[4].endian);
}

void	texture_init(t_struct *stru)
{
	stru->tex[0].img = mlx_xpm_file_to_image(stru->var.mlx,
			"./textures/player.xpm", &(stru->tex[0].width),
			&(stru->tex[0].height));
	if (stru->tex[0].img == NULL)
		ft_error(stru, "Texture invalide\n");
	stru->tex[1].img = mlx_xpm_file_to_image(stru->var.mlx,
			"./textures/coin.xpm", &(stru->tex[1].width),
			&(stru->tex[1].height));
	if (stru->tex[1].img == NULL)
		ft_error(stru, "Texture invalide\n");
	stru->tex[2].img = mlx_xpm_file_to_image(stru->var.mlx,
			"./textures/floor.xpm", &(stru->tex[2].width),
			&(stru->tex[2].height));
	if (stru->tex[2].img == NULL)
		ft_error(stru, "Texture invalide\n");
	stru->tex[3].img = mlx_xpm_file_to_image(stru->var.mlx,
			"./textures/wall.xpm", &(stru->tex[3].width),
			&(stru->tex[3].height));
	if (stru->tex[3].img == NULL)
		ft_error(stru, "Texture invalide\n");
	texture_init_2(stru);
}

int	win_refresh(t_struct *stru)
{
	int	i;
	int	j;

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
	mlx_put_image_to_window(stru->var.mlx,
		stru->var.win, stru->data.img, 0, 0);
	return (0);
}
