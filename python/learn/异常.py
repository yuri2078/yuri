from argparse import ZERO_OR_MORE
from typing import final


try:
    1 / 0
    x = 1
except ZeroDivisionError as e:
    print("出错捏")
    print("出错内容是 -- ",e)
except (TypeError,ZeroDivisionError):
    print("用元组找到多个错误")
else:
    print("没有异常捏")
finally:
    print("找不找到都执行这句话")
#有错误执行except 后面的语句，不会报错

#异常的嵌套
try:
    1 / 0
except:
    try:
        1 / 0
    except:
        print("内部异常")
    print("外部异常")

# raise TypeError("类型不正确捏") from ZeroDivisionError 
# 产生报错，程序会停止
#设置自定义错误，并可以指明来自哪里
#无法抛出自己创造的错误


s = "yuri"
assert s == "yuri" 
# 如果不是true 会报错

try:
    while True:
        while True:
            for i in range(100):
                print(i)
                if i > 6 :
                    print("通过产生错误，达到跳转的目的 -- 直通 except")
                    raise
except:
    print("已经结束捏")