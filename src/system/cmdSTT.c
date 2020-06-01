#include "cmdSTT.h"

void cmd_stt_init(void)
{
    cmd_add("stt_test", stt_test, "", 0);
    cmd_add("stt_test2", stt_test2, "%d %s", 2);
}

int stt_test(char* fmt, char* params, int nparams)
{
    printf("Hello World!\n");
    system("pwd");
    system("python3 ../sandbox/stt_test.py");
    return CMD_OK;
}

int stt_test2(char* fmt, char* params, int nparams)
{
    int num;
    char text[SCH_CMD_MAX_STR_PARAMS];
    if(params == NULL || sscanf(params, fmt, &num, text) != nparams)
        return CMD_ERROR;

    printf("num: %d\n", num);
    printf("text: %s\n", text);
    return CMD_OK;
}