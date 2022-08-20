/* Assignment 5
 * Operating Systems
 * Kinneret College on the Sea of Galilee
 * Semester 1 5781
 * 
 * Submitted by: (Add Student Names Here)
 *
 * mm_alloc.c
 *
 * Stub implementations of the mm_* routines.
 */

#include "mm_alloc.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h> 
#include <unistd.h> 
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

#define BLOCK_SIZE sizeof(struct block)

struct block head ; // the first root on linked list , he will have the mamory 20000 without the header . 
extern void * base = NULL;  // pointer to the head of the heap  


    
    //****************************************************  extend heap -(sbrk statement) - last block is the last pointer to break , we save it and then move the braek to another place ***************************************************************************
    
	struct block* extend_heap (struct block *last_block  , size_t size ) 
	{
		struct block* break1 ; 
		break1 = sbrk(0) ;  // pointer to current break now. 
		if(sbrk(BLOCK_SIZE + size ) == (void*) -1 )  // sbrk fail
		{
			//sbrk fail 
			return NULL; 
		}
		else
		{
			break1->size = size ;
			break1->next = NULL ;  
			break1->free = 0 ; 
		}
		
		if(last_block) // if last block not NULL , move the break to the new place 
		{
			last_block->next = break1;
		}
		
			return break1;  // return the pointer to the begining of the block ; 
	}
    
//*************************************************find a block - return where the break is after we found it ***************************************************
struct block * find_a_block(struct block **last , size_t size )
{
	struct block *break1 = base;
	while( break1 && !(break1->free && break1->size>=size)){
		*last=break1;
		break1=break1->next;
	}
	return break1;
	
}

///********************************************************print the linked list blocks *********************************************************************

void print_Blocks(struct block *current)  
{  	
	printf(YEL "---------------------------------------------------------------------\n" RESET );
    while(current != NULL){  
	
        printf("free = %d, size = %ld, current = %p, next-node = %p\n",  
                current->free, current->size, current, current->next);       
        current = current->next;  
    }  
    return ; 
}
//************************************************ split a block ****************************************************


//Making way for a new block allocation by splitting a free block i.e freeList using First Fit
void split(struct block *fitting_slot,size_t size){
    //printf("split start \n ");
	struct block *new; 
	new = ((char*)fitting_slot+ size+BLOCK_SIZE);
	new->free = 1;
	new->size = fitting_slot->size - size -BLOCK_SIZE; // minus sizeof(struct );
	new->next = fitting_slot->next;
	fitting_slot->free = 0;
	fitting_slot->next = new;
	fitting_slot->size=size;
	//printf("\nafter split\n"); 
	//print_Blocks(base); 
	
	
	//try one 
	/*
	
		if(new->next && new->next->free==1) 
	{
		combine(new);
	}
	
	if(fitting_slot && fitting_slot->free==1) // 
		combine(fitting_slot);
		
	//printf("\nblocks after combine : \n "); 
	//print_Blocks(base); 
	return;
	*/
  
}

///******************************************************** MALLOC *****************************************************************************************
/*
 * allocat new struct with the size you entered , return pointer to the struct 
 * 
 * */
void *mm_malloc(size_t size) {
    /* INSERT YOUR CODE HERE */
  //  printf("starting malloc \n ");
    struct block *b ;
    struct block *last ; 
    size_t s =size;
    if(size==0)
    return NULL; 
    
    if(base ==NULL ) // if the pointer is not null
    {
		b = extend_heap(NULL , s );
		if(!b) 
		 {
			 printf("you cant extend heap , return null\n"  ); 
			 return NULL ; 
		 }
		 
		 base=b;
		// print_Blocks(base) ; 
	}
	else 
	{
		//printf("the base is not null , find a block mataim begin \n");
		b=find_a_block(&last , s); 
		if(!b)
		{
			//printf("no block found , so we are tring to extent one to heap \n");
			b=extend_heap(last , s);
			if(!b)
			{
				//printf("no block found yet , you cant extend one , return null");
				return NULL ; 
			}
		}
		else
		{
			//printf("block is found !!! yayyy us ! you can use it now ! \n");
			if(b->size - s >= sizeof(struct block)+4)
			{
			//	printf("he is very big one , you need to split it to two structs , split beginning \n ");
				split(b,s);
			}
			//printf("the struct we fount is exacly what we need , we make it not free any more \n");
			b->free= 0 ; 
		}
		
		//printf("there is a block found : \n size = %d , free=  %d , next = %p , prev = %p \n", b->size , b->free , b->next, b->prev );
	 
	
		
	}	
	//print_Blocks(base ) ; 
	
	
	return memset((int*)b , 0, size);   //(void*) ((char*) b + BLOCK_SIZE);

}
    
    
 

