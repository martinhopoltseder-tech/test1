#include "ft_printf.h"

int	pf_putchar(char c)
{
	if (write(1, &c, 1) != 1)
		return (-1);
	return (1);
}

int	pf_putstr(char *s)
{
	int	i;

	if (s == NULL)
		s = "(null)";
	i = 0;
	while (s[i] != '\0')
	{
		if (pf_putchar(s[i]) < 0)
			return (-1);
		i++;
	}
	return (i);
}

int	pf_pointer(void *ptr)
{
	int	count;
	int	printed;

	if (ptr == NULL)
		return (pf_putstr("(nil)"));
	count = pf_putstr("0x");
	if (count < 0)
		return (-1);
	printed = pf_putbase((unsigned long)ptr, "0123456789abcdef", 16);
	if (printed < 0)
		return (-1);
	return (count + printed);
}
