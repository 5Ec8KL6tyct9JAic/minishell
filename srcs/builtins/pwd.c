/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchebbi <nchebbi@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 03:20:38 by larbre            #+#    #+#             */
/*   Updated: 2024/03/11 18:21:11 by nchebbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_pwd(void)
{
	char	*path;
	char	*buffer;

	buffer = getcwd(NULL, 0);
	if (!buffer)
	{
		free(buffer);
		return (NULL);
	}
	path = malloc(ft_strlen(buffer) + 3);
	if (!path)
	{
		free(buffer);
		return (NULL);
	}
	ft_strlcpy(path, buffer, ft_strlen(buffer) + 1);
	ft_strlcat(path, "$ ", ft_strlen(buffer) + 3);
	free(buffer);
	return (path);
}
