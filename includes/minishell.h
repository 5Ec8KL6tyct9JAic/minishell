/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalerio <dvalerio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:12:42 by dvalerio          #+#    #+#             */
/*   Updated: 2023/12/21 15:49:14 by dvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include "includes.h"

struct s_command
{
	char	*command;
	char	**arguments;
	int		pipe[2];
	int		tmp_fd;
};

struct s_data
{
	int			len_cmd;
	pid_t		*pid;
	t_lexical	*lexical;
	t_command	command;
	t_malloc	*garbage;
	char		**env;
	int			status;
	int			is_running;
};


# endif