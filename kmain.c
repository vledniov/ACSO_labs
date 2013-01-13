#include "lib/video.c"
#include "lib/io.c"
#include "lib/kbd.c"

int main( void )
{  
  char* vidmem = (char *) 0xb8000;
  char* str;
  int line=0;
  vidmem[0] = '~';
  vidmem[1] = 0x7;
  int pos = 2;
  for(;;)
  {
    str = gets(vidmem, pos);
    pos = typer(vidmem, pos, str);
    line++;
    pos = line*160;
    if(line==8){
      pos = clrscr(vidmem);
      line = 0;
      pos = typer(vidmem, pos, str);
    }

  }
  return 0;
}

int gets(char* vidmem, int position) {
  char* string;
  int i;
  char c;
  for(i=0;;i++){
    c = getchar();
    if (c == '\n') break;
    position = putc(vidmem, position, c);
    string[i] = c;
  }
  string[i] = '\0';
  return string;
}