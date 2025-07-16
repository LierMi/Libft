/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liemi <liemi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 16:45:41 by liemi             #+#    #+#             */
/*   Updated: 2025/07/16 17:22:30 by liemi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	// Part 1 Tests

	// Character tests
	printf("ft_isalpha('A') = %d\n", ft_isalpha('A'));
	printf("ft_isdigit('9') = %d\n", ft_isdigit('9'));
	printf("ft_isalnum('@') = %d\n", ft_isalnum('@'));
	printf("ft_isascii(128) = %d\n", ft_isascii(128));
	printf("ft_isprint(31) = %d\n", ft_isprint(31));
	printf("ft_tolower('D') = %c\n", ft_tolower('D'));
	printf("ft_toupper('z') = %c\n", ft_toupper('z'));

	// String len
	printf("ft_strlen(\"Hello\") = %zu\n", ft_strlen("Hello"));

	// memset & bzero
	char	buf1[10] = "abcdef";
	ft_memset(buf1, '*', 3);
	printf("ft_memset: %s\n", buf1);

	char	buf2[10] = "abcdef";
	ft_bzero(buf2, 3);
	printf("ft_bzero: %s\n", buf2 + 3);

	// memcpy & memmove
	char	src[] = "123456";
	char	dest[10];
	ft_memcpy(dest, src, 6);
	printf("ft_memcpy: %s\n", dest);

	char	overlap[] = "abcdef";
	ft_memmove(overlap + 2, overlap, 4);
	printf("ft_memmove(overlap): %s\n", overlap);

	// strlcpy & strlcat
	char	dst1[20] = "foo";
	ft_strlcpy(dst1, "bar", sizeof(dst1));
	printf("ft_strlcpy: %s\n", dst1);

	char	dst2[20] = "foo";
	ft_strlcat(dst2, "bar", sizeof(dst2));
	printf("ft_strlcat: %s\n", dst2);

	// strchr & strrchr
	printf("ft_strchr(\"abcde\", 'c') = %s\n", ft_strchr("abcde", 'c'));
	printf("ft_strrchr(\"abcabc\", 'b') = %s\n", ft_strrchr("abcabc", 'b'));

	// strncmp
	printf("ft_strcmp(\"abc\", \"abd\", 2) = %d\n", ft_strncmp("abc", "abd", 2));

	// memchr & memcmp
	printf("ft_memchr(\"abc\", 'b', 3) = %s\n", (char *)ft_memchr("abc", 'b', 3));
	peintf("ft_memcmp(\"abc\", \"abc\", 3) = %d\n", ft_memcmp("abc", "abc", 3));

	// strnstr
	printf("ft_strnstr(\"hello world\", \"world\", 11) = %s\n", ft_strnstr("hello world", "world", 11));

	// atoi
	printf("ft_atoi(\" -42\") = %d\n", ft_atoi(" -42"));

	// calloc & strdup
	char	*calloc_test = ft_calloc(5, sizeof(char));
	if (calloc_test)
	{
		ft_strcpy(calloc_test, "Hi");
		printf("ft_calloc result: %s\n", calloc_test);
		free(dup);
	}

	char	*dup = ft_strdup("libft");
	printf("ft_strdup: %s\n", dup);
	free(dup);

	// Part 2 Tests

	// substr
	char	*sub = ft_substr("libft", 1, 3);
	printf("ft_substr: %s\n", sub);
	free(sub);

	// strjoin
	char	*join = ft_strjoin("Hello, ", "world");
	printf("ft_strjoin: %s\n", join);
	free(join);

	//strtrim
	char	*trim = ft_strtrim("..hello..", ".");
	printf("ft_strtrim: %s\n", trim);
	free(trim);

	// split
	char	**split = ft_split("a,b,c", ',');
	if (split)
	{
		for (int i = 0; split[i]; i++)
		{
			printf("ft_split[%d]: %s\n", i, split[i]);
			free(split[i]);
		}
		free(split);
	}

	// itoa
	char	*itoa = ft_itoa(-123);
	printf("ft_itoa: %s\n", itoa);
	free(itoa);

	// strmapi
	char	*mapped = ft_strmapi("abc", [](unsigned int i, char c){ return c + 1; });
	printf("ft_strmapi: %s\n", mapped);
	free(mapped);

	// striteri
	char	str[] = "abc";
	ft_striteri(str, [](unsigned int i, char *c){ *c += 1 });
	printf("ft_striteri: %s\n", str);

	// Output to fd
	ft_putchar_fd('H', 1);
	ft_putstr_fd("eeah", 1);
	ft_putendl_fd(" World!", 1);
	ft_putnbr_fd(12345, 1);
	write(1, "\n", 1);

	return (0);
}

// bonus part
// 工具函数 返回大写字符串副本
void	*to_upper(void *content)
{
	char	*str = (char *)content;
	char	*new = ft_strdup(str);
	int		i;

	if (!new)
		return (NULL);
	i = 0;
	while (new[i])
	{
		new[i] = (char)toupper(new[i]);
		i++;
	}
	return ((void *)new);
}

// 原地转小写
void	to_lower(void *content)
{
	char	*str;
	int		i;

	str = (char *)content;
	i = 0;
	while (str[i])
	{
		str[i] = (char)tolower(str[i]);
		i++;
	}
}

// 打印链表内容
void	print_list(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		printf("[%d] %s\n", i++, (char *)lst->content);
		lst = lst->next;
	}
}

// 释放节点内容
void	del_func(void *content)
{
	free(content);
}

int	main(void)
{
	t_list	*head;
	t_list	*mapped;
	t_list	*last;
	t_list	*tmp;

	// lstnew
	head = ft_lstnew(ft_strdup("Node1"));
	printf("%s\n\n", (char *)head->content);

	// lstadd_front
	tmp = ft_lstnew(ft_strdup("Node0"));
	ft_lstadd_front(&head, tmp);
	print_list(head);
	printf("\n");

	// lstsize
	printf("%d\n\n", ft_lstsize(head));

	// lstlast
	last = ft_lstlast(head);
	printf("%s\n\n", (char *)last->content);

	// lstadd_back
	ft_lstadd_back(&head, ft_lstnew(ft_strdup("Node2")));
	printf("\n");
	print_list(head);
	print("\n");

	// lstdelone
	tmp = ft_lstnew(ft_strdup("Temp"));
	ft_lstdelone(tmp, del_func);

	// lstiter
	ft_lstiter(head, to_lower);
	print_list(head);
	printf("\n");

	// lstmap
	mapped = ft_lstmap(head, to_upper, del_func);
	ptint_list(mapped);
	printf("\n");

	// lstclear
	ft_lstclear(&head, del_func);
	ft_lstclear(&mapped, del_func);
	printf("\n");

	return (0);
}