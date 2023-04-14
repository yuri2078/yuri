# qt 常用类解析

## QTableView

> QTableView是Qt中的表格视图控件，可以用于显示表格数据。它的底层模型通常是由QAbstractItemModel的子类实现的。下面介绍一些QTableView的常用函数及其参数解析。

### setModel()

> `void setModel(QAbstractItemModel *model)`：

该函数用于设置QTableView的底层数据模型。model参数为QAbstractItemModel类型的指针。

示例：

```cpp
QTableView *tableView = new QTableView;
QStandardItemModel *model = new QStandardItemModel;
tableView->setModel(model);
```

### setSelectionBehavior()

> `void setSelectionBehavior(QAbstractItemView::SelectionBehavior behavior)`：

该函数用于设置选择行为。behavior参数为QAbstractItemView::SelectRows或QAbstractItemView::SelectItems，分别表示选中整行或选中单元格。

`void setSelectionMode(QAbstractItemView::SelectionMode mode)`：

该函数用于设置选择模式。mode参数为QAbstractItemView::SingleSelection或QAbstractItemView::MultiSelection，分别表示单选和多选。

示例：

```cpp
QTableView *tableView = new QTableView;
tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
tableView->setSelectionMode(QAbstractItemView::SingleSelection);
```

### setEditTriggers()

> `void setEditTriggers(QAbstractItemView::EditTriggers triggers)`：

该函数用于设置编辑触发器。triggers参数为一个枚举值，表示何时允许编辑单元格。常见的枚举值有以下几种：

- QAbstractItemView::NoEditTriggers：禁止编辑
- QAbstractItemView::DoubleClicked：双击编辑
- QAbstractItemView::EditKeyPressed：按下Enter键或F2键编辑
- QAbstractItemView::AnyKeyPressed：按下任意键编辑

示例：

```cpp
QTableView *tableView = new QTableView;
tableView->setEditTriggers(QAbstractItemView::DoubleClicked);
```

### setHorizontalHeader() 

> `void setHorizontalHeader(QHeaderView *header)`：

该函数用于设置水平表头。header参数为QHeaderView类型的指针。

`void setVerticalHeader(QHeaderView *header)`：

该函数用于设置垂直表头。header参数为QHeaderView类型的指针。

示例：

```cpp
QTableView *tableView = new QTableView;
QHeaderView *horizontalHeader = new QHeaderView(Qt::Horizontal, tableView);
QHeaderView *verticalHeader = new QHeaderView(Qt::Vertical, tableView);
tableView->setHorizontalHeader(horizontalHeader);
tableView->setVerticalHeader(verticalHeader);
```

### setSortingEnabled()

> `void setSortingEnabled(bool enable)`：

该函数用于启用或禁用排序功能。enable参数为布尔类型，为true时启用排序功能，为false时禁用。

示例：

```cpp
QTableView *tableView = new QTableView;
tableView->setSortingEnabled(true);
```

### setColumnWidth() 

> `void setColumnWidth(int column, int width)`：

该函数用于设置列的宽度。column参数为列的索引，width参数为列的宽度。

`void setRowHeight(int row, int height)`：

该函数用于设置行的高度。row参数为行的索引，height参数为行的高度。

示例：
    
```c++
QTableView *tableView = new QTableView;
tableView->setColumnWidth(0, 100);
tableView->setRowHeight(0, 30);

// 以上是QTableView的一些常用函数及其参数解析。通过这些函数，可以对表格视图进行设置、编辑、排序等操作。在实际开发中，可以根据需要选择合适的函数进行使用。
```

## QSqlQuery

> QSqlQuery是Qt中用于执行SQL语句和访问查询结果的核心类之一。它提供了一系列的成员函数用于执行SQL查询、处理查询结果、获取查询状态等。下面是QSqlQuery的一些常用函数以及它们的参数解析。

### exec() 和 prepare()

> `bool exec(const QString &query)` ：

该函数用于执行一个SQL查询。query参数为一个SQL查询语句（包括SELECT、INSERT、UPDATE、DELETE等），函数返回一个布尔值，用于表示查询是否执行成功。

`bool prepare(const QString &query)`：

该函数用于准备SQL查询。query参数为一个SQL查询语句（包括SELECT、INSERT、UPDATE、DELETE等），但是不会立即执行，而是先进行准备阶段，查询需要时才能立即执行，具有潜在的性能优势。

示例：

```cpp
QSqlQuery query;
query.prepare("INSERT INTO TABLE_NAME (COLUMN1, COLUMN2) VALUES (:param1, :param2)");
query.bindValue(":param1", 123);
query.bindValue(":param2", "Hello");
query.exec();
```

### next() 和 previous()

> `bool next()`：

该函数用于使指针指向查询结果的下一行（如果存在）。函数返回一个布尔值，用于表示是否指向了下一行。

`bool previous()`：

