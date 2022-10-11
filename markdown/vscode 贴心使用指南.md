# vscode 贴心使用指南

vscode [配置各种编译环境](https://yuri2078.github.io/2021/12/11/vscode%E9%85%8D%E7%BD%AE%E6%95%99%E7%A8%8B/)

## 好用的插件

直接在插件列表搜索就行了

### 图标

1. **vscode-icons**
1. **Material Icon Theme**

### 主题

1.  **Dracula Official**
1. **one dark pro**

### 字体

1. One Dark Pro++ (TPack)

### 环境

1. **chinese** 中文汉化插件
1. **c/c++**  写cpp必备插件 支持语法高亮，代码提示
2. **Code Runner** 在终端中一键跑代码
3. **Error Lens** 可以让错误提示在行内显示
4. **CodeSnap** 代码截图
4. **clangd** 使用clangd代替c/c++
4. **Dev Containers **使用vscode打开docker容器
4. **docker **docker容器管理
4. **CodeLLDB** clangd 调试插件
4. **vim** 使vscode支持vim操作

## .vscode 文件夹

> 工作区中新建一个.vscode 文件夹，里面可以存放配置文件
>
> settings.json 用来存放 工作区修改的设置
>
> launch.json 用来存放vscode调试设置
>
> tasks.json 用来存放vscode自动任务

#### windows 配置教程

### settings.json

这是我自用的设置仅仅用于 linux + clangd 编译c++。window请更改部分参数

```json
{
    "files.autoSave": "afterDelay", //设置自动保存
    "files.defaultLanguage": "c++", // ctrl+N新建文件后默认的语言
    "editor.formatOnSave": true, //设置保存时格式化代码
    "editor.formatOnPaste": false,
    "editor.formatOnType": true, // 输入分号(C/C++的语句结束标识)后自动格式化当前这一行的代码
    "editor.suggest.snippetsPreventQuickSuggestions": false, // clangd的snippets有很多的跳转点，不用这个就必须手动触发Intellisense了
    "editor.acceptSuggestionOnEnter": "off", // 我个人的习惯，按回车时一定是真正的换行，只有tab才会接受Intellisense
    // "editor.snippetSuggestions": "top", // （可选）snippets显示在补全列表顶端，默认是inline
    "code-runner.runInTerminal": true, // 设置成false会在“输出”中输出，无法输入
    "code-runner.executorMap": {
        "c": "cd $dir && gcc '$fileName' -o '$fileNameWithoutExt.exe' -Wall -g -O2 -static-libgcc -std=c11 -fexec-charset=GBK && &'$dir$fileNameWithoutExt'",
        "cpp": "cd $dir && g++ '$fileName' -o '$fileNameWithoutExt.exe' -Wall -g -O2 -static-libgcc -std=c++17 -fexec-charset=GBK && &'$dir$fileNameWithoutExt'"
        //"csharp": "cd $dir && dotnet run" c#运行命令，需要的可以打开，默认是运行c#工程文件
    }, // 
    "code-runner.saveFileBeforeRun": true, // run code前保存
    "code-runner.preserveFocus": true, // 若为false，run code后光标会聚焦到终端上。如果需要频繁输入数据可设为false
    "code-runner.clearPreviousOutput": true, // 每次run code前清空属于code runner的终端消息，默认false
    "code-runner.ignoreSelection": true, // 默认为false，效果是鼠标选中一块代码后可以单独执行，但C是编译型语言，不适合这样用

    "C_Cpp.errorSquiggles": "Enabled",

    //设置光标丝滑显示
    "editor.cursorSmoothCaretAnimation": true,
    "workbench.list.smoothScrolling": true,
    "editor.smoothScrolling": true,
    "terminal.integrated.smoothScrolling": true,

    //设置插件自动补全括号
    "C_Cpp.autocompleteAddParentheses": true,

    //设置彩虹括号成对显示
    "editor.guides.bracketPairs": true, 
    "editor.bracketPairColorization.independentColorPoolPerBracketType": false,

    //设置禁用c/c++ 代码提示和自动补全功能
    "C_Cpp.intelliSenseEngineFallback": "Disabled",
    "C_Cpp.intelliSenseEngine": "Disabled",
    "C_Cpp.autocomplete": "Disabled", 
    "clangd.path": "/usr/bin/clangd",

    // Clangd 运行参数(在终端/命令行输入 clangd --help-list-hidden 可查看更多)
    "clangd.arguments": [
        // 让 Clangd 生成更详细的日志
        "--log=verbose",
        // 输出的 JSON 文件更美观
        "--pretty",
        // 全局补全(输入时弹出的建议将会提供 CMakeLists.txt 里配置的所有文件中可能的符号，会自动补充头文件)
        "--all-scopes-completion",
        // 建议风格：打包(重载函数只会给出一个建议）
        // 相反可以设置为detailed
        "--completion-style=bundled",
        // 跨文件重命名变量
        "--cross-file-rename",
        // 输入建议中，已包含头文件的项与还未包含头文件的项会以圆点加以区分
        "--header-insertion-decorators",
        // 在后台自动分析文件(基于 complie_commands，我们用CMake生成)
        "--background-index",
        // 启用 Clang-Tidy 以提供「静态检查」
        "--clang-tidy",
        // Clang-Tidy 静态检查的参数，指出按照哪些规则进行静态检查，详情见「与按照官方文档配置好的 VSCode 相比拥有的优势」
        // 参数后部分的*表示通配符
        // 在参数前加入-，如-modernize-use-trailing-return-type，将会禁用某一规则
        "--clang-tidy-checks=cppcoreguidelines-*,performance-*,bugprone-*,portability-*,modernize-*,google-*",
        // 默认格式化风格: 谷歌开源项目代码指南
        // "--fallback-style=file",
        // 同时开启的任务数量
        "-j=2",
        // pch优化的位置(memory 或 disk，选择memory会增加内存开销，但会提升性能) 推荐在板子上使用disk
        "--pch-storage=disk",
        // 启用这项时，补全函数时，将会给参数提供占位符，键入后按 Tab 可以切换到下一占位符，乃至函数末
        // 我选择禁用
        "--function-arg-placeholders=false",
        // compelie_commands.json 文件的目录位置(相对于工作区，由于 CMake 生成的该文件默认在 build 文件夹中，故设置为 build)
        "--compile-commands-dir=build"
    ],

    "editor.fontFamily": "'Fira Code', 'monospace', monospace", //设置字体格式
}
```

