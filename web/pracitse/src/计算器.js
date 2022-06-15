let result = document.getElementById("result");
let number = document.getElementsByClassName("number")
let equal = document.getElementById("equal");
let operator = document.getElementsByClassName("operator");
let num = Array("");
let oper = Array("");
let all_num = 0;
let sum = 0;

for (let i = 0; i < number.length; i++)
{
    number[i].onclick = function ()
    {
        num[all_num] = num[all_num] + number[i].innerHTML;
        if (all_num == 0)
        {
            result.innerHTML = "";
        }
        result.innerHTML = result.innerHTML + number[i].innerHTML;
    }
}

for (let i = 0; i < operator.length; i++)
{
    operator[i].onclick = function ()
    {
        num.push("");
        oper.push("");
        oper[all_num] = operator[i].innerHTML;
        all_num++;
        result.innerHTML = result.innerHTML + operator[i].innerHTML;
    }
}

equal.onclick = function ()
{
    let s;
    for (let i = 0; i < all_num ; i++)
    {
        if (oper[i] == "/" || oper[i] == "x" || oper[i] == "%")
        {
            switch (oper[i])
            {
                case "x": s = parseFloat(num[i]) * parseFloat(num[i + 1]); break;
                case "/": s = parseFloat(num[i]) / parseFloat(num[i + 1]); break;
                case "%": s = parseInt(num[i]) % parseInt(num[i + 1]); break;
            }
            num.splice(i, 1);
            oper.splice(i, 1);
            num[i] = s;
            all_num--;
            i--;
        }
    }
    s = parseFloat(num[0]);
    for (let i = 1; i < all_num + 1; i++)
    { 
        switch (oper[i-1])
        {
            case "+": s = s + parseFloat(num[i]); break;
            case "-": s = s - parseFloat(num[i]); break;
        }
    }
    all_num = 0;
    num = Array("");
    oper = Array("");
    result.innerHTML = s;
}

let clear = document.getElementById("clear");
clear.onclick = function ()
{
    result.innerHTML = "";
    for (let i = 0; i < all_num + 1; i++)
    {
        num[i] = oper[i] = "";
    }
    all_num = 0;
    num = Array("");
    oper = Array("");
}

let del = document.getElementById("del");
del.onclick = function ()
{
    if (all_num == 0)
    {
        result.innerHTML = "";
        alert("都没了你删个蛋蛋捏！");
        return 0;
    }
    if (num[all_num] == "")
    {
        oper.splice(all_num - 1, 1);
        all_num--;
    }
    else
    {
        num[all_num] =  num[all_num].substring(0, num[all_num].length-1);
    }
    result.innerHTML = result.innerHTML.substring(0, result.innerHTML.length - 1);
    console.log(num);
    console.log(oper);
    console.log(all_num);
}
