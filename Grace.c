#include <stdio.h>
#define DECL_MAIN() int main(void) { printf(meta, 10, 10, 10, 34, meta, 34, 10, 10, 10, 10, 10); return 0; }

const char *meta = "#include <stdio.h>%c#define DECL_MAIN() int main(void) { printf(meta, 10, 10, 10, 34, meta, 34, 10, 10, 10, 10, 10); return 0; }%c%cconst char *meta = %c%s%c;%c%c/*%c  ANYWAY IT WORKS!%c*/%cDECL_MAIN()";

/*
  ANYWAY IT WORKS!
*/
DECL_MAIN()