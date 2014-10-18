#include<stdio.h>
#include<stdlib.h>
#define NumberOf(action) 6
#define MAX_CAP 20
#define MAX_STATE 1000

typedef struct Jar{
    int cap;
    int val;
    int id; // 0->A, 1->B
}Jar;

typedef struct State{
    int ca, cb; // A,B存油量 
    int parent; // 父节点下标
    char* act;
}State;

Jar Ja, Jb;
State queue[MAX_STATE];
int tail, Target;
char *fill[] = {"Fill A", "Fill B"};
char *empty[] = {"Empty A", "Empty B"};
char *pour[] = {"A->B", "B->A"};
char *act_name;   // 当前操作名称 

int fill_a(), fill_b(), empty_a(), empty_b(), a_to_b(), b_to_a();

int (*action[])() = {
    fill_a, fill_b,
    empty_a, empty_b, 
    a_to_b, b_to_a
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

void init(){
    Ja.val = 0;
    Jb.val = 0;
    Ja.id = 0;
    Jb.id = 1;
    tail = 1;
    queue[0].ca = 0;
    queue[0].cb = 0;
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
    printf("%s\n", queue[n].act);
}

void setsit(int i){
    Ja.val = queue[i].ca;
    Jb.val = queue[i].cb;
}

int exist(){
    int i;
    for(i=0; i<tail; i++){
        if((queue[i].ca == Ja.val) 
            && (queue[i].cb == Jb.val))
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
        for(j=0;j<6;j++){
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
    printf("Ja.cap Jb.cap Target\n");
    scanf("%d %d %d", &Ja.cap, &Jb.cap, &Target);
    
    init();
    //show(tail);
    
    if(!solve())
        printf("failed... No target %d got.\n", Target);
    
    system("pause");
    return 0;
}
