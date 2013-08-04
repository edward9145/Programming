#include <stdio.h>

void hexdump(unsigned char* p, int c){
	int i;
	if(c<0) c = -c;

	while(1){
	   printf("%08x: ", (unsigned int)p);
	   for(i=0; i<16; i++){
	      if(i>=c) printf("   ");
	      else printf("%02x ", p[i]);
	   }
	   printf("    ");
	   for(i=0; i<16; i++){
	      if(i>=c) break;
	      if(p[i]<' ' || p[i]>'~') printf(".");
	      else printf("%c", p[i]);
	   }
	   printf("\n");
	   p += 16;
	   c -= 16;
	   if(c<=0) break;
	}
}

int main(){
	unsigned char ca[] = "*d%xyo!1x9#&";
	int ia[] = {21, 23, 14, 89, 21, 34};
	float fa[] = {2.8, 1.9, 8.3, 4.7, 5.9};

	hexdump(ca, sizeof(ca));
	hexdump((unsigned char *)ia, sizeof(ia));
	hexdump((unsigned char *)fa, sizeof(fa));

	return 0;
}
