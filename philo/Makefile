# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/03 21:45:13 by ebresser          #+#    #+#              #
#    Updated: 2022/07/03 23:06:34 by ebresser         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc #?
 
FLAGS = -Wall -Wextra -Werror -g -fsanitize=address -pthread

RM = /bin/rm -f

HEADERS = -I ./include

DIR_SRC = src
DIR_OBJ = obj

SRCS = $(DIR_SRC)/main.c

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
