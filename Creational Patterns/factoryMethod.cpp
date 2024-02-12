#include<iostream>
#include<memory>
 
//Pizza
class Pizza
{
public:
    virtual void BakePizza()=0; 
    virtual void PackPizza()=0;
};
 
class DominoPanerrPiza : public Pizza
{
public:
    void BakePizza()
    {
    std::cout<<"DominoPanerrPiza is ready"<<std::endl;
    }
    void PackPizza()
    {
        std::cout<<"DominoPanerrPiza is packed"<<std::endl;
    }
};
 
class DominoCheesePiza : public Pizza
{
public:
    void BakePizza()
    {
        std::cout<<"DominoCheesePiza is ready"<<std::endl;
    }
    void PackPizza()
    {
        std::cout<<"DominoCheesePiza is packed"<<std::endl;
    }
 
};
//class PizzaFactory
class PizzaFactory
{
protected:
    std::unique_ptr<Pizza>_mPizza;
public:
    Pizza* GetPizza(std::string type)
        {  
        _mPizza.reset(CreatePizza(type));
            return _mPizza.release();     
    }
private:
    virtual Pizza* CreatePizza(std::string type)=0;
};
 
//DominoPizzaFactory
class DominoPizzaFactory:public PizzaFactory
{
private:
    Pizza* CreatePizza(std::string type)
    {
            Pizza* pz = nullptr;
        if(type == "Paneer")
            pz = new DominoPanerrPiza;
            else if (type == "Cheese")
                pz = new DominoCheesePiza;
            else
                nullptr;
            return  pz;
    }
 
};
//Client
int main()
{
    std::cout<<"In Main"<<std::endl;
    //Select Factory
    std::unique_ptr<PizzaFactory>ptr{nullptr};
    ptr.reset(new DominoPizzaFactory);
    //Order the Pizza with type
    std::cout<<"Ordering Paneer Pizza from Domino"<<std::endl;
    std::unique_ptr<Pizza>upPz{nullptr};
    upPz.reset(ptr->GetPizza("Paneer"));
    upPz->BakePizza();
    upPz->PackPizza();
    std::cout<<"!!!!!!!!!!Got the Pizza!!!!!!!!!"<<std::endl;
    return 0;
}


/*
// aveli parz tarberak
#include <iostream>
using namespace std;

class Transport {   //interface
public:
    virtual void deliver() = 0;
    virtual ~Transport() {}
};

class Truck : public Transport {
public:
    void deliver() {
        cout << "texapoxver Truck-ov\n";
    }
};

class Ship : public Transport {
public:
    void deliver() {
        cout << "texapoxver Ship-ov\n";
    }
};

class Logistics {
public:
    void planDelivery() {
        cout << "katarvum en bernapoxadrumner\n";
    }
    virtual Transport* createTransport() const = 0;
    virtual ~Logistics() {}
};

class RoadLogistics : public Logistics {
public:
    Transport* createTransport() const override {
        return new Truck();
    }
};

class SeaLogistics : public Logistics {
public:
    Transport* createTransport() const override {
        return new Ship();
    }
};

int main()
{
    Logistics *Logistics = new RoadLogistics;
    Transport *transport = Logistics->createTransport();
    transport->deliver();

    return 0;
}


*/

/*
#include <iostream>
#include <string>
using namespace std;

class Button {   //interface
public:
    virtual void click() = 0;
    virtual string get_title() = 0;
    virtual ~Button() {}
};

class Windows_Button : public Button {
    string title = "";
public:
    Windows_Button(const string& s) : title(s) {} 
    void click() {
        cout << "Clicked Windows_Button\n";
    }
    string get_title() {
        return title;
    }
};

class HTML_Button : public Button {
    string title = "";
public:
    HTML_Button(const string& s) : title(s) {} 
    void click() {
        cout << "Clicked HTML_Button\n";
    }
    string get_title() {
        return title;
    }
};

class Linux_Button : public Button {
    string title = "";
public:
    Linux_Button(const string& s) : title(s) {} 
    void click() {
        cout << "Clicked Linux_Button\n";
    }
    string get_title() {
        return title;
    }
};

class Dialog {
public:
    virtual Button* createButton() const = 0;
    virtual ~Dialog() {}
};

class Windows_Dialog : public Dialog {
public:
    Button* createButton() const override {
        return new Windows_Button("win button");
    }
};

class HTML_Dialog : public Dialog {
public:
    Button* createButton() const override {
        return new HTML_Button("html button");
    }
};

class Linux_Dialog : public Dialog {
public:
    Button* createButton() const override {
        return new Linux_Button("linux button");
    }
};

int main()
{
    Windows_Dialog *wd = new Windows_Dialog;
    
    Button *button = wd->createButton();
    button->click();
    cout << button->get_title() << endl;
}
*/

