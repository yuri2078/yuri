'use strict'
function heredoc(fn)
{
    return fn.toString().split('\n').slice(1, -1).join('\n') + '\n';
}
var obj = heredoc(function(){/*
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
    "stu_id": "092021102",
    "stu_name": "赖天佑",
    "gender": "男",
    "math": 72,
    "english": 78,
    "computer": 73,
    "total": ""
  },
  {
    "stu_id": "092021103",
    "stu_name": "熊英叡",
    "gender": "男",
    "math": 76,
    "english": 60,
    "computer": 67,
    "total": ""
  },
  {
    "stu_id": "092021104",
    "stu_name": "邵锐泽",
    "gender": "男",
    "math": 84,
    "english": 67,
    "computer": 68,
    "total": ""
  },
  {
    "stu_id": "092021105",
    "stu_name": "熊元基",
    "gender": "男",
    "math": 69,
    "english": 61,
    "computer": 69,
    "total": ""
  },
  {
    "stu_id": "092021106",
    "stu_name": "傅阳成",
    "gender": "男",
    "math": 91,
    "english": 93,
    "computer": 67,
    "total": ""
  },
  {
    "stu_id": "092021107",
    "stu_name": "文光启",
    "gender": "男",
    "math": 84,
    "english": 87,
    "computer": 66,
    "total": ""
  },
  {
    "stu_id": "092021108",
    "stu_name": "郭鸿羲",
    "gender": "男",
    "math": 62,
    "english": 72,
    "computer": 94,
    "total": ""
  },
  {
    "stu_id": "092021109",
    "stu_name": "姚俊人",
    "gender": "男",
    "math": 92,
    "english": 67,
    "computer": 71,
    "total": ""
  },
  {
    "stu_id": "092021110",
    "stu_name": "顾俊雄",
    "gender": "男",
    "math": 71,
    "english": 86,
    "computer": 77,
    "total": ""
  },
  {
    "stu_id": "092021111",
    "stu_name": "段碧莹",
    "gender": "女",
    "math": 85,
    "english": 73,
    "computer": 75,
    "total": ""
  },
  {
    "stu_id": "092021112",
    "stu_name": "方忻乐",
    "gender": "女",
    "math": 71,
    "english": 65,
    "computer": 87,
    "total": ""
  },
  {
    "stu_id": "092021113",
    "stu_name": "林慕凝",
    "gender": "女",
    "math": 84,
    "english": 97,
    "computer": 69,
    "total": ""
  },
  {
    "stu_id": "092021114",
    "stu_name": "尹雁丝",
    "gender": "女",
    "math": 86,
    "english": 96,
    "computer": 91,
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
let number = 666;