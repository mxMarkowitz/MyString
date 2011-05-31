#include "MyString.h"
#include <string.h>
using std::cout;
using std::endl;

MyString::MyString()
{
    _capacity = 16;
    _length = 0;
    _string = new char[_capacity + 1];
    _string[0] = '\0';
}

MyString::MyString(const char * aCString)
{
    _capacity = strlen(aCString);
    _length = _capacity;

    _string = new char[_capacity + 1];
    for (int i = 0; i < _capacity; i++)
    {
        _string[i] = aCString[i];
    }
    _string[_length] = '\0';
}
MyString::MyString(int numChars)
{
    _capacity = numChars;
    _length = 0;
    _string = new char[_capacity + 1];
    _string[0] = '\0';
}

void MyString::Append(const MyString & aMyString)
{
    //set capacity
    int tempCapacity = _length + aMyString._length;
    //point old to different location
    char* tempString = _string;
    //allocate new string
    char* _string = new char[tempCapacity + 1];
    for (int i = 0; i < _capacity; i++)
    {
         _string[i] = tempString[i];
    }
    //deallocate old string
    delete [] tempString;
    for (int i = 0; i < tempCapacity; i++)
    {
        _string[i+_length] = aMyString._string[i];
    }
    //finalize values
    _capacity = tempCapacity;
    _length = _capacity;
    _string[_length] = '\0';
}

void MyString::Append(const char * aCString)
{
    //set capacity
    _capacity = _length + strlen(aCString);
    //point to old string
    char *tempString = _string;
    //allocate new string
    char *_string = new char[_capacity + 1];
    for (int i = 0; i < _length; i++)
    {
        _string[i] = tempString[i];
    }
    //deallocate old string
    delete [] tempString;

    for (int i = 0; i < strlen(aCString); i++)
    {
        _string[i + _length] = aCString[i];
    }

    //finalize values
    _length = _capacity;
    _string[_length] = '\0';

}
void MyString::Assign(const MyString & aMyString)
{
    //set new length
    _length = aMyString._length;

    if (_capacity < _length)
    {
        delete [] _string;
        _capacity = _length;
        char *_string = new char [_capacity + 1];
    }
    for (int i = 0; i < _length; i++)
    {
        _string[i] = aMyString._string[i];
    }
    _capacity = _length;
    _string[_length] = '\0';

    cout << _string << endl;
}
void MyString::Assign(const char * const aCString)
{
    _length = strlen(aCString);
    if (_capacity < _length)
    {
        _capacity = _length;
        char *_string = new char [_capacity + 1];
    }
     for (int i = 0; i < _length; i++)
    {
        _string[i] = aCString[i];
    }
    _capacity = _length;
    _string[_length] = '\0';

    cout << _string << endl;
}

char MyString::At(int index) const
{
    if (index <= 0 || index >= _length)
    {
        cout << "Index is out of bounds" << endl;
        return 0;
    }
    else
    {
        return _string[index];
    }
}
void MyString::Clear()
{
    char *_string = new char [capacity + 1];
    _length = 0;
    _string[_length] = '\0';
}
void MyString::Clear(int newCapacity)
{
    if (newCapacity < 0)
    {
        cout << "Capacity out of bounds" << endl;
        return 0;
    }
    else
    {
        _capacity = newCapacity;
        char *_string = new char [_capacity +1];
        _length = 0;
        _string[_length] = '\0';
    }
}

