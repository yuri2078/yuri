let restlt = document.getElementById("result");
let number = document.getElementsByClassName("number")
let equal = document.getElementById("equal");
let operator = document.getElementsByClassName("operator");
let num = Array("","","","","","","","","","","","");
let all_num = 0;



for (let i = 0; i < number.length; i++)
{
    number[i].onclick = function ()
    {
        num[all_num] = num[all_num] + number[i].innerHTML;
        if (restlt.innerHTML == "0")
        {
            restlt.innerHTML = "";
        }
        restlt.innerHTML = restlt.innerHTML + number[i].innerHTML;
    }
}

for (let i = 0; i < operator.length; i++)
{
    operator[i].onclick = function ()
    {
        all_num++;
        restlt.innerHTML = restlt.innerHTML + operator[i].innerHTML;
    }
}

equal.onclick = function ()
{
    restlt.innerHTML = num[all_num];
    console.log(num[all_num]);
}

