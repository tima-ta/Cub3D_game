/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araqioui <araqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:58:10 by araqioui          #+#    #+#             */
/*   Updated: 2023/06/26 10:55:42 by araqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../utils/get_next_line/get_next_line.h"
# include <math.h>
# include <stdbool.h>
# include <limits.h>
# include <mlx.h>

# define BOX_SIZE 32
# define ANGLE_SPEED 6
# define PLAYER_SPEED 10
# define MIN_FACTOR 0.3
# define WIN_WIDTH 1280
# define WIN_HEIGHT 720

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_hitpoint
{
	bool	it_hits;
	double	distance;
	double	x;
	double	y;
}	t_hitpoint;

typedef struct s_hit_info
{
	double		angle;
	double		x_inters;
	double		y_inters;
	double		dx;
	double		dy;
	bool		vert_hit;
	bool		left;
	t_hitpoint	horz_point;
	t_hitpoint	vert_point;
}	t_hit_info;

typedef struct s_direction
{
	bool		up;
	bool		down;
	bool		left;
	bool		right;
	t_hit_info	hit_info;
}	t_direction;

typedef struct s_coor
{
	int	x;
	int	y;
}	t_coor;

typedef struct s_coor_fl
{
	double	x;
	double	y;
}	t_coor_fl;

typedef struct s_info
{
	t_coor_fl	p_coor;
	double		angle;
	char		dir;
	char		**map;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	int			floor[3];
	int			ceiling[3];
}	t_info;

typedef struct s_holder
{
	t_info			data;
	t_coor			help_cor;
	t_direction		*dir;
	t_data			img_help;
	t_data			img;
	t_data			no;
	t_data			so;
	t_data			we;
	t_data			ea;
	int				width;
	int				height;
	int				num_rays;
	void			*win;
	void			*mlx;
}	t_holder;

/**************** FUNCTIONS **************/

/***************** Parsing ***************/

int				map__name(char *str);
void			ft_putstr_fd(char *s, int fd);
char			**reading_map(char *file);
int				parse_bottom(char **file, t_info *data, int index);
char			**ft_split(char const *s, char c, int *flg, int flg_0);
int				parse_top(char **map, t_info *data, int *index);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
char			*ft_strdup_(const char *s);
char			**free_2d(char **arr);
int				ft_atoi(const char *str);
void			_print_err(void);
bool			pick_color(char *info, int flg, t_info *data);
bool			reach_map(char *s);
char			*eliminate_new_line(char *s);
void			data_init(t_info *data);
void			data_free(t_info *data);
int				len_new_line(char *s);
int				strlen_nl(char *str);
int				check_chars(char **map, int *size);
int				vertically_check(char **map, int i, int flg);
int				horizontally_check(char **map, int s, int j, int flg);
bool			fill_texture(char *info, int flg, t_info *data);
void			fill_rgb_f(int r, int g, int b, t_info *data);
void			fill_rgb_c(int r, int g, int b, t_info *data);
int				check_spc(char *s);

/***************** Game ***************/

int				simulation(t_info data);
void			mini_map(t_holder hold);
void			calc(t_holder *holder);
int				is_player(char c);
double			deg_to_rad(double angle);
double			angle_range(double angle);
int				move_player(int keycode, void *param);
double			distance(double x1, double x2, double y1, double y2);
void			horizontal_hit_point(t_holder *hold, t_direction *ray);
void			vertical_hit_point(t_holder *hold, t_direction *ray);
void			calc_steps_horz(t_holder *hold, t_direction *ray, double angle);
void			calc_steps_vert(t_holder *hold, t_direction *ray, double angle);
void			found_hit_point(t_holder *hold, t_direction *ray, double angle);
void			render_walls_3d(t_holder hold);
unsigned int	rgb_to_hex(int r, int g, int b);
void			save_rays(t_holder *hold);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
int				ft_close(void *param);

#endif