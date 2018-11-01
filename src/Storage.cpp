#include "Storage.hpp"

// Storage类的实现

shared_ptr<Storage> Storage::getInstance(void) {
    if (m_instance == nullptr) {
        m_instance = new Storage();
    }
    return m_instance;
}
