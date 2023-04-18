#include <iostream>
#include <vector>

using namespace std;

// функція, яка знаходить порядок многочлена
int poly_order(vector<int> poly)
{
    int order = 0;
    for (int i = 0; i < poly.size(); i++)
    {
        if (poly[i] != 0)
        {
            order = i;
        }
    }
    return order;
}

// функція, яка перевіряє, чи є елемент генератором мультиплікативної групи розширення поля
bool is_generator(int a, int q)
{
    int power = 1;
    for (int i = 1; i <= q - 2; i++)
    {
        power = (power * a) % q;
        if (power == 1)
        {
            return false;
        }
    }
    if (power == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    // приклад знаходження порядку многочлена
    vector<int> poly = {1, 0, -3, 0, 2}; // 2x^4 - 3x^2 + 1
    int order = poly_order(poly);
    cout << "Порядок многочлена: " << order << endl;

    // приклад перевірки, чи є елемент генератором мультиплікативної групи розширення поля
    int a = 7;
    int q = 11;
    bool is_gen = is_generator(a, q);
    if (is_gen)
    {
        cout << a << " є генератором мультиплікативної групи розширення поля F_" << q << endl;
    }
    else
    {
        cout << a << " не є генератором мультиплікативної групи розширення поля F_" << q << endl;
    }

    return 0;
}
