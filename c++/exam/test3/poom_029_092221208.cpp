#include <iostream>
#include <cstring>
class charPerson
{
public:
    virtual void talk() = 0;
    virtual void kind_hearted() = 0;
};

class Person : public charPerson
{
private:
    char personTalk[20];
    char personKind_hearted[20];

public:
    Person(const char *personTalk, const char *personKind_hearted)
    {
        strcpy(this->personTalk, personTalk);
        strcpy(this->personKind_hearted, personKind_hearted);
    }
    void talk()
    {
        std::cout << personTalk << "\n";
    }
    void kind_hearted()
    {
        std::cout << personKind_hearted << "\n";
    }
};

void nature(Person &p)
{
    p.talk();
    p.kind_hearted();
}

int main()
{
    Person personA("沉默寡言", "乐于助人");
    Person personB("滔滔不绝", "非常冷漠");
    Person personC("惜字如金", "缩手缩脚");
    std::cout << "perosnA的性格:\n";
    nature(personA);
    std::cout << "perosnB的性格:\n";
    nature(personB);
    std::cout << "perosnC的性格:\n";
    nature(personC);
    return 0;
}