# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amamy <amamy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/28 18:16:49 by amamy             #+#    #+#              #
#    Updated: 2019/10/03 17:14:36 by amamy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
SHELL = /bin/sh
CC = clang
CFLAGS += -g
OBJDIR = obj
SRCDIR = src
PARSDIR = $(SRCDIR)/parsing
ALGDIR = $(SRCDIR)/algo
LIBDIR	= libft
INCLUDES = includes
HEAD	= $(INCLUDES)/lem-in.h

SRCS 	= $(SRCDIR)/main.c				\
		$(SRCDIR)/ft_free.c				\
		$(PARSDIR)/get_input.c			\
		$(PARSDIR)/get_room.c			\
		$(PARSDIR)/check_comment.c		\
		$(PARSDIR)/new_room.c			\
		$(PARSDIR)/get_links.c			\
		$(PARSDIR)/gnl_store.c			\
		$(ALGDIR)/bfs.c					\
		$(ALGDIR)/edmondkarps.c 		\
		$(ALGDIR)/queue_functions.c 	\
		$(ALGDIR)/save_path.c 			\
		$(ALGDIR)/solve.c 				\
		$(ALGDIR)/keep_path.c 			\
		$(ALGDIR)/send_ants.c 			\
		$(ALGDIR)/optimize_ants.c 	

ALLFLAGS = -I$(LIBDIR)/includes -I$(INCLUDES) -o
OBJ = $(subst $(SRCDIR), $(OBJDIR), $(SRCS:.c=.o))
LIB		= $(LIBDIR)/libft.a
RM = rm -rf
PRINT = printf

_GREEN=\e[32m
_YELLOW=\e[33m
_CYAN=\e[36m
_END=\e[0m

all: $(NAME)
	@echo "  _                           _        "
	@echo " | |                         (_)       "
	@echo " | | ___ _ __ ___    ______   _ _ __   "
	@echo " | |/ _ \ '_ \` _ \  |______| | | '_ \ "
	@echo " | |  __/ | | | | |          | | | | | "
	@echo " |_|\___|_| |_| |_|          |_|_| |_| "
	@echo "                                       "
	@echo "                                       "

$(NAME): $(LIB) $(OBJ)
	@$(PRINT) "Compilation OK! "
	@$(CC) $(CFLAGS) $(OBJ) $< -o $@
	@$(PRINT) "[$(_GREEN)✓$(_END)]\n"

$(LIB): | $(OBJDIR)
	@$(PRINT) "Compiling objects :\n"
	@make -C $(LIBDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEAD)
	@$(PRINT) "Lem-in : "
	@$(CC) -c $(CFLAGS) $(ALLFLAGS) $@ $<
	@$(PRINT) "$(_CYAN)$<\n$(_END)"

$(OBJDIR) :
	@mkdir  $@ $@/parsing $@/algo
	
$(OBJ) : | $(OBJDIR)

clean:
	@$(PRINT) "clean... "
	@$(RM) $(OBJDIR)
	@make clean -C $(LIBDIR) --no-print-directory > /dev/null
	@$(PRINT) "[$(_YELLOW)✓$(_END)]\n"

fclean: clean
	@$(PRINT) "fclean... "
	@$(RM) $(NAME)
	@make fclean -C $(LIBDIR) --no-print-directory > /dev/null
	@$(PRINT) "[$(_BLUE)✓$(_END)]\n"

re: fclean all clean

.PHONY: clean fclean all re
.SUFFIXES: .c .o .h
