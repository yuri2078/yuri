import decimal
#导入decimal 函数
"""" 提高浮点数精度函数库 """
decimal.Decimal(0.1)

# """随机生成函数"""
import random
random.randint(1,20) #随机生成1，20的数字

import itertools
itertools.zip_longest([1,2,3],[2,3,45,5]) #以最长的长度的列表来组成zip，没有的以none填充 

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

mmax = a if a > b else b #else 不可缺少
print(mmax)


#常用函数
print(ord('c')) #转换成对应数据

print("id a === ",id(a)) #返回对象的id值,他不可以被修改
# is is not 判断id是否相同

print("hell" in "hello") #判断是否包含某个元素，in not 不包含

del a #删除a，也可以切片删除
# print(a) a已经被删除了，所以报错

list([1,2,34,5])  #将可迭代对象转换成列表
tuple([1,2,34,5])  #将可迭代对象转换成元组
str(333) #转换成字符串
min(2,3) #可以是可迭代对象
max(3,4) #不能是空的
len(range(10))  #求长度，有最大值
sum(range(10))  #求和函数
sorted(["wo","fjikd"],key=len) #排序函数,返回全新的列表，根据key函数返回值
reversed([1,2,3,4]) #反转，返回一个可以迭代的对象
all([1,2,3,4]) #判断是否都是true 
a = "hello"
b = "world"
print("a = ",a)
print("b = ",b)
print("枚举对象 ---", list(enumerate(a,1))) #创建枚举对象,指定从哪里开始
print("zip 对象 ---",list(zip(a,b))) #将a和b组合在一起，长度不一致，则以最短的为准
print("map 对象 ---",list(map(ord,"hello world")) ) #遍历可迭代对象
print("map 对象 ---",list(map(pow,[1,2,3],[2,3,4])) )
print("filter 过滤 -",list(filter(str.isalnum,["2","3","hello"]))) #过滤器，返回迭代器

#迭代器只能搞一次，但是可迭代对象可以搞很多次
#迭代器在用完一次之后就会变成空，而可迭代对象可以使用很多次
c = iter(a)
print("转换成迭代器",list(iter([1,2,3,4,5]))) #转换成迭代器
print("指向下一个迭代器",list(next(c,"没啦，已经迭代完了"))) #指向下一个迭代器的元素
print("指向下一个迭代器",list(next(c,"没啦，已经迭代完了"))) #指向下一个迭代器的元素
print("指向下一个迭代器",list(next(c,"没啦，已经迭代完了"))) #指向下一个迭代器的元素
print("指向下一个迭代器",list(next(c,"没啦，已经迭代完了"))) #指向下一个迭代器的元素
print("指向下一个迭代器",list(next(c,"没啦，已经迭代完了"))) #指向下一个迭代器的元素
print("指向下一个迭代器",list(next(c,"没啦，已经迭代完了"))) #指向下一个迭代器的元素
#迭代至末尾迭代器失效
 
print("".join("44444")) #将可迭代对象转换成字符串
print("字符传的format方法 --- {} / --a".format(a))

str(444) #转换成字符串



