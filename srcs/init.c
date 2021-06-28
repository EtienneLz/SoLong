#include "../includes/solong.h"

static void vars_init(t_struct *stru)
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
    stru->var_mlx.size_case = 48;
    stru->data.img = NULL;
    stru->texture[0].img = NULL;
    stru->texture[1].img = NULL;
    stru->texture[2].img = NULL;
    stru->texture[3].img = NULL;
    stru->texture[4].img = NULL;
}

void	ft_putstr_fd(char *s, int fd)
{
	int i;

	i = 0;
	while (s[i])
		write(fd, &s[i++], 1);
}

int     main(int argc, char **argv)
{
    t_struct  stru;
    vars_init(&stru);
    if (argc != 2)
    {
        return (0);
    }
    else
    {
        ft_file_read(argv[1], &stru);
        stru.var_mlx.mlx = mlx_init();
        stru.data.res_x = stru.map_data.size_line_max * stru.var_mlx.size_case;
        stru.data.res_y = (stru.map_data.size_map) * stru.var_mlx.size_case;
        input_loop(&stru);
    }
    return (0);
}

