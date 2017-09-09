// CMain
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include "CZMain.h"

int main()
{
	Example *game = new Example();
	game->Run();
	delete game;

	_CrtDumpMemoryLeaks();
	while (true);
	return 0;
}

	/*

	Detected memory leaks!
	Dumping objects ->
	C:\PROGRAM FILES\VISUAL STUDIO\MyProjects\leaktest\leaktest.cpp(20) : {18}
	normal block at 0x00780E80, 64 bytes long.
	Data: <                > CD CD CD CD CD CD CD CD CD CD CD CD CD CD CD CD
	Object dump complete.

	– “C:\PROGRAM FILES\VISUAL STUDIO\MyProjects\leaktest\leaktest.cpp” là đường dẫn của file có memory leak.
	– (20) là dòng thứ 20 trong source code có memory leak.
	– {18} là vị trí của memory.
	– Nếu bạn không sử dụng câu lệnh #define _CRTDBG_MAP_ALLOC, format của thông tin memory leak như sau:

	Goto tới dòng code cấp phát bộ nhớ
	– Double click chuột vào dòng “C:\PROGRAM FILES\VISUAL STUDIO\MyProjects\leaktest\leaktest.cpp(20) : {18}” trên Windows output
	– Hoặc select dòng “C:\PROGRAM FILES\VISUAL STUDIO\MyProjects\leaktest\leaktest.cpp(20) : {18}” trên Windows output và ấn phím F4
	*/
	