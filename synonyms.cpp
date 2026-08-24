#include <iostream>
#include <unordered_map>
#include <string>

int main() {
	int N;
	std::cin >> N;

	std::unordered_map<std::string, std::string> vocab1, vocab2;
	std::string word1, word2;
	while (N--) {
		std::cin >> word1 >> word2;
		vocab1[word1] = word2;
		vocab1[word2] = word1;
	}

	std::cin >> word1;
	if (vocab1.count(word1)) std::cout << vocab1[word1] << std::endl;
	if (vocab2.count(word1)) std::cout << vocab2[word1] << std::endl;
}