#include "User.h"
#include "Message.h"

std::vector<User> load_users(const std::string& file_name) {
    std::vector<User> users;
    std::fstream ifs(file_name, std::ios::binary | std::ios::in);
    if (ifs.good()) {
        User user("", "", "");
        while (ifs >> user) {
            users.push_back(user);
        }
        ifs.close();
    }
    return users;
}

std::vector<Message> load_messages(const std::string& file_name) {
    std::vector<Message> messages;
    std::fstream ifs(file_name, std::ios::binary | std::ios::in);
    if (ifs.good()) {
        Message message("", "", "");
        while (ifs >> message) {
            messages.push_back(message);
        }
        ifs.close();
    }
    return messages;
}

int main()
{
    const std::string user_file_name = "users.dat";
    const std::string message_file_name = "messages.dat";

    std::vector<User> users = load_users(user_file_name);
    std::vector<Message> messages = load_messages(message_file_name);

    users.push_back(User("User", "user", "password123"));
    messages.push_back(Message("Hello, User!", "Hi", "How are you?"));

    save_users(users, user_file_name);
    save_messages(messages, message_file_name);

    return 0;
}
