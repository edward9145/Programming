#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

class elem{
    public:
    int alpha;
    int beta;
    int ab;
    elem(int a, int b):alpha(a), beta(b){
        ab = a*b;
    }
    bool operator < (const elem &e) const {
        return ab < e.ab;
    }
};

void print_elem(const elem &e){
    cout << "{" << e.alpha << "x" << e.beta << "=" << e.ab << "}" << endl;
}

bool less_alpha(const elem &e1, const elem &e2){
    return e1.alpha < e2.alpha;
}

bool less_beta(const elem &e1, const elem &e2){
    return e1.beta < e2.beta;
}

typedef map<string, int> m_si;
typedef map<string, int*> m_sPi;

void print_m_si(m_si::value_type it){
    cout << it.first << ":" << it.second <<endl;
}

void print_m_sPi(m_sPi::value_type it){
    cout << it.first << ":" << *(it.second) <<endl;
}

class add_m{
    public:
    int _add;
    add_m(int a):_add(a){}
    void operator () (m_si::value_type it){
        it.second = it.second + _add;
        cout << it.first << ":" << it.second << endl;
    }
    void operator () (m_sPi::value_type it){
        *(it.second) = *(it.second) + _add;
        cout << it.first << ":" << *(it.second) << endl;
    }
};

int main(){
    map<int, string> mapIS;
    mapIS[1] = "one";
    mapIS[1] = "1st";
    mapIS.insert(pair<int, string>(1, "first"));
    mapIS.insert(pair<int, string>(2, "two"));

    map<int, string>::iterator iter;
    for(iter=mapIS.begin(); iter!=mapIS.end(); iter++){
        cout << iter->first << ":" << iter->second << endl;
    }

    map<elem, string> mapElem;
    elem e0 = elem(0x0e,0);
    elem e1 = elem(0x0e,1);
    mapElem[e0] = "e0";
    mapElem[e1] = "e1";
    map<elem, string>::iterator iterElem;
    for(iterElem=mapElem.begin(); iterElem!=mapElem.end(); iterElem++){
        print_elem(iterElem->first);
        cout << iterElem->second << endl;
    }
    elem e1_ = elem(0x0e,1);
    elem e2 = elem(0x0e,2);
    cout << "mapElem[e1_]=" << mapElem[e1_] << endl;
    if(mapElem[e2] != "")
        cout << "mapElem[e2]=" << mapElem[e2] << endl;


    m_si mapStrInt;
    mapStrInt["s1"] = 1;
    mapStrInt["s2"] = 2;
    for_each(mapStrInt.begin(), mapStrInt.end(), add_m(2));
    for_each(mapStrInt.begin(), mapStrInt.end(), print_m_si);

    m_sPi mapStrPointerInt;
    int i1 = 1;
    int i2 = 2;
    mapStrPointerInt["sp1"] = &i1;
    mapStrPointerInt["sp2"] = &i2;
    for_each(mapStrPointerInt.begin(), mapStrPointerInt.end(), add_m(2));
    for_each(mapStrPointerInt.begin(), mapStrPointerInt.end(), print_m_sPi);

    return 0;
}

