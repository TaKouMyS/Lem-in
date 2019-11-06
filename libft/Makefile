# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amamy <amamy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/10 20:19:54 by amamy             #+#    #+#              #
#    Updated: 2019/11/06 10:35:47 by amamy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SHELL = /bin/sh
CC = clang
CFLAGS += -Wall -Werror -Wextra
OBJDIR = obj
FT_IS_DIR = is
FT_LST_DIR = lst
FT_MEM_DIR = mem
FT_MISC_DIR = misc
FT_PUT_DIR = put
FT_STR_DIR = str
INCLUDES = includes
HEAD = $(INCLUDES)/libft.h

SRCS =	$(FT_IS_DIR)/ft_isalnum.c			\
		$(FT_IS_DIR)/ft_isalpha.c			\
		$(FT_IS_DIR)/ft_isascii.c			\
		$(FT_IS_DIR)/ft_isdigit.c			\
		$(FT_IS_DIR)/ft_isprint.c			\
		$(FT_LST_DIR)/ft_lstadd.c			\
		$(FT_LST_DIR)/ft_lstdel.c			\
		$(FT_LST_DIR)/ft_lstdelone.c		\
		$(FT_LST_DIR)/ft_lstendadd.c		\
		$(FT_LST_DIR)/ft_lstiter.c			\
		$(FT_LST_DIR)/ft_lstmap.c			\
		$(FT_LST_DIR)/ft_lstnew.c			\
		$(FT_MEM_DIR)/ft_memalloc.c			\
		$(FT_MEM_DIR)/ft_memccpy.c			\
		$(FT_MEM_DIR)/ft_memchr.c			\
		$(FT_MEM_DIR)/ft_memdel.c			\
		$(FT_MEM_DIR)/ft_memcmp.c			\
		$(FT_MEM_DIR)/ft_memcpy.c			\
		$(FT_MEM_DIR)/ft_memmove.c			\
		$(FT_MEM_DIR)/ft_memset.c 			\
		$(FT_MISC_DIR)/ft_atoi.c			\
		$(FT_MISC_DIR)/ft_atoi_long.c		\
		$(FT_MISC_DIR)/ft_bzero.c			\
		$(FT_MISC_DIR)/ft_disp_ar.c			\
		$(FT_MISC_DIR)/ft_itoa_base.c		\
		$(FT_MISC_DIR)/ft_itoa.c			\
		$(FT_MISC_DIR)/ft_nb_len_base.c		\
		$(FT_MISC_DIR)/ft_nb_words.c		\
		$(FT_MISC_DIR)/ft_no_space.c		\
		$(FT_MISC_DIR)/ft_print_list.c		\
		$(FT_MISC_DIR)/ft_tolower.c			\
		$(FT_MISC_DIR)/ft_toupper.c			\
		$(FT_MISC_DIR)/get_next_line.c		\
		$(FT_PUT_DIR)/ft_putchar_fd.c		\
		$(FT_PUT_DIR)/ft_putchar.c			\
		$(FT_PUT_DIR)/ft_putendl_fd.c		\
		$(FT_PUT_DIR)/ft_putendl.c			\
		$(FT_PUT_DIR)/ft_putnbr_fd.c		\
		$(FT_PUT_DIR)/ft_putnbr.c			\
		$(FT_PUT_DIR)/ft_putstr_fd.c		\
		$(FT_PUT_DIR)/ft_putstr.c			\
		$(FT_STR_DIR)/ft_strcat.c			\
		$(FT_STR_DIR)/ft_strchr.c			\
		$(FT_STR_DIR)/ft_strclr.c			\
		$(FT_STR_DIR)/ft_strcmp.c			\
		$(FT_STR_DIR)/ft_strcpy.c			\
		$(FT_STR_DIR)/ft_strdel.c			\
		$(FT_STR_DIR)/ft_strdup.c			\
		$(FT_STR_DIR)/ft_strequ.c			\
		$(FT_STR_DIR)/ft_striter.c			\
		$(FT_STR_DIR)/ft_striteri.c			\
		$(FT_STR_DIR)/ft_strjoin.c			\
		$(FT_STR_DIR)/ft_strlcat.c			\
		$(FT_STR_DIR)/ft_strlen.c			\
		$(FT_STR_DIR)/ft_strmap.c			\
		$(FT_STR_DIR)/ft_strmapi.c			\
		$(FT_STR_DIR)/ft_strncat.c			\
		$(FT_STR_DIR)/ft_strncmp.c			\
		$(FT_STR_DIR)/ft_strncpy.c			\
		$(FT_STR_DIR)/ft_strndup.c			\
		$(FT_STR_DIR)/ft_strnequ.c			\
		$(FT_STR_DIR)/ft_strnew.c			\
		$(FT_STR_DIR)/ft_strnstr.c			\
		$(FT_STR_DIR)/ft_strrchr.c			\
		$(FT_STR_DIR)/ft_strrealloc.c		\
		$(FT_STR_DIR)/ft_strsplit.c			\
		$(FT_STR_DIR)/ft_strstr.c			\
		$(FT_STR_DIR)/ft_strsub.c			\
		$(FT_STR_DIR)/ft_strtrim.c			\

