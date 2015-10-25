#include<stdio.h>

int orig[100000];
int left_1[100000];
int right_1[100000];

int calc(int n){
    int left_pre=orig[0];
    int left_curr;
    int right_after=orig[n-1];
    int right_curr;
    left_1[0]=orig[0];
    right_1[n-1] = orig[n-1];
    for(int i=1; i<n; i++){
        left_curr = left_pre>0?left_pre+orig[i]:orig[i]; 
        left_1[i]=left_1[i-1]<left_curr?left_curr:left_1[i-1];
        left_pre = left_curr;

        right_curr = right_after>0?right_after+orig[n-1-i]:orig[n-1-i];
        right_1[n-1-i] = right_1[n-1-i+1]<right_curr?right_curr:right_1[n-1-i+1];
        right_after = right_curr;
        
    }
//    for(int i=n-2; i>=0; i--){
//        right_curr = right_after>0?right_after+orig[i]:orig[i];
//        right_1[i] = right_1[i+1]<right_curr?right_curr:right_1[i+1];
//        right_after = right_curr;
//    }
    int max=left_1[0]+right_1[1];
    for(int l=0,r=l+1; r<n; l++,r++){
        max = left_1[l]+right_1[r]>max?left_1[l]+right_1[r]:max;
    }
    return max;
}

int main(){
    int n;
    while(scanf("%d", &n)!=EOF){
        if(n==0 || n>100000 || n<2)
            break;
        for(int i=0; i<n; i++)
            scanf("%d", orig+i);
        printf("%d\n", calc(n));
    }
    return 0;
}
