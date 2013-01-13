void putc (char* vidmem, int pos, char c)
{
  vidmem[pos] = c;
  vidmem[pos+1] = 0x7;
}

void puts (char* vidmem, int pos)
{
  int i;
  char* str;
  if (pos > 320){
    for (i=320; i<=pos; i++)
    {
      str[i] = vidmem[i];
    }
    clrscr(vidmem, pos);
  }
  else {
    for (i=2; i<=pos; i++)
    {
      str[i] = vidmem[i];
    }
  }
  vidmem[0] = 'Y';
  vidmem[1] = 0x7;
  vidmem[2] = 'o';
  vidmem[3] = 0x7;
  vidmem[4] = 'u';
  vidmem[5] = 0x7;
  vidmem[6] = ' ';
  vidmem[7] = 0x7;
  vidmem[8] = 't';
  vidmem[9] = 0x7;
  vidmem[10] = 'y';
  vidmem[11] = 0x7;
  vidmem[12] = 'p';
  vidmem[13] = 0x7;
  vidmem[14] = 'e';
  vidmem[15] = 0x7;
  vidmem[16] = 'd';
  vidmem[17] = 0x7;
  vidmem[18] = ':';
  vidmem[19] = 0x7;
  vidmem[20] = ' ';
  vidmem[21] = 0x7;
  for (i=0; i<=pos-2; i++)
  {
    vidmem[i+20] = str[i];
  }
}

void clrscr(char* vidmem, int pos)
{
  int i;
  for(i=0;i<=pos;i+=2){
    vidmem[i] = 0;
    vidmem[i+1] = 0x7;
  }
}