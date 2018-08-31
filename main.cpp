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

        A(A&&)
    {
        std::cout << "A{A&&}" << std::endl;
    }

    A& operator=(const A&)
    {
        std::cout << "operator=(const A&)" << std::endl;
        return *this;
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

    // virtual ~A()
    // {
    //     std::cout << "~A()" << std::endl;
    // }

    int x{0};
};

struct B : public A {
    B() : A()
    {
        std::cout << "B{}" << std::endl;
    }

    B(const B& b) : A(b)
    {
        std::cout << "B{const B&}" << std::endl;
    }

    B(B&& b) : A(b)
    {
        std::cout << "B{B&&}" << std::endl;
    }

    B& operator=(const B&)
    {
        std::cout << "operator=(const B&)" << std::endl;
        return *this;
    }

    B& operator=(B&&)
    {
        std::cout << "operator=(B&&)" << std::endl;
        return *this;
    }

    ~B()
    {
        std::cout << "~B()" << std::endl;
    }

    // virtual ~B()
    // {
    //     std::cout << "~B()" << std::endl;
    // }
    
    int y{0};
};

struct C {
    const A& get_rand() const
    {
        return maca.front();
    }

    A& get_rand()
    {
        return maca.front();
    }

    std::vector<A> maca{1};
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

int main()
{
    {
        std::cout << "constructors mechanics: " << std::endl; 
        auto a = A{};
        auto b = A{};

        std::cout << "this is copy:" << std::endl;
        auto c = a;

        std::cout << "this is move:" << std::endl;
        auto d = std::move(a);

        std::cout << "this is copy assing:" << std::endl;
        b = c;

        std::cout << "this is move assing:" << std::endl;
        c = A{};
        
        std::cout << "this is swap:" << std::endl;
        std::swap(b,c);
    }

    {
        auto b = B{};
    }

    return 0;
}
