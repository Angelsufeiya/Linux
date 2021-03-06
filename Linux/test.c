// 操作共享变量会有问题的售票系统代码 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include <pthread.h>

int ticket = 100;

void *route(void *arg)
{
	while(1){
		if (ticket > 0) {
			// 如果有票就一直枪
			usleep(1000);
			printf("sell ticket:%d\n", ticket);
			ticket--;
		}
		else {
			pthread_exit(NULL);
		}
	}
}

int main(){
	pthread_t tid[4];
	int i, ret;

	for(i = 0; i < 4; i++){
		ret = pthread_create(&tid[i], NULL, route, NULL);
		if(ret != 0){
			printf("thread create error");
			return -1;
		}
	}

	for(i = 0; i < 4; i++){
		pthread_join(tid[i], NULL);
	}

	return 0;
}

