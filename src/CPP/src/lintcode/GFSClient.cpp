/*
 * [Source] http://www.lintcode.com/en/problem/gfs-client/
 * [Difficulty]: Medium
 * [Tag]: 
 */

#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

namespace {
    vector<string> split(string& str) {
        vector<string> res;
        size_t st = 0, ed = str.find_first_of('|');
        while (ed != string::npos) {
            res.push_back( str.substr(st, ed - st) );
            st = ed + 1;
            ed = str.find_first_of('|', st);
        }
        return res;
    }

    string convert(vector<string> chunks) {
        string res("");
        for (string& chunk : chunks) {
            res += chunk + "|";
        }
        return res;
    }
}

class BaseGFSClient {
private: map<string, string> chunk_list;
public:
    string readChunk(string& filename, int chunkIndex) {
        string serialized = chunk_list[filename];
        vector<string> chunks = split(serialized);
        return chunks[chunkIndex];
    }

    void writeChunk(string& filename, int chunkIndex,
                    string& content) {
        string serialized;
        if (chunk_list.find(filename) == chunk_list.end())
            serialized = "";
        else
            serialized = chunk_list[filename];

        vector<string> chunks = split(serialized);
        while ((int)chunks.size() < chunkIndex + 1) {
            chunks.push_back("");
        }
        chunks[chunkIndex] = content;

        string newSerialized = convert(chunks);
        chunk_list[filename] = newSerialized;
    }
 };

// [Corner Case]:
// [Solution]:
class GFSClient : public BaseGFSClient {
public:
    GFSClient(int chunkSize): chunkSize_(chunkSize) {
    }

    // @param filename a file name
    // @return conetent of the file given from GFS
    string read(string filename) {
        if (fileSizes_.find(filename) == fileSizes_.end())
            return "";

        int size = fileSizes_[filename];
        string file = "";
        for (int i = 0; i < size; ++i) {
            file += readChunk(filename, i);
        }

        return file;
    }

    // @param filename a file name
    // @param content a string
    // @return void
    void write(string filename, string content) {
        int len = content.length();
        int size = len / chunkSize_ + (len % chunkSize_ == 0 ? 0 : 1); // (len - 1)/chunkSize_ + 1;
        fileSizes_[filename] = size;

        for (int i = 0; i < size; ++i) {
            int st = i * chunkSize_;
            int partialLen = min(chunkSize_, len - st); // substr still work with longer length
            string partialContent = content.substr(st, partialLen);
            writeChunk(filename, i, partialContent);
        }
    }

private:
    int chunkSize_;
    map<string, int> fileSizes_;
};

// [Solution]:

int main() {
    GFSClient gfs(5);
    cout << gfs.read("a.txt") << endl;
    gfs.write("a.txt", "World");
    cout << gfs.read("a.txt") << endl;
    gfs.write("b.txt", "111112222233");
    cout << gfs.read("b.txt") << endl;
    gfs.write("b.txt", "aaaaabbbbb");
    cout << gfs.read("b.txt") << endl;

    return 0;
}
