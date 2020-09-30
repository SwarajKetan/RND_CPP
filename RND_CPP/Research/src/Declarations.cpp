#pragma once
#include "Runnable.h"

#define Size_1(x) sizeof(x)/sizeof(x[0])
// That horrible T(&)[N] notation is a reference to an (unnamed) array
template<typename T, int N>
constexpr int Size_2(T(&)[N]) {
    return N;
}

class Declarations_base {
public:
    void f() {
        std::cout << "base f" << std::endl;
    }
};

class Declarations_child : Declarations_base {
public:
    using Declarations_base::f;
    void g() {
        std::cout << "child g" << std::endl;
    }
};


struct Declarations : public Runnable {

    // Compiletime array length finding
    // http://www.reedbeta.com/blog/cpp-compile-time-array-size/

    struct Point {
        int x;
        int y;
    };

    struct PointConsumer {
        void set_Point(Point p) {};
        //void set_Points(initializer_list<Point> mylist) {};
    };
 
    void f(); // forward declaration
    
    using func1 = void(*)(int);
    void SomeFunction(int x) {/**/}
    
	void Run() {

        int arr[] = { 1, 3, 4 };
        // static assert is for compile-time assert
        static_assert(Size_2(arr) == 3, "err");

        //
        Declarations_child ch;
        ch.f();
        
       
        func1 funcptr = [](int f) {};
        //func1 funcptr2 = &SomeFunction;

        const double pi = 3.14; //OK
        int i = f(2); //OK. f is forward-declared
        std::string str; // OK std::string is declared in <string> header
        //C obj; // error! C not yet declared.
        //j = 0; // error! No type specified.
        auto k = 0; // OK. type inferred as int by compiler.

        Point p{ 10,20 };
	};

    int f(int i)
    {
        return i + 42;
    }

};