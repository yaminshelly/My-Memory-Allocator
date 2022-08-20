/* Assignment 5
 * Operating Systems
 * Kinneret College on the Sea of Galilee
 * Semester 1 5781
 * 
 * Submitted by: (Add Student Names Here)
 *
 * mm_test.c
 *
 * Testing file for memory allocation and deallocation.
 */

#include <assert.h>
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include "mm_alloc.h"
#include <string.h>
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

void basic() {
	/* Perform basic tests.*/
	/* BEGIN: Remove the test below when you start to work */
	printf(YEL"\n*****************basic*********************** \n"RESET);
	printf(YEL"\n\n***  Allocates 100 bytes:   ***\n"RESET);
    int *data = (int*) mm_malloc(25 * sizeof(int));
    if(data==NULL ) printf("allocated fail/n ");
    else
    printf("allocation succseed !\n" ); 
    data[0]=9 ;
    data[6]=7;
    data[2]=4;
    
    
	for (int i=0 ; i<25 ; i++)
	{
		printf("%d , " , data[i] );
	}
    
    	
	printf(YEL"\n\n***   free the allocation :   ***\n"RESET);
    mm_free(data);
     printf("freed the data succsessful \n"); 
   


    printf(YEL"\n\n***   allocated 0 bytes :   ***\n"RESET);
	int *data2 = (int*)mm_malloc(0);  //DATA2 == NULL 
	if(data2 ==NULL)
	printf("allocated sucseed ");
	else
	printf("failed allocated "); 
	
	printf(YEL"\n\n***   Frees a non-existent pointer:   ***\n"RESET);
    mm_free(data2); // free(null) , just return , do nothing 
    
     printf(YEL"\n\n***   Reallocates from 0:   ***\n"RESET);
	 data2=  mm_realloc(data2,40); 
     if (data2 ==NULL) printf("failed "); 
     else
     printf("Reallocates from 0 succseed ");
  
     
     printf(YEL"\n\n***   Reallocates to 0:   ***\n"RESET);
    if (mm_realloc(data2,0)==NULL ) printf("realloc 0 return NULL , check complited "); 
    else
    printf("mm realloc failed "); 
     
     
    printf(YEL"\nmalloc test successful!\n"RESET);
    
    	return;
}


