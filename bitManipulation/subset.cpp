#include<bits/stdc++.h>
using namespace std;
void subsets(int A[], int N)
    {
        for(int i = 0;i < (1 << N); ++i)
        {
            for(int j = 0;j < N;++j)
                if(i & (1 << j))
                    cout << A[j] << " ";
            cout << endl;
    }
    }
int main(){
    int n=4;
    int arr[n]={1,2,3,4};
    subsets(arr,4);
    return 0;
}
