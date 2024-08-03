/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosoyan <mmosoyan@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:00:13 by mmosoyan          #+#    #+#             */
/*   Updated: 2024/03/20 21:45:35 by mmosoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *str, ...)
{
	va_list	list;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(list, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += ft_checktype(str, list, i);
			i += 2;
		}
		else
		{
			write(1, &str[i++], 1);
			count++;
		}
	}
	va_end(list);
	return (count);
}

int	ft_checktype(char const *str, va_list list, int i)
{
	int	count;

	count = 0;
	if (str[i + 1] == 'd' || str[i + 1] == 'i')
		count += ft_putnbr_base(va_arg(list, int), "0123456789");
	else if (str[i + 1] == 'u')
		count += ft_putnbr_base(va_arg(list, unsigned int), "0123456789");
	else if (str[i + 1] == 'x')
		count += ft_putnbr_base(va_arg(list, unsigned int), "0123456789abcdef");
	else if (str[i + 1] == 'X')
		count += ft_putnbr_base(va_arg(list, unsigned int), "0123456789ABCDEF");
	else if (str[i + 1] == 'c')
		count += ft_putchar(va_arg(list, int));
	else if (str[i + 1] == 's')
		count += ft_putstr(va_arg(list, char *));
	else if (str[i + 1] == '%')
		count += ft_putchar('%');
	else if (str[i + 1] == 'p')
	{
		count += write(1, "0x", 2);
		count += ft_putptr(va_arg(list, unsigned long), "0123456789abcdef");
	}
	return (count);
}
