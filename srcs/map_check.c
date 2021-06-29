#include "../includes/solong.h"

static void	count_line(t_struct *stru)
{
	int		i;
	int		ret;
	char	*line;
	int		end_check;
	int		coin_check;

	line = NULL;
	end_check = 0;
	coin_check = 0;
	while ((ret = get_next_line(stru->data.fd, &line)) != 0)
	{
		i = 0;
		if ((unsigned int)stru->map_data.size_line_max < ft_strlen(line))
			stru->map_data.size_line_max = ft_strlen(line);
		stru->map_data.size_map++;
		while (line[i])
		{
			if (line[i] == 'E')
				end_check = 1;
			if (line[i] == 'C')
			{
				coin_check = 1;
				stru->check.coin_left++;
			}
			i++;
		}
		free(line);
	}
	free(line);
	if (end_check == 0 || coin_check == 0)
		ft_error(stru, "Map invalide\nSortie ou piece manquante\n");
	stru->map_data.size_map++;
	close(stru->data.fd);
}

static void	parse_map(t_struct *stru)
{
	int				i;
	unsigned int	j;
	char			*line;

	i = 0;
	line = NULL;
	if (!(stru->map_data.map = malloc(sizeof(char *) * (stru->map_data.size_map + 1))))
		ft_error(stru, "Allocation de memoire echouee\n");
	while (i < stru->map_data.size_map)
	{
		get_next_line(stru->data.fd, &line);
		j = 0;
		stru->map_data.map[i] = NULL;
		if (!(stru->map_data.map[i] = malloc(sizeof(char) * (stru->map_data.size_line_max + 1))))
			ft_error(stru, "Allocation de memoire echouee\n");
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
				ft_error(stru, "Map invalide\nCaractere inconnu\n");
			j++;
		}
		while (j < (unsigned int)stru->map_data.size_line_max)
			stru->map_data.map[i][j++] = ' ';
		stru->map_data.map[i][j] = '\0';
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

void	ft_fill(char **frame, int i, int j, size_t size_line_max, int size_map)
{
	if (frame[i][j] == ' ')
	{
		free(frame);
		err();
	}
	if (frame[i][j] == '0')
	{
		if (i == 0 || i == size_map || j == 0 || j == (int)size_line_max)
			err();
		frame[i][j] = 'A';
		ft_fill(frame, i + 1, j, size_line_max, size_map);
		if (i != 0)
			ft_fill(frame, i - 1, j, size_line_max, size_map);
		ft_fill(frame, i, j + 1, size_line_max, size_map);
		if (j != 0)
			ft_fill(frame, i, j - 1, size_line_max, size_map);
	}
	else if (frame[i][j] != '1' && frame[i][j] != 'A')
	{
		free(frame);
		err();
	}
}

void	ft_file_read(char *file_name, t_struct *stru)
{
	if ((stru->data.fd = open(file_name, O_RDONLY)) == -1)
		ft_error(stru, "Ouverture du fichier impossible\n");
	count_line(stru);
	if ((stru->data.fd = open(file_name, O_RDONLY)) == -1)
		ft_error(stru, "Ouverture du fichier impossible\n");
	parse_map(stru);
	close(stru->data.fd);
	check_map(stru);
}
