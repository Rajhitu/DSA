//Q1.	WAP to add two distances (in kilometre-meter) by
//passing structure to a function.
#include <stdio.h>
struct dist
{
    int kilometre;
    int metre;
} ;
void add_dis(struct dist s[2])
{
    int kilometre, metre;
    metre = s[0].metre + s[1].metre;

    kilometre = s[0].kilometre + s[1].kilometre + metre / 1000;
    metre = metre % 1000;
    printf("the added value of distance are %d kilometre %d metre ", kilometre, metre);
}

int main()
{ struct dist s[2];


    for (int i = 0; i < 2; i++)
    {
        printf("enter the distance %d in kilometre and metre ", i + 1);
        scanf("%d %d", &s[i].kilometre, &s[i].metre);
    }
add_dis(s);
    return 0;
}
