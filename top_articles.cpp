#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
    size_t total = size * nmemb;
    output->append((char*)contents, total);
    return total;
}

struct Article {
    std::string name;
    int comments;
    
    bool operator<(const Article& other) const {
        if (comments != other.comments)
            return comments > other.comments;
        return name > other.name;
    }
};

std::vector<std::string> topArticles(int limit) {
    CURL* curl = curl_easy_init();
    if (!curl) return {};
    
    std::vector<Article> articles;
    int page = 1;
    int totalPages = 1;
    
    while (page <= totalPages) {
        std::string url = "https://jsonmock.hackerrank.com/api/articles?page=" + std::to_string(page);
        std::string response;
        
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        
        if (curl_easy_perform(curl) == CURLE_OK) {
            try {
                json data = json::parse(response);
                
                if (page == 1) {
                    totalPages = data["total_pages"].get<int>();
                }
                
                for (auto& item : data["data"]) {
                    std::string title;
                    
                    if (!item["title"].is_null() && !item["title"].get<std::string>().empty()) {
                        title = item["title"].get<std::string>();
                    } else if (!item["story_title"].is_null() && !item["story_title"].get<std::string>().empty()) {
                        title = item["story_title"].get<std::string>();
                    } else {
                        continue;
                    }
                    
                    int comments = 0;
                    if (!item["num_comments"].is_null()) {
                        comments = item["num_comments"].get<int>();
                    }
                    
                    articles.push_back({title, comments});
                }
            } catch (...) {
                // I skipped malformed responses
            }
        }
        page++;
    }
    
    curl_easy_cleanup(curl);
    std::sort(articles.begin(), articles.end());
    
    std::vector<std::string> result;
    for (int i = 0; i < std::min(limit, (int)articles.size()); i++) {
        result.push_back(articles[i].name);
    }
    
    return result;
}