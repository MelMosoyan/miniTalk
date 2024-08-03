/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosoyan <mmosoyan@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 17:07:21 by mmosoyan          #+#    #+#             */
/*   Updated: 2024/07/29 20:20:07 by mmosoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"

void	get_the_bits(int bit)
{
	static int	charr = 0;
	static int	count = 0;

	charr += ((bit & 1) << count);
	count++;
	if (count == 7)
	{
		ft_printf("%c", charr);
		if (!charr)
			ft_printf("\n");
		count = 0;
		charr = 0;
	}
}

int	main(void)
{
	ft_printf("the PID of server is : %d\n", getpid());
	while (1)
	{
		signal(SIGUSR1, get_the_bits);
		signal(SIGUSR2, get_the_bits);
		pause();
	}
	return (0);
}
