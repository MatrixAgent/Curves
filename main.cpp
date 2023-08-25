#include <iostream>

#define _USE_MATH_DEFINES
#include <math.h>

#include "curves.h"
#include <random>
#include <numeric>

using namespace std;

int main(int argc, char* argv[])
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> int_distr(0, 2);
    uniform_real_distribution<> real_distr(0, 10);

    vector<shared_ptr<Curve>> vec;

    // Заполняем контейнер vec случайными объектами
    for (int i = 0; i < 20; ++i)
        vec.push_back(shared_ptr<Curve>([&]() -> Curve*
            {
                int k = int_distr(gen);
                switch (k)
                {
                case 0:
                    return new Circle(real_distr(gen), real_distr(gen), real_distr(gen));
                case 1:
                    return new Ellipse(real_distr(gen), real_distr(gen), real_distr(gen), real_distr(gen));
                case 2:
                    return new Helix(real_distr(gen), real_distr(gen), real_distr(gen), real_distr(gen));
                default:
                    return nullptr;
                }
            }())
        );

    for (auto& curve : vec)
        cout << curve->point(M_PI / 4) << "; " << curve->derivative(M_PI / 4) << endl;

    vector<shared_ptr<Curve>> circles;

    // Выберем все окружности из vec в circles
    copy_if(vec.begin(), vec.end(), back_inserter(circles), [](auto c) { return dynamic_cast<Circle*>(c.get()) != nullptr; });

    sort(circles.begin(), circles.end(), [](auto c1, auto c2) { return dynamic_cast<Circle*>(c1.get())->r < dynamic_cast<Circle*>(c2.get())->r; });

    // Выведем отсортированные радиусы
    for (auto& curve : circles)
    {
        cout << dynamic_cast<Circle*>(curve.get())->r << endl;
    }

    double sum = 0;
    for (auto& c : circles) sum += dynamic_cast<Circle*>(c.get())->r;
    cout << sum;
    return 0;
}
