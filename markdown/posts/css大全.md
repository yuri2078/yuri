---
title: css大全
author: yuri2078
avatar: 'https://cdn.jsdelivr.net/gh/yuri2078/images/img/custom/avatar.jpg'
authorLink: 'https://2078.site'
authorAbout: 一般过路人
authorDesc: 一般过路人
categories: 小记
comments: true
description: '我的爱宛如孤岛之花，不为人知的绽放,不为人知的凋零！'
photos: 'https://cdn.jsdelivr.net/gh/yuri2078/images/headPictures/16.png'
date: 2022-08-04 19:11:49
tags: web
keywords:
---


## 文本

### direction

1. 定义 属性规定文本的方向 / 书写方向。

2. 语法 direction:ltr|rtl|inherit;

3. 属性值

4. | 值      | 描述                                      |
   | ------- | ----------------------------------------- |
   | ltr     | 默认。文本方向从左到右。                  |
   | rtl     | 文本方向从右到左。                        |
   | inherit | 规定应该从父元素继承 direction 属性的值。 |

### letter-spacing

1. 定义 属性增加或减少字符间的空白（字符间距）.

2. 语法 letter-spacing:normal|length|inherit;

3. 属性值

4. | normal  | 默认。规定字符间没有额外的空间。               |
   | ------- | ---------------------------------------------- |
   | length  | 定义字符间的固定空间（允许使用负值）。         |
   | inherit | 规定应该从父元素继承 letter-spacing 属性的值。 |

### line-height

1. 定义 属性设置行间的距离（行高）。。

2. 语法 line-height:normal|number|length|%|inherit;

3. 属性值

4. | normal  | 默认。设置合理的行间距。                             |
   | ------- | ---------------------------------------------------- |
   | number  | 设置数字，此数字会与当前的字体尺寸相乘来设置行间距。 |
   | length  | 设置固定的行间距。                                   |
   | %       | 基于当前字体尺寸的百分比行间距。                     |
   | inherit | 规定应该从父元素继承 line-height 属性的值。          |

### text-align

1. 定义 属性规定元素中的文本的水平对齐方式。

2. 语法 text-align:left|right|center|justify|inherit;

3. 属性值

4. | left    | 把文本排列到左边。默认值：由浏览器决定。   |
   | ------- | ------------------------------------------ |
   | right   | 把文本排列到右边。                         |
   | center  | 把文本排列到中间。                         |
   | justify | 实现两端对齐文本效果。                     |
   | inherit | 规定应该从父元素继承 text-align 属性的值。 |

### text-decoration

1. 定义 属性规定添加到文本的修饰。

2. 语法 text-decoration：none|underline|overline|line-through|blink|inherit;

3. 属性值

4. | none         | 默认。定义标准的文本。                          |
   | ------------ | ----------------------------------------------- |
   | underline    | 定义文本下的一条线。                            |
   | overline     | 定义文本上的一条线。                            |
   | line-through | 定义穿过文本下的一条线。                        |
   | inherit      | 规定应该从父元素继承 text-decoration 属性的值。 |

### text-indent

1. 定义 属性规定文本块中首行文本的缩进。

2. 语法 text-indent：length|%|inherit;

3. 属性值

4. | length  | 定义固定的缩进。默认值：0。                 |
   | ------- | ------------------------------------------- |
   | %       | 定义基于父元素宽度的百分比的缩进。          |
   | inherit | 规定应该从父元素继承 text-indent 属性的值。 |

### text-overflow

1. 定义 属性规定当文本溢出包含元素时发生的事情

2. 语法 text-overflow: clip|ellipsis|string;

3. 属性值 

4. | 值       | 描述                                 |
   | -------- | ------------------------------------ |
   | clip     | 修剪文本。                           |
   | ellipsis | 显示省略符号来代表被修剪的文本。     |
   | string   | 使用给定的字符串来代表被修剪的文本。 |

### text-shadow

1. 定义 属性连接一个或更多的阴影文本。

