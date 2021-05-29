#include <iostream>
#include "CustomVectorLib.hpp"
#include <vector>
#include <chrono>

void Emplace();
void Swap();
void SwapIt();
void ShrinkToFit();
void Crend();
void CustomVectorPushBack(int size);
void StdVectorPushBack(int size);

using std::cout;
using std::endl;

//clockStart = std::chrono::steady_clock::now();
//accumulatedTime += std::chrono::duration<double>(std::chrono::steady_clock::now() - clockStart).count();
std::chrono::steady_clock::time_point clockStart;
double accumulatedTime;

int main()
{
    //VectorTestFuncs();
    
    int sizes[5] = { 10000, 100000, 1000000, 10000000, 100000000};
    
    for(int i = 0; i < 5; i++)
    {
        CustomVectorPushBack(sizes[i]);
        StdVectorPushBack(sizes[i]);
    }
    
    cout<<endl;
    Emplace();
    cout<<endl;
    Swap();
    cout<<endl;
    SwapIt();
    cout<<endl;
    ShrinkToFit();
    cout<<endl;
    Crend();
    return 0;
}

void Emplace(){
    CustomVector<int> v = {10,20,30};

    auto it = v.emplace ( v.begin()+1, -1 );
    v.emplace ( it, -2 );
    v.emplace ( v.end(), -3 );


    cout << "Emplace funkcijos rezultatai: ";
    for (auto& x: v)
    cout << ' ' << x;
    cout << '\n';

    cout << "Laukiami rezultatai: 10 -2 -1 20 30 -3" << endl << endl;
}

void Swap(){
    cout << endl;
    CustomVector<int> v1 (3,100);   // three ints with a value of 100
    CustomVector<int> v2 (5,200);   // five ints with a value of 200

    v1.swap(v2);

    cout << "Swap funkcijos rezultatai: " << endl;
    cout << "v1 vektoriaus reiksmes:";
    for (unsigned i=0; i<v1.size(); i++)
    cout << ' ' << v1[i];
    cout << '\n';

    cout << "v2 vektoriaus reiksmes:";
    for (unsigned i=0; i<v2.size(); i++)
    cout << ' ' << v2[i];
    cout << '\n';

    cout << "Laukiamas rezultatas:" << endl << "v1: 200 200 200 200 200" << endl << "v2: 100 100 100" << endl << endl;
}

void SwapIt(){
    unsigned int i;
    CustomVector<int> v1 (3,1);   // three ints with a value of 100
    CustomVector<int> v2 (5,2);   // five ints with a value of 200

    v1.swap(v2);

    cout << "SwapIt funkcijos rezultatai: " << endl;
    cout << "v1 vektoriaus reiksmes:";
    for (CustomVector<int>::iterator it = v1.begin(); it!=v1.end(); ++it)
    cout << ' ' << *it;
    cout << '\n';

    cout << "v2 vektoriaus reiksmes:";
    for (CustomVector<int>::iterator it = v2.begin(); it!=v2.end(); ++it)
    cout << ' ' << *it;
    cout << '\n';

    cout << "Laukiamas rezultatas:" << endl << "v1: 2 2 2 2 2" << endl << "v2: 1 1 1" << endl << endl;
}

void ShrinkToFit(){
    CustomVector<int> v (100);
    cout << "Vektoriaus dydis ji sukurus: " << v.capacity() << '\n';

    v.resize(10);
    cout << "Vektoriaus dydis ji resize'inus: " << v.capacity() << '\n';

    v.shrink_to_fit();
    cout << "Vektoriaus dydis panaudojus shrink_to_fit: " << v.capacity() << '\n';

    cout << "Laukiamas rezultatas:" 
    << endl << "1: 100"
    << endl << "2: 100" 
        << endl << "3: 10" << endl << endl;
}

void Crend(){
    CustomVector<int> v = {1,2,3,4,5};

    cout << "Crend rezultatai: ";
    for (auto rit = v.crbegin(); rit != v.crend(); ++rit)
    cout << ' ' << *rit;
    cout << '\n';

    cout << "Laukiamas rezultatas: 5 4 3 2 1" << endl << endl;
}

void CustomVectorPushBack(int size){
    clockStart = std::chrono::steady_clock::now();
    
    int n = 0;
    CustomVector<int> vect;
    
    for(int i = 0; i < size; i++){
        vect.push_back(i);
        if(vect.capacity() == vect.size()) n++;
    }
        
    double timeTaken = std::chrono::duration<double>(std::chrono::steady_clock::now() - clockStart).count();
    cout << "CustomVector - " << size << " - veiksmai truko " << timeTaken << "s. ir buvo ivykdyta " << n << " atminties perskirstymu" << endl;
}

void StdVectorPushBack(int size){
    clockStart = std::chrono::steady_clock::now();
    
    int n = 0;
    std::vector<int> vect;
    
    for(int i = 0; i < size; i++)
    {
        vect.push_back(i);
        if(vect.capacity() == vect.size()) n++;
    }
    
    double timeTaken = std::chrono::duration<double>(std::chrono::steady_clock::now() - clockStart).count();
    cout << "std::vector - " << size << " - veiksmai truko " << timeTaken << "s. ir buvo ivykdyta " << n << " atminties perskirstymu" << endl;
}