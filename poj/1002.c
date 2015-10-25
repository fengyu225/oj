#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>


char map[26] = {
    '2', '2', '2', 
    '3', '3', '3', 
    '4', '4', '4', 
    '5', '5', '5', 
    '6', '6', '6', 
    '7', '0', '7', 
    '7', '8', '8', 
    '8', '9', '9', 
    '9', '0'
};

struct node{
    char ch;
    bool is_leaf;
    struct node* children[10];
    int c;
};

struct node trie_nodes[1000000];
int size = 1;

void normalize(char* orig, char* result){
    char* curr = result;
    while(*orig){
        if(curr-result == 3){
            *curr++ = '-';
            continue;
        }
        if(*orig<='9' && *orig>='0')
            *curr++ = *orig++;
        else if(*orig<='Z' && *orig>='A')
            *curr++ = map[*orig++-'A'];
        else
            orig++;
    }
    *curr = '\0';
}

void trie_add(struct node* root, char* s){
    struct node* curr = root;
    while(*s){
        if(*s == '-'){
            s++;
            continue;
        }
        curr->is_leaf = false;
        if(!curr->children[*s-'0']){
            struct node* c = &trie_nodes[size++];
            c->ch = *s;
            c->is_leaf = true;
            curr->children[*s-'0'] = c;
        }
        curr = curr->children[*s-'0'];
        curr->c++;
        s++;
    }
}

bool has_dup = false;

void print_trie_leaf(struct node* curr, char curr_s[9], int c){
    if(curr->is_leaf){
        curr_s[c] = curr->ch;
        curr_s[c+1] = '\0';
        if(curr->c > 1){
            printf("%s %d\n", curr_s, curr->c);
            has_dup = true;
        }
        return;
    }
    if(c == 3)
        curr_s[c++] = '-';
    for(int i=0; i<10; i++){
        if(!curr->children[i])
            continue;
        curr_s[c] = curr->ch;
        print_trie_leaf(curr->children[i], curr_s, c+1);
    }
}

int main(){
    int c;
    struct node root = trie_nodes[size++];
    root.ch = ' ';
    root.is_leaf = false;
    scanf("%d", &c);
    for(int i=0; i<c; i++){
        char temp[20000];
        char result[9];
        scanf("%s", temp);
        normalize(temp,result);
        trie_add(&root,result);
    }
    char t[9];
    for(int i=0; i<10; i++)
        if(root.children[i])
            print_trie_leaf(root.children[i],t,0); 
    if(!has_dup)
        printf("No duplicates.\n");

    return 0;
}