void secondTest() {
	
	printf(RED "\n---------------------------------------secondTest-----------------------------------------------------------\n" RESET );	
	printf("Allocation 10 times... \n");
printf(RED "\n--------------------------------------------------------------------------------------------------\n" RESET );	

	printf(RED " \n\nmalloc 100 begin : \n" RESET );
	int *a=(int*)mm_malloc(25*sizeof(int));
	if(a ==NULL) printf("Allocation failed !\n "); 
	else 
	{
	a[0]=1 ; 
	a[1] = 4 ; 
	a[2] =7 ; 
		for (int i=0 ; i<25 ; i++)
		{
			printf("%d , " ,a[i] );
		}
	printf(RED"\nallocated 100 bytes successfully"RESET); 
	}
	
printf(RED "\n------------------------------------------------------------------------------------------------\n" RESET );	
	printf(RED"\n\nmalloc 80 begin : \n"RESET);
	int *b=(int*)mm_malloc(20*sizeof(int));
	if(b ==NULL) printf("Allocation failed !\n "); 
	else{
		b[0]=1 ; 
		b[1] = 4 ; 
		b[2] =7 ; 
		for (int i=0 ; i<20 ; i++)
		{
			printf("%d , " ,b[i] );
		}
		printf(RED"\nallocated 80 bytes successfully"RESET); 
	}
	
printf(RED "\n-----------------------------------------------------------------------------------------------\n" RESET );	
	printf(RED"\n\nmalloc 200 begin : \n"RESET);
	int *c=(int*)mm_malloc(50 *sizeof(int));
	if(c ==NULL) printf("Allocation failed !\n "); 
	else
	{
	c[0]=1 ; 
	c[1] = 4 ; 
	c[2] =7 ; 
	c[3]=5;
		for (int i=0 ; i<50 ; i++)
		{
			printf("%d , " , c[i] );
		}
	printf(RED"\nallocated 200 bytes successfully"RESET); 
	}
	
printf(RED "\n-----------------------------------------------------------------------------------------------\n" RESET );		
	printf(RED"\n\nmalloc 30 begin : \n"RESET);
	int *D=(int*)mm_malloc(30 *sizeof(int));
	if(D ==NULL) printf("Allocation failed !\n "); 
	else
	{
		D[0]=1 ; 
		D[1] = 4 ; 
		D[2] =7 ; 
		for (int i=0 ; i<30 ; i++)
		{
			printf("%d , " ,D[i] );
		}
		printf(RED"\nallocated 30 bytes successfully"RESET); 
	}
	
printf(RED "\n---------------------------------------------------------------------------------------------\n" RESET );	
	printf(RED"\n\nmalloc 40 begin : \n" RESET);
	int *e=(int*)mm_malloc(10 *sizeof(int)); 
	if(e ==NULL) printf("Allocation failed !\n "); 
	else
	{
		e[0]=1 ; 
		e[1] = 4 ; 
		e[2] =7 ; 
		for (int i=0 ; i<10 ; i++)
		{
			printf("%d , " , e[i] );
		}
		printf(RED"\nallocated 40 bytes successfully"RESET);
	} 
printf(RED "\n---------------------------------------------------------------------------------------------\n" RESET );	
	printf(RED"\n\nmalloc 280 begin : \n"RESET);
	 int *f=(int*)mm_malloc(70 *sizeof(int)); 
	 if(f ==NULL) printf("Allocation failed !\n "); 
	else
	{
		f[0]=1 ; 
		f[1] = 4 ; 
		f[2] =7 ; 
	 	for (int i=0 ; i<70 ; i++)
		{
		printf("%d , " , f[i] );
		}
		printf(RED"\nallocated 280 bytes successfully"RESET); 
	}
printf(RED "\n------------------------------------------------------------------------------------------------\n" RESET );	
	printf(RED"\n\nmalloc 300 begin : \n"RESET);
	int *g=(int*)mm_malloc(75*sizeof(int)); 
	 if(g ==NULL) printf("Allocation failed !\n "); 
	else
	{
		g[0]=1 ; 
		g[1] = 4 ; 
		g[2] =7 ; 
		for (int i=0 ; i<75 ; i++)
		{
			printf("%d , " , g[i] );
		}
		printf(RED"\nallocated 300 bytes successfully"RESET); 
	}
printf(RED "\n-------------------------------------------------------------------------------------------------\n" RESET );	
	printf(RED"\n\nmalloc 384 begin : \n"RESET);
	int *h=(int*)mm_malloc(96*sizeof(int));
	 if(h ==NULL) printf("Allocation failed !\n "); 
	else
	{
		h[0]=1 ; 
		h[1] = 4 ; 
		h[2] =7 ; 
		for (int i=0 ; i<96 ; i++)
		{
			printf("%d , " , h[i] );
		}
		printf(RED"\nallocated 384 bytes successfully"RESET);
	} 
printf(RED "\n-------------------------------------------------------------------------------------------------\n" RESET );	
	printf(RED"\n\nmalloc 296 begin : \n"RESET);
	int *I=(int*)mm_malloc(74*sizeof(int)); 
	 if(I ==NULL) printf("Allocation failed !\n "); 
	else
	{
		I[0]=1 ; 
		I[1] = 4 ; 
		I[2] =7 ; 
		for (int i=0 ; i<74 ; i++)
		{
			printf("%d , " , I[i] );
		}
		printf(RED" \nallocated 296 bytes successfully"RESET); 
	}
printf(RED "\n-------------------------------------------------------------------------------------------------\n" RESET );	
	printf(RED"\n\nmalloc 212 begin : \n"RESET);
	int *j=(int*)mm_malloc(53*sizeof(int)); 
	 if(e ==NULL) printf("Allocation failed !\n "); 
	else
	{
		j[0]=1 ; 
		j[1] = 4 ; 
		j[2] =7 ;  
			for (int i=0 ; i<53 ; i++)
		{
			printf("%d , " , j[i] );
		}
		printf( RED "\n allocated 212 bytes successfully" RESET ); 
	}
printf(BLU "\n--------------------------------------------------------------------------------------------------\n" RESET );		
	
	
printf(BLU "\n-------------------------------------------------------------------------------------------------\n" RESET );		






/************************************************************************************************************************************************/	
	// 5 free 
printf("free 5 times... \n");
printf(BLU "\n------------------------------------------------------------------------------------------------\n" RESET );		
	printf(BLU"\n\nFREE(1) 200 begin: \n "RESET); 
	mm_free(c);
	memset(c , 0, (50 *sizeof(int)));
	
	
	printf(BLU"\nfreed 200 bytes successfully"RESET); 
printf(BLU "\n------------------------------------------------------------------------------------------------\n" RESET );		
	printf(BLU"\n\nFREE(2) 384 begin :  \n"RESET);
	mm_free(h);
	memset(h , 0, (96 *sizeof(int)));
	
	printf(BLU"\nfreed 384 bytes successfully"RESET); 
printf(BLU "\n-----------------------------------------------------------------------------------------------\n" RESET );			
	printf(BLU"\n\nFREE(3) 300 begin : \n"RESET);
	mm_free(g);
	memset(g , 0, (75 *sizeof(int)));
	
	printf(BLU"\nfreed 300 bytes successfully"RESET); 
printf(BLU "\n------------------------------------------------------------------------------------------------\n" RESET );		
	printf(BLU"\n\nFREE(4) 280 begin :  \n"RESET);
	mm_free(f);
	memset(f , 0, (70 *sizeof(int)));
	
	printf(BLU"\nfreed 280 bytes successfully"RESET); 
printf(BLU "\n-------------------------------------------------------------------------------------------------\n" RESET );			
	printf(BLU"\n\nFREE(5) 212 begin : \n"RESET);
	mm_free(j);
	memset(j , 0, (53 *sizeof(int)));
	
printf(BLU"\nfreed 212 bytes successfully"RESET); 
	
	
	
printf(BLU "\n------------------------------------------------------------------------------------------------\n" RESET );			
printf(GRN "--------------------------------------------------------------------------------------------------\n" RESET );	
/************************************************************************************************************************************************/	
printf(GRN "malloc again after free \n" RESET );		
printf(GRN "--------------------------------------------------------------------------------------------------\n" RESET );	

/************************************************************************************************************************************************/		
//malloc again after free
	c=(int*)mm_malloc(50 *sizeof(int));
	h=(int*)mm_malloc(96*sizeof(int));
	g=(int*)mm_malloc(75*sizeof(int)); 
	f=(int*)mm_malloc(70 *sizeof(int)); 
	j=(int*)mm_malloc(53*sizeof(int));  //After each allocation, perform reads and writes to the newly allocate space. After reallocation, check that contents are preserved.
/************************************************************************************************************************************************/	

//10 rellocation 
	printf("Reallocation 10 times... ");
	
	
printf( GRN "\n****realloc(1) begin from 100 to  200 :  ****\n"RESET);
		mm_realloc(a, 50*sizeof(int));
printf( GRN "\n reallocated 100 bytes to 200  bytes successfully)\n"RESET);	
printf(GRN "--------------------------------------------------------------------------------------------------\n" RESET );
printf( GRN "\n****realloc(2) begin from 80 to  100 :  ****\n"RESET);
		mm_realloc(b, 25*sizeof(int));
printf( GRN "\n reallocated 80 bytes to 100 bytes successfully)\n"RESET);	
printf(GRN "--------------------------------------------------------------------------------------------------\n" RESET );
printf( GRN "\n****realloc(3) begin from 200 to  100 :  ****\n"RESET);
		mm_realloc(c, 25*sizeof(int));
printf( GRN "\n reallocated 200 bytes to 100 bytes successfully)\n"RESET);
printf(GRN "--------------------------------------------------------------------------------------------------\n" RESET );
printf( GRN "\n****realloc(4) begin from 120 to  80 :  ****\n"RESET);
		mm_realloc(D, 20*sizeof(int));
printf( GRN "\n reallocated 120 bytes to 80 bytes successfully)\n"RESET);
printf(GRN "--------------------------------------------------------------------------------------------------\n" RESET );
printf( GRN "\n****realloc(5) begin from 40 to  100 :  ****\n"RESET);
		mm_realloc(e, 25*sizeof(int));
printf( GRN "\n reallocated 40 bytes to 100 bytes successfully)\n"RESET);
printf(GRN "--------------------------------------------------------------------------------------------------\n" RESET );
printf( GRN "\n****realloc(6) begin from 280 to  100 :  ****\n"RESET);
		mm_realloc(f, 25*sizeof(int));
printf( GRN "\n reallocated 280 bytes to 100 bytes successfully)\n"RESET);
printf(GRN "--------------------------------------------------------------------------------------------------\n" RESET );
printf( GRN "\n****realloc(7) begin from 300 to  320 :  ****\n"RESET);
		mm_realloc(g, 80*sizeof(int));
printf( GRN "\n reallocated 300 bytes to 300 bytes successfully)\n"RESET);
printf(GRN "--------------------------------------------------------------------------------------------------\n" RESET );
printf( GRN "\n****realloc(8) begin from 384 to  80 :  ****\n"RESET);
		mm_realloc(h, 20*sizeof(int));
printf( GRN "\n reallocated 300 bytes to 300 bytes successfully)\n"RESET);
printf(GRN "--------------------------------------------------------------------------------------------------\n" RESET );
printf( GRN "\n****realloc(9) begin from 296 to  100 :  ****\n"RESET);
		mm_realloc(I, 25*sizeof(int));
printf( GRN "\n reallocated 300 bytes to 300 bytes successfully)\n"RESET);
printf(GRN "--------------------------------------------------------------------------------------------------\n" RESET );
printf( GRN "\n****realloc(10) begin from 212 to  208 :  ****\n"RESET);
		mm_realloc(j, 52*sizeof(int));
printf( GRN "\n reallocated 212 bytes to 208 bytes successfully)\n"RESET);
printf(GRN "--------------------------------------------------------------------------------------------------\n" RESET );
	return ; 
}

