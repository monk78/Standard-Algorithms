#include<stdio.h>
typedef long long int ll;
int main(){
    ll arr[4]={2,3,4,-5};
    printf("printing all the subarrays:");
    for(ll i=0;i<(1<<4);i++){
        for(ll j=0;j<4;j++){
            if(i&(1<<j))
                printf("%lld",arr[j]);

        }
        printf("\n");
    }
}
