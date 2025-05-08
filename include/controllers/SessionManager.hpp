#ifndef SESSION_MANAGER_HPP
#define SESSION_MANAGER_HPP

#include "Session.hpp"

class SessionManager {
    public:
        SessionManager();
        Session* get_active() const;
        void add(const Session& session);
        void change(const int id);
        ~SessionManager() = default;
    private:
        Session* active_session;
        std::vector<Session> sessions;
};

#endif