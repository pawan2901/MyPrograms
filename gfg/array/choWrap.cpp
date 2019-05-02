#include<iostream>

using namespace std;

int totalChoWrap(int cho, int wrap)
{
    if(cho < wrap)
        return 0;

    int newCho = cho/wrap;
    return (newCho+ totalChoWrap(newCho + cho%wrap, wrap));
}

int totalCho(int money, int price, int wrapPrice)
{
    int cho = money / price;

    return (cho+totalChoWrap(cho, wrapPrice));
}

int main() {
    cout << totalCho(18, 2, 3) << endl;
    return 0;
}
