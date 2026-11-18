/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 00:00:00 by student           #+#    #+#             */
/*   Updated: 2026/11/18 00:00:00 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>

int	emit_nbr_base(unsigned long long number, const char *digits)
{
	unsigned long long	base;
	int					written;
	int					last;

	base = 0;
	while (digits[base])
		base++;
	if (base < 2)
		return (-1);
	written = 0;
	if (number >= base)
	{
		written = emit_nbr_base(number / base, digits);
		if (written < 0)
			return (-1);
	}
	last = emit_char(digits[number % base]);
	if (last < 0)
		return (-1);
	return (written + last);
}

int	emit_signed(int number)
{
	long long	n;
	int			sign_written;
	int			digits_written;

	n = number;
	sign_written = 0;
	if (n < 0)
	{
		sign_written = emit_char('-');
		if (sign_written < 0)
			return (-1);
		n = -n;
	}
	digits_written = emit_nbr_base((unsigned long long)n, "0123456789");
	if (digits_written < 0)
		return (-1);
	return (sign_written + digits_written);
}

int	emit_pointer(void *pointer)
{
	int	written;
	int	digits_written;

	if (!pointer)
		return (emit_string("(nil)"));
	written = emit_string("0x");
	if (written < 0)
		return (-1);
	digits_written = emit_nbr_base((uintptr_t)pointer,
			"0123456789abcdef");
	if (digits_written < 0)
		return (-1);
	return (written + digits_written);
}
