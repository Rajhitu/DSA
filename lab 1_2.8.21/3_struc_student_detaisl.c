/*WAP to read and print the details of 5 CS student details 
using Dynamic Memory Allocation (roll, age, cgpa, subject).
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct stud
{
    int roll_025, age_025;
    int cgpa_025;
    char sub_025[10];
};
int main()
{
    int n;
    struct stud *s[10];

    printf("how many students are there");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        s[i] = (struct stud * )malloc(n * sizeof(struct stud));
    }
    
    
    printf("Enter the details ");
    for (int i = 0; i < n; i++)
    { 
        printf("Enter the roll ,age, sub  cgpa, ");

        scanf("%d%d%s%d",&s[i]->roll_025,&s[i]->age_025, &s[i]->sub_025, &s[i]->cgpa_025);
    }

    for (int i = 0; i < n; i++)
    {
        printf(" roll ,age, cgpa,sub for %d student  is %d %d %d %s \n", i + 1, s[i]->roll_025, s[i]->age_025, s[i]->cgpa_025, s[i]->sub_025);
    }

    return 0;
}
