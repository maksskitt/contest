#include <iostream>
#include <set>
#include <string>

int main()
{
    std::set<std::string> words;
    std::string word;
    while (std::cin >> word) words.insert(word);

    std::cout << words.size() << std::endl;

    return 0;
}
