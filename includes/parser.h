/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchebbi <nchebbi@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:26:53 by nchebbi           #+#    #+#             */
/*   Updated: 2024/03/18 19:56:58 by nchebbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

// 1: i will create a structure that will hold the command and the arguments of the command.
// 2: i will also create a function that will parse the command and the arguments and return the structure with the command and the arguments. 
// 3: i will also create a function that will free the structure.
//Q: est ce que ces bullet point sont correct pour reproduire le fonctionnement de bash mais en C. peut tu mexpliquer ce que tu entends comme difference pour bash entre les arguments et la commande ? 
//a: la commande est le nom de la commande et les arguments sont les arguments de la commande.
//q: donc pour la commande ls -latr

struct s_command
{
	char *filepath
	char *cmd;
	char **args;
};
//filepath = endroit ou se trouve la commande que lon vas devoir executer
//args[0] = commande a executer
//args[1] = argument de la commande.