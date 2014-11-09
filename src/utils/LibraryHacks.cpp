/*
 * LibraryHacks.cpp
 *
 *  Created on: 23 Jan 2011
 *      Author: Andy
 */

#include <cstdlib>
#include <sys/types.h>


/*
 * The default pulls in 70K of garbage
 */

namespace __gnu_cxx {

	void __verbose_terminate_handler() {
		for(;;);
	}
}


/*
 * The default pulls in about 12K of garbage
 */

extern "C" void __cxa_pure_virtual() {
	for(;;);
}


/*
 * Implement C++ new/delete operators using the heap
 */

void *operator new(size_t size) {
	return malloc(size);
}

void *operator new(size_t,void *ptr) {
	return ptr;
}

void *operator new[](size_t size) {
	return malloc(size);
}

void *operator new[](size_t,void *ptr) {
	return ptr;
}

void operator delete(void *p) {
	free(p);
}

void operator delete[](void *p) {
	free(p);
}


/*
 * EABI builds can generate reams of stack unwind code for system generated exceptions
 * e.g. (divide-by-zero). Since we don't support exceptions we'll wrap out these
 * symbols and save a lot of flash space.
 */

extern "C" void __wrap___aeabi_unwind_cpp_pr0() {}
extern "C" void __wrap___aeabi_unwind_cpp_pr1() {}
extern "C" void __wrap___aeabi_unwind_cpp_pr2() {}


/*
 * sbrk function for getting space for malloc and friends
 */

extern int  _end;

extern "C" {
	caddr_t _sbrk ( int incr ) {

		static unsigned char *heap = NULL;
		unsigned char *prev_heap;

		if (heap == NULL) {
			heap = (unsigned char *)&_end;
		}
		prev_heap = heap;
		/* check removed to show basic approach */

		heap += incr;

		return (caddr_t) prev_heap;
	}
}

void abort(void) {
	/* Abort called */
	while(1);
}


typedef void (*func_ptr)(void);

extern "C"{

extern func_ptr __init_array_start[0], __init_array_end[0];
extern func_ptr __fini_array_start[0], __fini_array_end[0];

void _init(void)
{
	for ( func_ptr* func = __init_array_start; func != __init_array_end && *func != 0x0; func++ )
		(*func)();
}

void _fini(void)
{
	for ( func_ptr* func = __fini_array_start; func != __fini_array_end; func++ )
		(*func)();
}

func_ptr _init_array_start[0] __attribute__ ((used, section(".init_array"), aligned(sizeof(func_ptr)))) = { };
func_ptr _fini_array_start[0] __attribute__ ((used, section(".fini_array"), aligned(sizeof(func_ptr)))) = { };

}

void* __dso_handle=0;
