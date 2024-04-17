#ifndef CUB3D_H
# define CUB3D_H

# define WIDTH	1600
# define HEIGHT	1200
# define PI 3.14159265
# define DIM_TXTR 64

# include "libft/libft.h"
# include "mlx.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdbool.h>
# include <math.h>

typedef struct s_image{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}				t_image;

typedef struct s_map{
	char	**map;
	int		size;
	int		size_long;
	t_image	background;
	t_image	floor;
	t_image	exit;
	t_image	coll;
}				t_map;

typedef struct s_x{
	double	pos;
	int		map;
	int		step;
	double	dir;
	double	plane;
	double	ray;
	double	delta_dist;
	double	side_dist;
}				t_x;

typedef struct s_y{
	double	pos;
	int		map;
	int		step;
	double	dir;
	double	plane;
	double	ray;
	double	delta_dist;
	double	side_dist;
}				t_y;

typedef struct s_count{
	int		perso;
	int		west;
	int		east;
	int		north;
	int		south;
	int		floor;
	int		ceiling;
	bool	a;
	bool	d;
	bool	s;
	bool	w;
	bool	rotate_r;
	bool	rotate_l;
}				t_count;

typedef struct s_wall{
	int		side;
	int		hit;
	int		line_height;
	int		drawend;
	int		drawstart;
	int		color;
	double	perp_wall;
	int		walltxtr;
}				t_wall;

typedef struct s_floor{
	int	r;
	int	g;
	int	b;
}				t_floor;

typedef struct s_ceiling{
	int	r;
	int	g;
	int	b;
}				t_ceiling;

typedef struct s_verticaline{
	int				texy;
	int				pixel;
	int				bits;
	double			pos;
}				t_vtcln;

typedef struct s_data{
	void		*mlx;
	void		*win;
	t_x			*x;
	t_y			*y;
	t_map		*map;
	t_count		*count;
	t_floor		*floor;
	t_ceiling	*ceiling;
	t_wall		*wall;
	t_image		txtr[4];
}				t_data;

/*main.c*/
int		main(int ac, char **av);
void	destroy(t_data *data);
void	init_count(t_count *count, t_data *data);
int		valid_file(char **s, int ac, int fd);

/*move.c*/
void	move_left_right(t_data *data);
void	rotate(t_data *data);
void	move_up_down(t_data *data);

/*init_pers.c*/
void	init_pers(char **position, int i, int j, t_data *data);
void	east_west_direction(char letter, t_data *data);
void	north_south_direction(char letter, t_data *data);

/*calculate.c*/
void	calculate_wall_height(t_data *data);
void	calculate_length_ray(t_data *data, double cameraX);
void	search_wall(t_data *data);
void	calculate_sidedist(t_data *data);
int		calcul_xtxtr(t_data *data);

/*utils.c*/
char	*skip_nl(char *line, int fd);
char	*ft_cut_beg(char *line, int beg);
int		tab_size(char **tab);
int		is_pers(char letter);
int		is_wall_space_newline(char letter);

/*free.c*/
void	free_tab(char **tab, int size);
void	my_free(t_data *data);
void	free_map(t_data *data);
void	free_xpm_ptr(t_data *data);

/*read_map.c*/
int		checking_longer_lines(char **position, int i, int j);
int		valid_map2(t_data *data, int size);
int		read_map(int fd, t_data *data);

/*valid_map.c*/
int		valid_upper_wall(char *line);
int		valid_lower_wall(t_data *data, char **position, int i, int j);
int		valid_map(char *line, t_data *data, int size);
int		checking_empty_spots(char **position, int i, int j, t_data *data);

/*check_path*/
int		check_before_path(char *line, int i);
char	*path_texture(char *line);
void	check_repetition(char first, t_data *data);
int		check_txtr(char *line, char first, char second);

/*parsing_textures.c*/
int		read_textures(int fd, t_data *data);
int		check_colour(char *line, t_data *data);
int		textures(char *line, t_data *data);
void	store_colours(char colour, int j, int c, t_data *data);

/*colours.c*/
void	draw(t_data *data);
void	draw_ceiling(int y, t_data *data);
void	draw_floor(int y, t_data *data);
int		create_trgb(int t, int r, int g, int b);

/*window.c*/
int		initialize(int fd, t_data *data);
int		close_cross(t_data *data);
int		move(t_data *data);
int		render(t_data *data);
void	raycasting(t_data *data);
int		esc(int key_code, t_data *data);

/*key.c*/
int		key_press(int key_code, t_data *data);
int		key_release(int key_code, t_data *data);
void	init_key(t_data *data);

/*utils2.c*/
int		isafter_textures(t_data *data);
char	*skip_nl2(char *line, int fd, t_data *data);
/*tools.c*/
char	*ft_straddchar(char *s1, char c);
int		skip_ws(char *line, int i);
char	**ft_tabaddstr(char **t1, char *str);

/*import_texture.c*/
void	get_texture_adress(t_data *data);
int		get_path_txtr(char *line, t_data *data, int txtr_type, int start_copy);
int		ciel_floor(char *line, t_data *data);

/*draw_texture.c*/
void	vertical_line(int x, t_data *data, int texX, double step);

#endif
