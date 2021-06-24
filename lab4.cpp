#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <iterator>

template <typename T> 
T vec(T L, T L1, T L2) {
    std::for_each(begin(L1), end(L1), [&L,&L1](int i) {
        
        if (std::find(L.begin(), L.end(), i) == std::end(L))
            L.push_back(i);
        });
    std::for_each(begin(L2), end(L2), [&L,&L2](int i) {
        if (std::find(L.begin(), L.end(), i) == std::end(L))
            L.push_back(i);
        });
    return L;
}

template <typename T>
T list(T L, T L1, T L2) {
    std::for_each(begin(L1), end(L1), [&L, &L1](int i) {

        if (std::find(L.begin(), L.end(), i) == std::end(L))
            L.push_back(i);
        });
    std::for_each(begin(L2), end(L2), [&L, &L2](int i) {
        if (std::find(L.begin(), L.end(), i) == std::end(L))
            L.push_back(i);
        });
    return L;
}

template <typename T>
T mset(T L, T L1, T L2)
{
    std::for_each(begin(L1), end(L1), [&L, &L1](int i) {

        if (std::find(L.begin(), L.end(), i) == std::end(L))
            L.insert(i);
        });
    std::for_each(begin(L2), end(L2), [&L, &L2](int i) {
        if (std::find(L.begin(), L.end(), i) == std::end(L))
            L.insert(i);
        });
    return L;
}

template <typename T>
T map(T& L, T L1, T L2)
{
    size_t counter = L.size();
    std::for_each(begin(L1), end(L1), [&L, &L1, &counter](std::pair<int, int> i)
        {
            auto result = std::find_if(begin(L), end(L), [&i](std::pair<int, int> el)
                {
                    return i.second == el.second;
                });
            if (result == L.end()) {
                L.insert(L.end(), std::pair<int, int>(counter + 1, i.second));
                counter = L.size();
            }
            });


    std::for_each(begin(L2), end(L2), [&L, &L2, &counter](std::pair<int, int> i)
        {
            auto result = std::find_if(begin(L), end(L), [&i](std::pair<int, int> el)
                {
                    return i.second == el.second;
                });
            if (result == L.end()) {
                L.insert(L.end(), std::pair<int, int>(counter + 1, i.second));
                counter = L.size();
            }
        });
    return L;
}

typedef std::map<int, int> MyMap;
template <class T>
struct printMap : public std::unary_function<T, void>
{
    std::ostream& os;
    printMap(std::ostream& strm) : os(strm) {}
    void operator()(const T& elem) const
    {
        os << elem.first << ", " << elem.second << "\n";
    }
};

template<typename T>
void print_container(const T& container) {
    for_each(container.begin(), container.end(), [](typename T::value_type v) {std::cout << v << " "; });
    std::cout << std::endl;
}

template<typename K, typename V>

void print_container(std::map<K, V>& container) {
    for_each(container.begin(), container.end(), [](std::pair<K, V> v) {std::cout << v.first << " " << v.second << " "; });
    std::cout << std::endl;
}
template<typename T>
void fill(T& container, int n) {
    for (int i = 0; i < n; ++i)
        container.push_back(rand() % 101 - 50);
}

template<typename K, typename V>
void fill(std::map<K, V> container, int n) {
    for (int i = 0; i < n; ++i)
        container.insert({ i, rand() % 101 - 50 });
}

template<typename T>

void fill(std::multiset<T> container, int n) {
    for (int i = 0; i < n; ++i)
        container.insert(rand() % 101 - 50);
}


float timePassed(float now, float then) {
    std::cout << "time = " << (now - then) / CLOCKS_PER_SEC << std::endl;
    return clock();
}

void name(std::string name) {
    std::cout << name << ": ";
}

int main() {
    srand(time(nullptr));
    float oldTime = clock();

    std::vector<int> v1 = {2,4,6,8};
    std::vector<int> v2 = { 1,3,5,7};
    std::vector<int> v;
    //fill(v1, 100000);
    //fill(v2, 100000);
    v = vec(v, v1, v2);
    name("vector");
    print_container(v);
    //oldTime = timePassed(clock(), oldTime);
   


    std::list<int> l1 = { 2,4,6,8 };
    std::list<int> l2 = { 1,3,5,7 };
    std::list<int> l;
    //fill(l1, 100000);
    //fill(l2, 100000);
    l=list(l, l1, l2);
    name("list");
    print_container(l);
    //oldTime = timePassed(clock(), oldTime);
    
 
    
    std::multiset <int> mset0;
    std::multiset <int> mset1 = {1,3,5,7};
    std::multiset <int> mset2 = { 2,4,6,8 };
    //fill(mset1, 100000);
    //fill(mset2, 100000);
    mset0 = mset(mset0, mset1, mset2);
    name("multiset");
    print_container(mset0);
    //oldTime = timePassed(clock(), oldTime);
   

    std::map<int, int> m;
    std::map<int, int> m1 = { {1,40},{2,30},{3,60} };
    std::map<int, int> m2 = { {1,40},{2,50},{3,70} };
    /*fill(m1, 100000);
    fill(m2, 100000);*/
    m = map(m, m1, m2);
    name("map");
    print_container(m);
    //oldTime = timePassed(clock(), oldTime);

}