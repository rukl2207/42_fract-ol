/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornhol <scornhol@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 21:59:48 by scornhol          #+#    #+#             */
/*   Updated: 2022/02/17 22:00:45 by scornhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atod(const char *str)
{
	double	res1;
	double	res2;
	char	*c;
	int		len;
	int		sign;

	c = (char *)str;
	while (ft_isspace(c[0]))
		c++;
	sign = 1;
	if (c[0] == '-')
		sign = -1;
	if (c[0] == '-' || c[0] == '+')
		c++;
	res1 = (double)ft_atoi(c);
	while (*c && *c != '.')
		c++;
	if (*c == '.')
		c++;
	res2 = (double)ft_atoi(c);
	len = ft_strlen(c);
	while (len--)
		res2 /= 10;
	return ((res1 + res2) * sign);
}
