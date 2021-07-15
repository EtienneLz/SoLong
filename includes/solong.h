/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouchez <elouchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 18:18:57 by elouchez          #+#    #+#             */
/*   Updated: 2021/07/15 18:08:07 by elouchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

typedef struct s_data
{
	void			*img;
	char			*addr;
	int				bbp;
	int				line_length;
	int				endian;
	int				height;
	int				width;
	int				res_x;
	int				res_y;
	int				fd;
}					t_data;

typedef struct s_map_data
{
	char			**map;
	int				size_map;
	int				size_line_max;
}					t_map_data;

typedef struct s_var
{
	void			*mlx;
	void			*win;
	int				size_case;
}					t_var;

typedef struct s_check
{
	int				pos_i;
	int				pos_j;
	int				s_pos_i;
	int				s_pos_j;
	int				nb_moves;
	int				coin_left;
	int				init_done;
	int				end_check;
	int				player_check;
	int				error;
}					t_check;

typedef struct s_struct
{
	t_data			data;
	t_map_data		map_data;
	t_var			var;
	t_check			check;
	t_data			tex[5];
}					t_struct;

void				ft_file_read(char *file_name, t_struct *stru);
int					get_next_line(int fd, char **line);
size_t				ft_strlen(const char *s);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strdup(const char *s1);
char				*ft_strchr(const char *s, int c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*clean_line(char *save, char **line);
char				*ft_save(char *buffer, char *save);
void				draw_player(int pos_i, int pos_j, t_struct *stru);
int					win_refresh(t_struct *stru);
void				my_mlx_pixel_put(t_struct *stru, int x, int y, int color);
int					ft_exit(void);
void				input_loop(t_struct *stru);
void				move_player(int direction, t_struct *stru);
void				ft_error(t_struct *stru, char *msg);
int					ft_free(t_struct *stru);
void				ft_putnbr_fd(int n, int fd);
unsigned int		mlx_get_pixel(t_struct *stru, int x, int y, int w_img);
unsigned int		mlx_rgb_to_int(int o, int r, int g, int b);
void				draw(t_struct *stru, int w_img, int i, int j);
void				ft_putstr_fd(char *s, int fd);
void				check_map(t_struct *stru);
void				ft_fill(char **frame, int i, int j, t_struct *stru);
char				**copy_map(t_struct *stru);
void				select_square(int i, int j, t_struct *stru);
void				texture_init(t_struct *stru);
void				check_line(t_struct *stru, int i, char *line);
char				*ft_itoa(int n);
void				err(t_struct *stru, char **tmp);

#endif
