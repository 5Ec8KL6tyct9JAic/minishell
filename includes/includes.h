/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalerio <dvalerio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:41:10 by dvalerio          #+#    #+#             */
/*   Updated: 2023/12/21 15:50:08 by dvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H
# define NAME "Minishell"

# include <assert.h> // emmet des assert
# include <dirent.h> // fonctions de gestion des répertoires
# include <errno.h> // permet de signaler des erreurs
# include <fcntl.h> // des constantes et des déclarations de func pour le ctrl des fichiers
# include <pwd.h> // fonctions liées à la gestion des informations sur les utilisateurs.
# include <readline/readline.h> // gestion de l'entrée utilisateur
# include <readline/history.h> // gestion de l'historique
# include <signal.h> // gestion des signaux
# include <stdlib.h> // fonctions standards
# include <stdbool.h> // permet d'utiliser le type bool
# include <stdio.h> // fonctions d'entrée/sortie
# include <string.h> // fonctions de manipulation de chaînes de caractères
# include <sys/types.h> // types de données utilisés dans les appels système
# include <sys/wait.h> // fonctions de gestion des processus
# include <termios.h> // fonctions de gestion du terminal
# include <unistd.h> // constantes et types symboliques standard
# include "../Libft/includes/libft.h" // fonctions de la libft
# include "color.h" // couleurs
# include "data.h" // structures de données
# include "utils.h" // fonctions utilitaires
# include "junk.h" // fonctions pour vider la poubelle (malloc, free, etc)
# include "parser.h" // fonctions de parsing
# include "minishell.h" // fonctions de minishell

#endif