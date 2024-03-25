CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME = get_next_line.a
HEADER = get_next_line.h

SRCS = get_next_line.c\
	   get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

#regla implicita
all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean $(NAME)


.PHONY:	all, clean, fclean, re
