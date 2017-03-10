# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/07 13:04:48 by jjacobi           #+#    #+#              #
#    Updated: 2017/03/09 23:02:35 by jjacobi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= jjacobi.filler

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

SRC_FILES   = main.c get_map.c
OBJ			= $(SRC_FILES:.c=.o)

H_DIRS		= -I ./includes -I ./libft/includes
SRC_FOLDER	= ./srcs
LIBFT_PATH	= ./libft

GREEN		= \033[32m
RED			= \033[31m
DEFAULT		= \033[37m

ifeq ($(shell uname),Darwin)
	ECHO	= echo
else
	ECHO	= echo -e
endif

all: $(NAME)

$(NAME): $(OBJ)
	@$(ECHO) "$(DEFAULT)"
	@($(MAKE) -C $(LIBFT_PATH))
	@$(CC) $(FLAGS) -o $@ $^ $(LIBFT_PATH)/libft.a $(H_DIRS)
	@$(ECHO) "$(GREEN)$(NAME)$(DEFAULT) created."

%.o: $(SRC_FOLDER)/%.c
	@$(ECHO) "\r$(GREEN) Compiling $@                      \c\033[K"
	@$(CC) $(FLAGS) -c -o $@ $< $(H_DIRS)
	

clean:
	@rm -rf $(OBJ)
	@($(MAKE) -C $(LIBFT_PATH) $@)

fclean:
	@rm -rf $(NAME) $(OBJ)
	@($(MAKE) -C $(LIBFT_PATH) $@)

re: fclean all

.PHONY: clean fclean re all
