#include <libc.h>

int	ft_printf(const char *str, ...)
{
	i = 0;
	result_length = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			result_length += ft_format(&args, str[i + 1]);
			i++;
		}
		else
			result_length += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (result_length);
}


int	sort_format(const char format, va_list *data)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_putchar(va_arg(*data, int));
	if (format == 's')
		len += ft_putstr(va_arg(*data, char *));
	if (format == 'p')
		len += ft_putptr(va_arg(*data, uintptr_t));
	if (format == 'd')
		len += ft_putnbr(va_arg(*data, int));
	if (format == 'i')
		len += ft_putnbr(va_arg(*data, int));
	if (format == 'u')
		len += ft_putunbr(va_arg(*data, unsigned int));
	if (format == 'x')
		len += ft_lower_puthex(va_arg(*data, unsigned int));
	if (format == 'X')
		len += ft_upper_puthex(va_arg(*data, unsigned int));
	if (format == 'b')
		len += ft_putbinary(va_arg(*data, unsigned int));
	if (format == '%')
		len += write(STDOUT_FILENO, "%", 1);
	return (len);
}

