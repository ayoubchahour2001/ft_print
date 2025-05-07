/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahour <achahour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:57:31 by achahour          #+#    #+#             */
/*   Updated: 2025/02/15 12:57:34 by achahour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_select_format(va_list argument, const char word);

int	ft_print_character(int character)
{
	write(1, &character, 1);
	return (1);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		size;
	va_list	argument;

	i = 0;
	size = 0;
	va_start(argument, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			size += ft_select_format(argument, str[i + 1]);
			i++;
		}
		else
			size += ft_print_character(str[i]);
		i++;
	}
	va_end(argument);
	return (size);
}

static int	ft_select_format(va_list argument, const char word)
{
	int	size;

	size = 0;
	if (word == 'c')
		size += ft_print_character(va_arg(argument, int));
	else if (word == 's')
		size += ft_print_string(va_arg(argument, char *));
	else if (word == 'p')
		size += ft_print_pointer(va_arg(argument, unsigned long long));
	else if (word == 'd' || word == 'i')
		size += ft_print_number(va_arg(argument, int));
	else if (word == 'u')
		size += ft_print_unsigned(va_arg(argument, unsigned int));
	else if (word == 'x' || word == 'X')
		size += ft_print_hexadecimal(va_arg(argument, unsigned int), word);
	else
		size += ft_print_character(word);
	return (size);
}
/*#include <stdio.h>  // For the real printf
#include "ft_printf.h"

int main(void)
{
    int ft_count;
    int std_count;

    // Test characters
    ft_count = ft_printf("printf - Character: %c %c %c\n", 'A','d','h');
    std_count = printf("printf - Character: %c\n", 'A');
    printf("ft_printf chars: %d, printf chars: %d\n\n", ft_count, std_count);

    // Test strings
    ft_count = ft_printf("printf - String: %s\n", "Hello, World!");
    std_count = printf("printf - String: %s\n", "Hello, World!");
    printf("ft_printf chars: %d, printf chars: %d\n\n", ft_count, std_count);

    // Test pointers
    int num = 42;
    ft_count = ft_printf("printf - Pointer: %p\n", &num);
    std_count = printf("printf - Pointer: %p\n", &num);
    printf("ft_printf chars: %d, printf chars: %d\n\n", ft_count, std_count);

    // Test integers
    ft_count = ft_printf("printf - Integer: %d\n", 12345);
    std_count = printf("printf - Integer: %d\n", 12345);
    printf("ft_printf chars: %d, printf chars: %d\n\n", ft_count, std_count);

    // Test unsigned integers
    ft_count = ft_printf("printf - Unsigned Integer: %u\n", 12345);
    std_count = printf("printf - Unsigned Integer: %u\n", 12345);
    printf("ft_printf chars: %d, printf chars: %d\n\n", ft_count, std_count);

    // Test hexadecimal (lowercase)
    ft_count = ft_printf("printf - Hexadecimal (lowercase): %x\n", 255);
    std_count = printf("printf - Hexadecimal (lowercase): %x\n", 255);
    printf("ft_printf chars: %d, printf chars: %d\n\n", ft_count, std_count);

    // Test hexadecimal (uppercase)
    ft_count = ft_printf("printf - Hexadecimal (uppercase): %X\n", 255);
    std_count = printf("printf - Hexadecimal (uppercase): %X\n", 255);
    printf("ft_printf chars: %d, printf chars: %d\n\n", ft_count, std_count);

    // Test percent sign
    ft_count = ft_printf("printf - Percent sign: %%\n");
    std_count = printf("printf - Percent sign: %%\n");
    printf("ft_printf chars: %d, printf chars: %d\n\n", ft_count, std_count);

    return 0;
}*/