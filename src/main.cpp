
#include <string>
#include <map>
#include <iostream>
#include <any>
#include "include/reflect.h"

class MyClass
{
public:
    int myInt;
    double myDouble;
    std::string myString;
};

// Interface the MyClass with the Reflect class template
template <>
class Reflect<MyClass>
{
public:
    static std::string className()
    {
        return "MyClass";
    }

    static std::map<std::string, std::any> &properties()
    {
        static std::map<std::string, std::any> props;
        return props;
    }
};

int main(int _argc, char **_argv)
{
    printf("Program code.\n");
    Reflect<MyClass>::properties()["myInt"] = 123;
    Reflect<MyClass>::properties()["myDouble"] = 3.14;
    Reflect<MyClass>::properties()["myString"] = std::string("Hello");
    Reflect<MyClass>::properties()["loggable"] = true;

    std::cout << "Class Name: " << Reflect<MyClass>::className() << std::endl;

    auto props = Reflect<MyClass>::properties();
    for (auto prop : props)
    {
        if (prop.second.type() == typeid(int))
        {
            std::cout << prop.first << ": " << std::any_cast<int>(prop.second) << std::endl;
        }
        else if (prop.second.type() == typeid(double))
        {
            std::cout << prop.first << ": " << std::any_cast<double>(prop.second) << std::endl;
        }
        else if (prop.second.type() == typeid(std::string))
        {
            std::cout << prop.first << ": " << std::any_cast<std::string>(prop.second) << std::endl;
        }
        else if (prop.second.type() == typeid(bool))
        {
            std::cout << prop.first << ": " << std::any_cast<bool>(prop.second) << std::endl;
        }
    }

    return 0;
}
