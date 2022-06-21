#字典的值都是不同的
yuri = {
    "晓美焰":"鹿目圆",
    "安达樱":"岛村抱月",
    "千寻":"眠雪"
}

# key : value 

print("type -- x",type(yuri))
print("yuri ---",yuri)

print("通过键访问值")
yuri["七海灯子"] = "小糸侑" #新建一个不存在的键值
print("yuri['七海灯子'] ---",yuri["七海灯子"])

print("添加键值：")
a = dict(wo="ni",ni="wo")
print("a  --- ",a)
a = dict([("wo","ni"),("ni","wo")])
print("a  --- ",a)
a = dict({"wo":"ni","ni":"wo"})
print("a  --- ",a)
a = dict({"wo":"ni","ni":"wo"},your="my")
print("a  --- ",a)
a = dict(zip(["wo","ni"],["ni","wo"]))
print("a  --- ",a)

print("增加key值")
a = dict.fromkeys("hello",1) #使用1初始化字典
print("a  --- ",a)

print("删除key值 : c --  ",a.pop("c","没有了捏"))
#删除最后一个元素
print("`删除最后一个key  --- ",a.popitem())

print("更新建值")
x = dict.fromkeys("yuri",520)
x['y'] = 555 #通过key更新
print("x  --- ",x)
x.update(y=666,u = 777,r = 888, i = 999, l = 000)
print("更新后的x   --- ",x) #更新的同时还可以增加key

print("查找 y --",x.get('y',"找不到捏"))
print("查找 x --",x.get('x',"找不到捏"))
print("setdefault -- 查找 y --",x.setdefault('y',"找到了就返回找到的值"))
print("setdefault -- 查找 x --",x.setdefault('x',"找不到则用这里替换并添加"))
print("x --- ",x)

keys = x.keys()
values = x.values()
items = x.items()

print("keys --- ",keys) #保存keys
print("values --- ",values) #保存value
print("还没更新的 items --- ",items) #保存所有的值

x['y'] = 55555
print("更新之后的 items --- ",items) #字典的值更新，这里也会更新

y = x.copy() #拷贝
print("y --- ",y)
z = {values:keys for values,keys in y.items()} #通过推导式，推导z
print("z --- ",z)