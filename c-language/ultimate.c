#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
#include <stdbool.h>

#define MAX 1000000
#define THREAD_COUNT 8

bool is_prime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

typedef struct {
    int start;
    int end;
    int* primes;
    int* count;
    pthread_mutex_t* count_mutex;
} thread_data;

void* find_primes(void* arg) {
    thread_data* data = (thread_data*)arg;
    for (int i = data->start; i <= data->end; ++i) {
        if (is_prime(i)) {
            pthread_mutex_lock(data->count_mutex);
            data->primes[(*data->count)++] = i;
            pthread_mutex_unlock(data->count_mutex);
        }
    }
    return NULL;
}

int main() {
    int primes[MAX];
    int count = 0;
    pthread_t threads[THREAD_COUNT];
    pthread_mutex_t count_mutex;
    pthread_mutex_init(&count_mutex, NULL);
    thread_data t_data[THREAD_COUNT];

    int range = MAX / THREAD_COUNT;

    for (int i = 0; i < THREAD_COUNT; ++i) {
        t_data[i].start = i * range + 1;
        t_data[i].end = (i + 1) * range;
        t_data[i].primes = primes;
        t_data[i].count = &count;
        t_data[i].count_mutex = &count_mutex;
        pthread_create(&threads[i], NULL, find_primes, (void*)&t_data[i]);
    }

    for (int i = 0; i < THREAD_COUNT; ++i) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&count_mutex);

    printf("Found %d primes up to %d:\n", count, MAX);
    for (int i = 0; i < count; ++i) {
        printf("%d ", primes[i]);
    }
    printf("\n");

    return 0;
}
