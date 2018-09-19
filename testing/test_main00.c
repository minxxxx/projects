/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main00.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 10:54:17 by khansman          #+#    #+#             */
/*   Updated: 2017/06/09 10:54:21 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"
#include <stdio.h>

# ifdef __APPLE__
#  include <strings.h>
# else
#  include <string.h>
# endif

/*
** make && gcc ./malloc.so testing/test_main00.c && ./a.out
*/

int	main()
{
	/* Test 00 */
	printf("\nTest 00\n");
	printf("Attempting to malloc, and free 12 bytes:\n");
	void	*test00 = malloc(12);
	free(test00);
	printf("\tSucess!\n");

	/* Test 01 */
	printf("\nTest 01\n");
	printf("Attempting to malloc, and free 10 * 32 bytes:\n");
	void	*test01[10];
	for (int k = 0; k < 10; k++) {
		test01[k] = malloc(32);
		printf("allocated test01[%d]: %p\n", k, test01[k]);
	}
	for (int k = 0; k < 10; k++) {
		printf("freeing test01[%d]: %p\n", k, test01[k]);
		free(test01[k]);
	}
	printf("\tSucess!\n");

	/* Test 02 */
	printf("\nTest 02\n");
	printf("Attempting to malloc, and free 255 bytes:\n");
	void	*test02 = malloc(255);
	free(test02);
	printf("\tSucess!\n");

	/* Test 03 */
	printf("\nTest 03\n");
	printf("Attempting to malloc, and free 10 * 1024 bytes:\n");
	void	*test03[10];
	for (int k = 0; k < 10; k++) {
		test03[k] = malloc(1024);
		printf("allocated test03[%d]: %p\n", k, test03[k]);
	}
	for (int k = 0; k < 10; k++) {
		printf("freeing test03[%d]: %p\n", k, test03[k]);
		free(test03[k]);
	}
	printf("\tSucess!\n");

	/* Test 04 */
	printf("\nTest 04\n");
	printf("Attempting to malloc, and free 100000 bytes:\n");
	void	*test04 = malloc(100000);
	free(test04);
	printf("\tSucess!\n");

	/* Test 05 */
	printf("\nTest 05\n");
	printf("Attempting to malloc, and free 10 * 102400 bytes:\n");
	void	*test05[10];
	for (int k = 0; k < 10; k++) {
		test05[k] = malloc(102400);
		printf("allocated test05[%d]: %p\n", k, test05[k]);
	}
	for (int k = 0; k < 10; k++) {
		printf("freeing test05[%d]: %p\n", k, test05[k]);
		free(test05[k]);
	}
	printf("\tSucess!\n");

	/* Test 06 */
	printf("\nTest 06\n");
	void	*test06[1000];
	printf("Attempting to malloc, and free 1000 * 1 byte:\n");
	for (int k = 0; k < 1000; k++)
		test06[k] = malloc(1);
	for (int k = 0; k < 1000; k++)
		free(test06[k]);
	printf("\tSucess!\n");
	printf("Attempting to malloc, and free 1000 * 1 byte:\n");
	for (int k = 0; k < 1000; k++)
		test06[k] = malloc(1);
	for (int k = 0; k < 1000; k++)
		free(test06[k]);
	printf("\tSucess!\n");
	printf("Attempting to malloc, and free 1000 * 8 byte:\n");
	for (int k = 0; k < 1000; k++)
		test06[k] = malloc(8);
	for (int k = 0; k < 1000; k++)
		free(test06[k]);
	printf("\tSucess!\n");

	/* Test 07 */
	printf("\nTest 07\n");
	printf("Attempting to resize string\n");
	void	*test07;
	test07 = malloc(199);
	memcpy(test07, "Hello World!", 13);
	test07 = realloc(test07, 20);
	printf((!strcmp(test07, "Hello World!")) ? "\tSucess!\n" : "\tFailed!\n");
	free(test07);

	/* Last Test */
	printf("\nLast Test\n");
	printf("Attempting to double free NULL\n");
	free(NULL);
	free(NULL);
	printf("\tSucess!\n");
}
