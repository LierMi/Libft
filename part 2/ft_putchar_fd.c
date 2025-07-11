/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liemi <liemi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:52:53 by liemi             #+#    #+#             */
/*   Updated: 2025/07/11 15:59:50 by liemi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	cft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// #include "libft.h"

// int	main(void)
// {
// 	ft_putchar_fd('4', 1);
// 	ft_putchar_fd('2', 1);
// 	ft_putchar_fd('\n', 1);
// 	return (0);
// }