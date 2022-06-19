let TIME = 2000; //延迟
let box = Array(); //图片路径，相对于html

box.push(("url(images/1.jpg)"));
box.push(("url(images/2.jpg)"));
box.push(("url(images/3.jpg)"));
box.push(("url(images/4.jpg)"));
box.push(("url(images/5.jpg)"));

console.log(box);

var f = 1;
var flag = 1;
var wocao = 1;
var circle = $(".circle");
var picture = $("#picture");

$(circle[0]).css("background-color", "red");


function time()
{
 
    let k = setInterval(() => {
        if (flag == 0)
        {
            return 0;
        }
        for (let i = 0; i < 5; i++)
        {
            $(circle[i]).css("background-color", "green");
        }
        $(circle[f % 5]).css("background-color", "red");
        before = f % 5;
        picture.css("background-image", box[f++ % 5]);
        
    }, TIME)
    if (flag == 0)
    {
        clearInterval(k);
        return 0;
    }
}

time();


circle.hover(function () {
    flag = 0;
    for (let i = 0; i < circle.length; i++)
    {
        if (circle[i] == this)
        {
            picture.css("background-image", box[i]);
            $(this).css("background-color", "red");
            f = i;
        }
        else
        {
            $(circle[i]).css("background-color", "green");
        }
    }

}, function () {
    if (flag == 0)
    {
        time();
        flag = 1;
    }  
    })