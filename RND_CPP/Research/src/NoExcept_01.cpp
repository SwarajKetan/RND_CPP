#include <iostream>
#include <exception>
#include "Runnable.h"
struct NoExcept_01 : public Runnable {

    // doesn't throw EXCEPTION. but in case any exception happens, program crashes
    void NoExceptTest() noexcept {
        throw std::logic_error("some error");
    };

    // compile time
    // may throw EXCEPTION.
    void NoExceptTest_02() noexcept(false) {
        throw std::logic_error("some error");
    };

    void Run()
    {
        NoExceptTest();
    }

};