#include "so_long_find_path_BFS.h"

t_queue *createQueue() {
    t_queue *q;

    q->front = NULL;
    q->rear = NULL;
    return (q);
}

void enqueue(t_queue *q, t_coordinate loc) {
    t_queue_node *newNode;

    newNode = malloc(sizeof(t_queue_node));
    if (newNode == NULL) {
        exit(1); // 메모리 할당 실패
    }
    newNode->loc = loc;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

t_coordinate dequeue(t_queue *q) {
    t_queue_node *temp;
    t_coordinate loc;

    if (q->front == NULL) {
        exit(EXIT_FAILURE); 
    }
    temp = q->front;
    loc = temp->loc;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return loc;
}

int is_queue_empty(t_queue *q) {
    return q->front == NULL;
}

void bfs_find_path(t_map *map, t_coordinate start) {
    t_queue *queue;
    t_coordinate current;

    queue = createQueue();
    enqueue(queue, start);
    while (!isEmpty(queue)) {
        current = dequeue(queue);

        // collectible을 찾았으면 수집
        if (map->map[current.y][current.x] == MAP_COLLECTIBLE) {
            map->map_elem->collectible--;
            // 모든 collectible을 수집했는지 확인
            if (map->map_elem->collectible == 0) {
                // 이후 로직 구현...
            }
        }

        // exit에 도달했는지 확인
        if (map->map[current.y][current.x] == MAP_EXIT && map->map_elem->collectible == 0) {
            // 경로 찾음
            break;
        }

        // 상하좌우 이동 가능 여부 확인 및 큐에 추가
        // 이 부분에서 MAP_WALL이 아니고 방문하지 않은 위치를 큐에 추가
    }
}
