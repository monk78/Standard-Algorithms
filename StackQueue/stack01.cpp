#include <bits/stdc++.h>
#include <deque>
using namespace std;
void showdq(deque <int> g,int arr[],int n)
{
    deque <int> :: iterator it;
    for (it = g.begin(); it != g.end(); ++it)
        cout <<arr[*it]<<" ";
    cout << '\n';
}
void printKMax(int arr[], int n, int k){
    int max=0;
    deque< int >dq;
    for(int i=0;i<=n-k;i++){
        int j=i;
        int sum=0;
        while(j<(j+k)){
            sum=sum+arr[j];
            dq.push_back(j);
            j++;
        }
        if(max<=sum){
            dq.pop_front();
            max=sum;
        }
        else
            dq.pop_front();
    }
    showdq(dq,arr,n);
}
int main(){
	int t;
	cin >> t;
	while(t--) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
        cout<<endl;
  	}
  	return 0;
}
