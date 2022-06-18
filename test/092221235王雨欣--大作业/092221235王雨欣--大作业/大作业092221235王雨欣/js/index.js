const dom = document.querySelector('.hover-box')
const ele = document.querySelector('.hover-select')
const selectBox = document.querySelectorAll('#section-bar-4 .el-card')

// 旅游景点鼠标移入
dom.addEventListener('mouseover', function () {
  if (dom.classList.contains('tab-current')) {
    ele.style.display = 'block'
  }
})

// 旅游景点鼠标移出
dom.addEventListener('mouseleave', function () {
  ele.style.display = 'none'
})

// 旅游景点点击
dom.onclick = (type) => {
  selectBox.forEach((item, index) => {
    item.style.display = 'flex'
  })
}

// 下拉框点击
ele.onclick = function (e) {
  selectBox.forEach((item, index) => {
    if (item.dataset.name === e.target.innerText) {
      item.style.display = 'block'
    } else {
      item.style.display = 'none'
    }
  })
  e.stopPropagation()
}
