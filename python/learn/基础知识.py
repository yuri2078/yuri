import decimal #导入decimal 函数
"""" 提高浮点数精度函数库 """
decimal.Decimal(0.1)

# """随机生成函数"""
import random
random.randint(1,20) #随机生成1，20的数字


""" python 学习手册 """ #字符串
a = 666;
# a = input("这是输入函数input a --- ") #指定接受类型为int
print("这是输出函数，默认换行,a --- ",a)
print("不想换行用end = '|' 重新指定  ",end='|')
print("\n")
b = 0.2
c = 0.1

#python的空格是有严格规定的，空格相同则是同一个语句
#if语句不同于 c 需要加冒号
if((b + c ) == 0.3): 
    print("b + c == 0.3")
else:
    print("b + c != 0.3")
    print("b + c == ", b + c) 
    #因为浮点数的存储原理，所以0.3 不等于 0.1 + 0.2
    #但是可以使用高精度浮点数

#python 的与或非是 and or not

max = a if a > b else b #else 不可缺少
print(max)










