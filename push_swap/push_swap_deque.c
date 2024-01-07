#include "push_swap.h"

void    init_deque(t_deque *dq)
{
    dq->data = (element *)malloc(sizeof(element) * MAX_SIZE);
    dq->front = 0;
    dq->rear = 0;
}

boolean is_empty(t_deque *dq)
{
    return (dq->front == dq->rear);
}

boolean is_full(t_deque *dq)
{
    return ((dq->rear + 1) % MAX_SIZE == dq->front);
}

element get_front(t_deque *dq)
{
    if (is_empty(dq))
    {
        printf("This t_deque is empty");
        return (ERROR);
    }
    return (dq->data[(dq->front + 1) % MAX_SIZE]);
}

element get_rear(t_deque *dq)
{
    if (is_empty(dq))
    {
        printf("This t_deque is full");
        return (ERROR);
    }
    return (dq->data[dq->rear]);
}

void    push_front(t_deque *dq, int num)
{
    if (is_full(dq))
    {
        printf("que is full");
        return ;
    }
    dq->front = (dq->front - 1 + MAX_SIZE) % MAX_SIZE;
    dq->data[dq->front] = num;
}


void    push_rear(t_deque *dq, int num)
{
    if (is_full(dq))
    {
        printf("que is full");
        return ;
    }
    dq->rear = (dq->rear + 1) % MAX_SIZE;
    dq->data[dq->rear] = num;
}

element    pop_front(t_deque *dq)
{
    element tmp;

    if (is_empty(dq))
    {
        printf("que is empty");
        return (ERROR);
    }
    tmp = dq->data[(dq->front + 1) % MAX_SIZE];
    dq->front = (dq->front + 1) % MAX_SIZE;
    return (tmp);
}

element    pop_rear(t_deque *dq)
{
    element tmp;

    if (is_empty(dq))
    {
        printf("que is empty");
        return (ERROR);
    }
    tmp = dq->data[dq->rear];
    dq->rear = (dq->rear - 1 + MAX_SIZE) % MAX_SIZE;
    return (tmp);
}

void    print_dq(t_deque *dq)
{
    int i;

    i = dq->front;
    printf("t_deque(fornt = %d rear= %d)=", dq->front, dq->rear);
    if (is_empty(dq))
    {
        printf("que is empty");
        return ;
    }
    while (i != dq->rear)
    {
        printf("%d |", dq->data[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", dq->data[i]);
}

int main() {

    t_deque q;

 

    init_deque(&q);

    printf("# ADD FRONT\n\n");

    for (int i = 0; i < 3; i++) {

        push_front(&q, i);

        print_dq(&q);

    }

    printf("\n# DELETE REAR\n\n");

    for (int i = 0; i < 3; i++) {

        pop_rear(&q);

        print_dq(&q);

    }

 

    printf("\n# ADD REAR\n\n");

    for (int i = 0; i < 3; i++) {

        push_rear(&q, i);

        print_dq(&q);

    }

 

    printf("\n# DELETE FRONT\n\n");

    for (int i = 0; i < 3; i++) {

        pop_front(&q);

        print_dq(&q);

    }

 

    free(q.data);

 

    return 0;

}