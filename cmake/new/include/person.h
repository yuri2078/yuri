#ifndef PERSON_H
#define PERSON_H

#include <iostream>

class Person {
private:
  int age;
  std::string name;

public:
  Person();
  Person(const int age, const std::string &name);

  friend std::ostream & operator<<(std::ostream &cout,const Person &person);

  virtual ~Person();
};

#endif /* PERSON_H */
