
let button = $("button");
button.click(() => {
    let username = $("input[name='username']");
    let passward = $("input[name='passward']");
    if (username.val() == "yuri" && passward.val() == "yuri")
    {
        alert("登录成功！");
    }
    else
    {
        alert("账号或密码错误！");
    }
    
})

let login = $('[type = "text"]');
console.log(login.css("width"));



