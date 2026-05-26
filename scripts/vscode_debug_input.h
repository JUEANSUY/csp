#ifdef LOCAL_INPUT
#include <stdio.h>

#if defined(__GNUC__)
static void codex_redirect_stdin(void) __attribute__((constructor));
#endif

static void codex_redirect_stdin(void) {
    FILE *fp = fopen("input.txt", "r");
    if (fp != NULL) {
        fclose(fp);
        freopen("input.txt", "r", stdin);
    }
}
#endif
