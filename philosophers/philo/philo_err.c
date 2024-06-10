#include "philosophers.h"

int	print_err(char *str, int exit_num)
{
	printf("%s\n", str);
	exit(exit_num);
	return (exit_num);
}
