# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/03 21:45:13 by ebresser          #+#    #+#              #
#    Updated: 2022/07/09 20:56:19 by ebresser         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc #?

FLAGS = -Wall -Wextra -Werror -g  -pthread #-fsanitize=address

RM = /bin/rm -f

HEADERS = -I ./include

DIR_SRC = src
DIR_OBJ = obj

SRCS =	$(DIR_SRC)/main.c \
		$(DIR_SRC)/actions.c \
		$(DIR_SRC)/check_input.c \
		$(DIR_SRC)/printer.c \
		$(DIR_SRC)/set_simulation.c \
		$(DIR_SRC)/start_simulation.c \
		$(DIR_SRC)/threads_routines.c \
		$(DIR_SRC)/time.c \
		$(DIR_SRC)/utils.c

OBJS = $(subst $(DIR_SRC), $(DIR_OBJ), $(SRCS:.c=.o))

$(DIR_OBJ)/%.o:	$(DIR_SRC)/%.c
	@mkdir -p $(DIR_OBJ)
	@$(CC) $(FLAGS) $(HEADERS) -c $< -o $@
	@echo "Compiled "$<" successfully!"

all:	$(NAME)

$(NAME):	$(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -o $@
	@echo "Created philo executable file successfully!"

clean:
	@$(RM) $(OBJS)
	@$(RM) -r $(DIR_OBJ)
	@echo "Cleanup completed!"

fclean:	clean
	@$(RM) $(NAME)

re: fclean all

.PONY: all clean fclean re
