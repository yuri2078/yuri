let thead_td = document.getElementsByTagName("thead")[0].getElementsByTagName("tr")[0].getElementsByTagName("td");
let title = Array(thead_td.length); //新建标题数组存储标题
for (let i = 0; i < thead_td.length; i++) //将标题存储进去
{
    title[i] = thead_td[i].innerHTML;
    thead_td[i].setAttribute("onclick", "title_onclick(this)");
}

//新建对象数组
let student = new Array();
//循环新建对象
let tbody_tr = document.getElementsByTagName("tbody")[0].getElementsByTagName("tr");
for (let i = 0; i < tbody_tr.length; i++)
{
    let information = new Object();
    for (let j = 0; j < tbody_tr[i].getElementsByTagName("td").length; j++)
    {
        let td = tbody_tr[i].getElementsByTagName("td")[j];
        td.setAttribute("class", "col-" + j);
        information[title[j]] = td.innerHTML;
    }
    student.push(information);
}
var f = 1;
function title_onclick(obj)
{
    //判断是不是姓名，是姓名就采用拼音排序
    if (obj.innerHTML == "姓名")
    {
        for (let i = 0; i < student.length; i++)
        {
            for (let j = i + 1; j < student.length; j++)
            {
                if (student[i][obj.innerHTML].localeCompare(student[j][obj.innerHTML]) == 1)
                {
                    let temp = student[i];
                    student[i] = student[j];
                    student[j] = temp;
                }
            }
        }
    }
    else
    {
        for (let i = 0; i < student.length; i++)
        {
            for (let j = i + 1; j < student.length; j++)
            {
                if (student[i][obj.innerHTML] > student[j][obj.innerHTML])
                {
                    let temp = student[i];
                    student[i] = student[j];
                    student[j] = temp;
                }
            }
        }
    }
    //实现反向排序
    if (f == -1)
    {
        student.reverse();
    }
    f = -f;
    set_table();
}

//排序后重新建立表格
function set_table()
{
    let tbody = document.getElementsByTagName("tbody")[0];
    tbody.innerHTML = "";
    for (let i = 0; i < student.length; i++)
    {
        let tr = document.createElement("tr");
        for (let j in student[i])
        {
            let td = document.createElement("td");
            td.innerHTML = student[i][j];
            tr.appendChild(td);
        }
        tbody.appendChild(tr);
    }
}