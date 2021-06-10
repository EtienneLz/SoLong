#include "../includes/solong.h"

static void vars_init(t_struct *stru)
{
    stru->map_data.size_map = 0;
    stru->map_data.size_line_max = 0;
    stru->map_data.map = NULL;
    stru->data.res_x = 0;
    stru->data.res_y = 0;
}

int     main(int argc, char **argv)
{
    if (argc != 2)
        return(0);
    else
    {
        t_struct  stru;
        vars_init(&stru);
        ft_file_read(argv[2], &stru);

    }
    return (0);
}