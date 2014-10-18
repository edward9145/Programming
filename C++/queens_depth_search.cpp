#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#define pop() stack[--sp]
#define push(node) stack[sp++] = node
#define stack_empty (sp<=0)

#define MAX_N 20
#define MAX_NODE 200 

typedef struct state_t{
    int n;
    int q[MAX_N];
}state_t;

state_t stack[MAX_NODE];
int sp = 0;
int count = 0;

void print_queen(state_t *result){
    int i = 0;
    printf("%3d:\t ", count);
    for(i=0;i<(result->n);i++)
        printf("%d ", (result->q[i]));
    printf("\n");
}

int conflict(int q, int p, int* queens){
    int i;
    for(i=0;i<q;i++){
        if(queens[i] == p) return 1;
        if(queens[i]-p == q-i) return 1;
        if(queens[i]-p == i-q) return 1;
    }
    return 0;
}

void queen(int n){
    state_t st;
    int i;
    while(!stack_empty){
        st = pop();
        if(st.n >= n){
            count ++;
            print_queen(&st);
            continue;
        }
        st.n ++;
        for(i=0;i<n;i++){
            if(conflict(st.n -1, i, st.q))
                continue;
            st.q[st.n-1] = i;
            push(st);
        }
    }
}

int main(){
    state_t init_st;
    
    init_st.n = 0;
    push(init_st);
    queen(8);

    system("pause");        
    return 0;
}
