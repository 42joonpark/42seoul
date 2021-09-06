/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 19:29:13 by joonpark          #+#    #+#             */
/*   Updated: 2021/06/23 13:55:42 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "get_next_line.h"
# include "mlx.h"
# include "errors.h"
# include "key_code.h"
# include <math.h>

# define WINDOW_WIDTH	1920
# define WINDOW_HEIGHT	1080

# define ISOMETRIC		1
# define PARALLEL		-1

# define BG_COLOR		0x222222
# define ONE_OF_FIVE	0xBE5381
# define TWO_OF_FIVE	0xFE69BA
# define THREE_OF_FIVE	0xF67DB0
# define FOUR_OF_FIVE	0xFED1E5
# define FIVE_OF_FIVE	0xD8F9FF
# define COLOR_CNT		5

typedef struct			s_coord
{
	int					z;
	int					color;
	struct s_coord		*next;
}						t_coord;

typedef struct			s_chead
{
	struct s_coord		*head;
	struct s_coord		*tail;
}						t_chead;

typedef struct			s_point
{
	int					y;
	int					x;
	int					z;
	int					color;
}						t_point;

typedef struct			s_map
{
	int					width;
	int					height;
	int					z_min;
	int					z_max;
	t_point				**arr;
}						t_map;

typedef struct			s_camera
{
	int					x_axis;
	int					y_axis;
	int					z_axis;
	int					s_speed;
	int					x_pos;
	int					y_pos;
}						t_camera;

typedef struct			s_fdf
{
	void				*mlx;
	void				*win;
	void				*img;
	char				*data_addr;
	int					bits_per_pixel;
	int					size_line;
	int					endian;
	int					scale;
	int					is_isometric;
	t_map				*map;
	t_camera			*camera;
}						t_fdf;

int						terminate(char *s);
void					fatal(char *s);
void					finish_program(t_fdf *fdf);
void					free_map(t_map *map);
void					free_results(char **results);
int						free_chead(t_chead *header);
int						read_map_terminate(char *msg, char *s,
											char **res, t_chead *header);
void					fdf_init(t_fdf *data, const char *file_name);
void					make_hook(t_fdf *fdf);
int						make_map_arr(t_map *map, t_chead *header);
int						read_map(int fd, t_map *map);
int						get_color(const char *line);
int						get_default_color(t_fdf *fdf, int z);
int						get_current_color(t_point diff, t_point s,
											t_point e, t_point cur);
t_point					get_new_point(int x, int y, t_fdf *fdf);
int						ft_min(int a, int b);
int						ft_max(int a, int b);
double					to_radian(double a);
int						draw(t_fdf *fdf);
void					iso(t_point *point);
t_point					conversion(t_point point, t_fdf *fdf);
void					control_keyboard(int keycode, t_fdf *fdf);

#endif
