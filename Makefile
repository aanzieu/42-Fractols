# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aanzieu <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/21 08:51:13 by aanzieu           #+#    #+#              #
#    Updated: 2017/03/28 10:23:56 by aanzieu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol

SRCDIR	= srcs
CUDASRC	= cudasrcs
CUDAHDR = cudainclude

CSRC	= $(CUDASRC)/fractol_cuda_mandelbrot.cu \
			$(CUDASRC)/fractol_cuda_julia.cu \

SRC		= $(SRCDIR)/fractol.c \
			$(SRCDIR)/fractol_colors.c \
			$(SRCDIR)/fractol_error.c \
			$(SRCDIR)/fractol_init.c \
			$(SRCDIR)/fractol_draw.c \
			$(SRCDIR)/fractol_mandelbrot.c \
			$(SRCDIR)/fractol_sponger.c \
			$(SRCDIR)/fractol_cube.c \
			$(SRCDIR)/fractol_julia.c \
			$(SRCDIR)/fractol_del.c \
			$(SRCDIR)/fractol_hook.c \
			$(SRCDIR)/fractol_mouse.c \


OBJ		= $(patsubst src/%.c,obj/%.o,$(SRC))
.SILENT:

COBJ		= $(patsubst cudasrcs/%.cu,cudaobj/%.o,$(CSRC))
.SILENT:


LIBFTDIR = srcs/libft/
LIBFT =  $(LIBFTDIR)libft.a
MLXDIR = minilibx_macos/
MLXLIB = $(MLXDIR)libmlx.a

FLGS	= -Wall -Wextra -Werror

CUDA=/Developer/NVIDIA/CUDA-8.0
NVCC=/Developer/NVIDIA/CUDA-8.0/bin/nvcc
NVCC_C= -ccbin /usr/bin/clang -m64
NVCC_FRAMEWORK= -Xlinker -framework,OpenGL -Xlinker -framework,AppKit
NVCC_LIB= -Xlinker -rpath -Xlinker /Developer/NVIDIA/CUDA-8.0/lib
NVCC_ARCH= -Xcompiler -arch -Xcompiler x86_64
NVCC_STD= -Xcompiler -stdlib=libc++
NVCC_VCODE= -gencode arch=compute_20,code=sm_20 -gencode arch=compute_30,code=sm_30
NVCC_FLAGS= -Xcompiler -Werror -Xcompiler -Wall -Xcompiler -Wextra

all: $(NAME)

$(NAME): $(LIBFT) $(MLXLIB) $(OBJ) $(COBJ)
	@nvcc -Wno-deprecated-gpu-targets $(NVCC_C) $(NVCC_ARCH) $(NVCC_STD) $(NVCC_FRAMEWORK) $(NVCC_FLAGS) $(NVCC_LIB) -o $(NAME) $(OBJ) $(LIBFT) $(MLXLIB) $(COBJ)
	printf '\033[32m[✔] %s\n\033[0m' "Create Fractol"


$(LIBFT):
	make -C $(LIBFTDIR)

$(MLXLIB):
	make -C $(MLXDIR)

obj/%.o: srcs/%.c
	mkdir -p srcsobj
	@gcc -L $(LIBFTDIR) -I $(MLXDIR) $(CUDAHDR) -c $< -o $@
	printf '\033[0m[✔] %s\n\033[0m' "$<"

cudaobj/%.o: cudasrcs/%.cu
	mkdir -p cudaobj
	@nvcc -Wno-deprecated-gpu-targets $(NVCC_C) $(NVCC_ARCH) $(NVCC_STD) $(NVCC_VCODE) -I $(CUDA)/include -I ./include -I $(CUDAHDR) -c $< -o $@
	printf '\033[0m[✔] %s\n\033[0m' "$<"

clean:
	/bin/rm -rf obj/
	/bin/rm -rf cudaobj/
	make -C srcs/libft/ clean
	make -C minilibx_macos/ clean
	printf '\033[31m[✔] %s\n\033[0m' "Clean Libft"

fclean: clean
	/bin/rm -f $(NAME)
	make -C srcs/libft/ fclean
	printf '\033[31m[✔] %s\n\033[0m' "Fclean Libft"

re: fclean all

all: $(NAME)
.PHONY: clean fclean re all
