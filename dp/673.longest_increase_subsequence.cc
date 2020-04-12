char *q() {
    char s[40];
    // char *t = "%cchar* q(){%cchar*s=%c%s%c;%cprintf(s,10,10,34,s,34,10);return s;}";
    // char *t = "%s%s";
    sprintf(s, "%s%c", "abc", 10);
    return s;
}

int main() {
    std::cout << "res:" << q() << std::endl;
    return 0;
}
