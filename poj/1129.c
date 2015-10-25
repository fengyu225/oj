/*
 * http://poj.org/problem?id=1129
 *
 * Description
 *
 When a radio station is broadcasting over a very large area, repeaters are used to retransmit the signal so that every receiver has a strong signal. However, the channels used by each repeater must be carefully chosen so that nearby repeaters do not interfere with one another. This condition is satisfied if adjacent repeaters use different channels. 

 Since the radio frequency spectrum is a precious resource, the number of channels required by a given network of repeaters should be minimised. You have to write a program that reads in a description of a repeater network and determines the minimum number of channels required.
 Input

 The input consists of a number of maps of repeater networks. Each map begins with a line containing the number of repeaters. This is between 1 and 26, and the repeaters are referred to by consecutive upper-case letters of the alphabet starting with A. For example, ten repeaters would have the names A,B,C,...,I and J. A network with zero repeaters indicates the end of input. 

 Following the number of repeaters is a list of adjacency relationships. Each line has the form: 

 A:BCDH 

 which indicates that the repeaters B, C, D and H are adjacent to the repeater A. The first line describes those adjacent to repeater A, the second those adjacent to B, and so on for all of the repeaters. If a repeater is not adjacent to any other, its line has the form 

 A: 

 The repeaters are listed in alphabetical order. 

 Note that the adjacency is a symmetric relationship; if A is adjacent to B, then B is necessarily adjacent to A. Also, since the repeaters lie in a plane, the graph formed by connecting adjacent repeaters does not have any line segments that cross. 
 Output

 For each map (except the final one with no repeaters), print a line containing the minumum number of channels needed so that no adjacent channels interfere. The sample output shows the format of this line. Take care that channels is in the singular form when only one channel is required.
 Sample Input

2
A:
B:
4
A:BC
B:ACD
C:ABD
D:BC
4
A:BCD
B:ACD
C:ABD
D:ABC
0
 Sample Output

 1 channel needed.
 3 channels needed.
 4 channels needed.
 */
#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>
#include<string.h>

int color[27] = {1};

int used[27] = {1};

bool graph[27][27];

int curr_c;
int count;

void solve(){
    int k;
    curr_c = 0;
    for(int i=0; i<27; i++) color[i]=-1;
    for(int i=0; i<count; i++){
        for(int i=0; i<27; i++) used[i]=0;
        for(int j=0; j<count; j++){
            if(!graph[i][j]) continue;
            if(color[j] != -1)
                used[color[j]] = 1;
        }
        int k;
        for(k=0; k<count; k++)
            if(!used[k])
                break;
        color[i] = k;
        curr_c = k>curr_c?k:curr_c;
    }
    curr_c++;
    if(curr_c==1)
        printf("%d channel needed.\n", curr_c);
    else
        printf("%d channels needed.\n", curr_c);
}

int main(){
    int c;
    char str[27];
    while(1){
        scanf("%d", &c);
        if(c==0) break;
        memset(graph, false, sizeof(bool)*27*27);
        count=c;
        for(int i=0;i<c;i++){
            memset(str,'\0',sizeof(str));
            scanf("%s",str);
            if(strlen(str)<=2)
                continue;
            for(int j=2; j<strlen(str); j++)
                graph[str[0]-'A'][str[j]-'A'] = graph[str[j]-'A'][str[0]-'A'] = true;
        }
        solve();
    }
    return 0;
}
