/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 21:27:54 by bford             #+#    #+#             */
/*   Updated: 2020/01/07 17:49:23 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_array_size(void **array)
{
	int		i;

	if (!array)
		return (0);
	i = 0;
	while (array[i])
		i++;
	return (i);
}