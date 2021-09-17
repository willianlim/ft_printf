CC = clang
NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror -c
LIBFT = libft.a
SOURCEDIR = ./source
OBJDIR = ./obj
LIB_PATH = ./libft
INCLUDES = ./includes

SOURCES_FILE = ft_printf.c ft_fill.c reset_option.c ft_placeholder.c screen_d.c annex1.c annex2.c annex3.c annex4.c annex5.c annex6.c screen_c.c screen_s.c screen_u.c screen_x.c screen_p.c screen_percent.c
OBJFILE = $(SOURCES_FILE:.c=.o)
OBJECTS = $(addprefix $(OBJDIR)/,$(OBJFILE))

all:$(NAME)

$(NAME):$(OBJECTS)
	$(MAKE) -C $(LIB_PATH)
	cp $(LIB_PATH)/$(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJECTS)
	ranlib $(NAME)

$(OBJDIR)/%.o: $(SOURCEDIR)/%.c
	mkdir -p ./obj
	$(CC) -c $< -I ./includes -o $@

bonus: re

clean:
	$(RM) -r ./obj
	$(MAKE) fclean -C $(LIB_PATH)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re
