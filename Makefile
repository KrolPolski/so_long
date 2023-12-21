NAME	:= so_long
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast 
LIBMLX	:= ./MLX42

HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS    := $(LIBMLX)/build/libmlx42.a -ldl -pthread -lm -L/Users/rboudwin/.brew/Cellar/glfw/3.3.8/lib -lglfw 
		
SRCS	:= main.c \
		   map_validator.c \
		   adv_validator.c \
		   tools.c \
		   draw_map.c

OBJS	:= ${SRCS:.c=.o} Libft/libft.a

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

Libft/libft.a: 
	$(MAKE) -C libft/ all
	$(MAKE) -C libft/ bonus

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build
	rm -f libft/.bonus;

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx
