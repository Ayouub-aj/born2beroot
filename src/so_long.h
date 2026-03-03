/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   so_long.h										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: swilmer <marvin@42.fr>					 +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2021/10/10 17:43:56 by swilmer		   #+#	#+#			 */
/*   Updated: 2021/10/12 07:09:42 by swilmer		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/libft.h"
# include <fcntl.h>
# include <mlx.h>

# define IMG 100

typedef enum e_bool
{
	TRUE = 1,
	FALSE = 0
}	t_bool;

typedef struct s_xy
{
	int	x;
	int	y;
}	t_xy;

typedef enum e_boxtype
{
	EMPTY = '0',
	WALL = '1',
	COLLECTABLE = 'C',
	HERO = 'P',
	EXIT = 'E'
}	t_boxtype;

typedef struct s_box
{
	t_boxtype		type;
	t_boxtype		og_type;
	t_xy			pos;
	struct s_box	*up;
	struct s_box	*down;
	struct s_box	*left;
	struct s_box	*right;
}	t_box;

enum e_keycode
{
	KEY_W = 13,
	KEY_S = 1,
	KEY_A = 0,
	KEY_D = 2,
	KEY_UP = 126,
	KEY_DOWN = 125,
	KEY_LEFT = 123,
	KEY_RIGHT = 124,
	KEY_ESC = 53
};

typedef struct s_hero
{
	t_box	*box;
	t_box	*og_box;
	void	*current_img;
	t_bool	completed;
}	t_hero;

typedef struct s_img {
	void	*ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_game
{
	t_xy			size;
	t_box			**map;
	t_hero			hero;
	int				og_collects;
	int				collects;
	int				moves;
	void			*ground_img;
	void			*wall_img;
	void			*collect_img;
	void			*exit_open_img;
}	t_game;

typedef struct s_mlx {
	void		*init;
	void		*win;
	t_img		*bgr_img;
	int			w;
	int			h;
	int			win_w;
	int			win_h;
	t_game		game;
}	t_mlx;

typedef struct s_countchars
{
	int	c;
	int	e;
	int	p;
}	t_countchars;

void	so_long(const char **map);
void	*ft_nn(void *ptr, char *msg);
void	create_window(t_mlx *mlx);
t_img	*new_image(t_mlx *mlx, int w, int h);
void	fill_square_img(t_img *img, int width, int height, unsigned int colour);
void	my_mlx_pixel_put(t_img *img, int x, int y, int colour);
int		close_game(void);
void	parse_map(const char *map, t_mlx *mlx);
void	parse_map_ber_ext(const char *map);
int		parse_map_line_count(const char *map);
char	**parse_map_get_strings(const char *map, int lines);
int		parse_map_line_len(char **s);
void	parse_map_check_walls(char **ss, int len, int lines);
void	parse_map_check_chars(char **ss);
t_box	**parse_map_create_boxes(char **ss, int len, int lines, t_mlx *mlx);
void	parse_map_connect_boxes(int len, int lines, t_mlx *mlx);
int		parse_map_open_file(const char *map);
void	prepare_imgs(t_mlx *mlx);
void	prepare_settings(t_mlx *mlx);
int		render_next_frame(t_mlx *mlx);
int		key_hook(int key, t_mlx *mlx);
char	*ft_strf(char const *format, ...);
void	*eni(void *ptr);
void	render_map(t_mlx *mlx);
void	render_hero(t_mlx *mlx);
int		calc_hmove_x(t_mlx *mlx);
int		calc_hmove_y(t_mlx *mlx);
int		move(t_mlx *mlx, t_box *box);
void	render_box(t_box box, int x, int y, t_mlx *mlx);
int		calc_move_x(int x, t_mlx *mlx);
int		calc_move_y(int y, t_mlx *mlx);

#endif
