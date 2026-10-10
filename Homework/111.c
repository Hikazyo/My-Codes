#include <stdio.h>
#include <stdlib.h>

typedef struct Node {          /* ① 用 typedef 给类型起名 Node */
    char c;
    struct Node *next, *pre;
} Node;

void insert(Node *cur, Node *n) {
    n->pre = cur;              /* ② 成员名统一成 pre */
    n->next = cur->next;
    cur->next->pre = n;
    cur->next = n;
}

int main(void) {
    Node *head = (Node *)malloc(sizeof(Node));
    Node *tail = (Node *)malloc(sizeof(Node));
    head->pre = NULL;
    head->next = tail;
    tail->pre = head;
    tail->next = NULL;

    Node *cur = head;
    int stu = 1;               /* 1 插入模式, 0 替换模式 */

    char ch;
    while (scanf("%c", &ch) == 1) {
        if (ch == '\n') continue;
        switch (ch) {
            case ']':          /* End */
                cur = tail->pre;
                break;         /* ③ 每个 case 都补上 break */
            case '[':          /* Home */
                cur = head;
                break;
            case '{':          /* ← */
                if (cur != head) cur = cur->pre;
                break;
            case '}':          /* → */
                if (cur->next != tail) cur = cur->next;
                break;
            case '-':          /* Insert */
                stu = !stu;
                break;
            case '=':          /* Backspace */
                if (cur != head) {
                    Node *t = cur;
                    cur = t->pre;
                    cur->next = t->next;
                    t->next->pre = cur;
                    free(t);
                }
                break;
            default:           /* ④ a-z 或空格 */
                if (stu || cur->next == tail) {   /* 文末退化为插入 */
                    Node *n = (Node *)malloc(sizeof(Node));
                    n->c = (char)ch;
                    insert(cur, n);
                    cur = n;
                } else {
                    cur->next->c = (char)ch;
                    cur = cur->next;
                }
        }
    }

    for (Node *p = head->next; p != tail; p = p->next)
        putchar(p->c);

    return 0;
}
