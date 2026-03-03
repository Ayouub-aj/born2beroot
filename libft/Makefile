NAME		= libft.a

FOLDER		= ./core3/

SRC			= \
ft_abs.c \
ft_atoi.c \
ft_bzero.c \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_islower.c \
ft_isprint.c \
ft_isspace.c \
ft_isupper.c \
ft_lstsize.c \
ft_max.c \
ft_memcmp.c \
ft_memcpy.c \
ft_memmove.c \
ft_memset.c \
ft_min.c \
ft_nbrlen_uint.c \
ft_nbrlen.c \
ft_putchar_fd.c \
ft_putchar.c \
ft_putendl_fd.c \
ft_putendl.c \
ft_putnbr_fd.c \
ft_putnbr.c \
ft_putstr_fd.c \
ft_putstr.c \
ft_stpcpy.c \
ft_strcat.c \
ft_strchr.c \
ft_strcmp.c \
ft_strcpy.c \
ft_strlcat.c \
ft_strlcpy.c \
ft_strlen.c \
ft_strncmp.c \
ft_strnlen.c \
ft_strnstr.c \
ft_strrchr.c \
ft_strrev.c \
ft_strtrim.c \
ft_substring.c \
ft_tolower.c \
ft_toupper.c \

FOLDER_MOD	= ./modified/

SRC_MOD		= \
ft_calloc.c \
ft_itoa.c \
ft_lstadd_back.c \
ft_lstadd_front.c \
ft_lstclear.c \
ft_lstdelone.c \
ft_lstiter.c \
ft_lstlast.c \
ft_lstmap.c \
ft_lstnew.c \
ft_memccpy.c \
ft_memchr.c \
ft_split.c \
ft_strdup.c \
ft_strimplode.c \
ft_strjoin_free.c \
ft_strjoin.c \
ft_strmapi.c \
ft_substr.c \

FOLDER_ADD	= ./added/

SRC_ADD		= \
ft_arrbbl.c \
ft_arrdup.c \
ft_arrissrt.c \
ft_arrisunq.c \
ft_count_strings.c \
ft_exit.c \
ft_free_array.c \
ft_free_queue.c \
ft_free_strings.c \
ft_free.c \
ft_gnl.c \
ft_lstclear_malloc.c \
ft_lstdelone_malloc.c \
ft_lstfind.c \
ft_lstmap_malloc.c \
ft_lstnew_malloc.c \
ft_lstremove_malloc.c \
ft_lstremove.c \
ft_malloc.c \
ft_malloc2.c \
ft_printf/ft_format_lstnew.c \
ft_printf/ft_format_lstreset.c \
ft_printf/ft_format_putchar.c \
ft_printf/ft_format_puthex.c \
ft_printf/ft_format_putnbr_uint.c \
ft_printf/ft_format_putnbr.c \
ft_printf/ft_format_putptr.c \
ft_printf/ft_format_putstr.c \
ft_printf/ft_format_utils.c \
ft_printf/ft_printf.c \
ft_ptrcmp.c \
ft_satoi.c \

FOLDER_BON	= ./bonus/

SRC_BON		= \

INCLUDES	= ./

HDR         = \
libft.h \

SRCS		= $(addprefix $(FOLDER), $(SRC))

SRCS_MOD	= $(addprefix $(FOLDER_MOD), $(SRC_MOD))

SRCS_ADD	= $(addprefix $(FOLDER_ADD), $(SRC_ADD))

SRCS_BON	= $(addprefix $(FOLDER_BON), $(SRC_BON))

HDRS		= $(addprefix $(INCLUDES), $(HDR))

HDRS_BON	= $(addprefix $(INCLUDES), $(HDR_BON))

OBJS		= $(SRCS:%.c=%.o)

OBJS_MOD	= $(SRCS_MOD:%.c=%.o)

OBJS_ADD	= $(SRCS_ADD:%.c=%.o)

OBJS_BON	= $(SRCS_BON:%.c=%.o)

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

RM      	= rm -f

BON			= bonus_on

%.o:		%.c Makefile $(HDRS) $(HDRS_BON)
			$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES)

all:		$(NAME)

$(NAME):	$(OBJS) $(OBJS_MOD) $(OBJS_ADD)
			$(RM) $(NAME)
			ar rcs $(NAME) $(OBJS) $(OBJS_MOD) $(OBJS_ADD)
			$(RM) $(BON)

bonus:		all #$(BON)

$(BON):		$(NAME) $(OBJS_BON)
			ar rcs $(NAME) $(OBJS_BON)
			touch $(BON)

clean:
			$(RM) $(OBJS) $(OBJS_MOD) $(OBJS_ADD) $(OBJS_BON)

fclean:		clean
			$(RM) $(NAME) $(BON)

re:			fclean all

.PHONY:		all clean fclean re bonus
