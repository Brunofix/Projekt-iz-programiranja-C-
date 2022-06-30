#include <stdlib.h>
#include "header.h"

int main(void)
{
	int choice = 0;
	STUDENT* headNode = NULL;

	do
	{
		choice = mainMenu(&headNode);
	} while (choice != 0);

	return 0;
}