int printf(const char*,...);
#define S "int printf(const char*,...);%c#define S %c%s%c%c#define DECL_MAIN() int main(void) {printf(S,10,34,S,34,10,10);}%cDECL_MAIN(/*WOW*/)"
#define DECL_MAIN() int main(void) {printf(S,10,34,S,34,10,10);}
DECL_MAIN(/*WOW*/)