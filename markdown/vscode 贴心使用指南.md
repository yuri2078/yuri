# vscode 贴心使用指南

vscode [配置各种编译环境](https://yuri2078.github.io/2021/12/11/vscode%E9%85%8D%E7%BD%AE%E6%95%99%E7%A8%8B/)

## 好用的插件

### 图标

1. 名称: **vscode-icons**

### 主题

1. 名称: **Dracula Official**

### 字体

1. One Dark Pro++ (TPack)

### 环境

1. **c/c++**  写cpp必备插件 支持语法高亮，代码提示
2. **Code Runner** 在终端中一键跑代码
3. **Error Lens** 可以让错误提示在行内显示
4. **CodeSnap** 代码截图

## 设置

### settings.json

```json
{
    "files.defaultLanguage": "c++", // ctrl+N新建文件后默认的语言
    "editor.formatOnSave": true,
    "editor.formatOnType": true, // 输入分号(C/C++的语句结束标识)后自动格式化当前这一行的代码
    "editor.suggest.snippetsPreventQuickSuggestions": false, // clangd的snippets有很多的跳转点，不用这个就必须手动触发Intellisense了
    "editor.acceptSuggestionOnEnter": "off", // 我个人的习惯，按回车时一定是真正的换行，只有tab才会接受Intellisense
    // "editor.snippetSuggestions": "top", // （可选）snippets显示在补全列表顶端，默认是inline
    "code-runner.runInTerminal": true, // 设置成false会在“输出”中输出，无法输入
    "code-runner.executorMap": {
        // "c": "cd $dir && gcc '$fileName' -o '$fileNameWithoutExt.exe' -Wall -g -O2 -static-libgcc -std=c11 -fexec-charset=GBK && &'$dir$fileNameWithoutExt'",
        // "cpp": "cd $dir && g++ '$fileName' -o '$fileNameWithoutExt.exe' -Wall -g -O2 -static-libgcc -std=c++17 -fexec-charset=GBK && &'$dir$fileNameWithoutExt'"
        "c": "cd $dir && gcc $fileName -o $fileNameWithoutExt -Wall -g -O2 -static-libgcc -std=c11  && $dir$fileNameWithoutExt",
        "cpp": "cd $dir && g++ $fileName -o $fileNameWithoutExt -Wall -g -O2 -static-libgcc -std=c++20  && $dir$fileNameWithoutExt",
        "csharp": "cd $dir && dotnet run"
    }, // 右键run code时运行的命令；未注释的仅适用于PowerShell（Win10默认），文件名中有空格也可以编译运行；注释掉的适用于cmd（win7默认），PS和bash也能用，但文件名中有空格时无法运行
    "code-runner.saveFileBeforeRun": true, // run code前保存
    "code-runner.preserveFocus": true, // 若为false，run code后光标会聚焦到终端上。如果需要频繁输入数据可设为false
    "code-runner.clearPreviousOutput": true, // 每次run code前清空属于code runner的终端消息，默认false
    "code-runner.ignoreSelection": true, // 默认为false，效果是鼠标选中一块代码后可以单独执行，但C是编译型语言，不适合这样用
    "C_Cpp.clang_format_sortIncludes": true,
    {
  "workbench.colorTheme": "One Dark Pro",
  "workbench.iconTheme": "vscode-icons",
  "editor.cursorSmoothCaretAnimation": true,
  "workbench.list.smoothScrolling": true,
  "editor.smoothScrolling": true,
  "terminal.integrated.smoothScrolling": true,
  "C_Cpp.autocompleteAddParentheses": true,
  "files.autoSave": "afterDelay",
  "editor.fontSize": 17,
  "editor.guides.bracketPairs": true,
  "git.defaultCloneDirectory": "https://github.com/yuri2078/yuri",
  "editor.fontFamily": "Fira Code",
  "editor.fontWeight": "1",
  "editor.fontLigatures": false,
  "git.enableSmartCommit": true,
  "git.confirmSync": false,
  "git.autofetch": true,
  "backgroundCover.imagePath": "/home/yuri/Pictures/download/wallaven-4.png",
  "editor.cursorBlinking": "smooth",
  "editor.bracketPairColorization.independentColorPoolPerBracketType": true,
  "editor.suggest.preview": true,
}
}
```

