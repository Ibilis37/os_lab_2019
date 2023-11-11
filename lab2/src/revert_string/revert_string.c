#include "revert_string.h"
#include <string.h>
void RevertString(char* str)
{
        int len = strlen(str);
        char var;
        for(int i = 0; i<len/2; i++){
		var = str[i];
		str[i] = str[len-i-1];
                str[len-i-1]=var;
        }  
}
