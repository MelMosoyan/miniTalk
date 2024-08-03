/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosoyan <mmosoyan@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:46:49 by mmosoyan          #+#    #+#             */
/*   Updated: 2024/03/20 21:42:46 by mmosoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_valid(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[i] == '\0')
		return (0);
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (1);
}

int	ft_strlen(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

int	ft_length(long long n, char *base)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(base);
	if (n >= 0 && n <= 9)
		return (1);
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n)
	{
		n /= len;
		i++;
	}
	return (i);
}

int	ft_putnbr_base(long long n, char *base)
{
	int	i;
	int	res;

	i = 0;
	res = ft_length(n, base);
	if (is_valid(base))
	{
		while (base[i])
			i++;
		if (n < 0)
		{
			ft_putchar('-');
			n = -n;
		}
		if (n >= i)
			ft_putnbr_base(n / i, base);
		write(1, &base[n % i], 1);
		return (res);
	}
	return (0);
}
