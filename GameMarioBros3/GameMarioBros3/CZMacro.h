//
// Created: 8/9/2017
// Created: Zero
// Function: define macro
//

#include <stdio.h>

#ifndef __CZMACRO_H__
#define __CZMACRO_H__

#define  Log(...)  { printf(__VA_ARGS__); printf("\n"); }

// Safely release pointer referenced item
#define SAFE_RELEASE(p) { if(p) { (p)->Release(); (p)=NULL; } }

// Safely delete pointer referenced item
#define SAFE_DELETE(p) { if(p) { delete(p); (p)=NULL; } }

//Find Max
#define MAX(a,b)			(((a) > (b)) ? (a) : (b))

//Find Min
#define MIN(a,b)            (((a) < (b)) ? (a) : (b))

#endif