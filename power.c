#include <stdio.h>
#include <math.h>
#define M 1000000007
#define lli long long int

lli power(int num, int pow)
{
	if(num == 0)
		return 0;
	if(pow == 0)
		return 1;

	lli temp = power(num, pow/2);
	temp %= M;
	temp *= temp;
	temp %= M;
	if(pow % 2)
		temp *= num;
	return temp%M;
}

int main()
{
	int z = 999999974;
	lli temp = power(2, z);
	temp *= 603457371;
	temp %= M;
    printf("%lld", temp);
}