FT_PRINTF = ft_printf
LIBDIR	= libft
CONVDIR = src/conversions
FLAGDIR = src/flags

FT_PRINTF_SRCS =	$(FT_PRINTF)/$(LIBDIR)/ft_atoi.c				\
					$(FT_PRINTF)/$(LIBDIR)/ft_bzero.c				\
					$(FT_PRINTF)/$(LIBDIR)/ft_intlen.c				\
					$(FT_PRINTF)/$(LIBDIR)/ft_itoa_base_p.c			\
					$(FT_PRINTF)/$(LIBDIR)/ft_itoa_bmul.c			\
					$(FT_PRINTF)/$(LIBDIR)/ft_itoa_l.c				\
					$(FT_PRINTF)/$(LIBDIR)/ft_memalloc.c			\
					$(FT_PRINTF)/$(LIBDIR)/ft_memset.c				\
					$(FT_PRINTF)/$(LIBDIR)/ft_nb_len_base.c			\
					$(FT_PRINTF)/$(LIBDIR)/ft_putchar.c				\
					$(FT_PRINTF)/$(LIBDIR)/ft_putstrn.c				\
					$(FT_PRINTF)/$(LIBDIR)/ft_strcat.c				\
					$(FT_PRINTF)/$(LIBDIR)/ft_strchr.c				\
					$(FT_PRINTF)/$(LIBDIR)/ft_strcmp.c				\
					$(FT_PRINTF)/$(LIBDIR)/ft_strcpy.c				\
					$(FT_PRINTF)/$(LIBDIR)/ft_strdup.c				\
					$(FT_PRINTF)/$(LIBDIR)/ft_strjoin.c				\
					$(FT_PRINTF)/$(LIBDIR)/ft_strlen.c				\
					$(FT_PRINTF)/$(LIBDIR)/ft_strncpy.c				\
					$(FT_PRINTF)/$(LIBDIR)/ft_strndup.c				\
					$(FT_PRINTF)/$(LIBDIR)/ft_strnew.c				\
					$(FT_PRINTF)/$(LIBDIR)/ft_strsub.c				\
					$(FT_PRINTF)/$(LIBDIR)/ft_tolower.c				\
					$(FT_PRINTF)/$(CONVDIR)/ft_c.c					\
					$(FT_PRINTF)/$(CONVDIR)/ft_d_i.c				\
					$(FT_PRINTF)/$(CONVDIR)/ft_f.c					\
					$(FT_PRINTF)/$(CONVDIR)/ft_f2.c					\
					$(FT_PRINTF)/$(CONVDIR)/ft_o.c					\
					$(FT_PRINTF)/$(CONVDIR)/ft_p.c					\
					$(FT_PRINTF)/$(CONVDIR)/ft_s_mode0.c			\
					$(FT_PRINTF)/$(CONVDIR)/ft_s_mode1.c			\
					$(FT_PRINTF)/$(CONVDIR)/ft_u.c					\
					$(FT_PRINTF)/$(CONVDIR)/ft_xx.c					\
					$(FT_PRINTF)/$(FLAGDIR)/ft_accuracy.c			\
					$(FT_PRINTF)/$(FLAGDIR)/ft_f_width_accuracy.c	\
					$(FT_PRINTF)/$(FLAGDIR)/ft_fwp_minus.c 			\
					$(FT_PRINTF)/$(FLAGDIR)/ft_fwp_string.c			\
					$(FT_PRINTF)/$(FLAGDIR)/ft_fwp.c				\
					$(FT_PRINTF)/$(FLAGDIR)/ft_fwp_not_ap_neg.c		\
					$(FT_PRINTF)/$(FLAGDIR)/ft_fwp_cases.c			\
					$(FT_PRINTF)/$(FLAGDIR)/ft_hhh_lll.c			\
					$(FT_PRINTF)/$(FLAGDIR)/ft_plus_minus.c			\
					$(FT_PRINTF)/$(FLAGDIR)/ft_sharp.c				\
					$(FT_PRINTF)/$(FLAGDIR)/ft_width_string.c		\
					$(FT_PRINTF)/$(FLAGDIR)/ft_width_minus.c		\
					$(FT_PRINTF)/$(FLAGDIR)/ft_width.c				\
					$(FT_PRINTF)/src/ft_printf.c						\
					$(FT_PRINTF)/src/ft_analyse_format.c				\
					$(FT_PRINTF)/src/ft_flags.c							\
					$(FT_PRINTF)/src/ft_which_flag.c					\
					$(FT_PRINTF)/src/ft_only_conv.c						\
					$(FT_PRINTF)/src/ft_active_flags.c					\
					$(FT_PRINTF)/src/ft_flags2.c						\
					$(FT_PRINTF)/src/ft_disable_flag.c					\
					$(FT_PRINTF)/src/ft_forbidden_conv.c


