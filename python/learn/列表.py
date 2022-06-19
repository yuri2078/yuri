import copy
from secrets import randbelow
a = [1,2,3,4,5] #直接定义列表
b = [1,2,3,4,5]
a.append(6) #向尾部插入列表
a.extend(b) #插入可迭代的对象，列表属于可迭代对象
len(a) #获取a的长度
print("通过for in 遍历列表")
#通过for in 遍历列表
for i in a:
    print(i,end="  ")

print("\n通过切片访问元素")
print(a)
print(a[-1]) #可以通过下标访问元素 下标可以是负的值 -1 就是最后一个，但是不可以越界
print(a[:3]) #切片输出 0 到 3 不包含结尾3
print(a[3:]) #切片输出 2 到 末尾 包含开头3
print(a[:]) #可以全部缺省
print(a[::-1])  #指定跳跃的宽度 
a[4:] = "d" #后面的元素赋值为d 只改变一个
#a[::2] = "wo" 报错
#a[2::2] = "wo" 不报错
print(a)

print("向列表中插入数据")
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

print("删除列表中的元素")
a.pop(5) #删除指定位置的元素
print(a)

a.remove("helloworld") #删除第一个存在的元素并且返回已经删除的元素的值，如果不存在就报错


print(a)


#清除a中的所有元素
a.clear()
print(a)


print("改变列表中的数据")
b = [3,2,11,343,45,22,4,67,2]
b.sort() #排序算法
b.reverse() #逆向

print(b)

print("查找列表元素")

b.count(2) #统计元素出现的次数
b.index(2,0,len(b)) #查找元素出现的位置 只返回第一个出现的值 ,从0到len开始找


c = b.copy() #浅拷贝 不会发生b中的值改变，而c中跟着改变

c = a + b # 列表元素相加
c = a * 2 # 列表元素×几个
c = [[12,2],"wocao",[1,"nima"]]  #列表元素嵌套
print(c)

# is 判断两个变量地址是否相等
print("为什么要用深拷贝")
is_1 = 44
is_2 = 44
print(is_1 is is_2)

is_3 = [[0,0,0],[0,0,0],[0,0,0]]
is_4 =[[0] * 3 ] *3

print(is_3)
print(is_4)

is_3[1][1] = 1
is_4[1][1] = 1 

print(is_3)
print(is_4)


#我们发现他中间的每个元素都改变了
#由此推断is_4[0] is_4[1] is_4[2] 的地址是相同的
print([1,2,4] is [1,2,3]) #打印相同的数据，发现并不一样，这是因为是浅拷贝，只赋值了引用

print(is_4[0] is is_4[1]) #我们发现是ture，说明他们地址一样

#深浅拷贝

print("深浅拷贝的区别")
a = [1,1,1,1,1]
b = a
a[3] = 666
print(a) #我们发现a，b是一样的
print(b) #该表了a也就改变了b

a = [1,1,1,1,1]
b = a.copy() 
b = a[:] #和上面是一个效果
a[3] = 666
print("使用copy后的拷贝")
print(a) #我们发现a改变了，但是b没有改变
print(b)

b = copy.copy(a) #浅拷贝
b = copy.deepcopy(a) #深拷贝

#列表推导式
print("列表推导式")
a = [i for i in range(10)] #将元素加一添加到a中
b = [
    [1,2,3],
    [4,5,6],
    [7,8,9]
]

a = [row[1] for row in b]  #遍历b 提取出每行元素，再将每行的 row[1] 赋值给a
a = [[0] * 3 for i in range(3)] #创建3 x 3 列表
a = [i  for i in range(10) if i%2] #先运行 for 语句的表达式再进行判断 最后赋值

a = [i for j in [["hello"],[" world"]] for i in j]  # 嵌套推导式

print(a)


