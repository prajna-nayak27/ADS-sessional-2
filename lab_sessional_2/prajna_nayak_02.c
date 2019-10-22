#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "heap_s2.h"


static void _heapify_ (struct air data[], uint32_t len, uint32_t parent) {
	assert (len > 0 && len < HEAP_MAX_SIZE && parent > 0 );

	uint32_t child = 2 * parent;

	while (child <= len) {
		if (child + 1 <= len) {
			if (data[child+1] > data[child]){
				++child;
			}
		}
		if (data[parent] >= data[child]) {
			break;
		}
		_swap_(&data[parent], &data[child]);
		parent = child;
		child = 2 * parent;
	}
}



static void _test_heap_(struct air data[], uint32_t len) {

	for (uint32_t child = len; child > 1; --child) {
		assert(data[child] <= data[child/2]);
	}

}


Heap 	heap_new(struct air data[], uint32_t len) {
	assert (len > 0 && len < HEAP_MAX_SIZE);

	Heap heap;
	uint32_t idx = len/2;
	for (idx = len/2; idx > 0; --idx) {
		_heapify_(data, len, idx);
	}
	heap.size = len;
	memcpy(heap.data, data, (len+1) * sizeof(int32_t));
	_test_heap_(heap.data, heap.size);

	return heap;
}

