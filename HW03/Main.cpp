// Main.cpp

#include <iostream>
#include <string>

class Item
{
public:
	Item(const std::string& name, int price);

	const std::string& GetName() const
	{
		return name_;
	}

	int GetPrice() const
	{
		return price_;
	}
	
	void Clear()
	{
		name_ = "";
		price_ = 0;
	}

private:
	std::string name_;
	int price_;
};

template <typename T>
class Inventory
{
public:

	//Constructor Function
	Inventory(int capacity = 10)
	{
		if (capacity <= 0)
		{
			capacity_ = 1;
		}
		else
		{
			capacity_ = capacity;
		}

		pItems_ = new T[capacity_];
	}

	//Deconstructor Function
	~Inventory()
	{
		delete[] pItems_;
		pItems_ = nullptr;
	}


	void AddItem(const T& item)
	{
		if (capacity_ <= size_)
		{
			std::cout << "Inventory is full!" << std::endl;
			return;
		}
		else
		{
			std::cout << "Your item has been added." << std::endl;
			size_++;
		}
	}

	void RemoveLastItem()
	{
		if (size_ == 0)
		{
			std::cout << "Your Inventory is empty." << std::endl;
			return;
		}
		else
		{
			std::cout << "One of your item has been deleted." << std::endl;
			size_--;
		}
	}

	int GetSize() const
	{
		return size_;
	}

	int GetCapacity() const
	{
		return capacity_;
	}

	void PrintAllItems() const
	{
		for (int i = 0; i < 11; ++i)
		{

		}
	}

private: 
	T* pItems_;
	int capacity_;
	int size_;
};


void main()
{
	Inventory<Item>* itemInventory = new Inventory<Item>();
	
	for (int i = 0; i < 11; ++i)
	{
		itemInventory->AddItem(Item("Item" + std::to_string(i), i * 100));
	}
	
	itemInventory->PrintAllItems();

	delete itemInventory;
}