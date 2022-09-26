# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nevan-ge <nevan-ge@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/20 09:43:48 by maykman           #+#    #+#              #
#    Updated: 2022/09/25 15:18:33 by nevan-ge         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COMPILATION
CC			:=	@gcc
CFLAGS		:=	-Wall -Wextra -Werror

# VARIABLES
NAME		:= rush-02
INCLUDES	:=	/includes

# FILES
SRCS		:=	main.c \
				read_file.c \
				utils.c
OBJS		:=	$(addprefix srcs/, ${SRCS:.c=.o})

# RULES
%.o:		%.c
	${CC} ${CFLAGS} -c -I.${INCLUDES} $< -o ${<:.c=.o}

$(NAME):	${OBJS}
	${CC} ${CFLAGS} $^ -o $@

all:		${NAME}

clean:
	@rm -f ${OBJS}
	
fclean:
	@rm -f ${NAME} ${OBJS}

re:			fclean all

.PHONY:		all clean fclean re