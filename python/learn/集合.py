a = {} #字典
print("type a --- ",type(a))

a = {"hello"} #集合 
#是无序的，并且不可以改变,且只能存在一个
print("type a --- ",type(a))

a = {"hello":"1"} #字典
print("type a --- ",type(a))

#创建集合的三种方式
a = {i for i in "yuri love"}
print("a --- ",a) #可以看到他是无序的
print("type a --- ",type(a)) 

a = set("yuri yuri")
print("a --- ",a) 
print("type a --- ",type(a)) 
#不可以通过下标访问

b = set("good by")
print("通过isdisjoint 判断两个集合是否毫不相干", a.isdisjoint(b)) #都有一个y 
print("通过issubset 判断a是否为b的子集", a.issubset("yuri yuri ")) 
a <= b#检测子集
a < b  #检测真子集
a >= b #超集
a > b #真超集
a & b #交集
a | b #并集
a - b #补集
a ^ b  #堆成差集
print("通过issuperset 判断a是否为b的超集", a.issuperset("yuri")) 
print("通过union 求并集", a.union("hhh")) 
print("通过intersection 求交集", a.intersection("yuri")) 
print("通过difference 求补集", a.difference("yuri")) 
print("通过difference 求对称差集", a.symmetric_difference("yuri")) 

f = frozenset("fill") #不可以改变的集合 
#f.update("fish") 报错

print("f ---- ",f)