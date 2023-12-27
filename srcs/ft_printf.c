/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hang <hang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:47:37 by hang              #+#    #+#             */
/*   Updated: 2023/12/27 21:41:11 by hang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	datatype(va_list *args, char input, int *length, int *i)
{
	if (input == 'c')
		printfputchar(va_arg(*args, int), length);
	else if (input == 's')
		printfstring(va_arg(*args, char *), length);
	else if (input == 'p')
		printfpointer(va_arg(*args, uintptr_t), length);
	else if (input == 'x')
		printfhexadecimal(va_arg(*args, unsigned int), length, 'x');
	else if (input == 'X')
		printfhexadecimal(va_arg(*args, unsigned int), length, 'X');
	else if (input == '%')
		printfputchar('%', length);
	else if (input == 'u')
		printfinteger(va_arg(*args, unsigned int), length);
	else if (input == 'd' || input == 'i')
		printfinteger(va_arg(*args, int), length);
	else
		(*i)--;
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		length;
	va_list	args;

	length = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
			datatype(&args, str[++i], &length, &i);
		else
			printfputchar(str[i], &length);
		i++;
	}
	va_end(args);
	return (length);
}
