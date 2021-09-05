CC = gcc
NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror -c
LIBFT = libft.a
SOURCEDIR = ./source
OBJDIR = ./obj
LIB_PATH = ./libft
INCLUDES = ./includes

SOURCES_FILE = ft_printf.c ft_fill.c reset_option.c ft_placeholder.c screen_d.c annex1.c annex2.c screen_c.c screen_s.c
OBJFILE = $(SOURCES_FILE:.c=.o)
OBJECTS = $(addprefix $(OBJDIR)/,$(OBJFILE))

all:$(NAME)

$(NAME):$(OBJECTS)
	make -C $(LIB_PATH)
	cp $(LIB_PATH)/$(LIBFT) $(NAME)
#	cp ./libft      /li
#	$(CC) -g3 $(CFLAGS) $(SRCS) -I$(INCLUDES)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

$(OBJDIR)/%.o: $(SOURCEDIR)/%.c
	$(CC) -I./includes -c $< -o $@

bonus: re

clean:
	@/bin/rm -f $(OBJECTS)
	@make clean -C $(LIB_PATH)


fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re
