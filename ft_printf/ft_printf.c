#include "ft_printf.h"

static int	pf_format(char c, va_list *args)
{
	if (c == 'c')
		return (pf_putchar((char)va_arg(*args, int)));
	if (c == 's')
		return (pf_putstr(va_arg(*args, char *)));
	if (c == 'p')
		return (pf_pointer(va_arg(*args, void *)));
	if (c == 'd' || c == 'i')
		return (pf_putnbr((long)va_arg(*args, int)));
	if (c == 'u')
		return (pf_putbase(va_arg(*args, unsigned int), "0123456789", 10));
	if (c == 'x' || c == 'X')
		return (pf_puthex(va_arg(*args, unsigned int), c));
	if (c == '%')
		return (pf_putchar('%'));
	return (pf_putchar(c));
}

static int	pf_print_one(const char *format, int *i, va_list *args)
{
	if (format[*i] == '%' && format[*i + 1] != '\0')
	{
		(*i)++;
		return (pf_format(format[*i], args));
	}
	return (pf_putchar(format[*i]));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;
	int		printed;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	i = 0;
	count = 0;
	printed = 0;
	while (format[i] != '\0')
	{
		printed = pf_print_one(format, &i, &args);
		if (printed < 0)
			break ;
		count += printed;
		i++;
	}
	va_end(args);
	if (printed < 0)
		return (-1);
	return (count);
}
