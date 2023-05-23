// 返回String
pub fn get_name() -> String {
  // Stringr:from("yuri") 么有return 默认返回最后一句
  return String::from("yuri");
}

// 返回字符串
pub fn get_str() -> &'static str {
  return "yuri is yes";
}

// 复杂类型，直接值传递，那么之前的就不能使用
fn use_and(name:String) {
  println!("name -> {}", name);
}
// 引用传递
fn use_val(name:&String) {
  println!("name -> {}", name);
}

//fn print(val:&i32) {
//  println!("val -> {}", val);
//}

fn print(mut val:&mut i32) {
  *val = 666;
}

pub fn main() {
  println!("{}", get_name());
  println!("str -> {}", get_str());
  let name = String::from("marry");
  use_val(&name);
  println!("name -> {}", name); // 可以使用
  use_and(name);
  // println!("name -> {}", name); 不能使用
  let mut val = 66; 
  println!("val -> {}", val);
  print(&mut val);
  println!("val -> {}", val);
}
