int main(void) {
	int d = 1633837924;
	printf("d(16) = %x\n",d);
	char* x = (char*)&d;
	printf("&d = %p\n",&d);
	printf("%p = %c\n", x, *x); x++;
	printf("%p = %c\n", x, *x); x++;
	printf("%p = %c\n", x, *x); x++;
	printf("%p = %c\n", x, *x);
	//printf("%p\n", c);
	//printf("%p\n", d);
	return 0;
}
