/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyatsenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 10:46:49 by yyatsenk          #+#    #+#             */
/*   Updated: 2017/11/01 14:13:47 by yyatsenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		string_length(long long int n)
{
	size_t			i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char				*ft_itoa_l_l(long long int n)
{
	size_t			str_len;
	long long int	tmp_n;
	char			*str;

	str_len = string_length(n);
	tmp_n = n;
	if (n < 0)
	{
		if (n < -9223372036854775807)
		{
			str = ft_strnew(str_len);
			str = ft_strcpy(str, "-9223372036854775808");
			return (str);
		}
		tmp_n = -n;
		str_len++;
	}
	if (!(str = ft_strnew(str_len)))
		return (0);
	str[--str_len] = tmp_n % 10 + '0';
	while (tmp_n /= 10)
		str[--str_len] = tmp_n % 10 + '0';
	if (n < 0)
		*(str + 0) = '-';
	return (str);
}
