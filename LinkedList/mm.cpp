#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
#define for(__k,__l,__u) for(__k=__l;__k<__u;__k++)
long long int P,L,k;
long long* Powers ;
long long count = 1;
long long length = 1;
////////////////GCD
long long GCD(long long a, long long b)
{

	long long remainder = a%b ;
	while(remainder != 0)
	{
		a = b;
		b = remainder;
		remainder = a%b;
	}
	return b;
}


////////////////////Mod
long long modpow(long long base, long long exp, long long modulus) {
  base %= modulus;
  long long result = 1;
  while (exp > 0) {
    if (exp & 1)
		result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result;
}
///////////////////////////////chk
void check(long long k)
{
    bool flag = false;
	long long int x,y,z,o=int(2*sqrt(P));

	for(x,1,o)
	{
		for(y,x,o)
		{
			for(z,1,o)
			{
				if(modpow(x,k,P)+modpow(y,k,P)-modpow(z,k,P) == 0)
				{
					Powers = (long long *)realloc(Powers, sizeof(long long)*(length+1));
					Powers[length] = k;
					length++;
					count++;
					if(L>P)
    			        count += (long long )((L-k)/(P-1));

					flag = true;
					break;
				}
			}
			if(flag )break;
		}
		if(flag )
		{
			flag = false;
			break;
		}
	}
}

bool inPowers(long long _gcd)
{

    long long first, last, mid;
    first = 0;
    last = length-1;
    while(last >= first)
    {
        mid = (first + last)/2;
        if(Powers[mid] == _gcd)
            return true;
        else if(_gcd < Powers[mid])
            last = mid-1;
        else
            first = mid+1;
    }

    return false;
}
////////////////////////////////main
int main()
{
    long long gcd;
		cin>>P>>L;
		Powers = new long long[1];
		Powers[0] = 1;
		count+=(long long)((L-1)/(P-1));
	    for(k,2,P-1){
	        gcd = GCD(k,P-1);
	        if(inPowers(gcd))
	        {
	            count++;
				if(L>P)
				    count += (long long )((L-k)/(P-1));
	            length++;
				Powers = (long long *)realloc(Powers, sizeof(long long int)*(length+1));
				Powers[length-1] = k;
	        }
	        else if(gcd == k)
	            check(k);
	    }
		cout<<count;
}


Language: C++14
