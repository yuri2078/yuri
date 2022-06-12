""" 做一个小游戏 """
guess = input("不妨猜一下小甲鱼现在心里想的是哪个数字： ")
guess = int(guess)
import random
daan=random.randint(1,20)
daan =int(daan)
while guess != daan:
    if guess == daan:
        print("你现在是小甲鱼心里的蛔虫吗？")
        print("猜中了也没有奖励，啦啦啦啦")
    else :
        if guess < daan:
            print("小了")
        else :
            print("大了")
    guess = input("请重新输入你的数 ： ")
    guess = int(guess)
print("你好牛啊")
print("游戏结束，不玩啦")
