#include "../include/person.h"

Person::Person(const int age, const std::string &name) : age(age), name(name) {

}

Person::~Person() {

}

std::ostream & operator<<(std::ostream &cout, const Person &person) {
  cout << "age -> " <<  person.age << " name -> " << person.name << "\n";
  return cout;
}
