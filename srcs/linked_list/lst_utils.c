/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchebbi <nchebbi@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 22:27:06 by nchebbi           #+#    #+#             */
/*   Updated: 2024/03/25 22:49:10 by nchebbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//creer une liste chainee

t_cmd	*create_lst(char *str)
{
	t_cmd	*tmp;

	tmp = malloc(sizeof(t_cmd));
	if (!tmp)
		return (NULL);
	tmp->cmd = str;
	tmp->next = NULL;
	tmp->prev = NULL;
return (tmp);
}

//calcul de la taille dune liste chainee

int	len_lst(t_cmd *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

//ajout dun element a la fin de la liste chainee
void lst_add_back(t_cmd **lst, t_cmd *new)
{
	t_cmd	*current;
	t_cmd	*tmp_prev;

	if (!*lst)
		*lst = new;
	else
	{
		tmp_prev = *lst;
		current = *lst;
		while (current->next)
		{
			tmp_prev = current;
			current = current->next;
			new->prev = current;
		}
		current->next = new;
		current->prev = tmp_prev;
		}
}
