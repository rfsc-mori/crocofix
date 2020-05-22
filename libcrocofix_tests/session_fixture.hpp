#ifndef crocofix_libcrocofix_tests_session_fixture_hpp
#define crocofix_libcrocofix_tests_session_fixture_hpp

#include <libcrocofix/session.hpp>
#include <libcrocofixutility/blocking_queue.hpp>
#include "test_reader.hpp"
#include "test_writer.hpp"
#include "test_scheduler.hpp"
#include <queue>
#include <chrono>

namespace crocofix
{

const std::chrono::milliseconds default_timeout = std::chrono::milliseconds(2000);

class session_fixture
{
public:

    session_fixture();

protected:

    void perform_default_logon_sequence();

    bool sent_from_initiator(const std::string& msg_type, 
                             const std::initializer_list<crocofix::field> fields = {},
                             const std::chrono::milliseconds timeout = default_timeout);

    bool received_at_acceptor(const std::string& msg_type, 
                              const std::initializer_list<crocofix::field> fields = {},
                              const std::chrono::milliseconds timeout = default_timeout);
    
    bool sent_from_acceptor(const std::string& msg_type, 
                            const std::initializer_list<crocofix::field> fields = {},
                            const std::chrono::milliseconds timeout = default_timeout);
    
    bool received_at_initiator(const std::string& msg_type, 
                               const std::initializer_list<crocofix::field> fields = {},
                               const std::chrono::milliseconds timeout = default_timeout);

    bool expect(blocking_queue<message>& messages,
                const std::string& msg_type, 
                const std::initializer_list<crocofix::field> fields,
                const std::chrono::milliseconds timeout);

    bool initiator_state_change(session_state expected_state,
                                const std::chrono::milliseconds timeout = default_timeout);

    bool acceptor_state_change(session_state expected_state,
                               const std::chrono::milliseconds timeout = default_timeout);

    bool expect_state_change(blocking_queue<crocofix::session_state>& state_changes,
                             session_state expected_state,
                             const std::chrono::milliseconds timeout = default_timeout);

    void send_from_initiator(const std::string& msg_type,
                             std::initializer_list<field> fields = {},
                             int options = encode_options::standard);                             

    blocking_queue<crocofix::message> initiator_outgoing_messages;
    blocking_queue<crocofix::message> initiator_incoming_messages;

    blocking_queue<crocofix::message> acceptor_outgoing_messages;
    blocking_queue<crocofix::message> acceptor_incoming_messages;

    blocking_queue<crocofix::session_state> initiator_state_changes;
    blocking_queue<crocofix::session_state> acceptor_state_changes;

    crocofix::test_scheduler scheduler;

    crocofix::test_reader initiator_reader;
    crocofix::test_writer initiator_writer;
    crocofix::session initiator;

    crocofix::test_reader acceptor_reader;
    crocofix::test_writer acceptor_writer;
    crocofix::session acceptor;

};

}

#endif