该函数用于使指针指向查询结果的上一行（如果存在）。函数返回一个布尔值，用于表示是否指向了上一行。

示例：

```cpp
QSqlQuery query("SELECT * FROM TABLE_NAME WHERE ID > 1");
while (query.next()) {
    QString name = query.value(0).toString();
    int age = query.value(1).toInt();
    qDebug() << "name = " << name << ", age = " << age;
}
```

### value() 和 record()

> `QVariant value(int index)`：

该函数返回查询结果集中指定列的值（可以根据列的索引或者列名来获取值）。index参数为列的索引或者列名。返回值为一个QVariant类型的值，可以通过toBool()、toInt()、toString()等方法进行类型转换。

`QSqlRecord record() const`：

该函数返回查询结果集的字段清单，即列名、列类型等。返回值为一个QSqlRecord类型的对象，可以通过columnCount()、fieldName()、field()等方法进行操作。

示例：

```cpp
QSqlQuery query("SELECT * FROM TABLE_NAME WHERE ID = 1");
if (query.next()) {
    QString name = query.value(0).toString();
    int age = query.value(1).toInt();
    qDebug() << "name = " << name << ", age = " << age;
}
QSqlRecord record = query.record();
int columnCount = record.count();
for(int i = 0; i < columnCount; ++i) {
    qDebug() << "column " << i << ": " << record.fieldName(i) << " (" << record.field(i).type() << ")";
}
```

### bindValue() 和 bind()

> `bool bindValue(const QString &placeholder, const QVariant &val, QSql::ParamType type = QSql::In)`：

该函数用于绑定一个参数。placeholder参数为占位符，val参数为绑定的值。type参数表示参数的类型，默认为QSql::In，表示输入参数。

`bool bind(int index, const QVariant &val, QSql::ParamType type = QSql::In)`：

该函数用于绑定一个参数。index参数为参数的索引，val参数为绑定的值。type参数表示参数的类型，默认为QSql::In，表示输入参数。

示例：

```cpp
QSqlQuery query;
query.prepare("SELECT * FROM TABLE_NAME WHERE NAME = ?");
query.bindValue(0, "张三");
query.exec();
```

### lastInsertId() 和 numRowsAffected()

> `qint64 lastInsertId() const`：

该函数用于获取最后一次插入记录的自增主键ID。返回值为qint64类型的值。

`int numRowsAffected() const`：

该函数用于获取查询后受到影响的行数。返回值为int类型的值。

示例：

```cpp
QSqlQuery query("INSERT INTO TABLE_NAME (NAME, AGE) VALUES ('张三', 20)");
qDebug() << "Last insert ID: " << query.lastInsertId();
qDebug() << "Num rows affected: " << query.numRowsAffected();
```

以上是QSqlQuery的一些常用函数及其参数解析。通过这些函数，可以实现SQL查询、参数绑定、结果读取等功能。需要根据实际情况进行灵活运用。

## QTableView qss

QTableView控件支持的样式表属性包括：

### 控件属性

- color: 设置内容文本的颜色。
- border: 设置边框，如 border: 1px solid red。
- background-color: 设置背景颜色。
- selection-color: 设置选中单元格中文本的颜色。
- selection-background-color: 设置选中单元格的背景颜色。
- alternate-background-color: 设置交替行的背景颜色。
- gridline-color: 设置网格线的颜色。
- font: 设置字体，如 font-size: 12px; font-family: Arial;。

### 子元素选择器

QTableView的子元素包括QHeaderView，可以通过以下样式选择器设置：

- QHeaderView::section: 设置表头的样式。可以修改表头高度、背景色、文字颜色等，如 QHeaderView::section { background-color: black; color:white; height:30px; }。
- QHeaderView::down-arrow/QHeaderView::up-arrow: 设置表头排序箭头的样式，如 QHeaderView::down-arrow { image: url(path/to/down_arrow.png); }。
- QHeaderView::section:checked: 设置表头复选框选中时的样式。
- QHeaderView::section:horizontal/ QHeaderView::section:vertical: 分别设置水平、垂直方向的表头的样式。

另外，QTableView还具有一些基类QAbstractItemView定义的样式控制属性，如：

- QAbstractItemView::item: 表示单元格的属性，可以控制单元格的颜色、字体、箭头等样式。
- QAbstractItemView::item:selected: 表示选中的单元格，可以控制选中行、列或单元格的背景色和字体颜色等样式。
- QAbstractItemView::item:checked: 表示多选框或单选框选中的状态。
- QAbstractItemView::branch: 表示树状结构的展开/收缩节点的样式。
- QAbstractItemView::indicator: 表示多选框或单选框的样式。

需要注意的是，由于每个QTableView的样式是不同的，需要根据实际情况进行样式调整，可以通过在样式表中使用QSS的子元素选择器来调整各个子元素的样式。