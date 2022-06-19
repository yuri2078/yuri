#元组不支持修改和删除

from ctypes.wintypes import PINT


print("元组")
a= (1,2,3,4,5,6) #元组用逗号隔开，并且括号可以省略
# a[2] = 44 报错，不可修改
print(a)



print("元组的切片输出")
print(a[:3])
print(a[3:])
print(a[:])
print(a[::-1])

print("元素的查找")

a.count(3) #统计个数
a.index(3)  #查找元素

print("元组的拼接")
b = a *3
c = a + b
print(a)
print(b)
print(c)

print(type(a))

print("元组生成器")
d = [i for i in a]
# d = (i for i in a) 没有这种用法
print(d)
print(type(d))
d[1] =99 #这是一个列表是可以修改的
print(d)


print("批量赋值")
a,b,c,*d = [1,2,3,4,5,6,7]
#数量必须要相等，不相等最后一个必须带上*号
print(a)
print(b)
print(c)
print(d)