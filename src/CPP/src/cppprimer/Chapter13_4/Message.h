#ifndef MESSAGE_H_
#define MESSAGE_H_

#include <set>
#include <string>

namespace Chapter13_4 {

    class Folder;

    class Message {
        friend class Folder;

    public:
        explicit Message(const std::string &str = "") :
            content(str) {}

        Message(const Message &m);
        Message& operator=(const Message &m);
        ~Message();

        void save(Folder &f);
        void remove(Folder &f);

    private:
        std::string content;
        std::set<Folder*> folders;

        void add_to_Folders(const Message &m);
        void remove_from_Folders();

        void addFldr(Folder *f);
        void remFldr(Folder *f);
    };

}

#endif
