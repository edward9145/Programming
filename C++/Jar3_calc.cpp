#include<stdio.h>
#include<stdlib.h>
#define NumberOf(action) 9
#define MAX_CAP 20
#define MAX_STATE 1000

typedef struct Jar{
    int cap;
    int val;
    int id; // 0->A, 1->B, 2->C
}Jar;

typedef struct State{
    int ca, cb, cc; // A,B存油量 
    int parent; // 父节点下标
    char* act;
}State;

Jar Ja, Jb, Jc;
State queue[MAX_STATE];
int tail, Target;
char *fill[] = {"Fill A", "Fill B", "Fill C"};
char *empty[] = {"Empty A", "Empty B", "Empty C"};
char *pour[] = {"A->B", "B->A", "B->C", "C->B", "C->A", "A->C"};
char *act_name;   // 当前操作名称 

int fill_a(), fill_b(), fill_c(), empty_a(), empty_b(), empty_c(), 
    a_to_b(), b_to_a(), b_to_c(), c_to_b(), c_to_a(), a_to_c();

int (*action[])() = {
    a_to_b, b_to_a , b_to_c, c_to_b, c_to_a, a_to_c,
    empty_a, empty_b, empty_c,
};

int Fill_X(Jar *jar){
    if(jar->val == jar->cap)
        return 0;
    jar->val = jar->cap;
    act_name = fill[jar->id];
    return 1;
}

int fill_a(){
    return Fill_X(&Ja);
}
int fill_b(){
    return Fill_X(&Jb);
}
int fill_c(){
    return Fill_X(&Jc);
}

int Empty_X(Jar *jar){
    if(jar->val == 0)
        return 0;
    jar->val = 0;
    act_name = empty[jar->id];
    return 1;
}

int empty_a(){
    return Empty_X(&Ja);
}
int empty_b(){
    return Empty_X(&Jb);
}
int empty_c(){
    return Empty_X(&Jc);
}

int X_to_Y(Jar *jx, Jar *jy){
    int t;
    
    if(jy->val == jy->cap)
        return 0;
    if(jx->val == 0)
        return 0;
    t = jy->cap - jy->val;
    if( t>= jx->val){
        jy->val += jx->val;
        jx->val = 0;
    }
    else{
        jy->val = jy->cap;
        jx->val -= t;
    }
    act_name = pour[jx->id];
    return 1;
}

int a_to_b(){
    return X_to_Y(&Ja, &Jb);
}
int b_to_a(){
    return X_to_Y(&Jb, &Ja);
}
int b_to_c(){
    return X_to_Y(&Jb, &Jc);
}
int c_to_b(){
    return X_to_Y(&Jc, &Jb);
}
int c_to_a(){
    return X_to_Y(&Jc, &Ja);
}
int a_to_c(){
    return X_to_Y(&Ja, &Jc);
}


void init(int valA, int valB, int valC){
    Ja.val = valA;
    Jb.val = valB;
    Jc.val = valC;
    Ja.id = 0;
    Jb.id = 1;
    Jc.id = 2;
    tail = 1;
    queue[0].ca = valA;
    queue[0].cb = valB;
    queue[0].cc = valC;
    queue[0].parent = -1;
    queue[0].act = "Start";
}

int succeed(int i){
    return queue[i].cb == Target;
} 

void show(int n){
    int i;
    i = queue[n].parent;
    if(i != -1)
        show(i);
    printf("%s\t %d, %d, %d\n", queue[n].act, queue[n].ca, queue[n].cb, queue[n].cc);
}

void setsit(int i){
    Ja.val = queue[i].ca;
    Jb.val = queue[i].cb;
    Jc.val = queue[i].cc;
}

int exist(){
    int i;
    for(i=0; i<tail; i++){
        if((queue[i].ca == Ja.val) 
            && (queue[i].cb == Jb.val)
            && (queue[i].cc == Jc.val))
            return 1;
    }
    return 0;
}

void append(int parent){
    if(tail >= MAX_STATE){
        printf("%d queue nodes required\n", tail);
        exit(1);
    }
    queue[tail].parent = parent;
    queue[tail].ca = Ja.val;
    queue[tail].cb = Jb.val;
    queue[tail].cc = Jc.val;
    queue[tail].act = act_name;
    tail++;
}

int solve(){
    int i,j;
    
    for(i=0;i<tail;i++){
        if(succeed(i)){
            show(i);
            return 1;
        }
        for(j=0;j<NumberOf(action);j++){
            setsit(i);  // 将油罐油量设置为节点i的状态
            if(action[j]() && !exist()){  //生成新状态并检查是否出现过 
                //printf("%s\n", act_name);
                append(i); // 保存新状态
            } 
        }
    }
    
    return 0;
}

int main(){
//    FILE *fp;
    printf("Ja.cap Jb.cap Jc.cap Ja.val Jb.val Jc.val Target\n");
    scanf("%d %d %d %d %d %d %d", &Ja.cap, &Jb.cap, &Jc.cap, &Ja.val, &Jb.val, &Jc.val, &Target);
//    Ja.cap = 12, Jb.cap = 8, Jc.cap = 5, Target = 6;
//    printf("%d %d %d %d\n", Ja.cap, Jb.cap, Jc.cap, Target);
    init(Ja.val, Jb.val, Jc.val);
    //show(tail);
    
    if(!solve())
        printf("failed... No target %d got.\n", Target);
    
    system("pause");
    return 0;
}
