#include<iostream>
#include<fstream>
#include<string>

using std::cout;
using std::cin;
using std::endl;
using std::ios;

int main(void)
{
    std::ofstream fio;
    std::ifstream fii;
    std::string line, path;
    
    fii.open("path", ios::in);
    getline(fii, path);

    freopen("log", "w", stdout);
    cout<<"works"<<endl;
    cout<<"path is: "<<path<<endl;
    
    fio.open(path+"tests\\out", ios::trunc | ios::out);
    fio<<"testfio"<<endl;
    fio.close();

    fii.open(path+"tests\\test.wav", ios::in);
    while(fii) 
    {
        getline(fii, line);
        fio<<line<< endl;
    }

    fio.close();
    fii.close();

    return 0;
}