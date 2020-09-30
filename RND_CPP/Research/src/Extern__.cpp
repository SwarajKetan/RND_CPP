#pragma once

#include "Runnable.h"
//fileA.cpp
int i = 42; // declaration and definition

//fileB.cpp
extern int i;  // declaration only. same as i in FileA

//fileC.cpp
//extern int i;  // declaration only. same as i in FileA

//fileD.cpp
//int i = 43; // LNK2005! 'i' already has a definition.
//extern int i = 43; // same error (extern is ignored on definitions)

struct Extern__ : public Runnable {



	void Run() {

		
	};
};