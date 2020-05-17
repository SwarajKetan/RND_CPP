#include <iostream>
#include <future>
#include <exception>
#include "Runnable.h"

struct Threading_01  : public Runnable{
    void f() {
        std::cout << "f thread : " << std::this_thread::get_id() << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(5));
        std::cout << "f call done" << std::endl;
    };

    void g() {
        std::cout << "g thread : " << std::this_thread::get_id() << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout << "g call done" << std::endl;
    };

    void i() {
        std::cout << "i thread : " << std::this_thread::get_id() << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout << "i call done" << std::endl;
    };

    void Run()
    {   
        std::cout << "main thread : " << std::this_thread::get_id() << std::endl;

        auto d = std::launch::deferred;
        auto a = std::launch::async;
        auto da = std::launch::deferred | std::launch::async;

        auto xx = std::async(std::launch::async, [&] { f(); });
        auto yy = std::async(std::launch::deferred, [&] { g(); });
        auto zz = std::async(std::launch::async | std::launch::deferred, [&] { i(); });

        //xx.wait();
        //yy.wait();

        std::cout << "Hello World!\n";
    }

    ~Threading_01() {
        std::cout << "Threading_01 disposed" << std::endl;
    }

};