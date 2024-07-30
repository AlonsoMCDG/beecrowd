// bee 1855 - Mapa do Meistre
// Alonso Martins
// 29/07/2024
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct Pair
{
    int x;
    int y;
} Pair;

enum directions
{
    STOP,
    RIGHT,
    DOWN,
    UP,
    LEFT
};

bool is_valid_position(Pair pos, int W, int H)
{
    return 0 <= pos.x && pos.x < W && 0 <= pos.y && pos.y < H;
}

int get_direction(char c)
{
    return (4 + (c % 5)) % 5;
}

int main()
{
    int width, height, i, j;
    char map[100][102];
    char symbols[] = ".>v^<";
    Pair directions_values[] = {
        {.x =  0, .y =  0}, // STOP
        {.x = +1, .y =  0}, // RIGHT
        {.x =  0, .y = +1}, // DOWN
        {.x =  0, .y = -1}, // UP
        {.x = -1, .y =  0}  // LEFT
    };

    scanf("%d %d", &width, &height);

    for (i = 0; i < height; i ++)
    {
        scanf(" %s", map[i]);
    }

    bool visited[100][100] = {};
    bool is_valid_map = false;
    Pair curr_pos = {.x = 0, .y = 0};
    int moving_direction = STOP;

    while (is_valid_position(curr_pos, width, height) && !visited[curr_pos.y][curr_pos.x])
    {
        if (map[curr_pos.y][curr_pos.x] == '*') // chegou no bau
        {
            is_valid_map = true;
            break;
        }

        if (map[curr_pos.y][curr_pos.x] != '.') // eh uma celula de direcao
        {
            moving_direction = get_direction(map[curr_pos.y][curr_pos.x]);
            visited[curr_pos.y][curr_pos.x] = true;
        }

        if (moving_direction == STOP) // nao saiu do inicio
            break;
        
        curr_pos.x += directions_values[moving_direction].x;
        curr_pos.y += directions_values[moving_direction].y;
    }

    printf("%c\n", is_valid_map ? '*' : '!');

    return 0;
}
