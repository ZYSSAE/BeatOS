#include "BeatOS_Main.h"

int main(void)
{
	//Welcome to BeatOS!
	printf("Welcome to BeatOS!\nCopyright By INUTE 2014\n");

	UINT16 *n=malloc(sizeof(UINT16)*100);
	memset(n,1000,sizeof(UINT16)*100);
	printf("%d\n",*(n+10));
	printf("%d\n",*(n+11));
	printf("%d\n",*(n+12));
	printf("%d\n",*(n+50));
	printf("%d\n",*(n+51));
	printf("%d\n",*(n+52));
	printf("%d\n",*(n+70));
	printf("%d\n",*(n+71));
	printf("%d\n",*(n+72));
	printf("%d\n",*(n+99));
	free(n);

	//Shouldn't reach this statement
	return 1;
}
