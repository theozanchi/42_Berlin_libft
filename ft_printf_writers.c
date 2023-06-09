/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_writers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:57:16 by tzanchi           #+#    #+#             */
/*   Updated: 2023/05/30 14:52:03 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*putchar_count diplays the character 'c' in the standard output and returns 1*/
size_t	putchar_count(int c)
{
	write(1, &c, 1);
	return (1);
}

/*putstr_count displays the string pointed by 's' in the standard output and
returns the number of characters it displayed*/
size_t	putstr_count(char *s)
{
	size_t	count;

	if (s == NULL)
	{
		write(1, NULL_DISPLAY, ft_strlen(NULL_DISPLAY));
		return (6);
	}
	count = 0;
	while (*s)
	{
		write(1, s++, 1);
		count++;
	}
	return (count);
}

/*putnbr_base_count displays the integer 'nbr' in the base pointed by 'base'
in the standard output and returns the number of characters it displayed*/
size_t	putnbr_base_count(int nbr, char *base)
{
	int		base_length;
	long	long_nbr;
	size_t	count;

	base_length = ft_strlen(base);
	long_nbr = nbr;
	count = 0;
	if (long_nbr < 0)
	{
		count += putchar_count('-');
		long_nbr *= -1;
	}
	if (long_nbr >= base_length)
		count += putnbr_base_count(long_nbr / base_length, base);
	count += putchar_count(base[long_nbr % base_length]);
	return (count);
}

/*putunbr_base_count displays the unsigned integer 'nbr' in the base pointed by
'base' in the standard output and returns the number of characters it
displayed*/
size_t	putunbr_base_count(unsigned int nbr, char *base)
{
	unsigned long long	lnbr;
	unsigned int		base_length;
	size_t				count;

	lnbr = nbr;
	base_length = ft_strlen(base);
	count = 0;
	if (lnbr >= base_length)
		count += putnbr_base_count(lnbr / base_length, base);
	count += putchar_count(base[lnbr % base_length]);
	return (count);
}

/*putptr_base_count displays the address pointed by 'ptr' in the base pointed by
'base' in the standard output and returns the number of characters it
displayed. 'first_loop_flag' indicates whether putptr_base_count is called by the
first loop of the recursion or not*/
size_t	putptr_base_count(void *ptr, char *base, int first_loop_flag)
{
	unsigned long long	nbr;
	size_t				base_length;
	size_t				count;

	nbr = (unsigned long long)ptr;
	base_length = ft_strlen(base);
	count = 0;
	if (ptr == NULL)
	{
		count += putstr_count(NIL_DISPLAY);
		return (count);
	}
	if (first_loop_flag == 1)
		count += putstr_count(POINTER_PREFIX);
	if (nbr >= base_length)
		count += putptr_base_count((void *)(nbr / base_length), base, 0);
	count += putchar_count(base[nbr % base_length]);
	return (count);
}
