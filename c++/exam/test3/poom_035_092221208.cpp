#include <iostream>
class String
{
private:
    std::string str;

public:
    String(std::string str)
    {
        this->str = str;
    }

    String()
    {
        str = "";
    }
    
    String operator==(const String &s)
    {
        String temp(this->str);
        int i = 0;
        while(this->str[i] && s.str[i] && (this->str[i] == s.str[i]))
        {
            i++;
        }
        if(this->str[i] == s.str[i])
        {
            temp.str = temp.str + "=";
        }
        else
        {
            temp.str = temp.str + "!=";
        }

        temp.str = temp.str + s.str;
        return temp;
    }

    String operator>(const String &s)
    {
        String temp(this->str);
        int i = 0;
        while(this->str[i] && s.str[i] && (this->str[i] == s.str[i]))
        {
            i++;
        }
        if(this->str[i] > s.str[i])
        {
            temp.str = temp.str + ">";
        }
        else
        {
            temp.str = temp.str + "!>";
        }

        temp.str = temp.str + s.str;
        return temp;
    }

    String operator<(const String &s)
    {
        String temp(this->str);
        int i = 0;
        while(this->str[i] && s.str[i] && (this->str[i] == s.str[i]))
        {
            i++;
        }
        if(this->str[i] < s.str[i])
        {
            temp.str = temp.str + "<";
        }
        else
        {
            temp.str = temp.str + "!<";
        }
        temp.str = temp.str + s.str;
        return temp;
    }
    void display(void)
    {
        std::cout << str << "\n";
    }
};

int main()
{
    String string1("Hello"), string2("Book"), string3("Computer"), string4("Hello");
    (string1 > string2).display();
    (string2 < string3).display();
    (string1 == string4).display();
    return 0;
}