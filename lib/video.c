void putc(unsigned char c, int i) {
  char* vidmem = (char*) 0xb8000;
  vidmem[i] = c;
  vidmem[i] = 0x07;
  i+=2;
}