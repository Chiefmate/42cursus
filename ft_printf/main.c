#include <stdio.h>
#include <stdarg.h>
#include <string.h>

void	printValues(char *types, ...)
{
	va_list	ap;
	int		i = 0;

	va_start(ap, types);
	while (types[i] != '\0')
	{
		switch (types[i])
		{
			case 'i':
				printf("%d ", va_arg(ap, int));
				break ;
			case 'd':
				printf("%f ", va_arg(ap, double));
				break ;
			case 'c':
				printf("%c ", va_arg(ap, int));
				break ;
			case 's':
				printf("%s ", va_arg(ap, char *));
				break ;
			default:
				break ;
		}
		i++;
	}
	va_end(ap);
	printf("\n");
}

enum	DayOfWeek {
	Sunday = 0,
	Monday,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday
};

union	Box
{
	/* data */
	short	candy;
	float	snack;
	char	doll[8];
};


int main(void)
{
	enum DayOfWeek	week;
	union Box		b1;
	int				one = 1;
	int				ten = 10;

	week = Tuesday;

	printValues("i", 10);
	printValues("ci", 'a', 20);
	printValues("dci", 1.234567, 'a', 10);
	printValues("sicd", "Hello, world!", 10, 'a', 1.234567);

	printf("%d\n", week);

	printf("%ld\n", sizeof(b1));
	strcpy(b1.doll, "bear");

	printf("%d\n", b1.candy);
	printf("%f\n", b1.snack);
	printf("%s\n", b1.doll);

	printf("Testing printf format specs\n");
	printf("%d %d..\n", one, ten);
	printf("%3d %3d..\n", one, ten);
	printf("%.3d %.3d..\n", one, ten);
	printf("%03d %03d..\n", one, ten);
	printf("% 3d % 3d..\n", one, ten);
	printf("%-3d %-3d..\n", one, ten);
	printf("%+d %+d..\n", one, ten);


	return (0);
}