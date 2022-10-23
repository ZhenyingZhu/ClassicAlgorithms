/*
 * [Source] http://www.lintcode.com/en/problem/tiny-url/
 * [Difficulty]: Medium
 * [Tag]: 
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

namespace {
    const string serials("0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
    const int base = serials.size();
    const string prefix("http://tiny.url/");
    const int offset = prefix.length();
}

// [Corner Case]:
// [Solution]: Use id-longURL pair to store mapping. id use 62 base to convert to short URL
class TinyUrl {
public:
//    TinyUrl() {
//        lastId_ = 0;
//    }

    /**
     * @param url a long url
     * @return a short url starts with http://tiny.url/
     */
    string longToShort(string& url) {
        long id = lastId_;
        urlMap_[lastId_++] = url;
        return prefix + idToShortURL_(id);
    }

    /**
     * @param url a short url starts with http://tiny.url/
     * @return a long url
     */
    string shortToLong(string& url) {
        string shortURL = url.substr(offset);
        long id = shortURLToId(shortURL);
        if (urlMap_.find(id) == urlMap_.end())
            return "";
        return urlMap_[id];
    }

private:
    string idToShortURL_(long id) {
        vector<char> shortURLArr(6, serials[0]);

        size_t pos = shortURLArr.size() - 1;
        while (id > 0) {
            char cur = serials[id % base];
            shortURLArr[pos--] = cur;
            id /= base;
        }

        return string(shortURLArr.begin(), shortURLArr.end());
    }

    long shortURLToId(const string& shortURL) {
        long id = 0;
        for (const char& c : shortURL) {
            id = 62 * id + serials.find(c);
        }
        return id;
    }

private:
    long lastId_ = 1000;
    unordered_map<long, string> urlMap_;
};

// [Solution]:

int main() {

    TinyUrl ty;

    vector<string> urls = {"http://www.lintcode.com/faq/?id=10"};
    for (string& url : urls) {
        string shortUrl = ty.longToShort(url);
        string longUrl = ty.shortToLong(shortUrl);
        cout << longUrl << " " << shortUrl << endl;
        if (longUrl != url)
            cout << "FAIL" << endl;
    }

    return 0;
}
