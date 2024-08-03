/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosoyan <mmosoyan@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 19:35:59 by mmosoyan          #+#    #+#             */
/*   Updated: 2024/03/20 21:11:02 by mmosoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_plength(unsigned long n, char *base)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(base);
	if (n >= 0 && n <= 9)
		return (1);
	while (n)
	{
		n /= len;
		i++;
	}
	return (i);
}

int	ft_putptr(unsigned long p, char *base)
{
	int	i;
	int	res;

	i = 0;
	res = ft_plength(p, base);
	if (is_valid(base))
	{
		while (base[i])
			i++;
		if (p >= (unsigned long)i)
			ft_putnbr_base(p / i, base);
		write(1, &base[p % i], 1);
		return (res);
	}
	return (0);
}
