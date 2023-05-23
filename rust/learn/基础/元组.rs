fn show(tuple:(&str, i32, f64)) {
  println!("{:?}", tuple);
}

pub fn main() {
  let mut tuple:(&str, i32, f64) = ("yuri", 22, 66.6);
  show(tuple);

  // 使用 名字.0 访问数据
  println!("name -> {}", tuple.0);

  // 加了mut 就可以修改内部的值了
  tuple.0 = "yuri is yes";
  show(tuple); 
}
