/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liemi <liemi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 16:08:19 by liemi             #+#    #+#             */
/*   Updated: 2025/07/08 18:43:41 by liemi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcopy(void *dest, const void *src, size_t n);
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	i = 0;
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;

	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

// int	main(void)
// {
// 	char	src[10] = "ABCDEFG";
// 	char	dest[10];

// 	ft_memcpy(dest, src, 7);
// 	dest[7] = '\0';
// 	printf("%s\n", dest);
// 	return (0);
// }