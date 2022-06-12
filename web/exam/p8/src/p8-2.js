function set_name()
{
    
    if (document.getElementById("select-name") == null)
    {
        let select_name = document.createElement("select");
        select_name.setAttribute("id", "select-name");
        document.body.appendChild(select_name);
        for (let i = 0; i < school[0].college.length; i++)
        {
            let option = document.createElement("option");
            option.innerHTML = school[0].college[i].name;
            select_name.appendChild(option);
        }
    }
    else 
    {
        let select_name = document.getElementById("select-name");
        select_name.innerHTML = "";
        let select_year = document.getElementById("select-year");
        //获取year
        let year = select_year.options[select_year.selectedIndex].text; 
        for (let i = 0; i < school[year-2019].college.length; i++)
        {
            let option = document.createElement("option");
            option.innerHTML = school[year-2019].college[i].name;
            select_name.appendChild(option);
        }
        let major = select_name.options[select_name.selectedIndex].text;
        let i;
        for (i = 0; i < school[year - 2019].college.length; i++)
        {
            if (school[year - 2019].college[i].name == major)
            {
                console.log(major);
                break;
            }
        }
    }
}

function set_year()
{
    
    if (document.getElementById("select-year") == null)
    {
        let select_year = document.createElement("select");
        select_year.setAttribute("id", "select-year");
        document.body.appendChild(select_year);
        for (let i = 2019; i < 2022; i++)
        {
            let option = document.createElement("option");
            option.innerHTML = i;
            select_year.appendChild(option);
        }
    }
    else 
    {
        let select_year = document.getElementById("select-year");
        select_year.innerHTML = "";
        for (let i = 2019; i < 2022; i++)
        {
            let option = document.createElement("option");
            option.innerHTML = i;
            select_year.appendChild(option);
        }
    }
}


function set_major()
{
    
    if (document.getElementById("select-major") == null)
    {
        let select_major = document.createElement("select");
        select_major.setAttribute("id", "select-major");
        document.body.appendChild(select_major);
        for (let i = 0; i < school[0].college[0].major.length; i++)
        {
            let option = document.createElement("option");
            option.innerHTML = school[0].college[0].major[i];
            select_major.appendChild(option);
        }
    }
    else 
    {
        let select_major = document.getElementById("select-major");
        let select_year = document.getElementById("select-year");
        let year = select_year.options[select_year.selectedIndex].text;
        let name = document.getElementById("select-name");
        let major = name.options[name.selectedIndex].text;
        let i;
        for (i = 0; i < school[year - 2019].college.length; i++)
        {
            if (school[year - 2019].college[i].name == major)
            {
                break;
            }
        }
        if (i == 12)
        {
            alert("该学院今年未招收学生!");
            set_name();
            set_major();
            return 0;
        }
        select_major.innerHTML = "";
        for (let j = 0; j < school[year-2019].college[i].major.length; j++)
        {
            let option = document.createElement("option");
            option.innerHTML = school[year-2019].college[i].major[j];
            select_major.appendChild(option);
        }
    }
}

set_name();

set_year();

set_major();


let select_name = document.getElementById("select-name");
select_name.onchange = function () {
    set_major();
}

let select_year = document.getElementById("select-year");
select_year.onchange = function () {
    set_major();
}



