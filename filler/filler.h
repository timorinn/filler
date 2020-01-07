/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 14:08:31 by bford             #+#    #+#             */
/*   Updated: 2020/01/07 15:47:28 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"
# include <fcntl.h>

# include <stdio.h>

# define FILE_NAME "bford.filler"

struct		s_filler
{
	int		play_num;
	int		plateau_x;
	int		plateau_y;
	int		create_map;
	char	**map;
}			t_filler;


int			ft_check_exec(struct s_filler *filler);

#endif