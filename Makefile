NAME		= so_long

NAME_BON	= so_long

LIBA		= Libft/

lib			= libft.a

MLX_FOLDER	= mlx_beta2020/

FOLDER		= src/

SRC			= \
main.c \
so_long.c \
ft_nn.c \
create_window.c \
new_image.c \
fill_square_img.c \
my_mlx_pixel_put.c \
close_game.c \
parse_map.c \
parse_map_ber_ext.c \
parse_map_line_count.c \
parse_map_get_strings.c \
parse_map_line_len.c \
parse_map_check_walls.c \
parse_map_check_chars.c \
parse_map_create_boxes.c \
parse_map_connect_boxes.c \
parse_map_open_file.c \
prepare_imgs.c \
prepare_settings.c \
render_next_frame.c \
key_hook.c \
ft_strf.c \
eni.c \
render_map.c \
render_hero.c \
calc_hmove_x.c \
calc_hmove_y.c \
move.c \
render_box.c \
calc_move_x.c \
calc_move_y.c \

FOLDER_BON	= src_bonus/

SRC_BON		= \
main.c \
so_long.c \
ft_nn.c \
create_window.c \
new_image.c \
fill_square_img.c \
my_mlx_pixel_put.c \
fill_circle_gradient_img.c \
close_game.c \
parse_map.c \
parse_map_ber_ext.c \
parse_map_line_count.c \
parse_map_get_strings.c \
parse_map_line_len.c \
parse_map_check_walls.c \
parse_map_check_chars.c \
parse_map_create_boxes.c \
parse_map_connect_boxes.c \
parse_map_open_file.c \
prepare_imgs.c \
prepare_settings.c \
render_next_frame.c \
key_hook.c \
ft_strf.c \
eni.c \
render_map.c \
render_hero.c \
calc_hmove_x.c \
calc_hmove_y.c \
move.c \
hud.c \
change_resolution.c \
reset_game.c \
render_box.c \
next_level.c \
restart_window.c \
calc_move_x.c \
calc_move_y.c \

INCLUDE		= \
$(LIBA) \
$(MLX_FOLDER) \

HDR			= \
so_long.h \

HDR_BON		= \
so_long.h \

SRCS		= $(addprefix $(FOLDER), $(SRC))

SRCS_BON	= $(addprefix $(FOLDER_BON), $(SRC_BON))

INCLUDES	= $(addprefix -I, $(INCLUDE))

HDRS		= $(addprefix $(FOLDER), $(HDR))

HDRS_BON	= $(addprefix $(FOLDER_BON), $(HDR_BON))

OBJS		= $(SRCS:%.c=%.o)

OBJS_BON	= $(SRCS_BON:%.c=%.o)

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

MLX_FLAGS	= -L$(MLX_FOLDER) -lmlx -framework OpenGL -framework AppKit -lz

RM      	= rm -f

BON			= .bonus_on

%.o:		%.c Makefile $(HDRS) $(HDRS_BON)
			$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

all:		libft mlx $(NAME)
			
mlx:		
			make -C $(MLX_FOLDER)

libft:
			make -C $(LIBA)

$(NAME):	$(LIBA)$(lib) $(OBJS) $(MLX_FOLDER)/libmlx.dylib
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBA)$(lib) $(MLX_FLAGS)
			cp $(MLX_FOLDER)/libmlx.dylib .
			$(RM) $(BON)

bonus:		libft_bonus mlx $(BON) playbonus

libft_bonus:
			make bonus -C $(LIBA)

playbonus:
			./so_long maps_bonus/*.ber

$(BON):		$(LIBA)$(lib) $(OBJS_BON) $(MLX_FOLDER)/libmlx.dylib
			$(CC) $(CFLAGS) -o $(NAME_BON) $(OBJS_BON) $(LIBA)$(lib) $(MLX_FLAGS)
			cp $(MLX_FOLDER)/libmlx.dylib .
			touch $(BON)

clean:		libft_clean local_clean

mlx_clean:
			make clean -C $(MLX_FOLDER)

libft_clean:
			make clean -C $(LIBA)

local_clean:
			$(RM) $(OBJS) $(OBJS_BON)

fclean:		local_clean
			make clean -C $(MLX_FOLDER)
			make fclean -C $(LIBA)
			$(RM) $(NAME) $(NAME_BON) $(BON) libmlx.dylib

re:			fclean all

.PHONY:		all clean fclean re libft bonus libft_bonus libft_clean local_clean mlx mlx_clean run playbonus
