/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouchez <elouchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 18:01:57 by elouchez          #+#    #+#             */
/*   Updated: 2021/07/15 17:55:19 by elouchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

static void	count_line(t_struct *stru)
{
	int		i;
	int		ret;
	char	*line;

	line = NULL;
	ret = 1;
	while (ret != 0)
	{
		ret = get_next_line(stru->data.fd, &line);
		i = 0;
		if ((unsigned int)stru->map_data.size_line_max < ft_strlen(line))
			stru->map_data.size_line_max = ft_strlen(line);
		stru->map_data.size_map++;
		while (line[i])
		{
			if (line[i] == 'E')
				stru->check.end_check = 1;
			if (line[i] == 'C')
				stru->check.coin_left++;
			if (line[i] == 'P')
				stru->check.player_check++;
			i++;
		}
		free(line);
	}
}

static void	parse_map(t_struct *stru)
{
	int				i;
	char			*line;

	i = 0;
	line = NULL;
	stru->map_data.map = malloc(sizeof(char *) * (stru->map_data.size_map + 1));
	if (stru->map_data.map == NULL)
		ft_error(stru, "Allocation de memoire echouee\n");
	while (i < stru->map_data.size_map)
	{
		get_next_line(stru->data.fd, &line);
		stru->map_data.map[i] = NULL;
		stru->map_data.map[i] = malloc(sizeof(char)
				 * (stru->map_data.size_line_max + 1));
		if (stru->map_data.map[i] == NULL)
			ft_error(stru, "Allocation de memoire echouee\n");
		check_line(stru, i, line);
		free(line);
		i++;
	}
	stru->map_data.map[i] = NULL;
}

char	**copy_map(t_struct *stru)
{
	char	**tmp_map;
	int		i;
	int		j;

	i = 0;
	tmp_map = malloc(sizeof(char *) * (stru->map_data.size_map + 1));
	while (stru->map_data.map[i] != NULL)
	{
		tmp_map[i] = NULL;
		tmp_map[i] = malloc(sizeof(char) * (stru->map_data.size_line_max + 1));
		j = 0;
		while (stru->map_data.map[i][j])
		{
			tmp_map[i][j] = stru->map_data.map[i][j];
			if (stru->map_data.map[i][j] == 'C'
			|| stru->map_data.map[i][j] == 'P'
			|| stru->map_data.map[i][j] == 'E')
				tmp_map[i][j] = '0';
			j++;
		}
		i++;
	}
	tmp_map[i] = NULL;
	return (tmp_map);
}

void	ft_fill(char **frame, int i, int j, t_struct *stru)
{
	if (frame[i][j] == ' ')
	{
		free(frame);
		ft_error(stru, "Map non fermée");
	}
	if (frame[i][j] == '0')
	{
		if (i == 0 || i == stru->map_data.size_map || j == 0
			 || j == stru->map_data.size_line_max)
			ft_error(stru, "Position de départ incorrecte");
		frame[i][j] = 'A';
		ft_fill(frame, i + 1, j, stru);
		if (i != 0)
			ft_fill(frame, i - 1, j, stru);
		ft_fill(frame, i, j + 1, stru);
		if (j != 0)
			ft_fill(frame, i, j - 1, stru);
	}
	else if (frame[i][j] != '1' && frame[i][j] != 'A')
	{
		free(frame);
		ft_error(stru, "Map non fermée");
	}
}

void	ft_file_read(char *file_name, t_struct *stru)
{
	stru->data.fd = open(file_name, O_RDONLY);
	if (stru->data.fd == -1)
		ft_error(stru, "Ouverture du fichier impossible\n");
	count_line(stru);
	if (stru->check.end_check == 0 || stru->check.coin_left == 0)
		ft_error(stru, "Map invalide\nSortie ou piece manquante\n");
	if (stru->check.player_check > 1)
		ft_error(stru, "Plus d'une position de départ\n");
	close(stru->data.fd);
	stru->data.fd = open(file_name, O_RDONLY);
	if (stru->data.fd == -1)
		ft_error(stru, "Ouverture du fichier impossible\n");
	parse_map(stru);
	if (stru->check.error == 1)
		ft_error(stru, "Map invalide\nCaractère inconnu\n");
	close(stru->data.fd);
	check_map(stru);
}
