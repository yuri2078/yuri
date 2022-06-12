// 停留在鼠标上时
function over_mouse(obj)
{
    let left = document.getElementById("box-picture"); //获取给大图片画的方框
    let bannerPicture = document.getElementsByClassName("banner-picture"); // 获取展示的所有图片
    let bigPicture = document.getElementById("big-picture");  //获取大的图片
    let banner = get_style(document.getElementById("banner"), "width"); //获取用来聚焦的模块的宽度
    
    //设置每次触摸移动的宽度
    let width;
    if (banner == "580px")
    {
        width = 116;
    }
    else
    {
        width = 196;
    }

    // 循环找出正在触摸的那副图
    for (let i = 0; i < bannerPicture.length; i++)
    {
        if (bannerPicture[i] == obj)
        {
            left.style.cssText = "left:" + i * width + "px"; //绝对定位,改变left的值,达到移动效果
            bigPicture.innerHTML = '<img src="' + obj.src + ' " alt="">'; //更改大图片模块的内容,达到更换图片的目的
        }
    }
}

// 离开鼠标时
function leave_mouse()
{
    let left = document.getElementById("box-picture");
    let banner = document.getElementsByClassName("banner-picture");
    let bigPicture = document.getElementById("big-picture");
    bigPicture.innerHTML = '<img src="' + banner[0].src + ' " alt="">'; //大图改为默认
    left.style.cssText = "left:0;"; //方框移动到最初地方
}

//获取css样式,因为存在兼容性问题,这里使用两个函数进行封装
function get_style(element, attr) {

    if (element.currentStyle)
    {
        return element.currentStyle[attr];
    }
    else
    {
        return getComputedStyle(element, false)[attr];
    }
}

//对发送按钮进行设置
let send = document.getElementById("send");
send.onclick = function send_onclick()
{
    let mainInput = document.querySelector("#main-input"); //获取文本框的css 
    let history = document.getElementById("message-history"); //获取留言板
    var time = new Date(); //获取系统时间
    let ul;
    //判断是不是第一次,是否需要进行创建ul
    if (document.getElementsByTagName("ul").length == 5)
    {
        ul = document.createElement("ul");
        ul.setAttribute("id", "all-message");
    }
    else
    {
        ul = document.getElementById("all-message");
    }
    let get_li = ul.getElementsByTagName("li").length; //获取留言的总数
    let li = document.createElement("li"); //新建li标签
    let date = time.getHours() + " 时 " + time.getMinutes() + " 分 " + time.getSeconds() + " 秒 "; //打印时间
    //添加刚创建的li
    history.appendChild(ul);
    ul.appendChild(li);
    li.innerHTML = "第 " + get_li + " 条 : " + date;
    
    li.setAttribute("onclick", "get_message(this)"); //对刚创建的数据设置点击函数
    //通过localstorage 存储留言
    localStorage.setItem(date, mainInput.value); //将key值设置为时间,方便查找
    mainInput.value = "请输入内容"; //发送之后将文本框内容设为默认
}

//获取留言
function get_message(obj)
{
    let str = obj.innerHTML.substring(8); //将li标签里的时间提取出来
    alert(localStorage.getItem(str)); //通过时间查找本地的留言数据,并弹出
}

//设置清楚内容按钮
let reset = document.getElementById("reset");
reset.onclick = function reset_message()
{
    let mainInput = document.querySelector("#main-input");
    mainInput.value = "";
}

//第一次点击输入框时,清除文本框内容
var f = 0;
var mainInput = document.querySelector("#main-input");
function onfocus_input()
{
    if(f == 0)
    {
        mainInput.value = "";
        f = 1;
    }
}