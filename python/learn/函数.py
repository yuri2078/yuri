import imp


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
#执行到有装饰器的函数时 他不管会不会调用，先进行初始化 从下往上开始 对每个装饰器进行执行 
#此时 test = 三个装饰器中的inner 函数，而func原来时test函数，因为test = inner 所以 在调用inner
# 的return 函数之后 func 指向的是inner 函数，所以inner return 的值就是新的func
#调用 test 会直接进入inner 函数，然后开始执行，在执行到func 也就是传入的临时函数时，会跳过到下一个装饰器
# 然后继续执行，直到再次调用func 函数，或者已经没有装饰器了为止
#当没有装饰器了的时候，func 作为返回值开始一步一步返回，
#func一开始指向 test， 因为 test = inner 所以后面每次inner return 的值都会作为新的func 返回到上一个装饰器
#从后往前返回，直到结束程序
#

print("第一次执行 ---- \n\n")
def x_1(func):
    def inner():
        print("执行了fun1 -- inner x = func ")
        x = func()
        print("x_1 : x --- ",x)
        return x + 1
    print("执行了x——1")
    return inner

def x_2(func):
    def inner():
        print("执行了fun2 -- inner x = func ")
        x = func()
        print("x_2 : x --- ",x)
        return x + 2
    print("执行了x——2")
    return inner

def x_3(func):
    def inner():
        print("执行了fun3 -- inner x = func ")
        x = func()
        print("x_3 : x --- ",x)
        return x + 3
    print("执行了x——3")
    return inner
@x_1
@x_3
@x_2
def test():
    print("执行了test")
    return 2

print("test() ---",test())

print("\n\n第二次执行 ---- \n\n")

print("test() ---",test())
 
#匿名函数
Max = lambda x,y : x if x > y else y
print("Max (444,5)  -- ",Max(444,5))
lock = list(map(lambda x : x + '-',"yuri"))
print("lock (yuri) --- ",lock)


#通过嵌套函数实现斐波那契额数列
def fei():
    x,y = 1,1
    def bo():
        nonlocal x,y
        print(f"{x}",end=' ')
        x , y  = y , x
        y = x + y
    return bo
hello = fei()
for i in range(10):
    hello()

print()

#生成器 每次生成一个迭代器 ，不可以直接输出，需要遍历
#执行到yield后返回yield的值，然后再次执行的时候才执行yield后面的值
#他一次只生成一个数据 后续的数据，你不用，就不会生成

def put ():
    for i in range(11):
        if i % 2 == 1:
            print("前")
            yield i #
            print(f"后")
k = put()
print("put -- ",next(k)) #不会执行yield 后面的值，只有下次调用才会执行
print("第二次执行")
print("put -- ",next(k)) 

#通过生成器 产生斐波那契数列
def feibo():
    x, y = 1,1
    while(True):
        yield x
        x , y = y , x
        y = x + y
kk = feibo()
for i in range(20):
    print(next(kk),end=' ')

#生成器表达式
#她不像生成器，他会一次性生成所有的数据
print("\n通过生成器表达式生成东西")
print(list(i for i in range(10))) 


#递归函数的调用 
#告诉读者数据类型和返回类型
#list[int] 整型列表
def 递归打印(x:int) -> None:
    """
    功能：递归打印 1 - x
    参数： - x 打印 1 - x 的值
    """
    if(x > 1):
        递归打印(x-1)
    print("x --- ",x)

递归打印(10)
print(help(递归打印))

#高阶函数 函数作为一个函数的参数使用 
def 计算平方大小(func,x):
    x = [ func(i) for i in x]
    return x

def 平方(x):
    return x ** 2

print("输出1 -5 的平方")
_  = 计算平方大小(平方,range(1,6))
print(_)


import functools #导入模块
_ = functools.reduce(lambda x, y : x - y,range(10)) #计算1 - 2 - 3 - 4 .。。的值
print(" _ 的值为 --- ",_)

def test_2_func(func):
    def inner():
        x = 1
    return inner


@test_2_func
def test_2():
    return 2

print("test 2 _ name --- ",test_2.__name__) #他的名字是innner 也就是装饰器内部函数的名字

def test_3_func(func):
    @functools.wraps(func) #用魔法打败魔法
    def inner():
        x = 1
    return inner


@test_3_func
def test_3():
    return 2

print("test 3 _ name --- ",test_3.__name__) #他的名字是test_3

