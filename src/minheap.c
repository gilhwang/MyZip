#include "mzip/minheap.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Macros
#define MINHEAP_PARENT(pos) ( (pos-1) / 2 ) 
#define MINHEAP_LEFT(pos) ( 2*pos + 1 )
#define MINHEAP_RIGHT(pos) ( 2*pos + 2 )

// Error codes
#define MINHEAP_SUCCESS_CODE 0
#define MINHEAP_ERROR_MEMORY -1
#define MINHEAP_ERROR_EMPTY -2
#define MINHEAP_ERROR_NULL -3
 
/**
 * Swap values of two integers
 */
static void swap(uint32_t* first, uint32_t* second) 
{
    uint32_t temp = *first;
    *first = *second;
    *second = temp;
}

/**
 * Return the largest element among three
 */
static size_t get_min(MinHeap* heap, size_t a, size_t b, size_t c)
{
    size_t smallest = c;
    if (a < heap->size && heap->arr[a] < heap->arr[smallest]) {
        smallest = a;
    }
    if (b < heap->size && heap->arr[b] < heap->arr[smallest]) {
        smallest = b;
    }

    return smallest;
}

/**
 * Heapify a given heap into Min-heap
 */
static void minheap_heapify(MinHeap* heap, size_t i)
{
    size_t left = MINHEAP_LEFT(i);
    size_t right = MINHEAP_RIGHT(i);
    size_t smallest = get_min(heap, left, right, i);

    if (smallest != i) {
        swap(&heap->arr[i], &heap->arr[smallest]);
        minheap_heapify(heap, smallest);
    }
}


MinHeap* minheap_init(size_t capacity)
{
    // Minheap 
    MinHeap* heap = (MinHeap*) malloc(sizeof(MinHeap));
    if (heap == NULL) {
        fprintf(stderr, "Failed to allocate memory for minheap");
        return NULL;
    }

    // Element array
    heap->arr = (uint32_t*) malloc(capacity * sizeof(uint32_t));
    if (heap->arr == NULL) {
        fprintf(stderr, "Failed to allocate memory for minheap array");
        free(heap);
        return NULL;
    }

    // Parameters
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

int minheap_push(MinHeap* heap, uint32_t value)
{
    // Invalid heap
    if (heap == NULL) {
        return MINHEAP_ERROR_NULL;
    }

    // Resize array if needed
    if (heap->size == heap->capacity) {
        size_t new_capacity = (heap->capacity == 0) ? 1 : heap->capacity * 2;
        uint32_t* tempArr = realloc(heap->arr, new_capacity * sizeof(uint32_t));
        if (tempArr == NULL) {
            return MINHEAP_ERROR_MEMORY;
        }

        heap->arr = tempArr;
        heap->capacity = new_capacity;
    }

    // Insert new element
    size_t i = heap->size++;
    heap->arr[i] = value;
    while (i != 0 && heap->arr[MINHEAP_PARENT(i)] > heap->arr[i]) {
        swap(&heap->arr[i], &heap->arr[MINHEAP_PARENT(i)]);
        i = MINHEAP_PARENT(i);
    }
}

uint32_t minheap_pop(MinHeap* heap)
{
    if (heap == NULL) {
        return MINHEAP_ERROR_NULL;
    }
    if (heap->size == 0) {
        return MINHEAP_ERROR_EMPTY;
    }

    uint32_t minVal = heap->arr[0];
    if (heap->size > 1) {
        heap->arr[0] = heap->arr[heap->size - 1];
        heap->size--;
        minheap_heapify(heap, 0);
    }
    else {
        heap->size = 0;
    }
}

uint32_t minheap_get_min(MinHeap* heap)
{
    if (heap == NULL) {
        return MINHEAP_ERROR_NULL;
    }
    if (heap->size == 0) {
        return MINHEAP_ERROR_EMPTY;
    }

    return heap->arr[0];
}

void minheap_free(MinHeap* heap)
{
    if (heap) {
        free(heap->arr);
        free(heap);
    }
}