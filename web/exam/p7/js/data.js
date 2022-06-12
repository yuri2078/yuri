'use strict';
let goods = [
    {
        gid: "12388213",
        gname: "Type-c数据线",
        price: "9.9",
        count: 10
    },
    {
        gid: "121234513",
        gname: "Mate40手机膜",
        price: "29.9",
        count: 5
    },
    {
        gid: "234863783",
        gname: "Kingston优盘32GB",
        price: "39.9",
        count: 8
    }
];
let table = document.createElement("table");
let thead = document.createElement("thead");
let tbody = document.createElement("tbody");
let tfoot = document.createElement("tfoot");
let tr_thead = document.createElement("tr");


// thead部分
let title = ["商品编号", "商品名称", "单价", "数量", "小计", "",];
for (let i = 0; i < title.length; i++)
{
    let td = document.createElement("td");
    td.innerHTML = title[i];
    if (title[i] == "小计")
    {
        td.setAttribute("class", "money");
    }
    tr_thead.appendChild(td);
}

thead.appendChild(tr_thead);


table.appendChild(thead);
table.appendChild(tbody);
table.appendChild(tfoot);
//tbody部分
for (let i = 0; i < goods.length; i++)
{
    let tr = document.createElement("tr");
    for (let j in goods[i])
    {
        let td = document.createElement("td");
        td.innerHTML = goods[i][j];
        tr.appendChild(td);
    }
    //小计
    let td_money = document.createElement("td");
    td_money.setAttribute("class", "all_money");
    td_money.innerHTML = goods[i].price * goods[i].count;
    tr.appendChild(td_money);
    //按钮
    let td_button = document.createElement("td");
    let input = document.createElement("input");
    input.setAttribute("type", "button");
    input.setAttribute("value", "移除购物车");
    input.setAttribute("onclick", "button_delete(this)");
    td_button.appendChild(input);
    tr.appendChild(td_button);
    tbody.appendChild(tr);
}
//tfoot部分
let tr_tfoot = document.createElement("tr");
let td_all = document.createElement("td");
let td_money = document.createElement("td");

td_all.innerHTML = "总计";
td_money.setAttribute("class", "money");
td_money.setAttribute("colspan", "5");
tr_tfoot.appendChild(td_all);
tr_tfoot.appendChild(td_money);
tfoot.appendChild(tr_tfoot);

document.body.appendChild(table);

//删除函数
function button_delete(input)
{
    input.parentElement.parentElement.parentElement.removeChild(input.parentElement.parentElement);
    let gid = input.parentElement.parentElement.getElementsByTagName("td")[0].innerHTML;
    for (let i = 0; i < goods.length; i++)
    {
        if (goods[i].gid == gid)
        {
            delete goods[i];
            goods.length--;
        }
    }
    td_money.innerHTML = getMoney();
}

//设置总价
function getMoney()
{
    var money_length = document.getElementsByClassName('all_money').length;
    var all_money = document.getElementsByClassName("all_money");
    var money = 0;
    for (let i = 0; i < money_length; i++)
    {
        money = money + all_money[i].innerHTML * 1;
    }
    return money;
}

td_money.innerHTML = getMoney();


