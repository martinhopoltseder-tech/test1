/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_chars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 00:00:00 by student           #+#    #+#             */
/*   Updated: 2026/11/18 00:00:00 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	emit_char(char c)
{
	if (write(1, &c, 1) != 1)
		return (-1);
	return (1);
}

int	emit_string(const char *str)
{
	int	written;

	if (!str)
		str = "(null)";
	written = 0;
	while (*str)
	{
		if (emit_char(*str) < 0)
			return (-1);
		str++;
		written++;
	}
	return (written);
}
