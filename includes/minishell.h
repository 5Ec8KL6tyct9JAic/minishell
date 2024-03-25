/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchebbi <nchebbi@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 21:35:41 by nchebbi           #+#    #+#             */
/*   Updated: 2024/03/25 22:51:42 by nchebbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "Libft/includes/libft.h"
# include "parser.h"

# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/ioctl.h>
# include <sys/termios.h>
# include <unistd.h>
/* CONSTANTS */

# define SUCCESS 0
# define FAILURE -1
# define OPERATORS "|<>"
# define QUOTES "\"\'"
# define DELIMS "\"\' "
# define REDIRECTS "><"

/* ERROR MESSAGES */

// MINISHELL

# define CL_ARGUMENTS_ERR "minishell: no support for command-line arguments.\n"
# define NO_PIPE_PROMPT "minishell: no support for pipe prompt.\n"
# define NO_SYTX_PROMPT "minishell: no support for syntax prompt.\n"
# define PIPE_ERR "minishell: pipe() failed.\n"
# define FORK_ERR "minishell: fork() failed.\n"

// SYNTAX

# define UNCLOSED_QUOTES "minishell: unclosed quotes.\n"
# define UNEXPECTED_TOKEN "minishell: syntax error near unexpected token.\n"
# define SYTX_ERR_RDR "minishell: syntax error near unexpected token `newline.\n"

// EXIT CMD

# define EXIT_TOO_MANY_ARGS "minishell: exit: too many arguments\n"
# define EXIT_NON_NUMERIC_ARG "minishell: exit: numeric argument required\n" 

// CD CMD

# define PATH_MAX	4096
# define CD_TOO_MANY_ARGS "minishell: cd: too many arguments.\n"
# define OLDPWD_NOT_SET "minishell: cd: OLDPWD not set.\n"

typedef enum e_operator {
	NONE,
	RDR_OUT_REPLACE,
	RDR_OUT_APPEND,
	RDR_INPUT,
	RDR_INPUT_UNTIL,
	PIPE,
}t_operator;
//structure pour la liste chainee des commandes.
struct s_cmd
{
	char *cmd;
	struct s_cmd *next;
	struct s_cmd *prev;
}	t_cmd;

typedef struct s_parser {
	char		*input;
	char		*token;
	t_operator	operator;
}t_parser;

/* if func == t_statemnent -> p_ we're talking about the parser */
typedef struct s_statement {
	int					argc;
	char				**argv;
	t_operator			operator;
	struct s_statement	*next;
}t_statement;

/* if func == t_vars -> v_  we're talking about variables */
typedef struct s_vlst {
	char			*var_name;
	char			*var_value;
	bool			is_exported;
	struct s_vlst	*next;
	struct s_vlst	*prev;
}t_vlst;

/* data keeps a pointer to the head node in
 case of a need to call panic() (fork or pipe error) */

typedef struct s_data {
	char		**envp;
	t_vlst		*envp_lst;
	t_statement	*head;
}t_data;

void				child_signals(int signum);
void				dismiss_signal(int signum);

// Commands
char				*get_pwd(void);

// Utils

bool				is_all_digits_or_signals(char *str);

// Linked lists 
# endif