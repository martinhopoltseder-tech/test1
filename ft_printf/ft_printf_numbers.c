#include "ft_printf.h"

int	pf_putbase(unsigned long n, char *digits, unsigned int base)
{
	int	count;
	int	printed;

	count = 0;
	if (n >= base)
	{
		printed = pf_putbase(n / base, digits, base);
		if (printed < 0)
			return (-1);
		count += printed;
	}
	printed = pf_putchar(digits[n % base]);
	if (printed < 0)
		return (-1);
	return (count + printed);
}

int	pf_putnbr(long n)
{
	int	count;
	int	printed;

	count = 0;
	if (n < 0)
	{
		count = pf_putchar('-');
		if (count < 0)
			return (-1);
		n = -n;
	}
	printed = pf_putbase((unsigned long)n, "0123456789", 10);
	if (printed < 0)
		return (-1);
	return (count + printed);
}

int	pf_puthex(unsigned int n, char format)
{
	if (format == 'X')
		return (pf_putbase(n, "0123456789ABCDEF", 16));
	return (pf_putbase(n, "0123456789abcdef", 16));
}
