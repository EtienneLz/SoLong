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

void ft_free(t_struct *stru)
{
    if (stru->map_data.map)
        free(stru->map_data.map);
    ft_exit();
}

int ft_exit(void)
{
    exit(EXIT_SUCCESS);
}