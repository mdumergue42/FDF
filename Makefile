SRCS =	ft_window.c \
		ft_print_line.c \
		ft_printf.c \
		get_next_line.c \
		ft_atoi.c \
		ft_isdigit.c \
		ft_memmove.c \
		ft_split.c \
		ft_strlcpy.c \
		ft_strtrim.c \
		ft_bzero.c \
		ft_isprint.c \
		ft_memset.c \
		ft_strchr.c \
		ft_strlen.c \
		ft_substr.c \
		ft_calloc.c \
		ft_itoa.c \
		ft_putchar_fd.c \
		ft_strdup.c \
		ft_strmapi.c \
		ft_tolower.c \
		ft_isalnum.c \
		ft_memchr.c \
		ft_putendl_fd.c \
		ft_striteri.c \
		ft_strncmp.c \
		ft_toupper.c \
		ft_isalpha.c \
		ft_memcmp.c \
		ft_putnbr_fd.c \
		ft_strjoin.c \
		ft_strnstr.c \
		ft_isascii.c \
		ft_memcpy.c \
		ft_putstr_fd.c \
		ft_strlcat.c \
		ft_strrchr.c \
		ft_atoi_base.c
       

NAME    = fdf.a

OBJS    =  ${SRCS:.c=.o}

HEADERS    = includes/

CC = gcc

CFLAGS = -Wall -Wextra -Werror -lmlx lXext -lX11

all : ${NAME}

${OBJS} : 
	$(CC) $(CFLAGS) -I ${HEADERS} -c ${@:.o=.c} -o $@

${NAME} : ${OBJS}
	ar rcs ${NAME} ${OBJS}

clean :
	rm -f ${OBJS}

fclean : clean
	rm -f ${NAME}

re : fclean all

.PHONY : all clean fclean re
