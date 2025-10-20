#pragma once

#include <TObject.h>

class MyClass : public TObject
{
public:
    MyClass();               // default constructor
    MyClass(Int_t variable); // some other constructor
    virtual ~MyClass();      // destructor

private:
    // some private members
    ClassDef(MyClass, 1) // your_class
};