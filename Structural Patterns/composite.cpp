// CPP program to illustrate
// Composite design pattern
#include <iostream>
#include <vector>

class PageObject {
public:
	virtual void Add(PageObject a)
	{
	}
	virtual void Remove()
	{
	}
	virtual void Delete(PageObject a)
	{
	}
};

class Page : public PageObject {
public:
	void Add(PageObject a)
	{
		std::cout << "something is added to the page" << std::endl;
	}
	void Remove()
	{
		std::cout << "something is removed from the page" << std::endl;
	}
	void Delete(PageObject a)
	{
		std::cout << "something is deleted from page " << std::endl;
	}
};

class Copy : public PageObject {
	std::vector<PageObject> copyPages;

public:
	void AddElement(PageObject a)
	{
		copyPages.push_back(a);
	}

	void Add(PageObject a)
	{
		std::cout << "something is added to the copy" << std::endl;
	}
	void Remove()
	{
		std::cout << "something is removed from the copy" << std::endl;
	}
	void Delete(PageObject a)
	{
		std::cout << "something is deleted from the copy";
	}
};

int main()
{
	Page a;
	Page b;
	Copy allcopy;
	allcopy.AddElement(a);
	allcopy.AddElement(b);

	allcopy.Add(a);
	a.Add(b);

	allcopy.Remove();
	b.Remove();

	return 0;
}
