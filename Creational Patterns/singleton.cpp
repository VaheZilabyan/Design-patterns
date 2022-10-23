#include <iostream>
#include <string>

class Singleton
{
public:
    Singleton(Singleton &other) = delete;
    void operator=(const Singleton &) = delete;
	
    static Singleton *GetInstance();
	void set_value(std::string value);
	std::string get_value();
	
protected:
	Singleton() {}
    static Singleton* instance_;
    std::string value_;
};

Singleton* Singleton::instance_= nullptr;;

Singleton *Singleton::GetInstance()
{
    if(instance_== nullptr){
        instance_ = new Singleton();
    }
    return instance_;
}

void Singleton::set_value(std::string value)
{
	value_ = value;
}

std::string Singleton::get_value()
{
	return value_;
}

int main()
{
	Singleton *obj1 = obj1->GetInstance();
	Singleton *obj2 = Singleton::GetInstance();
	obj1->set_value("first");
	obj2->set_value("second");
	
	std::cout << obj1->get_value() << '\n';
	std::cout << obj2->get_value() << '\n';

    return 0;
}