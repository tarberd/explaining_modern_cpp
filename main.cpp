#include <iostream>
#include <vector>

struct A
{
    A()
    {
        std::cout << "A{}" << std::endl;
    }

    A(const A&)
    {
        std::cout << "A{const A&}" << std::endl;
    }

    A& operator=(const A&)
    {
        std::cout << "operator=(const A&)" << std::endl;
        return *this;
    }

    A(A&&)
    {
        std::cout << "A{A&&}" << std::endl;
    }

    A& operator=(A&&)
    {
        std::cout << "operator=(A&&)" << std::endl;
        return *this;
    }

    ~A()
    {
        std::cout << "~A()" << std::endl;
    }

    void const_function() const noexcept
    {
        std::cout << "A::const_function()" << std::endl;
    }

    void function() noexcept
    {
        x++;
        std::cout << "A::function()" << std::endl;
    }
    
    int x{0};
};

struct B : public A {

};

struct C {
 std::vector<A> maca{1};
 const A& get_rand() const
 {
     return maca.front();
 }

 A& get_rand()
 {
     return maca.front();
 }
};

A foo()
{
    return A{};
}

A goo()
{
    auto a = A{};
    a.x = 5;
    return a;
}

A hoo()
{
    auto a = A{};
    a.function();
    return a;
}

int main()
{
    auto c = C{};

    auto a = c.get_rand();

    a.x = 5;

    return 0;
}
