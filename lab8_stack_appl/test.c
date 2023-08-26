#include <stdio.h>

void update(int *a,int *b) 
{
      int *temp ;
      temp=*a-*b;
      *a=*a+*b;
      if(*temp<0)
      *temp=*temp*(-1);
      *b=*temp;
      
      
      
      
      
      
}

int main()
 {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}