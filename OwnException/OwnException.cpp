#include "pch.h"

using namespace System;

// User-defined exception class

ref class MyException : System::Exception
{
public:
    int errNo;
    MyException(String^ msg, int num) : Exception(msg), errNo(num) {}

};

void func(int a)
{
    try
    {
        if (a <= 0)
            throw gcnew ArgumentException("Argument <= 0");
    }
    catch (System::ArgumentException^ ex)
    {
        Console::WriteLine("Caught ArgumentException in func()");
        throw gcnew MyException(ex->Message, 1000);
    }

}



int main(array<System::String ^> ^args)
{
    Console::WriteLine("Custom Exceptions");
    try
    {
        func(0);
    }
    catch (MyException^ ex)
    {
        Console::WriteLine("Caught MyException in main()");
        Console::WriteLine("Message is '{0}'", ex->Message);
        Console::WriteLine("ErrNo is {0}", ex->errNo);
    }
    return 0;
}
