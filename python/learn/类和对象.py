class Person:
    name = "张三"
    age = 66
    def eat(self): 
        #必须传入self，不然他不知道是哪个对象
        #类似c++ 的this指针
        print("张三正在睡觉")

class Student(Person):
    name = "李四" #覆盖

s = Student() 
print("isinstance 判断s 是不是 person 的对象 ",isinstance(s,Person)) 