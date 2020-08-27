 #include<stdio.h>
 #define ll long long
 #define sl(n) scanf("%lld",&n)
 #define pl(n) printf("%lld",n)
 #define ss(n) scanf("%s",&n)
 #define ps(n) printf("%s",n)
 ll arr[100],N;
 void display(){
  ll i;
  if(n==0){
     ps("heap is empty:");
     return;
  }
  for(ll i=0;i<N;i++){
     pl(arr[i]);
  }
  ps("\n");
 }
void insert(ll num,ll loc){
	ll par;
	while(loc>0){
		par=(loc-1)/2;
		if(num<=arr[par]){arr[loc]=num;return;}
		arr[loc]=arr[par];
		loc=par;
	}
	arr[0]=num;
}
void delete(ll num){
	ll left,ll right,i,temp,par;
	for(i=0;i<N;i++){
			if(num==arr[i])break;
			if(num!=arr[i]){
				ps("not found in heap");
				return;
			}
		arr[i]=arr[N-1];
		N=N-1
	}
	
	
}

 int main(){
  ll choice,num;
  N=0;//represent number of nodes in the heap
  while(1){
  ps("1.insert\n");
  ps("2.delete\n");
  ps("3.display\n");
  ps("4.Quit\n");
  ps("enter your choice:");
  sl(choice);
   switch(choice){
      case 1:
          ps("enter number to be inserted:");
		sl(num);
		insert(num,n);
		n=n+1;
		break;
	case 2:
		ps("enter number to be deleted:");
		sl(num);
		del(num);
		break;
	case 3:
		display();
		break;
	case 4:
		break;
	default:
		ps("wrong choice");
	}

	}
	}
