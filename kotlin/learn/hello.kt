package hello // 加不加都不会报错

class Person(val name : String){
    fun getName(){
        println("name is $name");
    }
}

fun main(){
    Person("yuri is yes!").getName();
    println("可以使用分号!");
    // 加不加分号都可以
}