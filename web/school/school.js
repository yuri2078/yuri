function scheduleHtmlProvider(iframeContent = "", frameContent = "", dom = document) {//函数名不要动
    return dom.getElementById('kbgrid_table_0').outerHTML
  }
  
  function scheduleHtmlParser(html) {
    let result = [] // 总数据属组
    // 加载html
    let $ = cheerio.load(html, {
      decodeEntities: false
    })
  
    // 遍历tbody 内容 -> tr
    $('tbody').children().each(function (i, tr) {
      // 遍历tr 内容 -> td
      $(tr).children().each(function (j, td) {
        // 获取id 厂里工td id 比如 2-1 代表星期二的第一节课
        currer_id = $(td).attr('id')
        // 排除没课的日子
        if (currer_id != undefined && $('#' + currer_id).children().length > 0) {
          $('#' + currer_id).children().each(function (k, p) {
            // 存储数据
            let data = {}
            data['name'] = $(p.firstChild).text()
            data['position'] = /[^东南校区\s | ^东湖校区\s]+/.exec($(p.children[2]).text()) + '' // 地点去除校区，自己什么校区的你不知道？
            // data['position'] = /[^墨轩湖校区\s]+/.exec($(p.children[2]).text()) + '' // 地点去除校区，自己什么校区的你不知道？
            data['teacher'] = $(p.children[3]).text()
            let string = $(p.children[1]).text() //  (7-8节)6周,10周,13-15周(单)
            let sec = Number(/^\d/.exec(/\d-{1}\d{1,2}节{1}/.exec(string) + '') + '') // 每节课的起始节数
  
            // 开始处理上课周数
  
            // 正则表达式优先提取带（单）（双）的课
            let reg = /\d{1,2}-{1}\d{1,2}周{1}\(.\)|\d{1,2}-{1}\d{1,2}周{1}|\d{1,2}周{1}/
            // set过滤重复的周数
            let weeks_set = new Set
            // 不断查找防止出现 (7-8节)6周,10周,13-15周(单) 这种鬼情况
            while (reg.test(string)) {
              // 保存找到的字符转
              let str = reg.exec(string) + ''
              // 将处理过的周数删除准备重新查找
              string = string.replace(str, '')
              // 如果带有-符号就是连续的周数
              if (str.includes('-')) {
                // 如果是单周或者双周将flag 置为2 每两周有一次课
                let flag = str.includes('单') || str.includes('双') ? 2 : 1
                let start = Number(/^\d{1,2}/.exec(str) + '') // 设置起始周数
                let end = Number(/^\d{1,2}/.exec(/\d{1,2}周/.exec(str) + '') + '') // 设置结束周数
  
                // 不断循环添加周数
                while (start <= end) {
                  weeks_set.add(start)
                  start += flag
                }
                // 不带连续符号的周数直接添加就行了
              } else {
                weeks_set.add(Number(/\d{1,2}/.exec(str) + ''))
              }
            }
            // 将set转为array属组
            let weeks = Array.from(weeks_set)
            // 升序排序
            weeks.sort((a, b) => a - b)
  
            data['weeks'] = weeks // 添加周数
            data['day'] = Number(/^\d/.exec(currer_id) + '') // 添加上课日期
            data['sections'] = [sec, sec + 1] // 添加课程节数
            result.push(data) // 添加准备的数据
          })
        }
      })
    })
    return result
  }
  
  async function scheduleTimer() {
    // 支持异步操作 推荐await写法
    // 返回时间配置JSON，所有项都为可选项，如果不进行时间配置，请返回空对象
  
    return {
      totalWeek: 16, // 总周数：[1, 30]之间的整数
      //   startSemester: '2023-2-20', // 开学时间：时间戳，13位长度字符串，推荐用代码生成
      startWithSunday: false, // 是否是周日为起始日，该选项为true时，会开启显示周末选项
      showWeekend: false, // 是否显示周末
      forenoon: 4, // 上午课程节数：[1, 10]之间的整数
      afternoon: 4, // 下午课程节数：[0, 10]之间的整数
      night: 2, // 晚间课程节数：[0, 10]之间的整数
      sections: [{
        section: 1,
        startTime: "08:50",
        endTime: "08:50"
      },
      {
        section: 2,
        startTime: "09:00",
        endTime: "09:50"
      },
      {
        section: 3,
        startTime: "10:10",
        endTime: "11:00"
      },
      {
        section: 4,
        startTime: "11:10",
        endTime: "12:00"
      },
      {
        section: 5,
        startTime: "13:30",
        endTime: "14:20"
      },
      {
        section: 6,
        startTime: "14:30",
        endTime: "15:20"
      },
      {
        section: 7,
        startTime: "15:40",
        endTime: "16:30"
      },
      {
        section: 8,
        startTime: "16:40",
        endTime: "17:30"
      },
      {
        section: 9,
        startTime: "18:30",
        endTime: "19:20"
      },
      {
        section: 10,
        startTime: "19:30",
        endTime: "20:20"
      }
      ], // 课程时间表，注意：总长度要和上边配置的节数加和对齐
    }
    // PS: 夏令时什么的还是让用户在夏令时的时候重新导入一遍吧，在这个函数里边适配吧！奥里给！————不愿意透露姓名的嘤某人
  }
  
  