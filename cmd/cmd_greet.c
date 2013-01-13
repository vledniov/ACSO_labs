int cmd_greet (char* vidmem, int pos) {
  pos = puts(vidmem, "Hello World!", pos);
  return pos;
}