#ifndef SOLONG_H
# define SOLONG_H

# include "../minilibx-linux/mlx.h" 
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>

# define UP	            119
# define DOWN		    115
# define RIGHT		    100
# define LEFT		    97
# define BUFFER_SIZE    4096

typedef struct      s_data 
{
    void            *img;
    char            *addr;
    int             bits_per_pixel;
    int             line_length;
    int             endian;
    int             res_x;
    int             res_y;
    int             fd;
}                   t_data;

typedef struct      s_map_data
{
    char            **map;
    int             size_map;
    int             size_line_max;
}                   t_map_data;

typedef struct      s_var_mlx 
{
    void            *mlx;
    void            *win;
    int             size_case;
}                   t_var_mlx;

typedef struct      s_check_flags
{
    int             pos_i;
    int             pos_j;
    int             s_pos_i;
    int             s_pos_j;
    int             init_done;
}                   t_check_flags;


typedef struct      s_struct
{
    t_data          data;
    t_map_data      map_data;
    t_var_mlx       var_mlx;
    t_check_flags   check_flags;
}                   t_struct;

void            ft_file_read(char *file_name, t_struct *stru);
int		        get_next_line(int fd, char **line);
size_t	        ft_strlen(const char *s);
char	        *ft_strjoin(char const *s1, char const *s2);
char	        *ft_strdup(const char *s1);
char	        *ft_strchr(const char *s, int c);
char	        *ft_substr(char const *s, unsigned int start, size_t len);
char	        *clean_line(char *save, char **line);
char	        *ft_save(char *buffer, char *save);
void            draw_player(int pos_i, int pos_j, t_struct *stru);
void            win_init(t_struct *stru);
void            my_mlx_pixel_put(t_data *data, int x, int y, int color);
int             ft_exit(void);
void            input_loop(t_struct *stru);
void            move_player(int direction, t_struct *stru);
void            ft_error(int code, t_struct *stru);
void            ft_free(t_struct *stru);
void            err(void);

#endif