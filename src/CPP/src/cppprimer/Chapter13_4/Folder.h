#ifndef FOLDER_H_
#define FOLDER_H_

#include <set>

namespace Chapter13_4 {

    class Message;

    class Folder {
        friend class Message;

    public:
        Folder() = default;
        Folder(const Folder &);

    private:
        std::set<Message*> message;
        void add_to_Message(const Folder&);
        void remove_from_Message();
        void addMsg(Message *m);
        void remMsg(Message *m);
    };
}

#endif
