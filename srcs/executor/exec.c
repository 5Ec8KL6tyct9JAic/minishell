/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalerio <dvalerio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:42:51 by dvalerio          #+#    #+#             */
/*   Updated: 2023/12/21 14:36:35 by dvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	small_cmd_exec(t_lexer *lexer, t_parser *parser)
{
	int		i;
	char	**cmd;

	i = 0;
	cmd = ft_strsplit(lexer->word, ' ');
	while (parser->envpath[i])
	{
		parser->fullpath = ft_strjoin(parser->envpath[i], cmd[0]);
		if (access(parser->fullpath, F_OK) == 0)
		{
			parser->pid = fork();
			if (parser->pid == 0)
			{
				execve(parser->fullpath, cmd, NULL);
				exit(0);
			}
			else
				wait(NULL);
			break ;
		}
		i++;
	}
	free_array(cmd);
}

void	exec(t_lexer *lexer, t_parser *parser)
{
	
}