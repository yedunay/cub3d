/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdur <eozdur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 09:40:51 by eozdur            #+#    #+#             */
/*   Updated: 2024/02/29 13:22:04 by eozdur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*res;

	res = malloc(count * size);
	if (!res)
		return (0);
	ft_bzero(res, count * size);
	return (res);
}
