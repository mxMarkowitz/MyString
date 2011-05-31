
#include "MyString.h"

using namespace std;

int main()
{

    MyString a();
    MyString b("Derp 123");
    MyString c("herp");
    MyString d(10);

    b.Assign(c);
    b.Assign("Derp 123");

    cout << b.At(0) << endl;
    cout << b.At(3) << endl;
    cout << b.At(300) << endl;



    return 0;
}
