

NAME = push_swap
CHECK = checker

SRCS =  $(wildcard src/*.c )
OBJS 	= ${SRCS:.c=.o}

CHECK_SRCS = $(wildcard src_bonus/*.c )
CHECK_OBJS = ${CHECK_SRCS:.c=.o}

HEADER	= -Iincludes

CC 		= gcc
CFLAGS = -Werror -Wall -Wextra 

.c.o:		%.o : %.c  
					@$(CC) ${CFLAGS} ${HEADER} -c $< -o $(<:.c=.o)

all: 		${NAME}

${NAME}:	${OBJS}
			
					@make re -C ./libft
			 		@$(CC) ${CFLAGS} ${OBJS} -Llibft -lft -o ${NAME}
			
bonus:	${CHECK}

${CHECK}: ${CHECK_OBJS} 
				
					@make re -C ./libft
					@$(CC) ${CFLAGS} ${CHECK_OBJS} -Llibft -lft -o ${CHECK}



clean:
					@make clean -C ./libft
					@rm -f ${OBJS} ${CHECK_OBJS}

fclean: 	clean
					@make fclean -C ./libft
					@rm -f $(NAME)
					@rm -f ${CHECK}

re:			fclean all

re_bonus:	fclean bonus