void thirdTest() {
	
	printf(CYN"*****************************************third test ********************************"RESET);
	/* Do more tests here (see PDF).*/ 
	printf("\nAllocating 20 times\n");
	char* Array[20];
	for(int i =0 ; i < 20 ; i++)
	{
		Array[i] = mm_malloc(15);
		if(Array == NULL)
		printf(RED "\n%d fail allocation  !\n" , i+1 ,RESET); 
		else 
		printf( GRN "%d  allocated 15 bytes successfully\n" , i+1  ,RESET ); 
	}
	printf("Allocating is done ! \n");
printf(GRN "--------------------------------------------------------------------------------------------------\n" RESET );	

	printf("\nfree 5 times : \n  ");
	for (int i = 0; i < 5; i++)
	{
		mm_free(Array[i]);
		printf("%i free is done  \n", i);
	}
printf("5 free is done !!! \n");

printf(GRN "--------------------------------------------------------------------------------------------------\n" RESET );	
	printf(" 20 allocation \n"); 
	for(int i =0 ; i < 20 ; i++)
	{
		Array[i] = mm_malloc(15);
		if(Array == NULL)
		printf(RED "\n%d fail allocation  !\n" , i+1 ,RESET); 
		else 
		printf( GRN "%d  allocated 15 bytes successfully\n" , i+1  ,RESET ); 
	}
	printf(" 20 Allocating is done ! \n");
printf(GRN "--------------------------------------------------------------------------------------------------\n" RESET );		
	
	printf("Reallocating 20 times\n");
	for (int i = 0; i < 20; i++)
	{
		Array[i] = mm_realloc(Array[i], 150);
		if(Array[i] == NULL)
		printf("%d fail realocation\n", i+1); 
		else 
		printf("%d reallocated successfully\n" , i+1 ); 
		
	}
	printf("20 mm_reallocating done\n");
	
printf(GRN "--------------------------------------------------------------------------------------------------\n" RESET );	 
	
	printf("\nfree 15 times : \n  ");
	for (int i = 0; i < 15; i++)
	{
		mm_free(Array[i]);
		printf("%i free is done  \n", i);
	}
	printf("15 free is done !!! \n");
printf(GRN "--------------------------------------------------------------------------------------------------\n" RESET );	

		printf("allocation before realloc \n"); 
	for(int i =0 ; i <10  ; i++)
	{
		Array[i] = mm_malloc(20);
		if(Array == NULL)
		printf(RED "\n%d fail allocation  !\n" , i+1 ,RESET); 
		else 
		printf( GRN "%d  allocated 15 bytes successfully\n" , i+1  ,RESET ); 
	}
	printf("allocation 10 times\n");
	
	
	
	
	return;
}

