/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:56:32 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/16 18:45:12 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stddef.h>

static void	ft_swap_chr(char *a, char *b);
static void	ft_strrev(char *str);
static char	*allocate_itoa_memory(int n);
static int	ft_abs(int i);

char	*ft_itoa(int n)
{
	char		*num_str;
	const char	*base_chr = "0123456789";
	const int	base = 10;
	int			sign;
	size_t		index;

	sign = 0;
	num_str = allocate_itoa_memory(n);
	if (num_str == NULL)
		return (NULL);
	if (n < 0)
		sign = -1;
	index = 0;
	if (n == 0)
		num_str[index++] = '0';
	while (n != 0)
	{
		num_str[index++] = base_chr[ft_abs(n % base)];
		n /= base;
	}
	if (sign == -1)
		num_str[index++] = '-';
	num_str[index] = '\0';
	ft_strrev(num_str);
	return (num_str);
}

static void	ft_swap_chr(char *a, char *b)
{
	char	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
	return ;
}

static void	ft_strrev(char *str)
{
	size_t	left;
	size_t	right;

	left = 0;
	right = ft_strlen(str);
	if (right > 0)
		right -= 1;
	while (left < right)
	{
		ft_swap_chr(&str[left], &str[right]);
		left += 1;
		right -= 1;
	}
	return ;
}

static char	*allocate_itoa_memory(int n)
{
	int			digit;
	const int	base = 10;

	digit = 0;
	if (n < 0)
		digit += 1;
	if (n == 0)
		digit = 1;
	while (n != 0)
	{
		n /= base;
		digit += 1;
	}
	return ((char *)malloc(sizeof(char) * (digit + 1)));
}

static int	ft_abs(int i)
{
	if (i < 0)
		return (-1 * i);
	else
		return (i);
}
