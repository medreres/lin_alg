#include <iostream>
#include <math.h>
using namespace std;

/**
 * У цьому коді функція order приймає елемент g та модуль n
 * та повертає його порядок в групі G = {1, 2, ..., n-1}.
 *  Функція is_generator перевіряє, чи є елемент a генератором мультиплікативної
 * групи поля F_p, де p є простим числом. Вона використовує функцію order для
 *  знаходження порядку k елемента a, а потім перевіряє, чи дорівнює k
 * значенню ейлерової функції від p, тобто чи є a генератором поля
 */
class ModularN
{
private:
    int N;

public:
    /**
     * @param {int} n -  A system of long-term modular arithmetic modulo a prime n
     * */
    ModularN(const int &n)
    {
        this->N = n;
    }

    /** @param {int} n -  value A number order of which is searched
     *  @details a^k = 1 (mod n)
     */

    int order(const int &n)
    {
        // if value doesn't belong to a group, return -1
        if (n > this->N)
            return -1;

        /**
         * The (additive) order of 𝑎 modulo 𝑛 is the smallest positive integer 𝑘
         * such that 𝑘𝑎 is a multiple of 𝑛 . By definition this is the l.c.m. of 𝑎
         * and 𝑛, so k = n / d, where d = gcd(a,n)
         * By making some transformations, we can infer that (a^r) mod n = 1,
         * where first smaller positive r is the order of the value
         */
        for (int k = 1; k < this->N; k++)
        {
            double result = int(pow(n, k)) % this->N;
            if (result == 1)
                return k;
        }

        // order is infinite
        return -1;
    }

    /** @param {int} n value A number which is questioned to be primitive (generator) */
    bool isGenerator(const int &n)
    {
        // generator number is such that includes all the elements from the group
        return this->order(n) == (this->N - 1);
    }
};

int main()
{
    const int MODULE_BY_N = 7;
    ModularN mod = ModularN(MODULE_BY_N);

    cout << mod.isGenerator(3) << endl;

    for (int i = 1; i < MODULE_BY_N; i++)
    {
        cout << "order (" << i << " mod " << MODULE_BY_N << ") = " << mod.order(i) << endl;
    }
}