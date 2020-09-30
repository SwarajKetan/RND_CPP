#pragma once
#include <memory>
#include <typeinfo>
#include <exception>
#define RUN(runnable) int main(){ try{ std::cout << "Running.." << typeid(runnable).name() << std::endl;{std::make_unique<runnable>()->Run();} std::getchar();} catch(const std::exception ex){std::cout << "exception: " << ex.what() <<std::endl;}}
