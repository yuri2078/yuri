""" python 学习手册 """ #字符串
import decimal #导入decimal 函数
"""" 提高浮点数精度函数库 """
print(0.1+0.2,'\n')
a=decimal.Decimal(0.1)
b=decimal.Decimal(0.2)
print(a)

"""随机生成函数"""
import random
daan=random.randint(1,20) #随机生成1，20的数字

#bool型字符测试

print(3 or 4,'\n')
print(3 and 4,'\n')
print(not 3,'\n')

#输入函数，总是字符串的形式读入用户输入的数据
c=input("请输入一个数") #可以在里面加类型比如 input(int)
print(c,'\n')

# int(x)转换类型为int 型

#同时输出多个变量和字符串，指定    分隔符
print("读者名：" ,"年龄：",sep='|')

#print后总会换行，不想换行，就指定一下    结束符号
print("hello")
print("huan huang le  ma ")
print("cesshihuibuhui huanhanan",end="")
print("测试,'\n")

#python 三目运算符测试
d=66 
e=77
f=99
max=d if d>e else e
print(max)
max=d if d>e else e if e>f else f #if else 的嵌套使用
#小甲鱼说的比较炫酷的用法
print(max)

#if语句的五种实现方式
print("if语句的物种实现方式")
if 3>5 :
    print("我在里面")
print("我也在外面")

#缩进部分就是代码块
if 4<5:
    print("4<5   yes!")
else :
    print("4<5  no!")
#else if 多重判断
if 3<4 :
    print("555")
elif 3==4:
    print("666")
else :
    print("777")








