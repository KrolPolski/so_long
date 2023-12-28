NAME	:= so_long
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast 
LIBMLX	:= ./MLX42

HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS    := $(LIBMLX)/build/libmlx42.a -ldl -pthread -lm -L/opt/homebrew/Cellar/glfw/3.3.9/lib -lglfw 
		
SRCS	:= main.c \
		   map_validator.c \
		   adv_validator.c \
		   tools.c \
		   draw_map.c \
		   hook_mgmt.c \
		   movement.c \
		   path_validator.c

OBJS	:= ${SRCS:.c=.o} Libft/libft.a

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

Libft/libft.a: 
	$(MAKE) -C Libft/ all
	$(MAKE) -C Libft/ bonus

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build
	rm -f Libft/.bonus;

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx
