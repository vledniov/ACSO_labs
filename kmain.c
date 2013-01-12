#include "lib/video.c"
#include "lib/io.c"
#include "lib/kbd.c"

pos = 0;

int main( void )
{
  for(;;) putc(getchar(), pos);
}