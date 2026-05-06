#include <iostream>
#include <vector>
#include "top_articles.cpp"

int main() {
    std::vector<std::string> results = topArticles(2);
    
    for (const auto& title : results) {
        std::cout << title << std::endl;
    }
    
    return 0;
}
