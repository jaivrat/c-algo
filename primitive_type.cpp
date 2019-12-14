
#include <iostream>

//Tricks
//Setting a xth bit on: 
//              number |= 1 << x;
//Clearing a bit:
//              number &= ~(1 << x);
//Toggling a bit: (Use XOR Operator)
//              number ^= 1 << x;




/**
 *  Ccount number of bits on 
 * **/

short count_bits(unsigned int x)
{
	short count = 0;
	const unsigned int ONE = 1;
	while(x){
		//printf("count=%d x = %d\n",count,x);
		count = count + x & ONE;
		x = x >> 1;
	}
	return(count);
}

int main()
{
  std::cout << "Testing for 2 = " << count_bits(2) << std::endl;
  std::cout << "Testing for 10 = " << count_bits(10) << std::endl;
}
