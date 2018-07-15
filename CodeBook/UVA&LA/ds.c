
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    double cof;
    int exp;
    struct node *next;
};

struct node *CreatePolyn(struct node *last) {
    int exp, n;
    double cof;
    scanf("%d", &n);
    struct node *ret = last;
    for (int i = 1; i <= n; i++) {
        scanf("%d %lf", &exp, &cof);
        struct node *cur = malloc(sizeof(struct node));
        last->next = cur, last = cur;
        cur->cof = cof, cur->exp = exp;
        cur->next = NULL;
    }
    return ret;
}

void PrintPolyn(struct node *head) {
    struct node *tmp = head->next;
    while (tmp) {
        if (tmp->cof == 0) continue;
        printf("%f*x^%d%c", tmp->cof, tmp->exp, (tmp->cof) < 0 ? '-' :'');
        tmp = tmp->next;
    }
    puts("");
}

void AddPolyn(struct node *head1, struct node *head2) {}

void Opposite(struct node *head) {}

void SubtractPolyn(struct node *head1, struct node *hea2d2) {}

void MultiplyPolyn(struct node *head1, struct node *head2) {}

void menu() {}

int main() {
    struct node *head1 = malloc(sizeof(struct node));
    struct node *head2 = malloc(sizeof(struct node));
    head1 = CreatePolyn(head1);
    head2 = CreatePolyn(head2);
    PrintPolyn(head1);
    PrintPolyn(head2);
    AddPolyn(head1, head2);
    PrintPolyn(head1);
    return 0;
}
