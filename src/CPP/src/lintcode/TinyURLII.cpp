/*
 * [Source] http://www.lintcode.com/en/problem/tiny-url-ii/
 * [Difficulty]: Medium
 * [Tag]: 
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// [Corner Case]: When customer created key is already in exist in normal map, or in custom created may, or the long url already map to any string, should return error
// [Solution]: Use id-longURL pair to store mapping. id use 62 base to convert to short URL. Use customer map to store customer specified short url.
class TinyUrl2 {
public:
    /**
     * @param long_url a long long url
     * @param a short key
     * @return a short url starts with http://tiny.url/
     */
    string createCustom(string long_url, string short_key) {
        long long existId = findLongURLId_(long_url);
        long long id = shortKeyToId_(short_key);

        // long_url already exist in urlMap_ but map to another short_key
        if (existId != -1 && existId != id)
            return "error";

        // the short_key exist in urlMap_
        if (urlMap_.find(id) != urlMap_.end()) {
            if (urlMap_[id] == long_url)
                return prefix + short_key;
            else
                return "error";
        }

        // short_key already exist in customMap_ but map to another long_url
        if (customMap_.find(short_key) != customMap_.end() && customMap_[short_key] != long_url)
            return "error";

        // long_url already exist in customMap but map to another custom key
        unordered_map<string, string>::iterator it = findLongURLCustomerKey_(long_url);
        if ( it != customMap_.end() ) {
            if (it->first != short_key)
                return "error";
            else
                return prefix + short_key;
        }

        customMap_[short_key] = long_url;
        return prefix + short_key;
    }

    /**
     * @param url a long long url
     * @return a short url starts with http://tiny.url/
     */
    string longToShort(string long_url) {
        // find long_url in the customMap first
        unordered_map<string, string>::iterator it = findLongURLCustomerKey_(long_url);
        if (it != customMap_.end())
            return prefix + it->first;

        // find long_url in the urlMap
        long long id = findLongURLId_(long_url);

        if (id == -1) { // not exist. find next available id
            while (urlMap_.find(lastId_) != urlMap_.end())
                ++lastId_;

            id = lastId_;
            urlMap_[lastId_++] = long_url;
        }

        return prefix + idToShortKey_(id);
    }

    /**
     * @param url a short url starts with http://tiny.url/
     * @return a long long url
     */
    string shortToLong(string short_url) {
        string shortKey = short_url.substr(offset);

        // search customMap first
        if (customMap_.find(shortKey) != customMap_.end()) {
            return customMap_[shortKey];
        }

        // search urlMap
        long long id = shortKeyToId_(shortKey);
        if (urlMap_.find(id) == urlMap_.end())
            return "";
        return urlMap_[id];
    }

private:
    string idToShortKey_(long long id) {
        vector<char> shortKeyArr;
        while (id > 0) {
            char cur = serials[id % base];
            shortKeyArr.push_back(cur);
            id /= base;
        }
        while (shortKeyArr.size() < 6) { // at least 6 chars
            shortKeyArr.push_back(serials[0]);
        }

        return string(shortKeyArr.rbegin(), shortKeyArr.rend());
    }

    long long shortKeyToId_(const string& shortKey) {
        long long id = 0;
        for (const char& c : shortKey) {
            id = base * id + serials.find(c);
        }
        return id;
    }

    long long findLongURLId_(const string& longUrl) {
        long long id = -1;
        for (auto it = urlMap_.begin(); it != urlMap_.end(); ++it) {
            if (it->second == longUrl) {
                id = it->first;
                break;
            }
        }
        return id;
    }

    unordered_map<string, string>::iterator findLongURLCustomerKey_(const string& longUrl) {
        for (auto it = customMap_.begin(); it != customMap_.end(); ++it) {
            if (it->second == longUrl) {
                return it;
            }
        }
        return customMap_.end();
    }

private:
    long long lastId_ = 1000;
    unordered_map<long long, string> urlMap_;
    unordered_map<string, string> customMap_;

    const string serials = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const int base = serials.size();
    const string prefix = "http://tiny.url/";
    const int offset = prefix.length();
};

// [Solution]:

int main() {

    TinyUrl2 ty;

    vector<string> urls = {"http://www.lintcode.com/faq/?id=10"};
    for (string& url : urls) {
        string shortUrl = ty.longToShort(url);
        string longUrl = ty.shortToLong(shortUrl);
        cout << longUrl << " " << shortUrl << endl;
        if (longUrl != url)
            cout << "FAIL" << endl;
    }
    string long_url("http://www.lintcode.com/"), short_key("lccode");
    string shortUrl = ty.createCustom(long_url, short_key);
    string longUrl = ty.shortToLong(shortUrl);
    cout << longUrl << " " << shortUrl << endl;
    if (longUrl != long_url)
        cout << "FAIL" << endl;
    string shortUrl2 = ty.longToShort(long_url);
    cout << longUrl << " " << shortUrl2 << endl;
    if (shortUrl2 != shortUrl)
        cout << "FAIL" << endl;
    

    cout << ty.createCustom("http://www.lintcode.com/p1", "000001") << endl;
    ty.createCustom("http://www.lintcode.com/p2", "000002");
    ty.createCustom("http://www.lintcode.com/p3", "000003");
    ty.createCustom("http://www.lintcode.com/p4", "000004");
    ty.longToShort("http://www.lintcode.com/problem/");
    ty.shortToLong("http://tiny.url/000002");
    ty.shortToLong("http://tiny.url/000004");
    ty.createCustom("http://www.facebook.com", "facebook");
    ty.createCustom("http://www.facebook.com", "facebook");
    ty.createCustom("http://www.google.com", "google");
    ty.createCustom("http://www.lintcode.com", "lc");
    ty.shortToLong("http://tiny.url/lc");
    ty.shortToLong("http://tiny.url/google");
    ty.createCustom("http://www.google.com", "google");
    ty.shortToLong("http://tiny.url/facebook");
    ty.longToShort("http://www.lintcode.com");
    ty.longToShort("http://www.google.com");
    ty.longToShort("http://www.facebook.com");
    return 0;
}
