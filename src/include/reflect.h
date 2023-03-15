#include <iostream>
#include <string>
#include <map>
#include <any>
#include <sstream>

// Define the Reflect class template
template <typename T>
class Reflect {
public:
    // Define a static method to get the class name
    static std::string className() {
        return typeid(T).name();
    }

    // Define a static method to get a map of the class's properties
    static std::map<std::string, std::any>& properties() {
        static std::map<std::string, std::any> props;
        return props;
    }

    // Define a getter function to get the value of a property
    template <typename U>
    static U get(const std::string& propName) {
        auto it = properties().find(propName);
        if (it != properties().end()) {
            return std::any_cast<U>(it->second);
        }
        throw std::runtime_error("Property does not exist");
    }

    // Define a setter function to set the value of a property
    template <typename U>
    static void set(const std::string& propName, const U& value) {
        properties()[propName] = value;
    }
};

// Specialize the Reflect class template for std::string
template <>
class Reflect<std::string> {
public:
    static std::string className() {
        return "std::string";
    }

    static std::map<std::string, std::any>& properties() {
        static std::map<std::string, std::any> props;
        return props;
    }

    template <typename U>
    static U get(const std::string& propName) {
        auto it = properties().find(propName);
        if (it != properties().end()) {
            return std::any_cast<U>(it->second);
        }
        throw std::runtime_error("Property does not exist");
    }

    template <typename U>
    static void set(const std::string& propName, const U& value) {
        std::ostringstream ss;
        ss << value;
        properties()[propName] = ss.str();
    }
};

// Specialize the Reflect class template for std::string
template <>
class Reflect<bool> {
public:
    static std::string className() {
        return "bool";
    }

    static std::map<std::string, std::any>& properties() {
        static std::map<std::string, std::any> props;
        return props;
    }

    template <typename U>
    static U get(const std::string& propName) {
        auto it = properties().find(propName);
        if (it != properties().end()) {
            return std::any_cast<U>(it->second);
        }
        throw std::runtime_error("Property does not exist");
    }

    template <typename U>
    static void set(const std::string& propName, const U& value) {
        std::ostringstream ss;
        ss << value;
        properties()[propName] = ss.str();
    }
};