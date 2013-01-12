void putc (char* vidmem, int pos, char c)
{
  vidmem[pos] = c;
  vidmem[pos+1] = 0x7;
  pos += 2;
}