#include <bits/stdc++.h>
using namespace std;
int check(int p,int arr[],int k){

    for(int i=0;i<k;i++)
    {
        if(arr[i]==p)
            return 0;
    }
    return 1;

}
int check2(int xx,int c[],int k){
    for(int i=0;i<k;i++){
        if(xx!=c[i])
            return 1;
    }
    return 0;
}
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)

       // Last i elements are already in place
       for (j = 0; j < n-i-1; j++)
           if (arr[j]>arr[j+1])
              swap(&arr[j], &arr[j+1]);
}
int main()
{
      int n,m,mina=0,maxa=0,minc=0,maxc=0;
      cin>>n;
      int a[100]={0};
      cin>>a[0];
      mina=a[0];
      maxa=a[0];
      for(int i=1;i<n;i++){
          cin>>a[i];
          if(mina>a[i])
            mina=a[i];
          if(maxa<a[i])
            maxa=a[i];
      }
      bubbleSort(a,n);
      cin>>m;
      int c[m];
      cin>>c[0];
      minc=c[0];
      maxc=c[0];
      for(int i=1;i<m;i++){
        cin>>c[i];
        if(minc>c[i])
             minc=c[i];
        if(maxc<c[i])
             maxc=c[i];
      }
      bubbleSort(c,m);
        //int b[100]={0};
        int ul=maxc-maxa;
        int ll=minc-mina;
    int arr[1000]={0},k=0;
   // int pr[n];
    for(int i=0;i<m;i++)
    {

       //int flag2=check2(arr,pr,k,n);
        int flag;
        for(int j=0;j<n;j++){
            int p=c[i]-a[j];
            flag=check(p,arr,k);
            if(p>=ll&&p<=ul&&flag==1){
                arr[k]=p;
                k++;
                flag=0;
                //flag2=0;
            }
       // flag2=0;
        }
        }

    bubbleSort(arr,k);
    int arrr[1000]={0},z=0;
    for(int i=0;i<k;i++){
        for(int j=0;j<n;j++){
            int xx=arr[i]+a[j];
            int flag2=check2(xx,c,m);
            cout<<"flag2-"<<flag2;
            int flag1=check(xx,arrr,z);
            cout<<"\nflag1-"<<flag1;
            if(flag2==1&&flag1==0)
                {
                    arrr[z]=arr[i];
                    z++;
                    flag1=0;
                }
        }

    }
        for(int i=0;i<z;i++)
        {
            if(arrr[i]>0)
                cout<<arrr[i]<<" ";
        }
    return 0;
}
