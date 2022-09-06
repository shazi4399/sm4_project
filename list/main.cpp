//
// Created by zhanghao on 22-9-4.
//
#inlcude <iostream>
using namespace std;

//head 表示头节点的下标
//e[i] 表示节点的i的next指针是多少；
int head,e[N],ne[N],idx;

void init(){
    head = -1;
    idx = 0;
}

void add_to_head(int x){
    e[idx] = x;
    ne[idx] = head;
    head = idx ++;
}

void add(int k,int x){
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx ++;
}

void remove(int k){
    ne[k] = ne[ne[k]];
}

int main(){
    int k ,x ;
    char op;

    cin >> op;
    if(op == 'H'){
        cin >> x;
        add_to_head(x);
    }else if(op == 'D'){
        cin >> k;
        if(!k) head = ne[head]; //删除头节点
        else remove(k-1);
    }if(s == 'I'){
        int k,x;
        cin >> k>> x;
        add(k-1,x);
    }
    return 0;
}


int main(){

}