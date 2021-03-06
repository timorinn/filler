/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_to_space.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 20:35:39 by bford             #+#    #+#             */
/*   Updated: 2020/01/06 20:38:10 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_len_to_space(char *s)
{
	char	*start;

	start = s;
	while (*s && (*s != ' ') && (*s < 9 || *s > 13))
		s++;
	return (s - start);
}
