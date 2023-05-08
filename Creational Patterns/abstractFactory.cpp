#include <iostream>
using namespace std;

class Button {
public:
    virtual void paint() const = 0;
};

class WinButton : public Button {
public:
    void paint() const override {
        cout << "created WinButton\n";    
    }  
};
class MacButton : public Button {
public:
    void paint() const override {
        cout << "created MacButton\n";    
    }  
};

class CheckBox {
public:
    virtual void paint() const = 0;
};

class WinCheckBox : public CheckBox {
public:
    void paint() const override {
        cout << "created WinCheckBox\n";    
    }  
};
class MacCheckBox : public CheckBox {
public:
    void paint() const override {
        cout << "created MacCheckBox\n";    
    }  
};

class GUIFactory {
public:
    virtual Button* createButton() const = 0;
    virtual CheckBox* createCheckbox() const = 0;
};

class WinFactory : public GUIFactory {
public:
    Button* createButton() const override {
        return new WinButton;
    }
    CheckBox* createCheckbox() const override {
        return new WinCheckBox;
    }    
};

class MacFactory : public GUIFactory {
public:
    Button* createButton() const override {
        return new MacButton;
    }
    CheckBox* createCheckbox() const override {
        return new MacCheckBox;
    }    
};

class Application {
public:
    Application(GUIFactory* arg) 
        : factory(arg)
    {
    }
    void createButton() {
        button = factory->createButton();
    }
    void createCheckbox() {
        checkBox = factory->createCheckbox();
    }
    void display() {
        button->paint();
        checkBox->paint();
    }
    
private:
    GUIFactory *factory;
    Button *button;
    CheckBox *checkBox;
};

int main()
{
    GUIFactory *win = new WinFactory();
    Application winApp(win);
    winApp.createButton();
    winApp.createCheckbox();
    winApp.display();
    
    GUIFactory *mac = new MacFactory();
    Application macApp(mac);
    macApp.createButton();
    macApp.createCheckbox();
    macApp.display();

    return 0;
}
