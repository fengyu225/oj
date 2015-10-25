/*
Description
George took sticks of the same length and cut them randomly until all parts became at most 50 units long. Now he wants to return sticks to the original state, but he forgot how many sticks he had originally and how long they were originally. Please help him and design a program which computes the smallest possible original length of those sticks. All lengths expressed in units are integers greater than zero.

Input
The input contains blocks of 2 lines. The first line contains the number of sticks parts after cutting, there are at most 64 sticks. The second line contains the lengths of those parts separated by the space. The last line of the file contains zero.

Output
The output should contains the smallest possible length of original sticks, one per line.

Sample Input

9
5 2 1 5 2 1 5 2 1
4
1 2 3 4
0

Sample Output

6
5 

 */

#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>


int sticks[65];
//int sticks[] = {5,2,1,5,2,1,5,2,1};
bool visited[65] = {false};
int goal,sum,len;

int comp(const void* a, const void* b){
    return (*(int*)b - *(int*)a);
}

bool dfs(int curr_sum, int curr_i, int count){
    if(count*goal == sum) return true;
    for(int i=curr_i; i<len; i++){
        if(visited[i] || (i&&sticks[i] == sticks[i-1]&&!visited[i-1])) continue;
        if(curr_sum+sticks[i] == goal){
            visited[i] = true;
            if(dfs(0,0,count+1)) return true;
            visited[i] = false;
            return false;
        }
        if(curr_sum+sticks[i]<goal){
            visited[i] = true;
            if(dfs(curr_sum+sticks[i],curr_i+1,count)) return true;
            visited[i] = false;
            if(curr_sum == 0) return false;
        }
    }
    return false;
}

int main(){
    while(~scanf("%d",&len)){
        if(!len) break;
        sum = 0;
        for(int i=0; i<len; i++){
            scanf("%d", &sticks[i]);
            sum += sticks[i];
        }
        qsort(sticks, len, sizeof(int), comp);
        for(goal=sticks[0];goal<sum;goal++){
            if(sum % goal != 0) continue;
            memset((void*)visited,false,sizeof(bool)*65);
            if(dfs(0,0,0)) 
                break;
        }
        printf("%d\n",goal);
    }
    return 0;
}
