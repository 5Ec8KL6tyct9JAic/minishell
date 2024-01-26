# # **************************************************************************** #
# #                                                                              #
# #                                                         :::      ::::::::    #
# #    Makefile                                           :+:      :+:    :+:    #
# #                                                     +:+ +:+         +:+      #
# #    By: nchebbi <nchebbi@student.42.fr>              +#+  +:+       +#+         #
# #                                                 +#+#+#+#+#+   +#+            #
# #    Created: 2024/01/23 19:29:39 by nchebbi            #+#    #+#              #
# #    Updated: 2024/01/23 19:29:40 by nchebbi           ###   ########.fr        #
# #                                                                              #
# # **************************************************************************** #

#//////////////////////////////COLORS/////////////////////////////////////#
COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_ORANGE=\033[0;34m
COLOUR_WHITE=\033[0;37m
COLOUR_YELLOW=\033[0;33m
COLOUR_CYAN=\033[0;36m
COLOUR_END=\033[0m
#//////////////////////////////PROJECT////////////////////////////////////#
NAME 			= minishell

#//////////////////////////////DIRECTORIES////////////////////////////////#
SRC_PATH 		= 	srcs

LIB 			= 	includes/Libft

HEADER 			= 	includes

HEADER_LIBFT 	= 	libft/includes
#/////////////////////////////FLAGS///////////////////////////////////////#
RM 				= 	rm -f

CC 				= 	cc

CFLAGS 			= 	-I $(HEADER) -I $(HEADER_LIBFT) -Wall -Wextra -Werror -fsanitize=address 



#/////////////////////////////SRCS////////////////////////////////////////
SRCS = main.c\
		# cofing_signals.c\
		# builtins/echo.c\
		# builtins/cd.c\
		# builtins/pwd.c\
		# builtins/export.c\
		# builtins/unset.c\
		# builtins/env.c\
		# builtins/exit.c\
		# exec/cmd_exec.c\
		# exec/executables.c\
		# exec/pipe.c\
		# exec/redirections.c\
		# parser/bad_syntax.c\
		# parser/parser.c\
		# parser/rm_quotes.c\
		# parser/utils_parser.c\
		# utils.c/linked_list/digit_and_signal_checker.c\
		# utils.c/linked_list/input_valid.c\
		# utils.c/shell_setup.c\

#//////////////////////////OBEJCTS/////////////////////////////////////////#
OBJS 		= $(SRCS:c=o)

OBJS_DIR 	= objs

DIRS		= objs objs/builtins objs/exec objs/parser objs/utils objs/utils/linked_list

_OBJS				= $(addprefix $(OBJS_DIR)/, $(OBJS))
#///////////////////////RULES/////////////////////////////////////////////#
# macOS with Homebrew
ifeq ($(shell uname -s), Darwin)
    READLINE_PATH = $(HOME)/.brew/opt/readline
    CFLAGS += -I $(READLINE_PATH)/include -L $(READLINE_PATH)/lib
endif

all: lib $(NAME)

lib : 
	@echo "$(COLOUR_ORANGE)Compiling libft...$(COLOUR_END)"
	@make -C $(LIB)
	@echo "$(COLOUR_ORANGE)Deplacement du libft.a$(COLOUR_END)\n"
	@cp ./$(LIB)/libft.a libft.a

$(NAME): $(_OBJS)
	@echo "$(COLOUR_CYAN)Compile..."
	@$(CC) $(_OBJS) libft.a $(CFLAGS) -o $@ -L includes/Libft -lreadline 
	@echo "$(COLOUR_GREEN)Minishell ready. $(COLOUR_END)"

$(OBJS_DIR)/%.o: $(SRC_PATH)/%.c
		@mkdir -p $(DIRS)
		@${CC} $(CFLAGS) -c $< -o $@ -g3

clean:
			@$(RM) $(OBS)
			@$(RM) ${_OBJS}
			@make fclean -C $(LIB)
			@echo "$(COLOUR_YELLOW)minishell Cleaned$(COLOUR_END)"

fclean:		clean
			$(RM) *.a
			@echo "$(COLOUR_RED)minishell Fcleaned$(COLOUR_END)"

re:			fclean all

.PHONY: re ignore fclean clean all $(LIBFT) $(NAME) $(PRINTF)
# # ********************************EOF****************************************** #
