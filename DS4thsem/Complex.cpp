#include<bits/stdc++.h>
using namespace std;
struct complexx{
    int real,img;
};
int main(){
 int choice,x,y,z;
 struct complexx a,b,c;
 while(1){
    printf("Press 1 : to add \n");
    printf("Press 2 : to subtract\n");
    printf("Press 3 :to multiply \n");
    printf("Press 4 :to divide .\n");
    printf("Press 5 to exit.\n");
    printf("Enter your choice\n");
    scanf("%d", &choice);
    if(choice==5)exit(0);
    if(choice>=1 && choice<=4){
        printf("enter a and b (a+ib):");
        scanf("%d%d",&a.real,&a.img);
        printf("enter c and d (c+id):");
        scanf("%d%d",&b.real,&b.img);
    }
    if(choice==1){
        c.real=a.real+b.real;
        c.img=a.img+b.img;
        if(c.img>=0)printf("sum=%d+%di\n",c.real,c.img);
        else printf("sum=%d %di\n",c.real,c.img);
    }
    else if(choice==2){
        c.real=a.real-b.real;
        c.img=a.img-b.img;
        if(c.img>=0)printf("difference=%d+%di\n",c.real,c.img);
        else printf("difference=%d %di\n",c.real,c.img);
    }
    else if(choice==3){
        c.real=a.real*b.real-a.img*b.img;
        c.img=a.img*b.real+a.real*b.img;
        if(c.img>=0)printf("mult=%d+%di\n",c.real,c.img);
        else printf("mult=%d %di\n",c.real,c.img);

    }
    else if(choice==4){
        if(b.real==0 && b.img==0)printf("division not allowed\n");
        else{
            x=a.real*b.real+a.img*b.img;
            y=a.img*b.real-a.real*b.img;
            z=b.real*b.real+b.img*b.img;
            if(x%z==0 && y%z==0){
                 if (y/z >= 0)
                    printf("Division of the complex numbers = %d + %di\n", x/z, y/z);
                 else
                    printf("Division of the complex numbers = %d %di\n", x/z, y/z);

                }
             else if (x%z == 0 && y%z != 0)
                {
                    if (y/z >= 0)
                    printf("Division of two complex numbers = %d + %d/%di\n", x/z, y, z);
                    else
                    printf("Division of two complex numbers = %d %d/%di\n", x/z, y, z);
                }
            else if (x%z != 0 && y%z == 0)
                {
                    if (y/z >= 0)
                        printf("Division of two complex numbers = %d/%d + %di\n", x, z, y/z);
                    else
                        printf("Division of two complex numbers = %d %d/%di\n", x, z, y/z);
                }
            else
                {
                if (y/z >= 0)
                    printf("Division of two complex numbers = %d/%d + %d/%di\n",x, z, y, z);
                else
                    printf("Division of two complex numbers = %d/%d %d/%di\n", x, z, y, z);
                }
        }

    }


 }

}
