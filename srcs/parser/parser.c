/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchebbi <nchebbi@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 19:20:33 by nchebbi           #+#    #+#             */
/*   Updated: 2024/03/20 15:41:13 by nchebbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_cmdnbr(char *input)
{
	int	i;
	int	cmdnbr;

	i = 0;
	cmdnbr = 1;
	while (input[i] != '\0')
	{
		if (input[i] == '|')
			cmdnbr++;
		i++;
	}
	return (cmdnbr);
}

char	**get_token(char *input)
{
	int		i;
	int		j;
	char	**token;

	i = 0;
	j = 0;
	k = 0;
	token = malloc(sizeof(char *) * (get_cmdnbr(input)));
	if (!token)
		return (NULL);
	while (input != '\0')
	{
		if (input[i] == ' ')
		{
			if (i - j > 0)
			{
				token[k] = ft_substr(input, j, i - j);
				k++;
			}
			j = i + 1;
		}
		i++;
	}
}
//func pour l'input du parse

// func parse