2. 语法 text-shadow: h-shadow v-shadow blur color;

3. 属性值 

4. | 值       | 描述                                                         |
   | -------- | ------------------------------------------------------------ |
   | h-shadow | 必需。水平阴影的位置。允许负值。                             |
   | v-shadow | 必需。垂直阴影的位置。允许负值。                             |
   | blur     | 可选。模糊的距离。                                           |
   | color    | 可选。阴影的颜色。参阅 [CSS 颜色值。](http://bbs.fishc.com/thread-81599-1-1.html) |

### text-transform

1. 定义 属性控制文本的大小写。

2. 语法 text-transform:none|capitalize|uppercase|lowercase|inherit;

3. 属性值 

4. | 值         | 描述                                           |
   | ---------- | ---------------------------------------------- |
   | none       | 默认。定义带有小写字母和大写字母的标准的文本。 |
   | capitalize | 文本中的每个单词以大写字母开头。               |
   | uppercase  | 定义仅有大写字母。                             |
   | lowercase  | 定义无大写字母，仅有小写字母。                 |
   | inherit    | 规定应该从父元素继承 text-transform 属性的值。 |

## 字体

### @font-face

1. 定义 网页设计师再也不必使用的”web-safe”的字体之一。

2. 语法 @font-face

   {

   font-properties

   }

3. 属性值 

4. | 值            | 说明 （索引中有详细介绍）                                    |
   | ------------- | ------------------------------------------------------------ |
   | font-family   | 必需的。定义字体的名称。                                     |
   | src           | 应该从父元素继承 opacity 属性的值。                          |
   | font-stretch  | 可选。定义该字体应该如何被拉长。默认值是”正常”               |
   | font-style    | 可选。定义该字体应该是怎样样式。默认值是”正常”               |
   | font-weight   | 可选。定义字体的粗细。默认值是”正常”                         |
   | unicode-range | 可选。定义该字体支持Unicode字符的范围。默认值是”ü+0-10 FFFF” |

### font-family

1. 定义 规定元素的字体系列。

2. 语法   font-family:"A",B,...,C;

3. 属性值 

4. | 值                         | 说明 （索引中有详细介绍）                                    |
   | -------------------------- | ------------------------------------------------------------ |
   | family-name generic-family | 用于某个元素的字体族名称或/及类族名称的一个优先表。默认值：取决于浏览器。 |
   | inherit                    | 定应该从父元素继承字体系列。                                 |

### font-size

1. 定义 属性可设置字体的尺寸。

2. 语法   font-size:A|smaller|larger|length|%|inherit

3. 属性值 

4. | 值                                                           | 说明 （索引中有详细介绍）                                    |
   | ------------------------------------------------------------ | ------------------------------------------------------------ |
   | A(xx-small、x-small、small、medium、large、x-large、xx-large) | 把字体的尺寸设置为不同的尺寸，从 xx-small 到 xx-large。默认值：medium。 |
   | smaller                                                      | 把 font-size 设置为比父元素更小的尺寸。                      |
   | larger                                                       | 把 font-size 设置为比父元素更大的尺寸。                      |
   | length                                                       | 把 font-size 设置为一个固定的值。                            |
   | %                                                            | 把 font-size 设置为基于父元素的一个百分比值。                |
   | inherit                                                      | 定应该从父元素继承字体系列。                                 |

### font-style

1. 定义 属性定义字体的风格。

2. 语法 font-style:normal|italic|oblique|inherit;

3. 属性值 

4. | 值      | 说明 （索引中有详细介绍）              |
   | ------- | -------------------------------------- |
   | normal  | 默认值。浏览器显示一个标准的字体样式。 |
   | italic  | 浏览器会显示一个斜体的字体样式。       |
   | oblique | 浏览器会显示一个倾斜的字体样式。       |
   | inherit | 规定应该从父元素继承字体样式。         |

### font-variant

1. 定义 属性设置小型大写字母的字体显示文本，这意味着所有的小写字母均会被转换为大写

2. 语法 font-variant:normal|small-caps|inherit;

3. 属性值 

4. | 值         | 说明 （索引中有详细介绍）                    |
   | ---------- | -------------------------------------------- |
   | normal     | 默认值。浏览器会显示一个标准的字体。         |
   | small-caps | 浏览器会显示小型大写字母的字体。             |
   | inherit    | 规定应该从父元素继承 font-variant 属性的值。 |

### font-weight

1. 定义 属性设置文本的粗细。

2. 语法 font-weight:normal|bold|bolder|lighter|100-900|inherit;

3. 属性值 

4. | 值                                          | 说明 （索引中有详细介绍）                                   |
   | ------------------------------------------- | ----------------------------------------------------------- |
   | normal                                      | 默认值。定义标准的字符。                                    |
   | bold                                        | 定义粗体字符。                                              |
   | bolder                                      | 定义更粗的字符。                                            |
   | lighter                                     | 定义更细的字符。                                            |
   | 100、200、300、400、500、600、700、800、900 | 定义由粗到细的字符。400 等同于 normal，而 700 等同于 bold。 |
   | inherit                                     | 规定应该从父元素继承字体的粗细。                            |

## 位置

### clear

1. 定义 属性指定段落的左侧或右侧不允许浮动的元素。

2. 语法  clear:none|left|right|both|inherit;

3. 属性值 

4. | 值      | 说明 （索引中有详细介绍）             |
   | ------- | ------------------------------------- |
   | none    | 默认值。允许浮动元素出现在两侧。      |
   | left    | 在左侧不允许浮动元素。                |
   | right   | 在右侧不允许浮动元素。                |
   | both    | 在左右两侧均不允许浮动元素。          |
   | inherit | 规定应该从父元素继承 clear 属性的值。 |

###  clip 

1. 定义 属性剪裁绝对定位元素。

2. 语法 clip:shape|auto|inherit;

3. 属性值 

4. | 值      | 说明 （索引中有详细介绍）                                    |
   | ------- | ------------------------------------------------------------ |
   | auto    | 默认值。不应用任何剪裁。                                     |
   | shape   | 设置元素的形状。唯一合法的形状值是：rect (top, right, bottom, left) |
   | inherit | 规定应该从父元素继承 clip 属性的值。                         |

###  cursor

1. 定义 属性定义了鼠标指针放在一个元素边界范围内时所用的光标形状

2. 语法 cursor:url|default|auto|A;

3. 属性值 

4. | 值        | 说明 （索引中有详细介绍）                                    |
   | --------- | ------------------------------------------------------------ |
   | auto      | 默认。浏览器设置的光标。                                     |
   | url       | 需使用的自定义光标的 URL。注释：请在此列表的末端始终定义一种普通的光标，以防没有由 URL 定义的可用光标。 |
   | auto      | 默认。浏览器设置的光标。                                     |
   | crosshair | 光标呈现为十字线。                                           |
   | pointer   | 光标呈现为指示链接的指针（一只手）                           |
   | move      | 此光标指示某对象可被移动。                                   |
   | e-resize  | 此光标指示矩形框的边缘可被向右（东）移动。                   |
   | ne-resize | 此光标指示矩形框的边缘可被向上及向右移动（北/东）。          |
   | nw-resize | 此光标指示矩形框的边缘可被向上及向左移动（北/西）。          |
   | n-resize  | 此光标指示矩形框的边缘可被向上（北）移动。                   |
   | se-resize | 此光标指示矩形框的边缘可被向下及向右移动（南/东）。          |
   | sw-resize | 此光标指示矩形框的边缘可被向下及向左移动（南/西）。          |
   | s-resize  | 此光标指示矩形框的边缘可被向下移动（北/西）。                |
   | w-resize  | 此光标指示矩形框的边缘可被向左移动（西）。                   |
   | text      | 此光标指示文本。                                             |
   | wait      | 此光标指示程序正忙（通常是一只表或沙漏）。                   |
   | help      | 此光标指示可用的帮助（通常是一个问号或一个气球）。           |

###  display 

1. 定义 属性规定元素应该生成的框的类型。

2. 语法 display:inline|block|A|;

3. 属性值 

4. | 值                 | 说明 （索引中有详细介绍）                                    |
   | ------------------ | ------------------------------------------------------------ |
   | inline             | 默认。此元素会被显示为内联元素，元素前后没有换行符。         |
   | block              | 此元素将显示为块级元素。                                     |
   | content            | 盒子文本正常绘制，而围绕在盒子中的框并不会生成。             |
   | flex               | 此元素将显示为弹性盒容器。                                   |
   | grid               | 此元素将显示为栅格容器。                                     |
   | inline-block       | 此元素将显示为行内块元素。                                   |
   | inline-flex        | 此元素将显示为行内弹性盒容器。                               |
   | inline-grid        | 此元素将显示为行内栅格容器。                                 |
   | inline-table       | 此元素会作为内联表格来显示（类似 ），表格前后没有换行符。    |
   | list-item          | 此元素会作为列表显示。                                       |
   | run-in             | 此元素会根据上下文作为块级元素或内联元素显示。               |
   | table              | 此元素会作为块级表格来显示（类似 table元素），表格前后带有换行符。 |
   | table-caption      | 此元素会作为一个表格标题显示（类似 caption 元素）。          |
   | table-column-group | 此元素会作为一个或多个列的分组来显示（类似 colgroup 元素）。 |
   | table-header-group | 此元素会作为一个或多个行的分组来显示（类似 thead 元素）。    |
   | table-footer-group | 此元素会作为一个或多个行的分组来显示（类似 tfoot 元素）。    |
   | table-row-group    | 此元素会作为一个或多个行的分组来显示（类似 tbody 元素）。    |
   | table-cell         | 此元素会作为一个表格单元格显示（类似 td 元素）               |
   | table-column       | 此元素会作为一个单元格列显示（类似 col 元素）                |
   | table-row          | 此元素会作为一个表格行显示（类似 tr 元素）。                 |
   | none               | 此元素不会被显示。                                           |
   | initial            | 设置该属性为默认元素。                                       |
   | inherit            | 规定应该从父元素继承 display 属性的值。                      |

###  float 

1. 定义 属性定义元素在哪个方向浮动。

2. 语法 float:none|left|right|inherit;

3. 属性值 

4. | 值      | 说明 （索引中有详细介绍）                            |
   | ------- | ---------------------------------------------------- |
   | none    | 默认值。元素不浮动，并会显示在其在文本中出现的位置。 |
   | left    | 元素向左浮动。                                       |
   | right   | 元素向右浮动。                                       |
   | inherit | 规定应该从父元素继承 float 属性的值。                |

###  top /right / buttom /left

1. 定义 属性规定元素的顶部 / 右边 / 下面 / 左边 边缘。

2. 语法 top:auto|%|length|inherit;

3. 属性值 

4. | 值      | 说明                                               |
   | ------- | -------------------------------------------------- |
   | auto    | 默认值。通过浏览器计算顶边缘的位置。               |
   | %       | 设置以包含元素的百分比计的顶边位置。可使用负值。   |
   | length  | 使用 px、cm 等单位设置元素的顶边位置。可使用负值。 |
   | inherit | 规定应该从父元素继承 top 属性的值。                |

###  overflow 

1. 定义 属性规定当内容溢出元素框时发生的事情。

2. 语法 overflow:visible|hidden|scroll|auto|inherit;

3. 属性值 

4. | 值      | 说明                                                     |
   | ------- | -------------------------------------------------------- |
   | visible | 默认值。内容不会被修剪，会呈现在元素框之外。             |
   | hidden  | 内容会被修剪，并且其余内容是不可见的。                   |
   | scroll  | 内容会被修剪，但是浏览器会显示滚动条以便查看其余的内容。 |
   | auto    | 如果内容被修剪，则浏览器会显示滚动条以便查看其余的内容。 |
   | inherit | 规定应该从父元素继承 overflow 属性的值。                 |

###  position 

1. 定义 属性规定元素的定位类型。

2. 语法 position:static|absolute|relative|fixed|inherit;

3. 属性值 

4. | 值       | 说明                                                         |
   | -------- | ------------------------------------------------------------ |
   | static   | 默认值。没有定位，元素出现在正常的流中（忽略 top, bottom, left, right 或者 z-index 声明）。 |
   | absolute | 生成绝对定位的元素，相对于 static 定位以外的第一个父元素进行定位。元素的位置通过 “left”, “top”, “right” 以及 “bottom” 属性进行规定。 |
   | fixed    | 生成绝对定位的元素，相对于浏览器窗口进行定位。元素的位置通过 “left”, “top”, “right” 以及 “bottom” 属性进行规定。 |
   | relative | 生成相对定位的元素，相对于其正常位置进行定位。因此，”left:20” 会向元素的 LEFT 位置添加 20 像素。 |
   | inherit  | 规定应该从父元素继承 position 属性的值。                     |

###  visibility 

1. 定义 属性规定元素是否可见。

2. 语法 visibility:visible|hidden|collapse|inherit;

3. 属性值 

4. | 值       | 说明                                                         |
   | -------- | ------------------------------------------------------------ |
   | visible  | 默认值。元素是可见的。                                       |
   | hidden   | 元素是不可见的。                                             |
   | collapse | 当在表格元素中使用时，此值可删除一行或一列，但是它不会影响表格的布局。被行或列占据的空间会留给其他内容使用。如果此值被用在其他的元素上，会呈现为 “hidden”。 |
   | inherit  | 规定应该从父元素继承 visibility 属性的值。                   |

###  z-index 

1. 定义  属性设置元素的堆叠顺序。

2. 语法 z-index:auto|number|inherit;

3. 属性值 

4. | 值      | 说明                                    |
   | ------- | --------------------------------------- |
   | auto    | 默认。堆叠顺序与父元素相等。            |
   | number  | 设置元素的堆叠顺序。                    |
   | inherit | 规定应该从父元素继承 z-index 属性的值。 |

###  

1. 定义 
2. 语法 
3. 属性值 



## 边界

###  border-radius

1. 定义 属性是一个简写属性，用于设置四个 border-*-radius 属性。

2. 语法 border-radius: 1-4 length|% / 1-4 length|%;

3. 属性值 

4. | 值     | 描述                     |
   | ------ | ------------------------ |
   | length | 定义圆角的形状。         |
   | %      | 以百分比定义圆角的形状。 |

###  box-shadow

1. 定义 性向框添加一个或多个阴影。

2. 语法 box-shadow: h-shadow v-shadow blur spread color inset;

3. 属性值 

4. | 值       | 描述                                 |
   | -------- | ------------------------------------ |
   | h-shadow | 必需。水平阴影的位置。允许负值。     |
   | v-shadow | 必需。垂直阴影的位置。允许负值。     |
   | blur     | 可选。模糊距离。                     |
   | spread   | 可选。阴影的尺寸。                   |
   | color    | 可选。阴影的颜色。                   |
   | inset    | 可选。将外部阴影 (outset) 改为内部阴 |

###  outline 

1. 定义 （轮廓）是绘制于元素周围的一条线，位于边框边缘的外围，可起到突出元素的作用

2. 语法 outline:outline-color|outline-style|outline-width|inherit;

3. 属性值 

4. | 值                                                           | 描述                                      |
   | ------------------------------------------------------------ | ----------------------------------------- |
   | [`outline-color`](https://man.ilovefishc.com/page/outline-color.html) | 规定边框的颜色。                          |
   | [`outline-style`](https://man.ilovefishc.com/page/outline-style.html) | 规定边框的样式。                          |
   | [`outline-width`](https://man.ilovefishc.com/page/outline-width.html) | 规定边框的宽度。                          |
   | inherit                                                      | 规定应该从父元素继承 outline 属性的设置。 |

1. 定义 
2. 语法 
3. 属性值 

###  

1. 定义 
2. 语法 
3. 属性值 

###  

1. 定义 
2. 语法 
3. 属性值 

###  

1. 定义 
2. 语法 
3. 属性值 

###  

1. 定义 
2. 语法 
3. 属性值 

###  

1. 定义 
2. 语法 
3. 属性值 

###  

1. 定义 
2. 语法 
3. 属性值 

###  

1. 定义 
2. 语法 
3. 属性值 

###  

1. 定义 
2. 语法 
3. 属性值 

###  

1. 定义 
2. 语法 
3. 属性值 

###  

1. 定义 
2. 语法 
3. 属性值 



## 2d/3d

###  transform

1. 定义 属性应用于元素的2D或3D转换。

2. 语法 transform: none|transform-functions;

3. 属性值 

4. | 值                                        | 说明                                    |
   | ----------------------------------------- | --------------------------------------- |
   | none                                      | 定义不进行转换。                        |
   | matrix(n,n,n,n,n,n)                       | 定义 2D 转换，使用六个值的矩阵。        |
   | matrix3d(n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n) | 定义 3D 转换，使用 16 个值的 4x4 矩阵。 |
   | translate(x,y)                            | 定义 2D 转换。                          |
   | translate3d(x,y,z)                        | 定义 3D 转换。                          |
   | translateX(x)                             | 定义转换，只是用 X 轴的值。             |
   | translateY(y)                             | 定义转换，只是用 Y 轴的值。             |
   | translateZ(z)                             | 定义 3D 转换，只是用 Z 轴的值。         |
   | scale(x[,y]?)                             | 定义 2D 缩放转换。                      |
   | scale3d(x,y,z)                            | 定义 3D 缩放转换。                      |
   | scaleX(x)                                 | 通过设置 X 轴的值来定义缩放转换。       |
   | scaleY(y)                                 | 通过设置 Y 轴的值来定义缩放转换。       |
   | scaleZ(z)                                 | 通过设置 Z 轴的值来定义 3D 缩放转换。   |
   | rotate(angle)                             | 定义 2D 旋转，在参数中规定角度。        |
   | rotate3d(x,y,z,angle)                     | 定义 3D 旋转。                          |
   | rotateX(angle)                            | 定义沿着 X 轴的 3D 旋转。               |
   | rotateY(angle)                            | 定义沿着 Y 轴的 3D 旋转。               |
   | rotateZ(angle)                            | 定义沿着 Z 轴的 3D 旋转。               |
   | skew(x-angle,y-angle)                     | 定义沿着 X 和 Y 轴的 2D 倾斜转换。      |
   | skewX(angle)                              | 定义沿着 X 轴的 2D 倾斜转换。           |
   | skewY(angle)                              | 定义沿着 Y 轴的 2D 倾斜转换。           |
   | perspective(n)                            | 为 3D 转换元素定义透视视图。            |

###   transform-Origin

1. 定义 属性允许更改转换元素的位置。

2. 语法 transform-origin: x-axis y-axis z-axis;

3. 属性值 

4. | 值     | 说明                                                         |
   | ------ | ------------------------------------------------------------ |
   | x-axis | 定义视图被置于 X 轴的何处。可能的值：left、center、right、length、% |
   | y-axis | 定义视图被置于 Y 轴的何处。可能的值：top、center、bottom、length、% |
   | z-axis | 定义视图被置于 Z 轴的何处。可能的值：length                  |

###  

1. 定义 
2. 语法 
3. 属性值 

###  

1. 定义 
2. 语法 
3. 属性值 

###  

1. 定义 
2. 语法 
3. 属性值 

###  

1. 定义 
2. 语法 
3. 属性值 

###  

1. 定义 
2. 语法 
3. 属性值 





























# 杂项知识

## css

1. calc(100% + 10px) 裁剪函数
1. filter: blur(2px); 模糊效果