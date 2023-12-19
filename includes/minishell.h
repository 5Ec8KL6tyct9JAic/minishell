/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalerio <dvalerio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:12:42 by dvalerio          #+#    #+#             */
/*   Updated: 2023/12/19 16:41:28 by dvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../Libft/includes/libft.h"
# include "color.h"
# include <assert.h> // emmet des assert
# include <errno.h> // permet de signaler des erreurs
# include <fcntl.h> // des constantes et des déclarations de func pour le ctrl des fichiers
# include <pwd.h> // fonctions liées à la gestion des informations sur les utilisateurs.
# include <signal.h> // gestion des signaux
# include <stdlib.h> // fonctions standards
# include <stdbool.h> // permet d'utiliser le type bool
# include <stdio.h> // fonctions d'entrée/sortie
# include <string.h> // fonctions de manipulation de chaînes de caractères
# include <sys/types.h> // types de données utilisés dans les appels système
# include <sys/wait.h> // fonctions de gestion des processus
# include <unistd.h> // constantes et types symboliques standard

// ASTREE

// COMMANDS

// EXECUTE

// LEXER
typedef	struct s_lexer
{
	struct s_lexer	*next;
	int				token;
	char			*word;
	int				outfile;
	int				infile;
	int				nword;
}	t_lexer;

// PARSER
typedef	struct s_parser
{
	char			**fullcmd;
	char			*fullpath;
	char			**envpath;
	int				infile;
	int				outfile;
	int				redirect;
	int				pid;
	struct s_parser	*next;
}	t_parser;

// UTILS
void	free_array(char **str);

# endif