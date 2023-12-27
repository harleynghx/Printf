/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hang <hang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:03:21 by hang              #+#    #+#             */
/*   Updated: 2023/12/27 20:38:39 by hang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

void	printfputchar(int c, int *length);
void	printfstring(char *str, int *length);
void	printfpointer(uintptr_t ptr, int *length);
void	printfinteger(long numbers, int *length);
void	printfhexadecimal(unsigned long nb, int *length, char xorX);
int		ft_printf(const char *, ...);

#endif