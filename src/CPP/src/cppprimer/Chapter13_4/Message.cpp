#include <iostream>
#include <string>
#include <set>

#include "Message.h"
#include "Folder.h"

using namespace std;

namespace Chapter13_4 {

    Message::Message(const Message &m) : content(m.content), folders(m.folders) {
        add_to_Folders(m);
    }

    Message& Message::operator=(const Message &m) {
        content = m.content;
        folders = m.folders;
        add_to_Folders(m);
        return *this;
    }

    Message::~Message() {
        remove_from_Folders();
    }

    void Message::save(Folder &f) {
        folders.insert(&f);
        f.addMsg(this);
    }

    void Message::remove(Folder &f) {
        folders.erase(&f);
        f.remMsg(this);
    }

    void Message::add_to_Folders(const Message &m) {
        for (auto f : m.folders)
            f->addMsg(this);
    }

    void Message::remove_from_Folders() {
        for (auto f : folders)
            f->remMsg(this);
    }

    void Message::addFldr(Folder *f) { folders.insert(f); }

    void Message::remFldr(Folder *f) { folders.erase(f); }

}
