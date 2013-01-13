#include "lib/video.c"
#include "lib/io.c"
#include "lib/kbd.c"

int main( void )
{  
  char* vidmem = (char *) 0xb8000;
  char* str;
  int pos = 2;
  int line=0;
  vidmem[0] = '~';
  vidmem[1] = 0x7;
  for(;;)
  {
    str = gets(vidmem, pos);
    pos = typer(vidmem, pos, str);
    line++;
    pos = line*160;
    if(compare(str, "greet")){pos = cmd_greet(vidmem, pos);line++;}
    if(line==15){
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

int compare(char* a, char* b){
  int c = 0;
  while(a[c] == b[c]){
      if(a[c] == '\0' || b[c] == '\0') break;
      c++;
    }
  if(a[c] == '\0' && b[c] == '\0')
    return 1;
  else
    return 0;
}