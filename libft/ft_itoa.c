/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydunay <ydunay@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 07:11:51 by ydunay            #+#    #+#             */
/*   Updated: 2023/10/14 07:11:53 by ydunay           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_len(int i)
{
	size_t	len;

	len = 1;
	while (i > 9 || i < -9)
	{
		i /= 10;
		len++;
	}
	return (len);
}

static char	*itoa_write(char *dst, int n, int len, int offset)
{
	while (n > 9)
	{
		dst[len + offset - 1] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	dst[len + offset - 1] = n + '0';
	return (dst);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		len;
	int		offset;

	len = int_len(n);
	offset = 0;
	if (n < 0)
		offset = 1;
	result = (char *)malloc((len + offset + 1) * sizeof(char));
	if (!result)
		return (NULL);
	if (n == -2147483648)
	{
		result[1] = '2';
		n = -147483648;
	}
	if (n < 0)
	{
		result[0] = '-';
		n = n * -1;
	}
	result = itoa_write(result, n, len, offset);
	result[len + offset] = '\0';
	return (result);
}
