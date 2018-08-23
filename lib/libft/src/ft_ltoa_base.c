/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 15:16:17 by jfleisch          #+#    #+#             */
/*   Updated: 2018/02/21 15:16:32 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int		get_len(long long n, int base)
{
	int	i;

	i = 0;
	if (n < 0)
		i = 3;
	else
		i = 2;
	while ((n = n / base))
		i++;
	i--;
	return (i);
}

static char		*get_str(long long n, int base)
{
	int		k;
	char	*str;
	char	checkbase[16];
	int		check;

	check = 1;
	ft_strcpy(checkbase, "0123456789abcdef");
	k = get_len(n, base);
	str = (char*)malloc(200);
	if (n < 0)
		check = -1;
	str[k--] = '\0';
	while (n)
	{
		str[k--] = checkbase[check * (n % base)];
		n = n / base;
	}
	if (check == -1)
		str[k--] = '-';
	free(str);
	return (str);
}

char			*ft_ltoa_base(long long n, int base)
{
	char	*str;

	if (n == 0)
		return ("0");
	str = get_str(n, base);
	return (str);
}
