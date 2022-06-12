x=(input("请输入一个需要转化的数字 :"))
x=int(x)
i=0
a=[]
while x!=0 :
    t=x%2
    a.append(t)
    i=i+1
    x=int(x/2)
i=i-1
while i >=0 :
    print(a[i],end="")
    i=i-1