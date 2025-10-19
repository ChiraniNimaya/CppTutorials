#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

std::vector<std::vector<std::string>> getAnagrams(std::vector<std::string> wordList)
{
    std::vector<std::vector<std::string>> result;
    std::unordered_map<std::string, std::vector<std::string>> wordMap;
    for (std::string word : wordList)
    {
        std::string key = word;
        std::sort(key.begin(), key.end());
        wordMap[key].push_back(word);
    }
    for (auto entry : wordMap)
    {
        std::vector words = entry.second;
        if (words.size() >= 2)
        {
            result.push_back(words);
        }
    }
    return result;
}

int main()
{
    std::vector<std::string> wordList = {"created", "abc", "catered", "reacted", "listen", "kkka", "tensil"};
    std::vector<std::vector<std::string>> result;
    result = getAnagrams(wordList);
    for (const auto& group : result) {
        std::cout << "[ ";
        for (const auto& word : group)
            std::cout << word << " ";
        std::cout << "]\n";
    }
    return 0;
}