#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class lruCache{
    

    typedef list<int> LI;
    typedef unordered_map<int, LI::iterator> MII;

    LI lq;
    MII cache;

    int cap;

    public:
    lruCache(int capacity):cap(capacity) {
        lq.clear();
        cache.clear();
    }
      
    void touch(int ele) {
       lq.erase(cache[ele]);
       lq.push_front(ele);
       cache[ele] = lq.begin();
    }

    int set(int ele);

    int get(int ele);

    void display(); 
};

int lruCache::set(int ele) {
   if (cache.find(ele) == cache.end()) {
       if(cache.size() == cap) {
           int last = lq.back();
           lq.pop_back();
           cache.find(last);
           cache.erase(last);
       } 
   } else {
       lq.erase(cache[ele]);
   }
   lq.push_front(ele);
   cache[ele] = lq.begin();
}

int lruCache::get(int ele)
{
    if(cache.find(ele) != cache.end()) {
        touch(ele);
        return ele;
    }
    return 0;
}

void lruCache::display()
{
    for(auto itr = lq.begin(); itr != lq.end(); itr++) {
        cout << (*itr) << endl;
    }
}

int main() 
{
    lruCache cache_obj(4);
    cache_obj.set(1);
    cache_obj.set(2);
    cache_obj.set(3);
    cache_obj.display();
    cache_obj.get(2);
    cache_obj.display();
    return 0;
}
