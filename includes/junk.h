/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   junk.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvalerio <dvalerio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:40:08 by dvalerio          #+#    #+#             */
/*   Updated: 2023/12/21 15:47:55 by dvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JUNK_H
# define JUNK_H

# include "includes.h"

struct s_malloc
{
	void			*content;
	struct s_malloc	*next;
};

#endif