#include "person.h"
#include <iostream>

Person::Person(std::string name, int age) : person_impl(std::make_unique<PersonImpl>(name, age))
{
  
};

void Person::PersonImpl::eat() {
  std::cout << name << "今年 " << age << " 岁了\n";
}

Person::PersonImpl::PersonImpl(std::string name, int age) {
  this->name = name;
  this->age = age;
}

void Person::eat() {
  person_impl->eat();
}


