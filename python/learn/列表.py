from turtle import clear


a = [1,2,3,4,5] #直接定义列表
b = [1,2,3,4,5]
a.append(6) #向尾部插入列表
a.extend(b) #插入可迭代的对象，列表属于可迭代对象
len(a) #获取a的长度

#通过for in 遍历列表
for i in a:
    print(i,end="  ")

print()
print(a[-1]) #可以通过下标访问元素 下标可以是负的值 -1 就是最后一个，但是不可以越界
print(a[:3]) #切片输出 0 到 3
print(a[2:]) #切片输出 2 到 末尾
print(a[:]) #可以全部缺省
print(a[::-1])  #指定跳跃的宽度 


print(a)
print("len == ",len(a))

#切片插入会覆盖后面的值
#插入的是普通字符串将会转化成各种各样的字符插入
#切片之后len的长度也会耕者改变
a[len(a)-1:] = "wocao" 

print(a)
print("len == ",len(a))

#向指定位置插入元素，字符串不会变成字符插入，而是直接一个字符串
#len的长度也会发生改变

a.insert(len(a),"helloworld")
print(a)
print("len === ",len(a))

a.pop(5) #删除指定位置的元素
print(a)

a.remove("helloworld") #删除第一个存在的元素并且返回已经删除的元素的值，如果不存在就报错


print(a)


#轻吹a中的所有元素
a.clear()
print(a)