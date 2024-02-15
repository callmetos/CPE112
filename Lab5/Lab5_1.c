//66070503413 Channathat Ueanapaphon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

typedef struct 
{
    char name[50];
    char artist[50];
    int time;
} Song;

typedef struct 
{
    Song queue[MAX];
    int front;
    int rear;
} Queue;

void insertQ(Queue *q, Song s) {
    if ((q->rear + 1) % MAX == q->front) {
        printf("Queue is full\n");
        return;
    }

    if (q->front == -1) {
        q->front = 0;
    }

    q->rear = (q->rear + 1) % MAX;
    q->queue[q->rear] = s;
}

Song deleteQ(Queue *q) {
    if (q->front == -1) {
        printf("No songs in the playlist\n");
        Song emptySong = {"", "", 0};
        return emptySong;
    }

    Song s = q->queue[q->front];

    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }

    printf("Now playing: %s by %s\n", s.name, s.artist);
    return s;
}

void showQ(Queue *q) {
    if (q->front == -1) {
        printf("No songs in the playlist\n");
        return;
    }

    printf("Songs in the playlist:\n");
    int i = q->front;
    int total_time = 0;

    do {
        printf("%s by %s %d\n", q->queue[i].name, q->queue[i].artist, q->queue[i].time);
        total_time += q->queue[i].time;
        i = (i + 1) % MAX;
    } while (i != (q->rear + 1) % MAX);

    printf("Remaining Time: %d\n", total_time);
}

int main() {
    Queue q;
    q.front = -1;
    q.rear = -1;

    char cmd[50];
    Song s;

    while (1) {
        fgets(cmd, sizeof(cmd), stdin);
        cmd[strcspn(cmd, "\n")] = '\0';

        if (strcmp(cmd, "add") == 0) {
            fgets(s.name, sizeof(s.name), stdin);
            s.name[strcspn(s.name, "\n")] = '\0';
            fgets(s.artist, sizeof(s.artist), stdin);
            s.artist[strcspn(s.artist, "\n")] = '\0';
            scanf("%d", &s.time);
            getchar();
            insertQ(&q, s);
        } else if (strcmp(cmd, "play") == 0) {
            deleteQ(&q);
        } else if (strcmp(cmd, "sum") == 0) {
            showQ(&q);
            break;
        }
    }

    return 0;
}
