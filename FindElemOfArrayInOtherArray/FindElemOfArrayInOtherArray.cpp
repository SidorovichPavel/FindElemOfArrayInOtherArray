#include <iostream>
#include <vector>
#include <random>
#include <map>
#include <ranges>
#include <limits>
#include <fstream>

int get_randval(int _MaxVal = std::numeric_limits<int>::max())
{
    return std::random_device{}() % _MaxVal;
}

int main()
{
    constexpr size_t src_size = 1024;
    constexpr size_t data_size = 8192;
    
    constexpr int max_val = 128;

    std::vector<int> srcv(src_size);
    for (auto& e : srcv)
        e = get_randval(max_val);

    std::ranges::sort(srcv);
    auto [rep_begin, rep_end] = std::ranges::unique(srcv);
    srcv.erase(rep_begin, rep_end);

    std::vector<int> datav(data_size);
    for (auto& e : datav)
        e = get_randval(max_val);

    std::map<int, size_t> direct;

    for (auto& e : srcv)
    {
        direct[e] = 0;//it does not matter
        for (auto de : datav)
            if (e == de)
                direct[e]++;
    }

    std::ranges::for_each(direct, [](auto& pair) {
        std::cout << "Value " << pair.first << " repeat counter: " << pair.second << std::endl;
        });

    std::ofstream fout;

    fout.open("srcv.txt");
    std::ranges::for_each(srcv, [&](auto& e) {fout << e << std::endl; });
    fout.close();

    std::ranges::sort(datav);
    fout.open("datav.txt");
    std::ranges::for_each(datav, [&](auto& de) {fout << de << std::endl; });
    fout.close();

    return 0;
}