#include <iostream>
#include <cstring>
#include "String.h"

using namespace std;

int main() {
    cout<<"Constructors" << "\n";
    String string0;
    cout<<"Default constructor" << "\n";
    cout<<"string0: ";
    string0.print();
    String string1(5, '1');
    cout<<"Construct and fills char"<< "\n";
    cout<<"string1: ";
    string1.print();
    String string2("string2");
    cout<<"Construct const char*"<< "\n";
    cout<<"string2: ";
    string2.print();
    String string3(string2, 0, 6);
    cout<<"Construct const String& other, size_t pos, size_t count = npos"<< "\n";
    cout<<"string3: ";
    string3.print();
    String string4(string2);
    cout<<"Copy constructor"<< "\n";
    cout<<"string4: ";
    string4.print();

    cout << "\n"<<"size()" << "\n";
    cout<< "string1 size = " <<string1.size() <<"\n";

    cout << "\n"<<"Operators = " << "\n";
    cout<< "parameters: const String& str" <<"\n";
    string0 = string3;
    cout<<"string0: ";
    string0.print();
    cout<< "parameters: const char* s" <<"\n";
    string4 = "string4";
    cout<<"string4: ";
    string4.print();
    cout<< "parameters: char ch" <<"\n";
    string3 = 's';
    cout<<"string3: ";
    string3.print();

    cout << "\n"<<"Operators += " << "\n";
    cout<< "parameters: const String& str" <<"\n";
    string1 += string0;
    cout<<"string1: ";
    string1.print();
    cout<< "parameters: char* s" <<"\n";
    string3 += "tring3";
    cout<<"string3: ";
    string3.print();

    cout << "\n"<<"resize(size_t count)" << "\n";
    cout<<"length before (string0) "<< string0.size() << "\n";
    string0.resize(8);
    cout<<"length before (string0) "<< string0.size() << "\n";

    cout << "\n"<<"resize(size_t count, char ch)" << "\n";
    cout<<"length before (string4) "<< string4.size() << "\n";
    string4.resize(12, '4');
    cout<<"length before (string4) "<< string4.size() << "\n";
    cout<<"string4: ";
    string4.print();

    cout << "\n"<<"swap(String& other)" << "\n";
    cout<<"string3 and string1 before " << "\n";
    cout<<"string3: ";
    string3.print();
    cout<<"string1: ";
    string1.print();
    cout<<"string3 and string1 after " << "\n";
    string3.swap(string1);
    cout<<"string3: ";
    string3.print();
    cout<<"string1: ";
    string1.print();

    cout << "\n"<<"Operators == " << "\n";
    cout <<"string0 == string4"<<"\n";
    if(string0 == string4) cout <<"true"<<"\n";
    else cout<< "false" << "\n";
    string0.resize(6);
    cout<<"\n"<<"string0: ";
    string0.print();
    cout<<"string1: ";
    string1.print();
    cout<<"string2: ";
    string2.print();
    cout<<"string3: ";
    string3.print();
    cout<<"string4: ";
    string4.print();
    String string5(4, '4');
    cout<<"string5: ";
    string5.print();


    cout<<"\n"<<"string3.find(string0, 2): ";
    cout << (int)string3.find(string0, 2);
    cout<<"\n"<<"string4.find_first_of(\"kri4\", 4, 4): ";
    cout << (int)string4.find_first_of("kri4", 4, 4);
    cout<<"\n"<<"string4.find_first_not_of(\"kri4\", 2, 4): ";
    cout << (int)string4.find_first_not_of("kri4", 2, 4);
    cout<<"\n"<<"string4.find_last_not_of(\"kri4\", 2, 4): ";
    cout << (int)string4.find_last_not_of("kri4", 8, 4);
    cout<<"\n"<<"string4.rfind(string5, 0): ";
    cout << (int)string4.rfind(string5, 0);

    cout << "\n" << "\n" <<"append(const String &str,  size_t pos, size_t count)" << "\n";
    string0.append(string5, 1, 1);
    cout<<"string0.append(string5, 1, 1): ";
    string0.print();

    return 0;
}