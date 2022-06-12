#include <Windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow) 
{
	MessageBox(NULL,TEXT("您的电脑已经损坏！"),TEXT("警告！！！"),MB_OK | 1 | MB_ICONERROR | MB_DEFBUTTON2); 
    //弹出对话框，mb ok 就是只有一个确认
    //1 是取消
    // 后面加上icon 可以指定弹出一张图片 
    //defbutton 默认聚焦按钮，改为第二个
	return 0;
}


