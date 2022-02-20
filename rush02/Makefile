# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nvan-ges <nvan-ges@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/20 09:43:48 by maykman           #+#    #+#              #
#    Updated: 2022/02/20 12:40:15 by nvan-ges         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COMPILATION
CC			:=	@gcc
CFLAGS		:=	-Wall -Wextra -Werror

# COLORS
RED				:=	\033[38;5;9m
GREEN			:=	\033[38;5;10m
BLUE			:= 	\033[38;5;14m
YELLOW			:=	\033[38;5;226m
RESET			:=	\033[38;5;7m

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
	@echo "${BLUE}Compliation of $<...${RESET}"

$(NAME):	${OBJS}
	${CC} ${CFLAGS} $^ -o $@

all:		${NAME}

clean:
	@rm -f ${OBJS}
	@echo "${YELLOW}Cleaning objects files...${RESET}"

fclean:
	@rm -f ${NAME} ${OBJS}
	@echo "${RED}Full clean...${RESET}"

re:			fclean all

.PHONY:		all clean fclean re