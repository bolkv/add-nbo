#include <arpa/inet.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>



uint32_t reading(char* stream){
	
	FILE*fp = fopen(stream,"r");
	if(!fp){
		printf("Failed to open file\n");
		exit(EXIT_FAILURE);
	}

	uint32_t p;
	size_t size = fread(&p, sizeof(char), 4, fp);
       	
	if(size < 4){
		printf("File size is smaller than 4bytes \n");
		fclose(fp);
		exit(EXIT_FAILURE);	
	}

	fclose(fp);
	return htonl(p);

}

void print_answer(uint32_t n1, uint32_t n2){
	uint32_t sum = n1 + n2;
	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n",n1,n1,n2,n2,sum,sum);
}

void solve(char* stream1, char* stream2){
	uint32_t n1 = reading(stream1);
	uint32_t n2 = reading(stream2);
	
	print_answer(n1,n2);
       		
}

int main(int argc, char*argv[]){
	if(argc !=3){
		printf("Execution eError: ./add-nbo <file1> <file2> \n");
		exit(EXIT_FAILURE);
	}

	solve(argv[1],argv[2]);
	return 0;

}
