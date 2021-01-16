#include "Header.h"

void KratNum(int a, int b, int c)
{
	for (int i = 1; i <= 1000; i++)
		if ((i%a == 0)&(i%b == 0)&(i%c == 0)) cout << i << " ";
}