
import time

def max(x,y = 9): #默认参数
    return x if x > y else y #返回值
# def max(x,/,y ): #  /的左边不允许使用关键字参数
# def max(x,*,y ): #  *的右边必须使用关键字参数
print("max 44 666 --- " ,max(44,666))
print("max 33.3 21 --- " ,max(33.3,21)) #位置函数，位置已经确定
print("指明 max x = 666 y = 44 --- " ,max(666,y = 444)) #关键字参数，位置不确定,位置参数，必须在关键字参数的前面
print("max 1 --- " ,max(1))

#收集参数
def printf(*temp):
    print("一共有{}个参数".format(len(temp)))
    print("temp[1] ---",temp[1])
    print("temp -- ",temp) #发现这是一个元组,*号，打包成元组
printf("ni","hao","xiexie")


def fun1(*temp, x,y, **t):
    #两个*号打包字典
    print("max --- ",x if x > y else y)
    print("t ----",t)
fun1(1,2,3,43,2,x=44,y=666,a = "b",c = "d")

a = (1,3,43,22)
def prin(x,y,z,t):
    print("prin --- ",x,y,z,t) #数量需要对应
prin( *a) #解包操作


a = {"x":"a","y":"b","z":"c","t":"d"}
def prin(x,y,z,t):
    print("prin --- ",x,y,z,t) #数量需要对应
prin( **a) #解包字典操作

x = 66
print("x --- 起始 --",x)
def fun1():
    global x #将全局变量引入函数内部，达到可以修改的目的
    y = 11
    print("y --- 起始 --",y)
    def fun2():
        nonlocal y #将上层作用域中的y引入到这里
        y = 6666
        print("y --- fun2 --",y)
    x = 88
    fun2()
    print("y --- fun1 --",y)
    print("x函数 --- ",x)

fun1()
print("x全局 --- ",x)


def fun3():
    print("fun3")
    temp = 666
    def fun4():
        print("fun4 temp -- ",temp)
    return fun4

#其中fun3的临时变量 temp 不会随着函数消失而消失
#因为fun4 嵌套在fun3里面 所以，fun4的外部变量得以暂时保存下来

wo = fun3() #将函数fun4返回赋值给变量
wo() #调用fun4


#闭包 ，原理 嵌套函数的外部变量会被保留
def point():
    s = 0
    def add(x):
        nonlocal s
        s = s + x
        print(f"总分是: {s}")
    return add

student = point()
student(66) #不断累加
student(33.4)
student(44)

#使用装饰器 
# test = x_1(test) 初始化阶段，不调用 test 后面的函数 此时 test = 内部的 inner 函数
# 调用阶段 等于 x_1(test)()  因为会暂时保留外部变量，所以任然能够访问到原来的函数
# 所以x_1 函数指挥执行一遍，后面都不会执行x_1

print("第一次执行 ---- \n\n")
def x_1(func):
    def inner():
        print("执行了fun1 -- inner")
        func() + 1
        print("fun 执行完毕")
    print("执行了x——1")
    return inner

@x_1
def test():
    print("执行了test")
    return 2

print("test() ---",test())

print("\n\n第二次执行 ---- \n\n")

print("test() ---",test())
 