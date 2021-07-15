/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouchez <elouchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 18:01:19 by elouchez          #+#    #+#             */
/*   Updated: 2021/07/15 18:09:52 by elouchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

static	void	ft_free_alt(t_struct *stru)
{
	if (stru->data.img != 0)
		mlx_destroy_image(stru->var.mlx, stru->data.img);
	mlx_destroy_window(stru->var.mlx, stru->var.win);
	mlx_destroy_display(stru->var.mlx);
	mlx_loop_end(&stru->var);
	free(stru->var.mlx);
}

void	err(t_struct *stru, char **tmp)
{
	int i;

	i = 0;
	while (tmp[i])
		free(tmp[i++]);
	free(tmp);
	ft_error(stru, "Map invalide\nMap non fermée\n");
}

void	ft_error(t_struct *stru, char *msg)
{
	write(1, "Erreur \n", 8);
	ft_putstr_fd(msg, 1);
	ft_free(stru);
}

int	ft_free(t_struct *stru)
{
	int	i;

	i = -1;
	if (stru->map_data.map)
	{
		while (stru->map_data.map[++i])
			free(stru->map_data.map[i]);
		free(stru->map_data.map);
	}
	if (stru->tex[0].img)
		mlx_destroy_image(stru->var.mlx, stru->tex[0].img);
	if (stru->tex[1].img)
		mlx_destroy_image(stru->var.mlx, stru->tex[1].img);
	if (stru->tex[2].img)
		mlx_destroy_image(stru->var.mlx, stru->tex[2].img);
	if (stru->tex[3].img)
		mlx_destroy_image(stru->var.mlx, stru->tex[3].img);
	if (stru->tex[4].img)
		mlx_destroy_image(stru->var.mlx, stru->tex[4].img);
	if (stru->check.init_done == 1)
		ft_free_alt(stru);
	ft_exit();
	return (0);
}

int	ft_exit(void)
{
	exit(EXIT_SUCCESS);
}
