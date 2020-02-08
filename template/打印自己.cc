#include <stdio.h>
char  ss[ 100 ];
char *q() {
    char *s =
        "char ss[100];%cchar* q(){%cchar*s=%c%s%c;%cprintf(ss,s,10,10,34,s,34,10);return ss;}";
    sprintf(ss, s, 10, 10, 34, s, 34, 10);
    return ss;
}

int main(int argc, char *avgv[]) {

    /*第一个参数就是指向要写入的那个字符串的指针，剩下的就和printf()一样了
    你可以比较一下，这是向屏幕输入*/
    std::cout << q();
    return 0;
}
