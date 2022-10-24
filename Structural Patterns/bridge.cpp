#include<iostream>
 
class WindowImp
{
public:
	virtual void DrawOnMobile() = 0;
	virtual void DrawOnDesktop() = 0;
};
 
class Window
{
protected:
	WindowImp* imp;
public:
	Window(WindowImp* w):imp(w){}
	virtual ~Window(){}
	virtual void Draw() = 0;
};
 
class MobileWindow: public Window
{
public:
	MobileWindow(WindowImp* w): Window(w){std::cout<<"Need Mobile Window"<<std::endl;}
	~MobileWindow(){}
	void Draw()
	{
		imp->DrawOnMobile();
	}
};
 
class DesktopWindow:public Window
{
public:
	DesktopWindow(WindowImp* w): Window(w){std::cout<<"Need Desktop Window"<<std::endl;}
	~DesktopWindow(){}
	void Draw()
	{
		imp->DrawOnDesktop();
	}
};
 
class LinuxImplementor: public WindowImp
{
public:
	LinuxImplementor(){std::cout<<"Linux OS has been selected"<<std::endl;}
	~LinuxImplementor(){}
	void DrawOnMobile()
	{
		std::cout<<"Linux OS for Mobile"<<std::endl;
	}
	void DrawOnDesktop()
	{
		std::cout<<"Linux OS for Desktop"<<std::endl;
	}
};
 
class MacImplementor: public WindowImp
{
public:
	MacImplementor(){std::cout<<"Mac OS has been selected"<<std::endl;}
	~MacImplementor(){}
 
	void DrawOnMobile()
	{
		std::cout<<"Mac OS for Mobile"<<std::endl;
	}
	void DrawOnDesktop()
	{
		std::cout<<"Mac OS for Desktop"<<std::endl;
	}
};
 
int main()
{
	std::cout<<"Bridge Design Pattern"<<std::endl;
	WindowImp* imp = new LinuxImplementor;
	MobileWindow mob(imp);
	mob.Draw();
	delete imp;
	return 0;
};