NAME=a.out
CC=cc
INCLUDE=-lpthread
FLAG=-Wall -Wextra -Werror -pthread

FLAG_LEAK_CHECK=-g3

SRC_MAIN=./srcs/main/main.c
SRC_CHECK_ARGS=./srcs/check_args/check_args.c
SRC_SET_PARAMS=./srcs/set_params/set_all.c ./srcs/set_params/set_philosophers.c
SRC_PROCESS=./srcs/process/main_process.c
SRC_ERROR=./srcs/error/error.c
SRC_FT_MALLOC=./srcs/ft_malloc/ft_free.c ./srcs/ft_malloc/ft_malloc.c
SRC_UTILS=./srcs/utils/ft_atoi_err.c ./srcs/utils/ft_bzero.c ./srcs/utils/get_time.c

SRCS=$(SRC_MAIN) $(SRC_CHECK_ARGS) $(SRC_SET_PARAMS) $(SRC_PROCESS) $(SRC_ERROR) $(SRC_FT_MALLOC) $(SRC_UTILS)
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

