var houmula = {
    name: '晓美焰',
    age: 17,
    friends: ['小圆', '沙耶香', '杏子', '麻美学姐'],
    isGirl: true,
    hate: null
};



var s = JSON.stringify(houmula, null, ' '); //转换成json,后面两个参数按行输出
//第二个参数，可以选择只打印指定的属性多个用[]框起来
alert(s);

//导入json文件


function heredoc(fn)
{
    return fn.toString().split('\n').slice(1, -1).join('\n') + '\n';
}
    var hello = heredoc(function(){/*
        [
            {
                "stu_id": "092021101",
                "stu_name": "尹修杰",
                "gender": "男",
                "math": 77,
                "english": 94,
                "computer": 89,
                "total": ""
            },
            {
                "stu_id": "092021115",
                "stu_name": "方绮怀",
                "gender": "女",
                "math": 67,
                "english": 70,
                "computer": 88,
                "total": ""
            }
        ]
     */});
temp = JSON.parse(hello);
console.log(hello);
// console.log(temp[1][0]);
for (var i in temp[1])
{
    console.log(temp[1][i]);
}
