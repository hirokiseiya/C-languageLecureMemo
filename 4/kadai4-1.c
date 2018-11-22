#include <stdio.h>

int main(void) {
  char str[] = "apple";
  char* x = (char*)&str;
  printf("char str[] = \"apple\";としたとき、\n");
  printf("%c = %p\n", *x, x); x++;
  printf("%c = %p\n", *x, x); x++;
  printf("%c = %p\n", *x, x); x++;
  printf("%c = %p\n", *x, x); x++;
  printf("%c = %p\n", *x, x); x++;
  printf("したがって、文字列の各文字は、連続したメモリ領域に記録されている。\n");
  printf("また、strのアドレスは、%p\n", str);
  printf("したがって、strのアドレスと格納されているアドレスは同じ所から始まる\n");
  return 0;
}
