#菱形继承优先访问左边的

class Person:
    def __init__(self,name,age) -> None:
        self.name = name
        self.age = age
    def eat(self): 
        #必须传入self，不然他不知道是哪个对象
        #类似c++ 的this指针
        print("张三正在睡觉")

class Student(Person):
    def __init__(self, name, age, sex) -> None:
        super().__init__(name, age) #自动识别基类，然后初始化基类
        self.sex = sex




s = Student(44,44,"男孩子") 
print("isinstance 判断s 是不是 person 的对象 ",isinstance(s,Person)) 
print("isinstance 判断student 是不是 person 的子类 ",issubclass(Student,Person)) 

p2 = Person("miku",66)
print("person . name -- ",p2.name)
print("student . sex -- ",s.sex)


