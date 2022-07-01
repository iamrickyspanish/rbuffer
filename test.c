#include "inc/rbuffer.h"
#include <stdio.h>    

 int main() {
    	//cbuffer_t buff = cbuffer_create()
	printf("test rolling ring buffer\n\n");
	cbuffer buff = cbuffer_create(4, sizeof(int));
	printf("newly initialized buffer should have size 0\n\n");
	if(cbuffer_size(buff) != 0) {
		//printf("newly initialized buffer should have size 0");	
		return 1;
	}
	int a = 5;
	int b = 3;
	cbuffer_push(buff, &a);
	printf("buffer should have size 1 after push\n\n");
	if (cbuffer_size(buff) != 1) {
		return 1;
	}	

	printf("shift hould return 1st item");
	
	cbuffer_push(buff, &b);
	int x = 0;
	cbuffer_shift(buff, &x);
	if(x != a) {
		return 1;
	}
	return 0;
 } 
