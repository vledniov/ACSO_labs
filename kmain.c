#include "lib/video.c"
#include "lib/io.c"
#include "lib/kbd.c"

int pos = 2;

int main( void )
{  
  char* vidmem = (char *) 0xb8000;
  vidmem[0] = '~';
  vidmem[1] = 0x7;
  for(;;) putc(vidmem, pos+=2, getchar());
}