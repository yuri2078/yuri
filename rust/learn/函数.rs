pub fn get_name() -> String {
  // String::from("yuri") 么有return 默认返回最后一句
  return String::from("yuri");
}

pub fn get_str() -> &'static str {
  return "yuri is yes";
}


pub fn main() {
  println!("{}", get_name());
  println!("str -> {}", get_str());
}
