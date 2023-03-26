#include <QApplication>
#include <QMainWindow>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/qtcpsocket.h>

int main(int argc, char **argv) {
  QApplication app(argc, argv);

  QMainWindow mainwindow;
  mainwindow.resize(300,300);

  mainwindow.show();



  return QApplication::exec();
}



// CmakeLists 添加 set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
// 重新构建一下项目 让cmake 生成 compile_commands.json 文件
// 重新启动 vscode 后 clangd 就可以看到qt文件了