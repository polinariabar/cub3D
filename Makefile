# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leweathe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/27 15:19:20 by leweathe          #+#    #+#              #
#    Updated: 2020/06/30 13:48:59 by leweathe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
SRCS = main.c srcs/error_massege.c srcs/ft_one_of_them.c srcs/init_structures.c \
	   srcs/ft_create_rgb.c srcs/ft_realloc_mass.c srcs/read_config.c srcs/ft_free_array.c \
	   srcs/ft_straight_len.c srcs/read_map.c srcs/ft_mass_len.c srcs/get_next_line.c \
	   srcs/set_config.c draw_srcs/casting_rays.c draw_srcs/exit_game.c draw_srcs/main_graphic.c \
	   draw_srcs/screeshot.c draw_srcs/correction.c	draw_srcs/init_struct.c draw_srcs/movements.c \
	   draw_srcs/sort_sprites.c draw_srcs/draw.c draw_srcs/key_events.c draw_srcs/print_figures.c \
	   draw_srcs/sprites.c draw_srcs/free_structs.c
OBJS = $(SRCS:.c=.o)
INCLUDES = includes/cub.h
FLAGS = -Wall -Wextra -Werror
FRAMEWORKS = -framework OpenGL -framework AppKit

all:		$(NAME)

$(NAME):	$(OBJS) $(INCLUDES)
			$(MAKE) -C libft
			$(MAKE) -C minilibx
			gcc $(FLAGS) -o $(NAME) $(OBJS) -I includes/*.h -L libft -lft -L minilibx -lmlx $(FRAMEWORKS)

start: all
			./cub3D information.cub

clean:
			$(MAKE) clean -C libft
			rm -rf $(OBJS)

fclean: clean
			rm -rf $(NAME)
			$(MAKE) fclean -C libft
			$(MAKE) clean -C minilibx
			rm -rf screenshot.bmp

re: fclean all

%.o: %.c
			gcc $(FLAGS) -I. -c $< -o $(<:.c=.o)
