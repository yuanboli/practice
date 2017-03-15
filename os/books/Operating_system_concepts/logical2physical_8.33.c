#include <stdio.h>
unsigned parse_unsigned(char* str){
	unsigned result = 0;
	for(int i; str[i] != '\0'; i++){
		result = result * 10 + (int)str[i] - '0';
	}
	return result;
}


int main(int argc, char* argv[]){
	unsigned virtual_address;
	virtual_address = parse_unsigned(argv[1]);
	unsigned page_num = virtual_address / 0x2000;
	unsigned offset = virtual_address - page_num * 0x2000;
	printf("The address %u contains:\n", virtual_address);
	printf("page number = %u\n", page_num);
	printf("offset = %u\n", offset);
	return 0;
}
