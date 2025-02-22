#include <iostream>

// умные указатели и шаблонные классы

// умные указатели умеют чистить за собой память

// Виды умных указателей
/*
	auto_ptr
	unique_ptr - гарантирует что это единственная точка управления объектом
	shared_ptr - имеет несколько ссылок на объект и удалить его можно, только удалив все ссылки
	weak_ptr - не влияет на жизнь объекта
*/

template <typename Type>
class SmartPointer
{
public:
	SmartPointer() : data_(nullptr) {}
	SmartPointer(Type* data) : data_(nullptr) {}
	~SmartPointer() { if (data_)delete data_; }

	Type& operator*() { return *data_; }
	Type* operator->()const { return data_; }

	void SetData(Type* data) { data_ = data; }
	Type GetData() { return data_; }

private:
	Type* data_;
};

struct My
{
	int a;
	float b;
	bool c;
};

int main()
{
	SmartPointer<My> obj(new My{ 3, 2.6f, false });
	if ((*obj).a == 5) throw - 1;
	if ((*obj).b < 0) throw - 1;
	obj->a;


	std::unique_ptr<My> p(new My);
	std::unique_ptr<My> object = std::make_unique<My>(1024);
	std::unique_ptr<My[]> p2(new My[33]);

	return 0;
}