///*********************************************************************************************************************************************************************

	/*This is to merge / combine  the consecutive free blocks . he get value of pointer to the begining of the struct .  This will save space.*/
void combine(struct block *block1){
	printf("starting combine \n");
	
	block1->size = block1->size  + block1->next->size + BLOCK_SIZE; 
	block1->next = block1->next->next;
	return;
	}



///********************************************************************************************************************************************************************
/*
 * Validating the input pointer (is it realy a malloc’ed pointer ?)
• Finding the meta-data pointer
 * 
 * */
struct block *validation(void *ptr, struct block **last)
{
	//printf("validation adress begin \n");
	if(base){
		void *breakp = sbrk(0); //the current address 
		
		//Your function should do nothing if passed a pointer that doesn’t point to an area you allocated. - YOU ASK 
		if(!(ptr>base && ptr<breakp)) 
		{
		printf(" ptr dose not exist (from validation func ) \n");
			return NULL;
		}
		struct block *b = base; //pointer to the base struct 
		*last=NULL;
		while(b && (void*)b<breakp && (void*)b<ptr)
		{  
			if((char*)b+BLOCK_SIZE==ptr)
				return b; 
			*last=b;
			b=b->next;
		}
		return NULL;
	}
	return NULL;
}



///********************************************************************************************************************************************************************
void *mm_realloc(void *old_struct, size_t size)
{
	//printf("mm_realloc begin \n");
	
    struct block *last ;
   size_t s = size ; 
   
  //mm_realloc(ptr, 0) is equivalent to calling mm free(ptr). In this case, free the block and return NULL.
   if(size==0)
   {
	   mm_free(old_struct); 
	   return NULL ; 
   } 
   
   
   if(!old_struct) //mm_relloc(NULL, n) for example 
		return (mm_malloc(size));  // return null if you cant allocate the new requesr size , Return the pointer to the newly allocated area
		    
	struct block *b= validation(old_struct , &last);
	
	if(!b)
	{
		return NULL; 
	}
	
//Make sure to handle the case where size is less than the original size or equal to the original size. In
//both cases, you don’t need to move the block, you can just modify the block metadata in place.

	if (b->size >= size)
	{
		if(b->size > size+BLOCK_SIZE + 4)  //if(b->size > s+sizeof(struct block)+4 )  //mm_realloc(ptr--400  , 50 );  
		{
			split(b,size); 
			//print_Blocks(base);
		}
		return old_struct; //dosent do nothing 
	}
	//b->size < size we ask for : for example mm_realloc (ptr ---700 , 800); 
	void *new_struct = mm_malloc (s);
	//print_Blocks(base);
	
	//if(!new_struct)
		//return NULL ;
		
	
	
	//if there is place to size struct 
	size_t i,place_on_struct ,*old_pointer,*new_pointer;
	place_on_struct=s/(sizeof(size_t)); // 400/8 = 60 -->it means there is 60 places to size t on our new struct 
	old_pointer=(size_t*)(old_struct); //pointer  size t , on the first sruct we get (ptr)
	new_pointer=(size_t*)(new_struct);//pointer to the start of the new struct we made 
	
	//copy from the old struct to the new and bigger struct , and then free the old one 
	
	for(i=0 ; i < place_on_struct ; i++)
	{
		new_pointer[i]=old_pointer[i];
	}
	
	
	for(int i =0 ; i< place_on_struct ; i++)
	{
	//	printf("%d " , new_pointer[i]); 
	}
	
	
	
	mm_free(old_struct); //free the old struct 
	//print_Blocks(base);
	return new_struct;
}

///**************************************************************************************************************************************************************************



///**************************************************************************************************************************************************************************
void mm_free(void *ptr) {
	
   // printf("starting  free\n");
	struct block *last; // save the last pointer of struct 
	struct block *block1 = validation(ptr,&last);  //pointer to the start of block , we check if this pointer is invalid (pointer to data malloc ) , last is moveed by reference ! 
	if(!block1){
		return;
	}
	block1->free = 1;
	
	//printf("\nafter free ! \n"); 
	//print_Blocks(base); 
	

	
	/**************there are two free strut one after one ***********/

	if(block1->next && block1->next->free==1) 
	{
		combine(block1);
	}
	
	if(last && last->free==1) 
	{
		combine(last);
	}
	memset(&ptr , 0, block1->size);
	
	//print_Blocks(base); 
	return ; 
 

}



//*************************************************************************************************************************************************************************************


