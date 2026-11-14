#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	pf_putchar(char c);
int	pf_putstr(char *s);
int	pf_putbase(unsigned long n, char *digits, unsigned int base);
int	pf_putnbr(long n);
int	pf_puthex(unsigned int n, char format);
int	pf_pointer(void *ptr);

#endif
