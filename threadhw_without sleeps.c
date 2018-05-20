#include <stdio.h>
#include <pthread.h>

struct Data {
	
	int fib;
	char string[10];
	
};


int fib(int n);
void *print(struct Data *d);



int main(int argc, char *argv[]){
	
	struct Data *d1ptr,*d2ptr,*d3ptr,*d4ptr, d1, d2, d3, d4;

	pthread_t thread1, thread2, thread3, thread4;
	
	d1ptr = &d1;
	d2ptr = &d2;
	d3ptr = &d3;
	d4ptr = &d4;

	strcpy(d1ptr->string,"Will");
	strcpy(d2ptr->string,"Luttmann");
	strcpy(d3ptr->string,"ESU");
	strcpy(d4ptr->string,"CPSC");
	
	d1ptr->fib = atoi(argv[1]); //atoi saves a string as int
	d2ptr->fib = atoi(argv[2]);
	d3ptr->fib = atoi(argv[3]);
	d4ptr->fib = atoi(argv[4]);
	

	pthread_create(&thread1, NULL, print, d1ptr);
	//sleep(2);
	pthread_create(&thread2, NULL, print, d2ptr);
	//sleep(2);
	pthread_create(&thread3, NULL, print, d3ptr);
	//sleep(2);
	pthread_create(&thread4, NULL, print, d4ptr);
	//sleep(2);
	
	//pthread_join(thread1, NULL);
	//pthread_join(thread2, NULL);
	//pthread_join(thread3, NULL);
	//pthread_join(thread4, NULL);

	//wastes time so main doesnt end before threads print


	printf("Waiting for main to end...\n");
	

	return 0;
}



int fib(int n) {
	
	if(n == 1)
		return 0;

	else if (n == 2)
		return 1;
	
	else
		return fib(n-1) + fib (n-2);

};

void *print(struct Data *d){
	int num;	
	
	printf("%s ", d->string);

	for(int i = 1; i <= d->fib;i++){
		num = fib(i);
		printf("%d ",num);	

	}
	
	printf("\n");
 	
};
