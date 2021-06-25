#include "../includes/solong.h"

void    err(void)
{
    exit(EXIT_SUCCESS);
}

void    ft_error(int code, t_struct *stru)
{
    write(1, "Erreur \n", 8);
    if (code == 1)
    {
        close(stru->data.fd);
        write(1, "Configuration invalide\n", 23);
        ft_free(stru);
    }
    if (code == 2)
    {
        close(stru->data.fd);
        write(1, "Ta mere\n", 8);
        ft_free(stru);
    }
    if (code == 3)
    {
        close(stru->data.fd);
        write(1, "Map invalide\n", 14);
        ft_free(stru);
    }
}

int ft_free(t_struct *stru)
{
    int i;

    i = 0;
    if (stru->map_data.map)
    {
        while (stru->map_data.map[i])
        {
            free(stru->map_data.map[i]);
            i++;
        }
        free(stru->map_data.map);
    }
    if (stru->texture[0].img)
        mlx_destroy_image(stru->var_mlx.mlx, stru->texture[0].img);
    if (stru->texture[1].img)
        mlx_destroy_image(stru->var_mlx.mlx, stru->texture[1].img);
    if (stru->texture[2].img)
        mlx_destroy_image(stru->var_mlx.mlx, stru->texture[2].img);
    if (stru->texture[3].img)
        mlx_destroy_image(stru->var_mlx.mlx, stru->texture[3].img);
    if (stru->texture[4].img)
        mlx_destroy_image(stru->var_mlx.mlx, stru->texture[4].img);
    mlx_destroy_image(stru->var_mlx.mlx, stru->data.img);
    mlx_destroy_window(stru->var_mlx.mlx, stru->var_mlx.win);
    ft_exit();
    return (0);
}

int ft_exit(void)
{
    exit(EXIT_SUCCESS);
}