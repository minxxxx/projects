#include <stdio.h>
#include <string.h>
#include "libft.h"

int main ()
{
	char dest[] = "oldstring";
	const char src[]  = "newstring";

	printf("Before memmove dest = %s, src = %s\n", dest, src);
	ft_memmove(dest, src, 9);
	printf("After memmove dest = %s, src = %s\n", dest, src);

	return(0);
}
