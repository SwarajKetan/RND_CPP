#pragma once
#include <memory>
#include <typeinfo>
#define RUN(runnable) int main(){std::cout << "Running.." << typeid(runnable).name() << std::endl;{std::make_unique<runnable>()->Run();} std::getchar();}
