#include "../headers/printer_utils.h"

char    *ft_strdup(const char *s1)
{
	char    *s2;
	int     size;

	size = ft_strlen(s1) + 1;
	s2 = (char *)malloc(size);
	if (!s2)
		return (0);
	ft_memcpy(s2, s1, size);
	return (s2);
}

size_t  ft_strlen(const char *s)
{
	size_t  i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void    *ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char       *d;
	const unsigned char *s;
	size_t              i;

	d = dst;
	s = src;
	if (d != s)
	{
		i = 0;
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (d);
}
