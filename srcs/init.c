/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouchez <elouchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 18:01:43 by elouchez          #+#    #+#             */
/*   Updated: 2021/07/01 18:01:44 by elouchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

static void	vars_init(t_struct *stru)
{
	stru->map_data.size_map = 0;
	stru->map_data.size_line_max = 0;
	stru->map_data.map = NULL;
	stru->data.fd = 0;
	stru->check.s_pos_i = 0;
	stru->check.s_pos_j = 0;
	stru->check.pos_i = 0;
	stru->check.pos_j = 0;
	stru->check.init_done = 0;
	stru->check.nb_moves = 0;
	stru->check.coin_left = 0;
	stru->check.player_check = 0;
	stru->var.size_case = 48;
	stru->data.img = NULL;
	stru->tex[0].img = NULL;
	stru->tex[1].img = NULL;
	stru->tex[2].img = NULL;
	stru->tex[3].img = NULL;
	stru->tex[4].img = NULL;
	stru->check.end_check = 0;
}

void	check_line(t_struct *stru, int i, char *line)
{
	unsigned int	j;

	j = 0;
	while (line[j])
	{
		if (line[j] == ' ' || line[j] == '1')
			stru->map_data.map[i][j] = line[j];
		else if (line[j] == '0')
			stru->map_data.map[i][j] = '0';
		else if (line[j] == 'C' || line[j] == 'E')
			stru->map_data.map[i][j] = line[j];
		else if (line[j] == 'P')
		{
			stru->check.s_pos_i = i;
			stru->check.s_pos_j = j;
			stru->map_data.map[i][j] = line[j];
		}
		else
			ft_error(stru, "Map invalide\nCaractère inconnu\n");
		j++;
	}
	while (j < (unsigned int)stru->map_data.size_line_max)
		stru->map_data.map[i][j++] = ' ';
	stru->map_data.map[i][j] = '\0';
}

void	check_map(t_struct *stru)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = copy_map(stru);
	ft_fill(tmp, stru->check.s_pos_i, stru->check.s_pos_j,
		stru);
	while (tmp[i])
		free(tmp[i++]);
	free(tmp);
	if (stru->check.s_pos_i == 0 || stru->check.s_pos_j == 0)
		ft_error(stru, "Map invalide\nPosition de départ manquante\n");
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
		write(fd, &s[i++], 1);
}

int	main(int argc, char **argv)
{
	t_struct	stru;
	int			i;

	i = 0;
	vars_init(&stru);
	if (argc != 2)
	{
		write(1, "Erreur\nNombre d'argument incorrect\n", 35);
		return (0);
	}
	while (argv[1][i] != '.')
		i++;
	if (argv[1][i + 1] == 'b' && argv[1][i + 2] == 'e'
		&& argv[1][i + 3] == 'r' && argv[1][i + 4] == '\0')
	{
		ft_file_read(argv[1], &stru);
		stru.var.mlx = mlx_init();
		stru.data.res_x = stru.map_data.size_line_max * stru.var.size_case;
		stru.data.res_y = (stru.map_data.size_map) * stru.var.size_case;
		input_loop(&stru);
	}
	else
		write(1, "Erreur\nFormat de map incorrect\n", 31);
	return (0);
}
