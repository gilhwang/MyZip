/**
 * @file minheap.h
 * @brief A Min heap implementation
 * @date 2026
 */

#pragma once

#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint32_t* arr;
    size_t size;
    size_t capacity;
} MinHeap;

/**
 * Iniitalize min heap
 * 
 * @param capacity The initial size of min heap array
 * @return Pointer to the initialized minheap on success. Otherwise NULL.
 */
MinHeap* minheap_init(size_t capacity);

/**
 * Insert new value to minheap
 * 
 * If capacity is reached, minheap array is automatically resized (doubled)
 * @param heap Pointer to the heap instance
 * @param value Value to be inserted
 * @return 0 if insert is success. Negative values otherwise.
 */
int minheap_push(MinHeap* heap, uint32_t value);


/**
 * Extract the smallest element
 * 
 * This operation will remove the smallest element from minheap
 * 
 * @param heap pointer to minheap
 * @return smallest element
 */
uint32_t minheap_pop(MinHeap* heap);

/**
 * Get smallest element
 * 
 * This operation does not remove the smallest element from minheap
 * @param heap pointer to minheap
 * @return smallest elemenet
 */
uint32_t minheap_get_min(MinHeap* heap);

/**
 * Clean up memory and destroy minheap
 * 
 * @param heap pointer to minheap
 */
void minheap_free(MinHeap* heap);