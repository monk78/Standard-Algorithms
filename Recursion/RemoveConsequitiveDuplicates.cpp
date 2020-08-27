#include<bits/stdc++.h>
using namespace std;
void removeConsecutiveDuplicates(char *input) {
	/* Don't write main().
	* Don't read input, it is passed as function argument.
	* Change in the given string itself.
	* No need to return or print anything
	* Taking input and printing output is handled automatically.
	*/
   if(input[0]=='\0')
      return;
  if(input[0]==input[1])
  {
    int i=1;
    for(;input[i]!='\0';i++){
      input[i-1]=input[i];
    }
    input[i-1]=input[i];

  }
  removeConsecutiveDuplicates(input+1);
}
int main(){
 char in[1000];
 cin>>in;
 removeConsecutiveDuplicates(in);
 cout<<"ans:"<<in<<endl;
 return 0;
}
