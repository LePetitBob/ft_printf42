#include "INCLUDES/ft_printf.h"

int main()
{
	int a = 0;
	int b = 0;
	int c = 42;
	a += ft_printf("%c%c%c | %s%s %s | %p %p | ", 'y', 0, 'o', "les cas particuliers c'est", "", NULL, (void *)0, &c);
	a += ft_printf("%d %-d |%012d| |%12.12d| |%-.4d| |%-12d|\n", c, c, c, c, c, INT_MIN);
	a += ft_printf("%u %u | %x %X\n", -100, 100, 123456789, 123456789);
	printf("\n\n");
	b += printf(   "%c%c%c | %s%s %s | %p %p | ", 'y', 0, 'o', "les cas particuliers c'est", "", NULL, (void *)0, &c);
	b += printf(   "%d %-d |%012d| |%12.12d| |%-.4d| |%-12d|\n", c, c, c, c, c, INT_MIN);
	b += printf(   "%u %u | %x %X\n", -100, 100, 123456789, 123456789);
	printf("\nret ft_printf : %d\nret printf    : %d\n\n", a, b);
	a += ft_printf("\n|%%%10s|\n|%7.2s|\n|%.4s|\n|%.12s|\n", "bob", NULL, NULL, "coucou");
	b += printf(   "\n|%%%10s|\n|%7.2s|\n|%.4s|\n|%.12s|\n", "bob", NULL, NULL, "coucou");
	printf("\nret ft_printf : %d\nret printf    : %d\n\n", a, b);
	return 0;
}
