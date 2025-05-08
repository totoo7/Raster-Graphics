#include "SessionManager.hpp"

SessionManager::SessionManager() : active_session(nullptr) {}

Session* SessionManager::get_active() const {
    return active_session;
}

void SessionManager::change(const int id) {
    for (size_t i = 0; i < sessions.size(); i++) {
        if (sessions[i].get_id() == id) {
            active_session = &sessions[i];
        }
    }
}

void SessionManager::add(const Session& session) {
    sessions.push_back(session);
    active_session = &sessions[sessions.size()-1];
} 