void myTest (){
	//************************************************************** MY TEST  ***************************************************  
	
	printf(CYN "****************************************************my test: *************************************************** " RESET);
    printf(CYN"\nmalloc 100 begin : \n"RESET);
 int *z=(int*)mm_malloc(100*sizeof(int));
 if(z) printf("Allocation 400 bytes\n"); 
 else 
 printf("fail allocation\n");
 
     printf(CYN"\nmalloc 250 begin : \n"RESET);
 char *y=(char*)mm_malloc(250*sizeof(int));
  if(y) printf("Allocation 1000 bytes\n"); 
 else 
 printf("fail allocation\n");

 
     printf(CYN"\nmalloc 100 begin : \n"RESET);
 int *x=(int*)mm_malloc(40*sizeof(int));
   if(x) printf("Allocation 160 bytes\n"); 
 else 
 printf("fail allocation\n");
 

     printf(CYN"\nfree  100 begin : "RESET);
     mm_free(z);
     printf(CYN"\nfree  succseed : \n"RESET);
     
     printf(CYN"\nmalloc 60 begin : \n"RESET);
 char *w=(char*)mm_malloc(60*sizeof(int));
  if(w) printf("Allocation 400 bytes\n"); 
 else 
 printf("fail allocation\n");

 
 
     printf(CYN"\nmalloc 280 begin : \n"RESET);
 int *v=(int*)mm_malloc(70*sizeof(int)); //split 
  if(v) printf("Allocation 280 bytes\n"); 
 else 
 printf("fail allocation\n");
        
      printf(CYN"\nmalloc 25 begin : \n"RESET);
 int *u=(int*)mm_malloc(25*sizeof(int)); //split 
  if(u) printf("Allocation 400 bytes\n"); 
 else 
 printf("fail allocation\n");
 

 printf(CYN"\nmalloc 200 begin : \n"RESET);
  int *t=(int*)mm_malloc(50*sizeof(int)); //split 
   if(t) printf("Allocation 400 bytes\n"); 
 else 
 printf("fail allocation\n");
  
printf(CYN"\nrelloc 400 begin to 250  : \n"RESET);
 int *s = mm_realloc(NULL , 250); // if null it will alloct new struct if threr is  a place 
  if(s) printf("realloc to 250\n"); 
 else 
 printf("fail allocation\n");
 
 printf(CYN"\nrealloc 400 to 700  : \n"RESET);
 int *ll = mm_realloc(t , 700 );  //check for l = 900 , change to 700 so split 
  if(ll) printf("realloc to 700 ok\n"); 
 else 
 printf("fail allocation\n");
 
 int *r = mm_realloc(w , 800 ); // check for w= 700 , change to 800
   if(r) printf("realloc from 240  to 800 ok\n"); 
 else 
 printf("fail reallocation\n");
   

 



 
    // printf("\nmalloc test successful!\n");
	/* END: Remove the test above when you start to work */
	
	
}

int main() {
	basic();
	printf("\n**********************	secondTest() BEGINNING    ! ********************\n" )  ; 
	secondTest(); 
	thirdTest();
	myTest();
	/* Add more tests here*/
	return 0;	
}
