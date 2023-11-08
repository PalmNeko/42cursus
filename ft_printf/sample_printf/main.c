/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:14:01 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/06 15:51:19 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>

int	main(void)
{
	// %c
	printf("\n%%c:\n");
	printf(" %c\n", -1);
	printf(" %c\n", 0);
	printf(" %c\n", 1);
	printf(" %c\n", 'a');
	printf(" %c\n", ' ');
	printf(" %c\n", (int)LLONG_MAX);
	printf(" %c\n", (int)LLONG_MIN);
	printf(" %012c\n", 'a');
	printf(" % 012c\n", 'a');
	printf(" %+012c\n", 'a');
	printf(" % 12c\n", 'a');
	printf(" %-012.3c\n", 'a');
	printf(" %-012.0c\n", 'a');
	printf(" %-012.c\n", 'a');
	// %s
	printf("\n%%s:\n");
	printf(" %s\n", NULL);
	printf(" %s\n", "");
	printf(" %s\n", "abcdefg");
	// %p
	printf("\n%%p:\n");
	printf(" %p\n", (void*)-1);
	printf(" %p\n", (void*)0);
	printf(" %p\n", (void*)1);
	printf(" %p\n", (void*)LLONG_MAX);
	printf(" %p\n", (void*)LLONG_MIN);
	printf(" %p\n", (void*)LLONG_MIN);
	// %d
	printf("\n%%d:\n");
	printf(" %d\n", -1);
	printf(" %d\n", 0);
	printf(" %d\n", 1);
	printf(" %d\n", INT_MIN);
	printf(" %d\n", INT_MAX);
	printf(" %d\n", (int)(LLONG_MAX));
	printf(" %d\n", (int)(LLONG_MIN));
	printf(" %-d\n", 100);
	printf(" %+d\n", 101);
	printf(" %+0d\n", 103);
	printf(" %-d\n", 102);
	printf(" % d\n", 103);
	printf(" % 0d\n", 103);
	printf(" % 0d\n", 103);
	printf(" % 012d\n", 103);
	printf(" % 012.d\n", 103);
	printf(" % 012.5d\n", 103);
	printf(" % 12.5d\n", 103);
	printf(" % -12.5d\n", 103);
	printf(" % d\n", -103);
	printf(" % 0d\n", -103);
	printf(" % 0d\n", -103);
	printf(" % 012d\n", -103);
	printf(" % 012.d\n", -103);
	printf(" % 012.5d\n", -103);
	printf(" % 12.5d\n", -103);
	printf(" % -12.5d\n", -103);
	// %i
	printf("\n%%i:\n");
	printf(" %i\n", -1);
	printf(" %i\n", 0);
	printf(" %i\n", 1);
	printf(" %i\n", INT_MIN);
	printf(" %i\n", INT_MAX);
	printf(" %i\n", (int)LLONG_MAX);
	printf(" %i\n", (int)LLONG_MIN);
	printf(" %-i\n", 100);
	printf(" %+i\n", 101);
	printf(" %+0i\n", 103);
	printf(" %-i\n", 102);
	printf(" % i\n", 103);
	printf(" % 0i\n", 103);
	printf(" % 0i\n", 103);
	printf(" % 012i\n", 103);
	printf(" % 012.i\n", 103);
	printf("a% 0 12.5i\n", 103);
	printf(" % 12.5i\n", 103);
	printf(" % -12.5i\n", 103);
	printf(" % i\n", -103);
	printf(" % 0i\n", -103);
	printf(" % 0i\n", -103);
	printf(" % 012i\n", -103);
	printf(" % 012.i\n", -103);
	printf(" % 012.5i\n", -103);
	printf(" % 12.5i\n", -103);
	printf(" % +-12.5i\n", -103);
	// %u
	printf("\n%%u:\n");
	printf(" %u\n", -1);
	printf(" %u\n", 0);
	printf(" %u\n", 1);
	printf(" %u\n", UINT_MAX);
	printf(" %u\n", (unsigned int)ULLONG_MAX);
	printf(" %-u\n", 100);
	printf(" %+u\n", 101);
	printf(" %+0u\n", 103);
	printf(" %-u\n", 102);
	printf(" % u\n", 103);
	printf(" % 0u\n", 103);
	printf(" % 0u\n", 103);
	printf(" % 012u\n", 103);
	printf(" % 012.u\n", 103);
	printf(" %-012.u\n", 103);
	printf(" % 012.5u\n", 103);
	printf(" %#12.5u\n", 103);
	printf(" %+12.5u\n", 103);
	// %x
	printf("\n%%x:\n");
	printf(" %x\n", -1);
	printf(" %x\n", 0);
	printf(" %x\n", 1);
	printf(" %x\n", UINT_MAX);
	printf(" %x\n", (unsigned int)ULLONG_MAX);
	printf(" %x\n", INT_MIN);
	printf(" %x\n", (unsigned int)LLONG_MIN);
	printf(" %-x\n", 100);
	printf(" %+x\n", 101);
	printf(" %+0x\n", 103);
	printf(" %-x\n", 102);
	printf(" % x\n", 103);
	printf(" % 0x\n", 103);
	printf(" % 0x\n", 103);
	printf(" % 012x\n", 103);
	printf(" % 012.x\n", 103);
	printf(" %-012.x\n", 103);
	printf(" % 012.5x\n", 103);
	printf(" %    12.5x\n", 104);
	// %X
	printf("\n%%X:\n");
	printf(" %X\n", -1);
	printf(" %X\n", 0);
	printf(" %X\n", 1);
	printf(" %X\n", UINT_MAX);
	printf(" %X\n", (unsigned int)ULLONG_MAX);
	printf(" %X\n", INT_MIN);
	printf(" %X\n", (unsigned int)LLONG_MIN);
	// %s
	printf("\n%%s:\n");
	printf(" %-s\n", "abcdefg");
	printf(" %+s\n", "abcdefg");
	printf(" %+0s\n", "abcdefg");
	printf(" %-s\n", "abcdefg");
	printf(" % s\n", "abcdefg");
	printf(" % 0s\n", "abcdefg");
	printf(" % 0s\n", "abcdefg");
	printf(" % 012s\n", "abcdefg");
	printf(" % 012.s\n", "abcdefg");
	printf(" %-012.s\n", "abcdefg");
	printf(" %-012s\n", "abcdefg");
	printf(" % 012.5s\n", "abcdefg");
	printf(" % 12.5s\n", "abcdefg");
	printf(" % 12.00005s\n", "abcdefg");
	printf(" % 12.00005s\n", NULL);
	printf(" % 012.5s\n", NULL);
	printf(" % 012.1s\n", NULL);
	printf(" %-012.1s\n", NULL);
	printf(" %#s\n", "abcdefg");
	// %%
	printf("\n%%%%:\n");
	printf(" %%\n");
	printf(" %%\n");
	printf(" %%\n");
	printf(" %%\n");
	printf(" %%\n");
	printf(" %%\n");
	printf(" %%\n");
	printf(" %012%\n");
	printf(" % 012%\n");
	printf(" %+012%\n");
	printf(" % 12%\n");
	printf(" %-012.3%\n");
	printf(" %-012.0%\n");
	printf(" %-012.%\n");
	printf(" %#%\n");
	// flag test #
	printf("\n my tests\n");
	printf(" on flag : of flag\n");
	printf(" %#o : %o\n", 10, 10);
	printf(" %+ d : %d\n", 10, 10);
	printf(" %+d : %d\n", 10, 10);
	printf(" % d : %d\n", 10, 10);
	printf(" %- 12.1u : %u\n", 10, 10);
	printf(" %-10.1s : %s\n", "321", "321");
	// Field Width
	fprintf(stdout, "\n Filed width\n");
	fprintf(stdout, " 12322123%03111111111d\n",3);
	fprintf(stdout, " 12322123%.11d\n",3);
	fprintf(stdout, " 12322123% 1.11i\n",3);
	fprintf(stdout, " 12322123% 13.0x\n",3);
	fprintf(stdout, " %+.0%\n");
	fprintf(stdout, " %+.0s\n", "123221");
	fprintf(stdout, " %+18.15s\n", "123221");
	fprintf(stdout, " %+18.s\n", "123221");
	// min width check
	fprintf(stdout, "\n min width check\n");
	fprintf(stdout, "@%-12d\n", 5);
	fprintf(stdout, "@%-+12d\n", 5);
	fprintf(stdout, "@%- 12d\n", 5);
	fprintf(stdout, "@%12d\n", 5);
	fprintf(stdout, "@%+12d\n", 5);
	fprintf(stdout, "@% 12d\n", 5);
	fprintf(stdout, "@%12s\n", "abc");
	fprintf(stdout, "@%+12s\n", "abc");
	fprintf(stdout, "@% 12s\n", "abc");
	return (0);
}
