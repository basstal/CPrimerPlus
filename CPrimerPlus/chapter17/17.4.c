/**
 * @file 17.4.c
 * @author your name (you@domain.com)
 * @brief
 * Rewrite mall.c ( Listing 17.9 ) so that it simulates a double booth having two queues.
 * @version 0.1
 * @date 2022-09-18
 *
 * @copyright Copyright (c) 2022
 *
 */
#define EX17_4
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue.h"

static void CopyToNode(Item item, Node *pn);
static void CopyToItem(Node *pn, Item *pi);

void InitializeQueue(Queue *pq)
{
    pq->front = pq->rear = NULL;
    pq->items = 0;
}

bool QueueIsFull(const Queue *pq)
{
    return pq->items == MAXQUEUE;
}

bool QueueIsEmpty(const Queue *pq)
{
    return pq->items == 0;
}

int QueueItemCount(const Queue *pq)
{
    return pq->items;
}

bool EnQueue(Item item, Queue *pq)
{
    Node *pnew;

    if (QueueIsFull(pq))
        return false;
    pnew = (Node *)malloc(sizeof(Node));
    if (pnew == NULL)
    {
        fprintf(stderr, "Unable to allocate memory!\n");
        exit(1);
    }
    CopyToNode(item, pnew);
    pnew->next = NULL;
    if (QueueIsEmpty(pq))
        pq->front = pnew;
    else
        pq->rear->next = pnew;
    pq->rear = pnew;
    pq->items++;
    return true;
}

bool DeQueue(Item *pitem, Queue *pq)
{
    Node *pt;

    if (QueueIsEmpty(pq))
        return false;
    CopyToItem(pq->front, pitem);
    pt = pq->front;
    pq->front = pq->front->next;
    free(pt);
    pq->items--;
    if (pq->items == 0)
        pq->rear = NULL;
    return true;
}

void EmptyTheQueue(Queue *pq)
{
    Item dummy;
    while (!QueueIsEmpty(pq))
        DeQueue(&dummy, pq);
}

static void CopyToNode(Item item, Node *pn)
{
    pn->item = item;
}

static void CopyToItem(Node *pn, Item *pi)
{
    *pi = pn->item;
}

// mall.c -- use the Queue interface
// compile with queue.c
#define MIN_PER_HR 60.0
bool newcustomer(double x);   // is there a new customer?
Item customertime(long when); // set customer parameters
int main(void)
{
    Queue line;
    Queue second_line;
    Item temp;                 // new customer data
    int hours;                 // hours of simulation
    int perhour;               // average # of arrivals per hour
    long cycle, cyclelimit;    // loop counter, limit
    long turnaways = 0;        // turned away by full queue
    long customers = 0;        // joined the queue
    long served = 0;           // served during the simulation
    long sum_line = 0;         // cumulative line length
    long sum_second_line = 0;  // cumulative second line length
    int wait_time = 0;         // time until Sigmund is free
    int second_wait_time = 0;  // time until the second line is free
    double min_per_cust;       // average time between arrivals
    long line_wait = 0;        // cumulative time in line
    long second_line_wait = 0; // cumulative time in second line
    InitializeQueue(&line);
    InitializeQueue(&second_line);
    srand((unsigned int)time(0)); // random initializing of rand()
    puts("Case Study: Sigmund Lander's Advice Booth");
    puts("Enter the number of simulation hours:");
    scanf("%d", &hours);
    cyclelimit = MIN_PER_HR * hours;
    puts("Enter the average number of customers per hour:");
    scanf("%d", &perhour);
    min_per_cust = MIN_PER_HR / perhour;
    for (cycle = 0; cycle < cyclelimit; cycle++)
    {
        if (newcustomer(min_per_cust))
        {
            if (QueueIsFull(&line) && QueueIsFull(&second_line))
                turnaways++;
            else
            {
                customers++;
                temp = customertime(cycle);
                EnQueue(temp, QueueIsFull(&second_line) ? &line : &second_line);
            }
        }
        if (wait_time <= 0 && !QueueIsEmpty(&line))
        {
            DeQueue(&temp, &line);
            wait_time = temp.processtime;
            line_wait += cycle - temp.arrive;
            served++;
        }
        if (wait_time > 0)
            wait_time--;
        sum_line += QueueItemCount(&line);
        if (second_wait_time <= 0 && !QueueIsEmpty(&second_line))
        {
            DeQueue(&temp, &second_line);
            second_wait_time = temp.processtime;
            second_line_wait += cycle - temp.arrive;
            served++;
        }
        if (second_wait_time > 0)
            second_wait_time--;
        sum_second_line += QueueItemCount(&second_line);
    }
    if (customers > 0)
    {
        printf("customers accepted: %ld\n", customers);
        printf(" customers served: %ld\n", served);
        printf(" turnaways: %ld\n", turnaways);
        printf("average queue size: %.2f\n",
               (double)(sum_line + sum_second_line) / cyclelimit);
        printf(" average wait time: %.2f minutes\n",
               (double)(line_wait + second_line_wait) / served);
    }
    else
        puts("No customers!");
    EmptyTheQueue(&line);
    EmptyTheQueue(&second_line);
    puts("Bye!");
    return 0;
}
// x = average time, in minutes, between customers
// return value is true if customer shows up this minute
bool newcustomer(double x)
{
    if (rand() * x / RAND_MAX < 1)
        return true;
    else
        return false;
}
// when is the time at which the customer arrives
// function returns an Item structure with the arrival time
// set to when and the processing time set to a random value
// in the range 1 - 3
Item customertime(long when)
{
    Item cust;
    cust.processtime = rand() % 3 + 1;
    cust.arrive = when;
    return cust;
}