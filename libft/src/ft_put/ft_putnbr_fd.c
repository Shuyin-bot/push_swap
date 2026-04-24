/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <sqian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 23:44:50 by sqian             #+#    #+#             */
/*   Updated: 2025/11/12 21:12:53 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	long	rv;

	nb = (long)n;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr_fd(nb / 10, fd);
		rv = nb % 10 + '0';
		ft_putchar_fd(rv, fd);
	}
	if (nb < 10)
		ft_putchar_fd(nb + '0', fd);
}

// int	main(void)
// {
// 	ft_putnbr_fd(123, 1);
// }
/*
ft_putchar_fd('\n', fd); //pass an integer
same as
write (fd, "-", 1); //takes a string (expect pointer to mem)

"-" ==> a ptr to mem that contains '-' followed by '\0'
*/
/*
Parameters:
n: The integer to output.
fd: The file descriptor on which to write.

Description:
Outputs the integer ’n’ to the specified file
descriptor.
*/
