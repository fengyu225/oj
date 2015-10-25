#include<stdio.h>
#include<math.h>

int main(){
    float a,b,c;
    int i=0;
    while(scanf("%f %f %f\n", &a, &b, &c)!=EOF && a!=0 && b!=0 && c!=0){
        printf("Triangle #%d\n", ++i);
        if(a<0){
            if(b>c){
                printf("Impossible.\n\n");
                continue;
            }
            float r=(float) sqrt(c*c-b*b);
            printf("a = %.3f\n\n", r);
            continue;
        }
        if(b<0){
            if(a>c){
                printf("Impossible.\n\n");
                continue;
            }
            float r=(float) sqrt(c*c-a*a);
            printf("b = %.3f\n\n", r);
            continue;
        }
        printf("c = %.3f\n\n", (float)sqrt(a*a+b*b));
    }   
    return 0;
}
