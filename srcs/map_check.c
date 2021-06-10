#include "../includes/solong.h"

static void    count_line(int fd, t_struct *stru)
{
    int ret;
    char *line;
    int i;

    i = 0;
    while ((ret = get_next_line(fd, &line) != 0))
    {
        if (stru->map_data.size_line_max < ft_strlen(line))
            stru->map_data.size_line_max = ft_strlen(line);
        stru->map_data.size_map++;
        free(line);
    }
    close(fd);
    if (!(stru->map_data.map = malloc(sizeof(char*) * (stru->map_data.size_map + 1))))
        ft_error(2);
    if ((fd = open("config.cub", O_RDONLY)) == -1)
        ft_error(1);
    while (i <= 9)
    {
        get_next_line(fd, &line);
        i++;
        free(line);
    }
}

static void    parse_map(int fd, t_struct *stru)
{
    int i;
    unsigned int j;
    int ret;
    char *line;

    i = 0;
    ret = 1;
    while (ret != 0)
    {
        ret = get_next_line(fd, &line);
        map_data.map[i] = NULL;
        j = 0;
        if (!(map_data.map[i] = malloc(sizeof(char) * (map_data.size_line_max + 1))))
            ft_error(1);
        while (line[j])
        {
            if (line[j] == ' ' || line[j] == '1')
                map_data.map[i][j] = line[j];
            else if (line[j] == '2')
                map_data.map[i][j] = '2';
            else if (line[j] == '0')
                map_data.map[i][j] = '0';
            else if (line[j] == 'N' || line[j] == 'S' || line[j] == 'W' || line[j] == 'E')
                map_data.map[i][j] = line[j];
            else
                ft_error(1);
            j++;
        }
        while (j < map_data.size_line_max)
            map_data.map[i][j++] = ' ';
        map_data.map[i][j] = '\0';
        free(line);
        i++;
    }
    map_data.map[i] = NULL;
}

void    ft_file_read(char *file_name, t_struct *stru)
{
    int fd;
    char *line;

    if ((fd = open(file_name, O_RDONLY)) == -1)
        strerror(errno);
    count_line(fd, &stru);
    parse_map(fd, &stru);
}