// bee 2666 - Imposto Real
// Alonso Martins
// 08/07/2024
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_CITIES 10002

int max_capacity;

typedef struct City
{
    int id;
    int gold;
    int num_childs;
    int capacity;
    struct City **next_city;
    int *dist;  // distance to next city in each index
} City;

void add_child(City *parent, City *child, int distance)
{
    if (parent->num_childs == parent->capacity)
    {
        parent->capacity *= 2;
        parent->next_city = realloc(parent->next_city, parent->capacity * sizeof(City *));
        parent->dist = realloc(parent->dist, parent->capacity * sizeof(int));
    }
    parent->next_city[parent->num_childs] = child;
    parent->dist[parent->num_childs] = distance;
    parent->num_childs++;
}

int collect_gold(City *city, City *parent, int dist_parent, int rank)
{
    int i, dist = 0, trips;

    for (i = 0; i < city->num_childs; i ++)
        if (city->next_city[i] != parent)
            dist += collect_gold(city->next_city[i], city, city->dist[i], rank + 2);

    if (parent != NULL)
    {
        parent->gold += city->gold;
        trips = (int)ceil(1.0 * city->gold / max_capacity);
        dist += 2 * dist_parent * trips;
    }

    return dist;
}

int main()
{
    int N, i, j, p, q, d, ans, totalgold = 0;
    scanf("%d %d", &N, &max_capacity);

    City cities[N + 1];
    for (i = 1; i <= N; i ++)
    {
        cities[i].id = i;
        cities[i].num_childs = 0;
        cities[i].capacity = 4;
        cities[i].next_city = (City **)malloc(4 * sizeof(City *));
        cities[i].dist = (int *)malloc(4 * sizeof(int));
    }

    for (i = 1; i <= N; i ++)
    {
        scanf("%d", &cities[i].gold);
    }

    for (i = 0; i < N - 1; i ++)
    {
        scanf("%d %d %d", &p, &q, &d);
        add_child(&cities[p], &cities[q], d);
        add_child(&cities[q], &cities[p], d);
    }

    ans = collect_gold(&cities[1], NULL, 0, 1);

    printf("%d\n", ans);

    for (int i = 1; i <= N; i++)
    {
        free(cities[i].next_city);
        free(cities[i].dist);
    }

    return 0;
}
