#include "../includes/solong.h"

static void    count_line(t_struct *stru)
{
    int ret;
    char *line;

    line = NULL;
    while ((ret = get_next_line(stru->data.fd, &line) != 0))
    {
        if ((unsigned int)stru->map_data.size_line_max < ft_strlen(line))
            stru->map_data.size_line_max = ft_strlen(line);
        stru->map_data.size_map++;
        free(line);
    }
    close(stru->data.fd);
}

static void    parse_map(t_struct *stru)
{
    int i;
    unsigned int j;
    int ret;
    char *line;

    i = 0;
    ret = 1;
    line = NULL;
    if (!(stru->map_data.map = malloc(sizeof(char*) * (stru->map_data.size_map + 1))))
        ft_error(2, stru);
    while ((ret = get_next_line(stru->data.fd, &line)) > 0)
    {
        j = 0;
        stru->map_data.map[i] = NULL;
        if (!(stru->map_data.map[i] = malloc(sizeof(char) * (stru->map_data.size_line_max + 1))))
            ft_error(1, stru);              
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
                stru->check_flags.s_pos_i = i;
                stru->check_flags.s_pos_j = j;
                stru->map_data.map[i][j] = line[j];
            }
            else
                ft_error(1, stru);
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

static char     **copy_map(t_struct *stru)
{   
    char **tmp_map;
    int i;
    int j;
    
    i = 0;
    tmp_map = malloc(sizeof(char *) * (stru->var_mlx.size_map + 1));
    while (stru->map_data.map[i] != NULL)
    {
        tmp_map[i] = NULL;
        tmp_map[i] = malloc(sizeof(char) * (stru->var_mlx.size_line_max + 1));
        j = 0;
        while (stru->map_data.map[i][j])
        {
            tmp_map[i][j] = stru->map_data.map[i][j];
            if (stru->map_data.map[i][j] == 'C' || stru->map_data.map[i][j] == 'P'
            || stru->map_data.map[i][j] == 'E')
            {
                tmp_map[i][j] = '0';
            }
            j++;
        }
        i++;
    }
    tmp_map[i] = NULL;
    return (tmp_map);
}

static void     ft_fill(char **frame, int i, int j, t_struct *stru)
{
    if (frame[i][j] == ' ')
    {
        free(frame);
        ft_error(3, stru);
    }
    if (frame[i][j] == '0')
    {
        if (i == 0 || i == stru->var_mlx.size_map || j == 0 || j == (int)stru->var_mlx.size_line_max)
            ft_error(3, stru);
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
        ft_error(3, stru);
    }
}

static void        check_map(t_struct *stru)
{
    char **tmp;
    int i;

    i = 0;
    tmp = copy_map(stru);
    ft_fill(tmp, stru->check_flags.s_pos_i, stru->check_flags.s_pos_j, stru);
    while(tmp[i])
        free(tmp[i++]);
    free(tmp);
    if (stru->check_flags.s_pos_i == 0 && stru->check_flags.s_pos_j == 0)
        ft_error(3, stru);
}

void    ft_file_read(char *file_name, t_struct *stru)
{
    if ((stru->data.fd = open(file_name, O_RDONLY)) == -1)
        ft_error(2, stru);
    count_line(stru);
    //write(1, "bloup", 5);
    parse_map(stru);
    //write(1, "bloup", 5);
    close(stru->data.fd);
    check_map(stru);
}