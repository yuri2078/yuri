x=input("请输入一个二进制数 ：")
x=int(x)
t=1
s=0
while x != 0 :
    s=s+t*(x%10)
    x=int(x/10)
    t=t*2
print(s)
