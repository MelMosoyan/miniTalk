NAME = libftprintf.a
SRCS = $(shell find . -name '*.c')
OBJS = $(SRCS:.c=.o)
CC = cc
FLAGS = -Wall -Wextra -Werror
AR = ar -r
RM = rm -rf

all : $(NAME)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)
	
re : fclean all

.PHONY : all clean fclean re
