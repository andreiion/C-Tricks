#include <stdio.h>                                                                 
#include <string.h>                                                                
#include <stdlib.h>                                                                
                                                                                   
#ifdef DEBUG                                                                       
#define printDebug(fmt, ...) \                                                     
        do { \                                                                     
                fprintf(stderr, "DEBUG %s[%d] %s() " fmt "\n", __FILE__, __LINE__, __func__, ##__VA_ARGS__); \
        } while(0)                                                                 
#else                                                                              
#define printDebug(fmt, ...) do { } while(0)                                       
#endif
