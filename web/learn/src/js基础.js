// 'use strict'; 加入这行启动严格模式，未声明的变量禁止使用
alert('不为人知的绽放!'); //让浏览器弹出警示框
age = prompt('请输入你的内容'); //让用户输入内容
console.log('这是给程序员测试用的'); //输出控制台 浏览器检查就可以看到
hhh = 888;


console.log(isNaN(age)); //检查是不是数字不是返回true 是的话，返回false


//变量知识总结

//声明变量,但是未赋值的则为 undefined
//未声明 直接使用则会报错   报错js将不会继续执行，就会停在报错的地方
//未声明 直接赋值是可以的 但是将会声明成全局变量
// Infinity 无穷大类 Number.MAX_VALUE
// -Infinity 无穷小类型
// NaN 代表一个非数值 当结果不是数值的时候就返回一份非数值


//创建对象
var Person = {
    name: '晓美焰',
    age: 17,
    classMate: ['小圆', '沙耶香', '杏子', '麻美学姐'],
    isGirl: true,
    hate: null
};

console.log(Person.name, '最喜欢', Person.classMate[0]); //打印多个字符串

console.log(`${Person.name} 今年 ${Person.age}岁了!`); //替换字符串的变量

var s = 'hello hello ';
var b = 'hello';
s.toUpperCase(); //将所有字符变大写
s.toLowerCase(); //将所有字符变小写
s.indexOf(b); //返回字符串出现的位置 没有则返回-1
s.substring(0, 5); //返回指定区间的字符串 但是不包括5
s.substring(5); //返回从5开始到结束的字符串


var arr = [1, 2, 3, 4, 5, 6];
console.log("字符长的长度是:", arr.length); //测试字符串长度
arr.length = 10; //则后面几个以underfined填充
arr[10] = "hello"; //数组总数发生变化，第11个为hello 前面没有的用underfined填充
var hello = new Array(1, 2, 3, "hello"); //创建数组
console.log(hello[0]); //打印数组内容
arr.indexOf(1); //寻找元素位置
arr.slice(0, 5); //截取0到5的元素 但是不包括5
arr.slice(5); //截取5到结束的字符
arr.push("hello", "hello"); //向尾部i添加新元素，并返回新长度
arr.pop(); //删除最后一个元素并且，返回被删除的元素,空的则返回undefined
arr.unshift("hello"); //往头部添加
arr.shift(); //删除头部
arr.sort(); //默认排序
arr.reverse(); //交换顺序
arr.splice(1, 2); //删除从1开始的两个数据，返回被删除的数组
arr.splice(1, 0, "hello"); //删除从1开始的0个数据并添加hello
arr.splice(1, 2, "hello"); //删除从1开始的2个数据并添加hello
arr.concat(1, 3); //添加新的数据或数组返回新的数组，并没有改变原来数组的值
arr.join('-'); //把arr的数据用-连接起来，并返回新的字符串

//函数的练习

function max(x, y)
{
    if (x > y)
    {
        console.log("x 非常的大呀！");
    }
    else 
    {
        console.log("y 非常的大呀!");
    }
    //默认返回结果是unfined
}

max(6,8); //调用函数