/*
 * mm_alloc.h
 *
 * A clone of the interface documented in "man 3 malloc".
 */

//#pragma once

#include <stdlib.h>

//GENERAL STRUCTURE FOR BLOCKS ALLOCATED AND DEALLOCATED
struct block{
 size_t size; //size of the block
 int free; //flag for if block is free  = 1 , or not = 0 ; 
 struct block *next; //pointer to the next block
 struct block *prev;
 void *ptr;
};

struct block* extend_heap (struct block *last_block  , size_t size ) ;
struct block * find_a_block(struct block **last , size_t size );
void print_Blocks(struct block *current)  ;
void combine(struct block *block1);
struct block *validation(void *ptr, struct block **last);
extern void split(struct block *fitting_slot,size_t size);
extern void *mm_malloc(size_t size);
extern void *mm_realloc(void *ptr, size_t size);
extern void mm_free(void *ptr);