ALLFLAGS = -I$(INCLUDES) -o
OBJ = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
PRINTF_OBJ = $(addprefix $(OBJDIR)/, $(FT_PRINTF_SRCS:.c=.o))
RM = rm -rf
PRINT = printf

_GREEN=\e[32m
_YELLOW=\e[33m
_CYAN=\e[36m
_END=\e[0m

all: $(NAME)

$(NAME): $(OBJ) $(PRINTF_OBJ)
	@$(PRINT) "\nCreating library... :"
	@ar rcs $@ $^
	@printf "[$(_GREEN)✓$(_END)]\n\n"

$(OBJDIR)/%.o: %.c $(HEAD)
	@$(PRINT) "Libft : "
	@$(CC) -c $(CFLAGS) $(ALLFLAGS) $@ $<
	@$(PRINT) "$(_YELLOW)$<\n$(_END)"
	
$(OBJDIR) :
	@mkdir  $@ $@/$(FT_IS_DIR) $@/$(FT_LST_DIR) $@/$(FT_MEM_DIR) \
			$@/$(FT_MISC_DIR) $@/$(FT_PUT_DIR) $@/$(FT_STR_DIR) $@/$(FT_PRINTF)\
			$@/$(FT_PRINTF)/src $@/$(FT_PRINTF)/$(LIBDIR) \
			$@/$(FT_PRINTF)/$(CONVDIR) $@/$(FT_PRINTF)/$(FLAGDIR)

$(OBJ) : | $(OBJDIR)

clean:
	@$(PRINT) "clean... "
	@$(RM) $(OBJDIR)
	@make clean -C $(FT_PRINTF) --no-print-directory > /dev/null
	@$(PRINT) "[$(_YELLOW)✓$(_END)]\n"

fclean: clean
	@$(PRINT) "fclean... "
	@$(RM) $(NAME)
	@make fclean -C $(FT_PRINTF) --no-print-directory > /dev/null
	@$(PRINT) "[$(_BLUE)✓$(_END)]\n"

re: fclean all

.PHONY: all clean fclean re
.SUFFIXES: .c .o .h
