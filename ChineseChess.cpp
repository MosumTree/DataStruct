#include <stdios.h>
#define HALF_BITS_LENGTH 4;
#define FULLMASK 255;//11111111
#define LMASK (FULLMASK<<HALF_BITS_LENGTH)//11110000
#define RMASK (FULLMASK>>HALF_BITS_LENGTH)//00001111
#define RSET(b,n) (b=((LMASK&b)|(n)))//b的右侧设置为n
#define LSET(b,n) (b=((RMASK&b)|((n)<<HALF_BITS_LENGTH)))//b的左侧设置为n
#define RGET(b) (RMASK&b)
#define LGET(b) ((LMASK&b)>>HALF_BITS_LENGTH)
#define GRIDW 3
int main(int argc, char const *argv[])
{
	unsigned char b;
	for (LSET(b,1); i < GRIDW*GRIDW; LSET(b,(LSET(b)+1)))
	{

	}
	return 0;
}m