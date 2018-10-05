# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/25 15:43:39 by okuzniet          #+#    #+#              #
#    Updated: 2018/09/25 15:43:44 by okuzniet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SWITCH				=	\033[
RESET				=	$(SWITCH)0m
S_BOLD				=	$(SWITCH)1m
C_YELLOW			=	$(SWITCH)33m
C_GREEN				=	$(SWITCH)32m
C_RED				=	$(SWITCH)31m

NAME				=	libftprintf.a
CC					=	gcc
FLAGS				=	-Wall -Werror -Wextra -O3 -c
INCLUDES			=	-I./inc -I./libft/inc
HEADERS_LIST		=	ft_printflib.h ft_printf.h
HEADERS_DIRECTORY	=	inc/
HEADERS				=	$(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))
SOURCES_DIRECTORY	=	src/
SOURCES_LIST		=	calculate_the_base.c\
						configure_length.c\
						ft_colour.c\
						ft_next_spec.c\
						ft_num_to_str.c\
						ft_pr_c.c\
						ft_pr_lst.c\
						ft_pr_n.c\
						ft_pr_no_func.c\
						ft_pr_p.c\
						ft_pr_percent_sign.c\
						ft_pr_s.c\
						ft_pr_signed.c\
						ft_pr_uc.c\
						ft_pr_unsigned.c\
						ft_pr_us.c\
						ft_printf.c\
						ft_read.c\
						ft_unicode_mask_for_str.c\
						get_length.c\
						identify_flag.c\
						identify_prec.c\
						identify_type.c\
						identify_width.c\
						make_false.c\
						set_function.c

SOURCES					=	$(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))
OBJECTS_DIRECTORY		=	obj/
OBJECTS_LIST			=	$(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS					=	$(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

#	libft
LIBFT_DIRECTORY			=	libft/
LIBFT_FILE				=	libft.a
LIBFT					=	$(addprefix $(LIBFT_DIRECTORY), $(LIBFT_FILE))
LIBFT_HEADERS_LIST		=	libft.h
LIBFT_HEADERS_DIRECTORY	=	libft/inc/
LIBFT_HEADERS			=	$(addprefix $(LIBFT_HEADERS_DIRECTORY), $(LIBFT_HEADERS_LIST))
LIBFT_SOURCES_DIRECTORY	=	libft/src/
LIBFT_SOURCES_LIST		=	ft_memset.c \
							ft_bzero.c \
							ft_memcpy.c \
							ft_memccpy.c \
							ft_memmove.c \
							ft_memchr.c \
							ft_memcmp.c \
							ft_strlen.c \
							ft_strdup.c \
							ft_strcpy.c \
							ft_strncpy.c \
							ft_strcat.c \
							ft_strncat.c \
							ft_strlcat.c \
							ft_strchr.c \
							ft_strrchr.c \
							ft_strstr.c \
							ft_strnstr.c \
							ft_strcmp.c \
							ft_strncmp.c \
							ft_atoi.c \
							ft_isalpha.c\
							ft_isdigit.c \
							ft_isalnum.c \
							ft_isascii.c \
							ft_isprint.c \
							ft_toupper.c \
							ft_tolower.c \
							\
							ft_memalloc.c \
							ft_memdel.c \
							ft_strnew.c \
							ft_strdel.c \
							ft_strclr.c \
							ft_striter.c \
							ft_striteri.c \
							ft_strmap.c \
							ft_strmapi.c \
							ft_strequ.c \
							ft_strnequ.c \
							ft_strsub.c \
							ft_strjoin.c \
							ft_strtrim.c \
							ft_strsplit.c \
							ft_itoa.c \
							ft_putchar.c \
							ft_putstr.c \
							ft_putendl.c \
							ft_putnbr.c \
							ft_putchar_fd.c \
							ft_putstr_fd.c \
							ft_putendl_fd.c \
							ft_putnbr_fd.c \
							\
							ft_lstnew.c \
							ft_lstdelone.c \
							ft_lstdel.c \
							ft_lstadd.c \
							ft_lstiter.c \
							ft_lstmap.c \
							\
							ft_strndup.c \
							ft_islower.c \
							ft_isupper.c \
							ft_countwords.c\
							ft_is_blank.c

LIBFT_SOURCES			=	$(addprefix $(LIBFT_SOURCES_DIRECTORY), $(LIBFT_SOURCES_LIST))
LIBFT_OBJECTS_DIRECTORY	=	libft/obj/
LIBFT_OBJECTS_LIST		=	$(patsubst %.c, %.o, $(LIBFT_SOURCES_LIST))
LIBFT_OBJECTS			=	$(addprefix $(LIBFT_OBJECTS_DIRECTORY), $(LIBFT_OBJECTS_LIST))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJECTS_DIRECTORY) $(OBJECTS) $(LIBFT_SOURCES) $(LIBFT_HEADERS)
	@make -C $(LIBFT_DIRECTORY)
	@ar rc $(NAME) $(OBJECTS) $(LIBFT_OBJECTS)
	@ranlib $(NAME)
	@echo "$(NAME) : $(S_BOLD)$(C_GREEN)$(NAME) was created$(RESET)"

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)
	@echo "$(NAME) : $(S_BOLD)$(C_YELLOW)$(OBJECTS_DIRECTORY) was created$(RESET)"

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(FLAGS) $(INCLUDES) $< -o $@
	@echo "$(NAME) : $(S_BOLD)$(C_YELLOW)$@ was created$(RESET)"

clean:
	@rm -rf $(OBJECTS_DIRECTORY)
	@make clean -C $(LIBFT_DIRECTORY)
	@echo "$(NAME) : $(S_BOLD)$(C_RED)$(OBJECTS_DIRECTORY) was deleted$(RESET)"
	@echo "$(NAME) : $(S_BOLD)$(C_RED)object files were deleted$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIRECTORY)
	@echo "$(NAME) : $(S_BOLD)$(C_RED)$(NAME) was deleted$(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE) all
