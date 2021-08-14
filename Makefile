PX_SRCS =	srcs/error.c srcs/exec.c srcs/ft_struct_sh.c srcs/main.c

PX_HEADER =	include/pipex.h

PX_NAME =	pipex

PX_OBJ = 	${PX_SRCS:.c=.o}

FLAGS =		-Wall -Wextra -Werror

LIB =		lib/libft/libft.a

%.o: %.c
				@gcc -c -g3 -o $@ $?

$(PX_NAME): ${PX_OBJ}
				@echo "[Libft compilation...]"
				@$(MAKE) -C lib/libft
				@gcc -g3 ${FLAGS} ${PX_OBJ} ${LIB} -o ${PX_NAME}
				@echo "[Done !]"

all:	${PX_NAME}

clean:	
				@echo "Cleaning..."
				@rm -f ${PX_NAME} 
				@$(MAKE) clean -C lib/libft
				@echo "Cleaning complete!"

fclean:			clean
				@$(MAKE) fclean -C lib/libft

re:				fclean all


.PHONY :		fclean all re clean