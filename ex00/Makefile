# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/19 15:02:31 by ehosta            #+#    #+#              #
#    Updated: 2025/05/21 10:52:29 by ehosta           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	megaphone

override SOURCE_DIR		:=	src/
override INCLUDE_DIR	:=	include/
INCLUDES				:=
SOURCES					:=	megaphone
override SOURCE			:=	$(addprefix $(SOURCE_DIR), $(addsuffix .cpp, $(SOURCES)))
override INCLUDE		:=	$(addprefix $(INCLUDE_DIR), $(addsuffix .hpp, $(INCLUDES)))

BUILD_DIR		:=	.dist/
override OBJ	:=	$(patsubst $(SOURCE_DIR)%.cpp, $(BUILD_DIR)%.o, $(SOURCE))
override DEPS	:=	$(patsubst %.o, %.d, $(OBJ)))
override DIRS	:=	$(sort $(dir $(NAME) $(OBJ) $(DEPS)))

CPPFLAGS	:=	-Wall -Wextra -Werror -MMD -MP --std=c++98
MAKEFLAGS	:=	--no-print-directory
GCC			:=	c++
RM			:=	rm -r

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ)
	$(GCC) $(CPPFLAGS) $(OBJ) -o $(NAME)

$(BUILD_DIR)%.o: $(SOURCE_DIR)%.cpp Makefile $(INCLUDE) | $(DIRS)
	$(GCC) $(CPPFLAGS) -c -I$(INCLUDE_DIR) $< -o $@

$(DIRS):
	@mkdir -p $@

.PHONY: bonus
bonus: all

.PHONY: clean
clean:
	$(RM) $(BUILD_DIR)

.PHONY: fclean
fclean: clean
	$(RM) $(NAME)

.PHONY: re
re: fclean
	$(MAKE)

.PHONY: run
run:
	@clear
	@$(MAKE) bonus
	@clear
	@./$(NAME)

-include $(DEPS)
