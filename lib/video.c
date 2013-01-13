int putc (char* vidmem, int pos, char c)
{
  vidmem[pos] = c;
  vidmem[pos+1] = 0x7;
  return pos+2;
}

int puts (char* vidmem, char* str, int pos)
{
  int i=0;
  while(str[i] != '\0'){
    pos = putc(vidmem, pos, str[i]);
    i++;
  }
  return pos;
}

int clrscr(char* vidmem)
{
  int i;
  for(i=0;i<=1120;i+=2){
    vidmem[i] = 0;
    vidmem[i+1] = 0xF;
  }
  return 0;
}

int typer(char* vidmem, int pos, char* string){
  pos = puts(vidmem, "You typed: ", pos);
  pos = puts(vidmem, string, pos);
  return pos;
}