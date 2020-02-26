#include "error.h"
#include "bitset.h"

int main()
{
	bitset_t my_bitset;

	int a;

	printf("%d : %x\n\n", a, &a);

	bitset_alloc(my_bitset, 100);
	//bitset_create(my_bitset, 100);

	printf("%ld : %ld\n", bitset_size(my_bitset), sizeof(my_bitset));

	if (my_bitset == NULL)
		printf("not ok\n");
	else
		printf("ok\n");

	printf("%ld : %ld\n", my_bitset[0], my_bitset[1]);

	//bitset_free(my_bitset);

	/*
	warning_msg("%d + %d = %d\n", 1, 1, 1+1);
	error_exit("ajajja\n");
	warning_msg("ok\n");
	*/

	return 0;
}