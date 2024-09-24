#include <cstring>
#include <iostream>

class Chicken {
  private:
    int age = 24;
    char* name = nullptr;

  public:
    Chicken() {};
    Chicken(int _age) : age(_age) {};
    Chicken(int _age, const char* _name) : age(_age) {
        int len = strlen(_name) + 1;
        name = new char[len];
        for (int i = 0; i < len; i++)
            name[i] = _name[i];
    };

    Chicken(const Chicken& other) : age(other.age) {
        if (other.name != nullptr) {
            int len = strlen(other.name) + 1;
            name = new char[len];
            for (int i = 0; i < len; i++)
                name[i] = other.name[i];
        }
    };

    ~Chicken() {
        if (name != nullptr)
            delete[] name;
    }
    void setAge(int _age) {
        age = _age;
    }
    void setName(const char* _name) {
        int len = strlen(_name) + 1;
        name = new char[len];
        for (int i = 0; i < len; i++)
            name[i] = _name[i];
    }

    const char* getName() const {
        return name;
    }

    const int& getAge() const {
        return age;
    }

    Chicken& operator=(const Chicken& other) {
        if (this == &other) {
            return *this;
        }

        age = other.age;

        if (name != nullptr) {
            delete[] name;
        }

        if (other.name != nullptr) {
            int len = strlen(other.name) + 1;
            name = new char[len];
            for (int i = 0; i < len; i++)
                name[i] = other.name[i];
        } else {
            name = nullptr;
        }

        return *this;
    }

    void printInfo() const {
        std::cout << "Hi, everyone! My name is " << (name ? name : "Unnamed") << ", I am " << age << " years old." << std::endl;
    }
};

int main() {

    Chicken c(24, "Kunkun");
    c.printInfo();

    Chicken c1 = c;
    c.printInfo();

    Chicken c2, c3;
    c2 = c3 = c;
    c2.printInfo();
    c3.printInfo();

    std::cout << "----------------------------------------------------" << std::endl;
    std::cout << "setting c's name to 'KFC' and print info of c and c2" << std::endl;
    c.setName("KFC");
    c.printInfo();
    c2.printInfo();
    return 0;
}