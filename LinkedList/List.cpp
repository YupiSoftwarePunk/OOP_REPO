#include <iostream>

// Шаблоны классов
// 
//  В с++ можно сделать шаблонами:
//      функции(методы классов это тоже касается)
//      классы
//      структуры
//      объединения
//      переопределения типов      
// deque,
//  
//      Структуры данных:
//          линейный массив                 + vector, array, basic_string
//          список
//              однонаправленый             + forward_list
//              двунаправленый              + list,
//              кольцевой
//          дерево
//              бинарное дерево             +  set, multimap, muliset,map, unordered_map
//                                             unordered_set, unordered_multiset,
//              красно-чёрное дерево
//              дерево отрезков             +-
//          графы
// 
//      Очереди
//          FILO                            +stack
//          FIFO                            +queue
//          priority                        +priority_queue
//  
//

#include <initializer_list>
template <typename Type>

class List 
{
public:
    //constructors
    List() :start_(nullptr), end_(nullptr), size_(0) {}

    explicit List(size_t size) : List() 
    {
        for (size_t i = 0; i < size; ++i) 
        {
            push_back(Type());
        }
    }

    List(std::initializer_list<Type> obj) : List() 
    {
        for (const auto& item : obj) 
        {
            push_back(item);
        }
    }

    List(const List& other) 
    {
        auto current = other.start_;
        size_ = 0;
        while (size_ != other.size_)
        {
            this->push_back(current->getData());
            current = current->getNext();
        }
    }

    // copy constructor
    List(List&& other) noexcept : start_(other.start_), end_(other.end_), size_(other.size_) 
    {
        other.start_ = nullptr;
        other.end_ = nullptr;
        other.size_ = 0;
    }

    // destructor
    ~List() 
    {
        auto current = start_;
        while (size_)
        {
            current = start_->getNext();
            delete start_;
            start_ = current;
        }
    }



    //operators
    List& operator=(const List& other)
    {
        if (this != &other) 
        {
            auto current = other.start_;
            while (current != nullptr) 
            {
                push_back(current->getData());
                current = current->getNext();
            }
        }
        return *this;
    }

    List& operator=(List&& other) noexcept
    {
        if (this != &other) 
        {
            
            start_ = other.start_;
            end_ = other.end_;
            size_ = other.size_;
            other.start_ = nullptr;
            other.end_ = nullptr;
            other.size_ = 0;
        }
        return *this;
    }

    Type& operator[](size_t index)
    {
        Node* res = start_;
        for (; index != 0; index--)
        {
            res = res->getNext();
        }
        return res->getData();
    }

    const Type& operator[](size_t index) const
    {
        Node* res = start_;
        for (; index != 0; index--)
        {
            res = res->getNext();
        }
        return res->getData();
    }

    //--------------------

    Type& at(size_t index)
    {
        if (index >= size_)
        {
            throw std::out_of_range("Index out of range");
        }
        Node* current = start_;

        for (size_t i = 0; i < index; i++)
        {
            current = current->getNext();
        }
        return current->getData();
    }

    const Type& at(size_t index) const
    {
        if (index >= size_)
        {
            throw std::out_of_range("Index out of range");
        }
        Node* current = start_;

        for (size_t i = 0; i < index; i++)
        {
            current = current->getNext();
        }
        return current->getData();
    }

    //technicaly at is operator replacement for cases of managemant with pointer
    //=====================
    //short acces

    Type& back() { return end_->getData(); }
    Type& front() { return start_->getData(); }

    const Type& back()const { return end_->getData(); }
    const Type& front()const { return start_->getData(); }

    void push_back(const Type& other)
    {
        Node* res = new Node{ other };
        if (start_ == end_ && start_ == nullptr && end_ == nullptr)
        {
            start_ = res;
        }
        else
        {
            end_->setNext(res);
            res->setPrev(end_);
        }
        end_ = res;
        size_ += 1;
    }

    void push_front(const Type& other)
    {
        Node* res = new Node{ other };
        if (start_ == end_ && start_ == nullptr && end_ == nullptr)
        {
            start_ = res;
        }
        else
        {
            start_->setNext(res);
            res->setPrev(start_);
        }
        start_ = res;
        size_ += 1;
    }

    void pop_back()
    {
        end_ = end_->getPrev();
        size_ -= 1;
        delete end_->getNext();
        end_->setNext(nullptr);
    }

    void pop_front()
    {
        start_ = start_->getNext();
        size_ -= 1;
        delete start_->getPrev();
        start_->setPrev(nullptr);
    }

    void insert(const Type& other, size_t index)
    {
        if (index > size_)
        {
            throw std::out_of_range("Index out of range");
        }
        if (index == 0) 
        {
            push_front(other);
        }
        else if (index == size_) 
        {
            push_back(other);
        }
        else
        {
            Node* current = start_;
            for (size_t i = 0; i < index; ++i)
            {
                current = current->getNext();
            }

            Node* res = new Node(res, current, current->getPrev());
            current->getPrev()->setNext(res);
            current->setPrev(res);

            ++size_;
        }
    }

    void erase(size_t index)
    {
        if (index >= size_)
        {
            throw std::out_of_range("Index out of range");
        }
        if (index == 0) 
        {
            pop_front();
        }
        else if (index == size_ - 1) 
        {
            pop_back();
        }
        else 
        {
            Node* toDelete = start_;
            for (size_t i = 0; i < index; ++i)
            {
                toDelete = toDelete->getNext();
            }
            toDelete->getPrev()->setNext(toDelete->getNext());
            toDelete->getNext()->setPrev(toDelete->getPrev());

            delete toDelete;
            --size_;
        }
    }


    size_t size()const { return size_; }

private:

    class Node 
    {
    public:
        Node(const Type& date) : data_(date), next_(nullptr), prev_(nullptr) {}
        Node(const Type& data, Node* next, Node* prev) : data_(data), next_(next), prev_(prev) {}
        ~Node() = default;

        void setDate(const Type& data)
        {
            this->data_ = data;
        }
        void setNext(Node* next)
        {
            this->next_ = next;
        }
        void setPrev(Node* prev)
        {
            this->prev_ = prev;
        }

        Type& getData()
        {
            return data_;
        }
        const Type& getData() const
        {
            return data_;
        }
        Type getNext() const
        {
            return next_;
        }
        Type getPrev() const
        {
            return prev_;
        }

    private:
        Node* next_;
        Node* prev_;
        Type data_;
    };

    Node* end_;
    Node* start_;
    size_t size_;
};



using MyType = double;
typedef double Duration;



int main12()
{


    return 0;
}
