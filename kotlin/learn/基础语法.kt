package com.base.main

public fun test(x : Int , y : Int) : Int{
    return x + y;
}

// public 和 Unit(void) 都可以省略
// vararg 可变参数
public fun printName(vararg args : Int) : Unit {
    for (arg in args) {
        println(arg);
    }
}

fun main() {
    var sum = test(4,5);
    println("4 + 5 = $sum");
    printName(1, 2, 3);
}
