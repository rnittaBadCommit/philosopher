NAME=a.out
CC=cc -g3 -pthread
INCLUDE=
FLAG=-Wall -Wextra -Werror -pthread

FLAG_LEAK_CHECK=-g3

SRC_MAIN=./srcs/main/main.c
SRC_CHECK_ARGS=./srcs/check_args/check_args.c
SRC_SET_PARAMS=./srcs/set_params/set_all.c ./srcs/set_params/set_philosopher_data.c ./srcs/set_params/make_fork.c ./srcs/set_params/set_philosophers.c 
SRC_THREAD=./srcs/thread/main_process.c ./srcs/thread/monitoring_thread.c ./srcs/thread/action.c
SRC_ERROR=./srcs/error/error.c
SRC_FT_MALLOC=./srcs/ft_malloc/ft_free.c ./srcs/ft_malloc/ft_malloc.c
SRC_UTILS=./srcs/utils/ft_atoi_err.c ./srcs/utils/ft_bzero.c ./srcs/utils/get_time.c ./srcs/utils/print_log_mutex.c ./srcs/utils/ft_usleep.c

SRCS=$(SRC_MAIN) $(SRC_CHECK_ARGS) $(SRC_SET_PARAMS) $(SRC_THREAD) $(SRC_ERROR) $(SRC_FT_MALLOC) $(SRC_UTILS)
OBJS = $(SRCS:.c=.o)

.c.o:
	$(CC) $(FLAG) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FLAGSEC) $(OBJS) $(LINK) -o $(NAME)

all: $(NAME)

sani: $(NAME)
	$(CC) $(OBJS) $(SANI) $(LINK) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean sani

