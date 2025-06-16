#ifndef SESSION_MANAGER_HPP
#define SESSION_MANAGER_HPP

#include "Session.hpp"

/**
 * @brief Manages multiple editing sessions for image processing.
 * 
 * Responsible for keeping track of all sessions, switching between them,
 * and accessing the currently active session.
 */
class SessionManager {
    public:
        /**
         * @brief Constructs a new SessionManager.
         * 
         * Initializes the session manager with no active session.
         */
        SessionManager();

        /**
         * @brief Gets a pointer to the currently active session.
         * 
         * @return Pointer to the active Session.
         */
        Session* get_active() const;

        /**
         * @brief Adds a new session to the session manager.
         * 
         * @param session The Session to be added.
         */
        void add(const Session& session);

        /**
         * @brief Changes the active session to the one with the given ID.
         * 
         * @param id The ID of the session to switch to.
         */
        void change(const int id);

        /**
         * @brief Default destructor.
         */
        ~SessionManager() = default;
    private:
        Session* active_session;
        std::vector<Session> sessions;
};

#endif