from copyreg import pickle
from importlib.resources import path
from turtle import end_fill
from pathlib import Path
import pickle

fp = open("E:\\vscode\\python\\learn\\hello.txt","w+")
print("fp 可以读吗? --- ",fp.readable())
print("fp 可以读吗? --- ",fp.writable())
print("tell 函数告诉你当前在哪里 -- ",fp.tell())
fp.seek(0) #指定文件指针位置

fp.write("hello\n") #写入一个
fp.writelines([ f"{i}" for i in range(10)]) #写入多个
print("read  读取一个内容",fp.readlines()) 
print("read readline  读取一行内容",fp.readlines()) 
print("read readlines  读取所有内容 以行为单位，组成列表",fp.readlines()) 

fp.flush() #刷新文件流，不关闭文件直接写入到文件中
fp.truncate(20) #将文件截取到指定位置，默认到尾部
fp.close()

路径 = Path.cwd() / "python" / "learn" / "hello-2.txt"
if 路径.is_file() == False:
    路径.open("w")
print("当前路径是 -- ",路径)
print("判断路径是不是一个文件夹 -- ",路径.is_dir())
print("判断路径是不是一个文件 -- ",路径.is_file())
print("获取目录最后一个元素 -- ",路径.name)
print("获取文件的父目录 -- ",路径.parent)
print("获取文件的父目录所组成的序列 -- ",list(路径.parents))
print("获取文件的扩展名 -- ",路径.suffix)
print("获取路劲将他拆分成元组组成起来 -- ",路径.parts)
print("获取文件目录的信息 -- ",路径.stat())
print("获取文件的占用大小 -- ",路径.stat().st_size)  
fp = open(路径,"w")
fp.close()

print("path 相对路径 --- ",Path.cwd())
print("path 产生相对路径 --- ",Path("./python")) 
print("resolve 将相对路径 转绝对路径  --- ",Path("./python/learn").resolve())
print("iterdir 列举出所有路径和文件  --- ",list(Path("./python/learn").iterdir()))
for i in Path("./python/learn").iterdir():
    print(i) #迭代出所有文件和目录

print("\n\n筛选出所有txt文件\n\n")
for i in Path("./python/learn").iterdir():
    print(i) if i.suffix == ".txt" else i

print(end='\n')

p = Path("./python/test/a/b/c")
p.mkdir(parents=True,exist_ok=True) 
#前面一个参数是，如果多个父级目录没有，则创建
#后面一个参数是，如果当前目录已经存在就打开，不创建
#不然统统报错/ 创建文件夹
p = p / "hello-3.txt"

_ = p
p = p.open("w") #直接打开 省略前面的路径
p.write("hjsldkfjlsdjfldsk")
p.close()
if (Path("./python/test/a/b/c") / "hello.txt").is_file():
    (Path("./python/test/a/b/c") / "hello.txt").unlink() #删除文件
# p.rmdir() #删除文件夹 ,如果文件夹里有文件，则会报错

_.rename(Path("./python/test/a/b/c") / "hello.txt") #改名字需要添加路径，不然就会改到别的东西
#文件如果已经存在就会报错
wocao = Path("./python/learn/wocao.txt")
if wocao.is_file() == False :
    wocao.open("w") 

hello = Path("./python/test/a/b/c/hello.txt") #用前面的文件替换后面的文件
# wocao.replace(hello)

_ = Path(".")
print("查找所有js 文件",list(_.glob("**/*.js")))
# 一个*号，下级目录下所有文件
# 两个 ** 号，当前目录，包括所有下级目录和所有下级的下级目录

with open("./python/learn/with.txt","w") as f:
    f.writelines("hello with and as")
    #操作完了，不用关闭，他会自己关闭的

with open("./python/learn/pkl打包.pkl","wb") as f:
    a = [1,3,4,4,5,6]
    b = "yuri is yes"
    c = 6676
    d = {"wo":"ni","ni":"wo"}
    pickle.dump((a,b,c,d),f)

with open("./python/learn/pkl打包.pkl","rb") as f:
    _ = pickle.load(f)
    print("pkl 文件的内容是 --- ",_)