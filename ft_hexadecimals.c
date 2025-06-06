/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahour <achahour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:57:20 by achahour          #+#    #+#             */
/*   Updated: 2025/02/15 12:57:24 by achahour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_length_hexadecimal(unsigned int num);

static void	ft_search_hexadecimal(unsigned int num, const char word);

int	ft_print_hexadecimal(unsigned int num, const char word)
{
	if (num == 0)
		return (ft_print_character('0'));
	else
		ft_search_hexadecimal(num, word);
	return (ft_length_hexadecimal(num));
}

static void	ft_search_hexadecimal(unsigned int num, const char word)
{
	if (num >= 16)
	{
		ft_search_hexadecimal(num / 16, word);
		ft_search_hexadecimal(num % 16, word);
	}
	else
	{
		if (num < 10)
			ft_print_character(num + '0');
		else
		{
			if (word == 'x')
				ft_print_character(num - 10 + 'a');
			if (word == 'X')
				ft_print_character(num - 10 + 'A');
		}
	}
}

static int	ft_length_hexadecimal(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}
