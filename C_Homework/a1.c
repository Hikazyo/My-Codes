#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node{
    char c;
    struct Node *next, *pre;
};

typedef struct Node Node;

void insert(Node *cur,Node *n) {
    n->pre = cur;
    n->next = cur->next;
    Node *swap = cur->next;
    swap->pre = n;   
    cur->next = n;
}

int main(){
    Node *head = (Node *)malloc(sizeof(Node));
    Node *tail = (Node *)malloc(sizeof(Node));
    head->pre = NULL;
    head->next = tail;
    tail->pre = head;
    tail->next = NULL;

    Node *cur = head;
    bool check = true;

    char ch;
    while(~scanf("%c", &ch)){
        if(ch == '\n') continue;
        switch(ch){
            case ']'://行尾
                cur = tail->pre;
                break;
            case '['://行首
                cur = head;
                break;
            case '{'://左
                if(cur != head) cur = cur->pre;
                break;
            case '}'://右
                if(cur->next != tail) cur = cur->next;
                break;
            case '-'://改插入
                check = !check;
                break;
            case '='://回退
                if(cur != head){
                    Node *t = cur;
                    cur = t->pre;
                    cur->next = t->next;
                    Node *swap = t->next;
                    swap->pre = cur;
                    free(t);
                }
                break;
            default://Insert ch
                if(check || cur->next == tail){
                    Node *n = (Node *)malloc(sizeof(Node));
                    n->c = ch;
                    insert(cur, n);
                    cur = n;
                }
                else{
                    Node *t = cur->next;
                    t->c = ch;
                    cur = t; 
                }
                break;
        }

    }
    
    for(Node *p = head->next; p != tail; p = p->next)
        printf("%c", p->c);
    return 0;
}