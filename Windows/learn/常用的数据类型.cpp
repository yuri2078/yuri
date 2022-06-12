#include <Windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow) 
{
	// DWORD 32位无符号整型 unsigend
    // HANDLE void 类型
    // PVOID void * 类型指针
    // BYTE, CHAR, WORD, SHORT 简单的变成大写
    // 指针类型一般加上LP 或者 P 如 LPWDWORD
    // 句柄类型一般都是对象前面加上 H 比如位图 BITMAP 对应的句柄为 HBITMAP
    // 无符号一般以 U 开头 比如无符号整型 UINT 
    // 一般以C开头的是const 类型 
    // STR 是字符串类型
    return 0;


    //常用
    WORD D1; //16位无符号
    DWORD D2; //32位无符号整型
    DWORD64 D3; //64 位无符号整型
    INT A;
    INT_PTR B;  //指向int 的指针
    INT32 C; 
    INT64 D;
    UINT E;
    LONG F;
    ULONG G; //无符号long
    LONGLONG H;
    SHORT I;
    LPARAM J; //消息的l型
    WPARAM K; //消息类型的w
    HANDLE L; //对象的句柄
    HICON M; //图标的句柄
    HINSTANCE N; //程序的句柄
    HKEY O; //注册表键的句柄
    HMODULE; //模块的句柄
    HWND; //窗口的句柄
    BOOL; //布尔的句柄
    BYTE; //字节类型 8 位
    CONST; //常量
    FLOAT; //浮点数据
    SIZE_T; //内存大小，以字节为单位
    VOID; //无类型
    WINAPI; //windows api 函数调用方式
    _stdcall;

    LPSTR; // 字符指针
    LPCSTR; //字符串常量
    LPCTSTR; //根据环境配置，unicode 宏 则为 lpcwstr类型 否则为 lpcstr类型
    LPCWSTR; //Unicode 字符串常量
    LPDWORD; //指向dword 类型数据的指针
    CHAR; //8比特字节
    TCHAR; //如果定义了 Unicode 则为 wchar 否则为char
    UCHAR; //无符号char
    WCHAR; //16为unicode 字符

}