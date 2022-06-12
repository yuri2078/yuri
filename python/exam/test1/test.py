s = [1,2,3,4,5]
print(s)
s.append("hello") #向列表添加一个元素
print(s)
s[ len(s) : ]="python" # 这也是添加元素的一种方式,不过是分开来放入的
#输出结果 ： [1, 2, 3, 4, 5, 'hello', 'p', 'y', 't', 'h', 'o', 'n']
print(s)
s.remove("hello") #删除指定元素，不存在就报错
print(s)
s.pop(5) #删除指定下标的元素，不存在就报错
print(s)
