#include <stdio.h>
struct Item
{
    int x;
    int y;
};

struct Polymaial
{
    struct Item item[50];
    int count;
} polynomial;

void show(struct Polymaial *p)
{
    int i;
    for (i = 0; i < p->count; i++)
    {
        printf("%d^%d+", p->item[i].x, p->item[i].y);
    }
    printf("\n");
}

void sort(struct Polymaial *p)
{
    for (int i = 1; i < p->count; i++)
    {
        int x1 = p->item[i].x;
        int x2 = p->item[i].y;
        int k = i - 1;
        while (k >= 0 && x2 > p->item[k].y)
        {
            p->item[k + 1].x = p->item[k].x;
            p->item[k + 1].y = p->item[k].y;
            k--;
        }
        p->item[k + 1].x = x1;
        p->item[k + 1].y = x2;
    }
}

void add(struct Polymaial *p)
{
    sort(p);
    int gs = 0;
    int k, s;
    for (int i = 0; i < p->count; i++)
    {
        k = i + 1;
        s = p->item[i].x;
        while (k < p->count && (p->item[i].y == p->item[k].y))
        {
            s = s + p->item[k].x;
            k++;
        }
        p->item[gs].x = s;
        p->item[gs].y = p->item[i].y;
        gs++;
        i = k - 1;
    }
    p->count = gs;
}

int main(void)
{
    int n, i;
    scanf("%d", &n);
    polynomial.count = n / 2;
    for (i = 0; i < n / 2; i++)
    {
        scanf("%d%d", &polynomial.item[i].x, &polynomial.item[i].y);
    }
    scanf("%d", &n);
    for (i = polynomial.count; i < polynomial.count + n / 2; i++)
    {
        scanf("%d%d", &polynomial.item[i].x, &polynomial.item[i].y);
    }
    polynomial.count += (n / 2);
    add(&polynomial);
    show(&polynomial);
    return 0;
}