/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 19:24:30 by bford             #+#    #+#             */
/*   Updated: 2020/01/07 14:08:54 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_check_exec(struct s_filler *filler)
{
	char	*exec1;
	char	*exec2;

	exec1 = NULL;
	exec2 = NULL;
	if (get_next_line(0, &exec1, 0) != 1 ||
	ft_strncmp(exec1, "$$$ exec p", 10) ||
	(exec1[10] != '1' && exec1[10] != '2') ||
	ft_strncmp(exec1 + 11, " : [", 4) ||
	exec1[ft_strlen(exec1) - 1] != ']' ||
	get_next_line(0, &exec2, 0) != 1 ||
	ft_strncmp(exec2, "$$$ exec p", 10) ||
	(exec2[10] != '1' && exec2[10] != '2') ||
	ft_strncmp(exec2 + 11, " : [", 4) ||
	exec2[ft_strlen(exec2) - 1] != ']' ||
	(ft_strcmp(exec1 + 15, "bford.filler]") &&
	ft_strcmp(exec2 + 15, "bford.filler]")) ||
	!ft_strcmp(exec1 + 15, exec2 + 15) ||
	(exec1[10] == exec2[10]))
		return (ft_strdel(&exec1) + ft_strdel(&exec2));
	filler->play_num = (!ft_strcmp(exec1 + 15, "bford.filler]") ?
		exec1[10] : exec2[10]) - '0';
	return (ft_strdel(&exec1) + ft_strdel(&exec2) + 1);
}
