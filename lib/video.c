//#include "kbd.c"

int i=0;
// 1 line 160
void setNewLine( ){
  i+=160-(i%160);
}

int getIndex(){
  return i;
}
void resetIndex(){
i=0;
}
int getLine(){
  int line;
  line =( i /160);
  return line;
}

void putc (char c) {
  char* vidmem = (char *) 0xb8000;
  vidmem[i] = c;
  i++;
  vidmem[i] = 0x7;
  i++;
}

void puts(char *c){
  int index =0;
  char* vidmem = (char*) 0xb8000;

 while(*c != '\0'){
 putc(*c);
 c++;
 }

}

void clrscr(){
 char* vidmem = (char *) 0xb8000;

  for(;i>=0;i--){
  vidmem[i] = ' ';
  
  i--;
  }
}

void downScroll(){
  char* vidmem = (char*) 0xb8000;
  int k=1;
  for(k; k<3860;k++){
    vidmem[k] = vidmem[(k+160)];
  }

}
