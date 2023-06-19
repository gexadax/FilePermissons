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
