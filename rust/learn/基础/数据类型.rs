pub fn main() {

  // let 关键字声明类型，如果没有指明mut那么该类型是不可变的。
  // let mut num =  66; 这有这样类型才是可变的
  // let 声明的变量可以被覆写或者改变类型，以最新的为主
  let num = 66;
  let number:u8 = 128;
  // i 表示 有符号， u 表示无符号
  // 可选 8 16 32 64 128 arch : 跟随计算机 x64 -> 64 x86 -> 32
  // isize 有符号数据， usize 无符号数据
  // i32 默认类型
  println!("num -> {}, number -> {}", num, number);


  let pri = 33.3; 
  let price:f64 = 1_000_000.0;
  // f32 单精度浮点型
  // f64 双精度浮点型
  // f64 默认类型
  // 当可读性差的时候使用下划线增加可读性
  println!("pri -> {}, price -> {}", pri, price);


  let flag:bool = true;
  // bool类型
  println!("flag -> {}", flag);
 
  
  let c:char = 'y';
  // 使用utf-8 作为底层编码，而不是asill
  println!("c -> {}", c);
  
  
  // 常量
  const PI:f64 = 3.1415926;
  // const 是常量，不可以被更改，也不可以被重新覆写
  // 常量会在编译期间替换
  println!("pi -> {}", PI);


  let name:&str = "yuri is yes";
  // 字符串类型 
  println!("str -> {}", name);


  let _name:String = String::new(); // 新建对象
  let name:String = String::from("yuri is yes"); // 从别的常量字符串中构建
  // 这是pub中的字符串对象，并不是rust内置类型
  println!("string -> {}, len -> {}", name, name.len());


  for c in "yuri is yes".chars() {
    print!("{} ", c);
  }
  println!();

  if true {
    println!("true");
  } else {
    println!("false");
  }

  let ret = match "yuri" {
    "yuri" => "百合",
    _ => "别的"
  };
  println!("ret -> {}", ret);

  // 循环遍历，左开右闭
  // 1..=5 表示包括右边
  for n in 1..5 {
    print!("{} ", n);
  }

  print!("\n");

  let books = vec![
    "你我的双人间",
    "温热的银莲花",
    "请欺负我吧，恶役小姐!"
  ];

  // iter 迭代器，迭代完了仍然可以使用
  // into_iter() 迭代完了不可使用，等于删除
  for book in books.iter() {
    // 迭代的类型是引用类型，不是具体的值
    // 所以用match匹配是需要加上 &
    // 不然就要用 match *book 了
    match book {
      &"请欺负我吧，恶役小姐!" =>  println!("daisiki!"),
      _ => println!("这个也很喜欢捏")
    }
  }

  println!("books -> {}", books.len());

  for book in books.into_iter() {
    println!("{}", book);
  }
  // 已经没有东西了，下面会报错
  // println!("books -> {}", books.len());
  
  let mut books = vec![
    "你我的双人间",
    "温热的银莲花",
    "请欺负我吧，恶役小姐!"
  ];

  // 可以更改的类型
  for book in books.iter_mut() {
    *book = match book {
      &mut "你我的双人间" =>  "你我的双人间!",
      _ => *book
    }
  }

  for book in books.iter() {
    println!("{}", book);
  }

  while true {
    break;
  }

  loop {
    break;
  }
  
}
