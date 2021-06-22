#include "../includes/solong.h"

static void vars_init(t_struct *stru)
{
    stru->map_data.size_map = 0;
    stru->map_data.size_line_max = 0;
    stru->map_data.map = NULL;
    stru->data.res_x = 720;
    stru->data.res_y = 480;
    stru->data.fd = 0;
    stru->check_flags.s_pos_i = 0;
    stru->check_flags.s_pos_j = 0;
    stru->check_flags.pos_i = 0;
    stru->check_flags.pos_j = 0;
    stru->check_flags.init_done = 0;
}

int     main(int argc, char **argv)
{
    t_struct  stru;
    vars_init(&stru);
    if (argc != 2)
    {
        printf("bloupppp");
        return (0);
    }
    else
    {
        ft_file_read(argv[1], &stru);
        write(1, "bloup", 5);
        stru.var_mlx.mlx = mlx_init();
        stru.var_mlx.size_case = stru.data.res_x / stru.map_data.size_line_max;
        
        input_loop(&stru);
    }
    return (0);
}