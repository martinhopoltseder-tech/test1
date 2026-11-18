/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 00:00:00 by student           #+#    #+#             */
/*   Updated: 2026/11/18 00:00:00 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	emit_format_more(char specifier, va_list *args)
{
	if (specifier == 'x')
		return (emit_nbr_base(va_arg(*args, unsigned int),
				"0123456789abcdef"));
	if (specifier == 'X')
		return (emit_nbr_base(va_arg(*args, unsigned int),
				"0123456789ABCDEF"));
	if (specifier == 'p')
		return (emit_pointer(va_arg(*args, void *)));
	if (specifier == '%')
		return (emit_char('%'));
	return (-1);
}

static int	emit_format(char specifier, va_list *args)
{
	if (specifier == 'c')
		return (emit_char((char)va_arg(*args, int)));
	if (specifier == 's')
		return (emit_string(va_arg(*args, char *)));
	if (specifier == 'd' || specifier == 'i')
		return (emit_signed(va_arg(*args, int)));
	if (specifier == 'u')
		return (emit_nbr_base(va_arg(*args, unsigned int),
				"0123456789"));
	return (emit_format_more(specifier, args));
}

static int	emit_one(const char *format, int i, va_list *args)
{
	if (format[i] == '%')
	{
		i++;
		if (format[i] == '\0')
			return (-1);
		return (emit_format(format[i], args));
	}
	return (emit_char(format[i]));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		total;
	int		written;

	if (!format)
		return (-1);
	va_start(args, format);
	i = 0;
	total = 0;
	written = 0;
	while (format[i] != '\0')
	{
		written = emit_one(format, i, &args);
		if (written < 0)
			break ;
		total = total + written;
		if (format[i] == '%')
			i++;
		i++;
	}
	va_end(args);
	if (written < 0)
		return (-1);
	return (total);
}
