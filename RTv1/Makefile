# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggroener <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/22 11:13:51 by ggroener          #+#    #+#              #
#    Updated: 2016/09/02 11:03:10 by daviwel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RT

CFLAGS = -Wall -Wextra -Werror -g 

CC = gcc

INCLUDES_PATH = includes/

SRCS_PATH = srcs/

SRCS_NAME1 = main.c \
			 cleanup.c \
			vector_dot.c \
			vector_new.c \
			vector_sub.c \
			vector_add.c \
			vector_cross.c \
			vector_scale.c \
			vector_dist.c \
			vector_rotate.c \
			vector_norm.c \
			vector_dir.c \
			vector_project.c \
			set_render_val.c

SRCS_NAME2 = count_types.c \
			raytrace.c\
			save_to_img.c\
			set_vec_shape.c\
			get_intersections.c\
			light.c\
			shadow.c\
			set_structs.c\
			new_triangle.c\
			solve_quadratic.c \
		   	normals.c \
			make_threads.c\
			color_add.c \
			close_window.c \

SRCS_NAME3 = ft_get_input.c \
			 ft_count_objs.c \
			 ft_fill_material.c \
			 ft_fill_camera.c \
			 ft_fill_light.c \
			 ft_fill_spheres.c \
			 ft_fill_triangle.c \
			 ft_fill_cone.c \
			 ft_fill_cylinder.c \
			 ft_fill_plane.c \
			 ft_input_check.c \
			 ft_fill_object.c \
			 ft_obj_vec_count.c \
			 read_obj.c \

SRCS_NAME4 = vector_unit.c \
			 vector_div.c \
			 vector_mult.c \
			 vector_comp.c \
			 in_epsilon.c \
			 rotate_tri.c \
			 key_hook.c \
			 manipulate_object.c \
			 intersect_object.c \
			 ft_increment_progress.c\
			 intersect_ray_trace.c \
			 intersect_triangle.c \
			 ft_plane_intersection.c

SRCS4 = $(addprefix $(SRCS_PATH), $(SRCS_NAME4))

SRCS3 = $(addprefix $(SRCS_PATH), $(SRCS_NAME3))

SRCS2 = $(addprefix $(SRCS_PATH), $(SRCS_NAME2))

SRCS1 = $(addprefix $(SRCS_PATH), $(SRCS_NAME1))

SRCS = $(SRCS1) $(SRCS2) $(SRCS3) $(SRCS4)

OBJS_PATH = objs/

OBJS_NAME = $(SRCS_NAME1:.c=.o) $(SRCS_NAME2:.c=.o) $(SRCS_NAME3:.c=.o) $(SRCS_NAME4:.c=.o)

OBJS = $(addprefix $(OBJS_PATH), $(OBJS_NAME))

#uncomment these to work on Mac and comment to work on Linux.
LIBRARY = -lmlx -L libft/ -lft -framework OpenGL -framework AppKit

INCLUDES = -I includes/ -I libft/includes

#uncomment these to work on Linux and comment to work on Mac.
#LIBRARY = -L /usr/X11/lib -lmlx -lX11 -lm -lXext -L libft/ -lft
 
#INCLUDES = -I includes/ -I libft/includes -I /usr/X11/include

HEADER = 	$(INCLUDES_PATH)colours.h \
			$(INCLUDES_PATH)light.h \
			$(INCLUDES_PATH)vector.h \
			$(INCLUDES_PATH)rt.h \

all: qme odir $(NAME)

define colourecho
	@tput setaf 14
	@echo $1
	@tput sgr0
endef

define colourecho2
	@tput setaf 2
	@echo $1
	@tput sgr0
endef

$(NAME): $(OBJS)
	@Make -C libft
	@$(call colourecho, " - Making $(NAME)")
	@clear
	@$(CC) $(CFLAGS) -o $(NAME) $^ $(LIBRARY) $(INCLUDES) -I$(INCLUDES_PATH)
	@clear
	@$(call colourecho, "Make Done!")

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@$(call colourecho, " - Compiling $<")
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $< -I$(INCLUDES_PATH)
	@$(call colourecho, "Compiling Done!")

odir:
	@mkdir -p $(OBJS_PATH)

clean:
	@Make clean -C libft
	@$(call colourecho, " - Clearing object files")
	@rm -f $(OBJS)
	@$(call colourecho, "clean done!")

fclean: clean
	@Make fclean -C libft
	@$(call colourecho, "Clearing executable files")
	@rm -f $(NAME)
	@$(call colourecho, "fclean done")

re: fclean all
	@$(call colourecho, "re Done!")

format: norme me

norm:
	@clear
	@$(call colourecho2, "Norminette:")
	@norminette $(SRCS1)
	@norminette $(SRCS2)
	@norminette $(SRCS3)
	@norminette	$(SRCS4)
	@norminette $(HEADER)

qme:
	@rm -Rf author
	@echo ddu-toit > author
	@echo oexall >> author
	@echo daviwel >> author
	@echo ggroener >> author
	
me: qme
	cat -e author

.PHONY: clean fclean re odir
