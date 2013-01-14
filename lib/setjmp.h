#ifndef __setjmp_h__
// http://brickos.sourceforge.net/docs/APIs/html-c/setjmp_8h-source.html inspired from here

#define __setjmp_h__

#ifdef  __cplusplus
extern "C" {
#endif

typedef struct
{
    unsigned edi, esi, ebp, esp, ebx, edx, ecx, eax;
    unsigned eip, eflags;
} jmp_buf[1];




int setjmp(jmp_buf b);
void longjmp(jmp_buf b, int ret_val);

#ifdef  __cplusplus
}
#endif
#endif // __setjmp_h__
