// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   pwd.c                                              :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: larbre <larbre@student.42.fr>              +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/02/01 03:20:38 by larbre            #+#    #+#             */
// /*   Updated: 2024/02/01 03:23:10 by larbre           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "minishell.h"

char     *get_pwd(void)
{
    char    *path;
    char    *buffer;
    
    buffer = getcwd(NULL, 0);
    if(!buffer){
        free(buffer);
        return (NULL);
    }
    path = malloc(ft_strlen(buffer) + 3);
    if (!path){
        free(buffer);
        return (NULL);
        }
    ft_strlcpy(path, buffer, ft_strlen(buffer) + 1);
    ft_strlcat(path, "$ ", ft_strlen(buffer) + 3);
    free(buffer);
    return(path);
}
