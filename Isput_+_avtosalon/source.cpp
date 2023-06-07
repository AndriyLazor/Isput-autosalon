#include <iostream>
#include <time.h>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

class User {
    string name;
    string surname;
    string father_name;
    string home_address;
    string phone_number;
    string user_name;
    string password;
public:
    User() {
        name = "not set!\n";
        surname = "not set!\n";
        father_name = "not set!\n";
        home_address = "not set!\n";
        phone_number = "not set!\n";
    }
    User(string name, string surname, string father_name, string home_address, string phone_number, string user_name, string password) {
        this->name = name;
        this->surname = surname;
        this->father_name = father_name;
        this->home_address = home_address;
        this->phone_number = phone_number;
        this->user_name = user_name;
        this->password = password;
    }

    void set() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter surname: ";
        cin >> surname;
        cout << "Enter father name: ";
        cin >> father_name;
        cout << "Enter home address: ";
        cin >> home_address;
        cout << "Enter phone number: ";
        cin >> phone_number;
        cout << "Enter user name: ";
        cin >> user_name;
        cout << "Enter password: ";
        cin >> password;
    }

    string get_name() { return name; }
    string get_surname() { return surname; }
    string get_father_name() { return father_name; }
    string get_home_address() { return home_address; }
    string get_phone_number() { return phone_number; }
    string get_user_name() { return user_name; }
    string get_password() { return password; }


    void print() {
        cout << "------------------------------------------------------\n";
        cout << "Name: " << name << "\n";
        cout << "Surname: " << surname << "\n";
        cout << "Father name: " << father_name << "\n";
        cout << "Home address: " << home_address << "\n";
        cout << "Phone number: " << phone_number << "\n";
        cout << "Username: " << user_name << "\n";
        cout << "Password: " << password << "\n";
        cout << "------------------------------------------------------\n";
    }
};

class Users_info {
    vector<User> users_info;
public:
    void set_users_info(vector<User> users_info) {
        this->users_info = users_info;
    }

    void add_user(User& user) {
        users_info.push_back(user);
    }

    bool check_name(string name) {
        for (int i = 0; i < users_info.size(); i++)
        {
            if (users_info[i].get_name() == name) return true;
        }
        return false;

    }

    bool check_if_logged_in(string user_name) {
        for (int i = 0; i < users_info.size(); i++)
        {
            if (users_info[i].get_user_name() == user_name) return true;
        }
        return false;
    }

    bool check_if_valid_username_and_password(string user_name, string password, string name) {
        for (int i = 0; i < users_info.size(); i++)
        {
            if (users_info[i].get_user_name() == user_name && users_info[i].get_password() == password && users_info[i].get_name() == name) {
                return true;
            }
        }
        return false;
    }

    void delete_user(string name) {
        users_info.erase(remove_if(users_info.begin(), users_info.end(), [name](User& user) {
            return user.get_name() == name;
            }), users_info.end());
    }

    void print_users_info() {
        for (int i = 0; i < users_info.size(); i++)
            users_info[i].print();
    }

    void write_users_info_to_file(const char* path) {
        FILE* file = fopen(path, "w");
        if (!file) cout << "File error!\n";
        else {
            for (User& user : users_info) {
                fprintf(file, "%s, %s, %s, %s, %s, %s, %s\n",
                    user.get_name().c_str(), user.get_surname().c_str(), user.get_father_name().c_str(),
                    user.get_home_address().c_str(), user.get_phone_number().c_str(),
                    user.get_user_name().c_str(), user.get_password().c_str());
            }

            fclose(file);
        }
    }

    void edit_user(User& edit_user, string name) {
        for (int i = 0; i < users_info.size(); i++)
        {
            if (users_info[i].get_name() == name) users_info[i] = edit_user;
        }
    }

};

void write_user_info_to_file(User& user, const char* path) {
    FILE* file = fopen(path, "a");
    fprintf(file, "%s, %s, %s, %s, %s, %s, %s\n", user.get_name().c_str(), user.get_surname().c_str(), user.get_father_name().c_str(), user.get_home_address().c_str(), user.get_phone_number().c_str(), user.get_user_name().c_str(), user.get_password().c_str());

    fclose(file);
}

vector<User> read_users_info_from_file(const char* path) {
    vector<User> users_info;
    FILE* file = fopen(path, "r");
    if (file) {
        char name[100], surname[100], father_name[100], home_address[100], phone_number[100], user_name[100], password[100];
        while (fscanf(file, "%[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %[^,\n]\n", name, surname, father_name, home_address, phone_number, user_name, password) == 7) {
            users_info.push_back(User(name, surname, father_name, home_address, phone_number, user_name, password));
        }
        fclose(file);
    }
    return users_info;
}

class Test {
    string category;
    string testName;
    vector<string> questions;
    vector<string> possible_answers;
    vector<char> answers;
public:
    Test() {
        category = " ";
        testName = " ";
    }

    Test(string category, string testName, vector<string> questions, vector<string> possible_answers, vector<char> answers) {
        this->category = category;
        this->testName = testName;
        this->questions = questions;
        this->possible_answers = possible_answers;
        this->answers = answers;
    }

    void add_question(string question) {
        questions.push_back(question);
    }

    void add_possible_answer(string possible_answer) {
        possible_answers.push_back(possible_answer);
    }

    void add_answer(char answer) {
        answers.push_back(answer);
    }


    void set_question() {
        string question;
        getline(cin >> ws, question);
    }

    void set_possible_answer() {
        string possible_answer;
        getline(cin >> ws, possible_answer);
    }

    void set_answer() {
        char answer;
        cin >> answer;
    }


    string get_category() const { return category; }
    string get_testName() const { return testName; }
    vector<string> get_questions() const { return questions; }
    vector<string> get_possible_answers() const { return possible_answers; }
    vector<char> get_answers() const { return answers; }

    void set_category(string category) { this->category = category; }
    void set_testName(string testName) { this->testName = testName; }
    void set_questions(vector<string> questions) { this->questions = questions; }
    void set_possible_answers(vector<string> possible_answers) { this->possible_answers = possible_answers; }
    void set_answers(vector<char> answers) { this->answers = answers; }


    void print() {
        cout << "Category: " << category << "\n";
        cout << "Test name: " << testName << "\n";
        cout << "Questions: ";
        for (string& question : questions) {
            cout << question << "\n";
        }
        cout << "Possible answers: ";
        for (string& possible_answer : possible_answers) {
            cout << possible_answer << "\n";
        }
        cout << "Answers: ";
        for (char& answer : answers) {
            cout << answer << "\n";
        }
    }


};

Test set_test() {
    Test newTest;

    string category;
    cout << "Enter the category of the test: ";
    getline(cin >> ws, category);
    newTest.set_category(category);

    string testName;
    cout << "Enter the name of the test: ";
    getline(cin >> ws, testName);
    newTest.set_testName(testName);

    int questions_count;
    cout << "Enter the number of questions for the test: ";
    cin >> questions_count;
    cin.ignore();

    for (int i = 0; i < questions_count; i++) {
        string question;
        cout << "Enter question " << i + 1 << ": ";
        getline(cin >> ws, question);
        newTest.add_question(question);

        cout << "Enter three possible answers: \n";
        for (int j = 0; j < 3; j++) {
            string possible_answer;
            cout << "Enter possible answer " << j + 1 << " for question " << i + 1 << ": ";
            getline(cin >> ws, possible_answer);
            newTest.add_possible_answer(possible_answer);
        }
    }

    cout << "Enter the correct answers for the questions (A, B, C, etc.):\n";
    for (int i = 0; i < questions_count; i++) {
        char answer;
        cout << "Enter correct answer for question " << i + 1 << ": ";
        cin >> answer;
        newTest.add_answer(answer);
    }

    return newTest;
}

class test_results {
    string name;
    string fullname;
    int Test_score;
    int percentage;
public:
    test_results(string fullname, string name, int Test_score, int percentage) {
        this->fullname = fullname;
        this->name = name;
        this->Test_score = Test_score;
        this->percentage = percentage;
    }

    void print() {
        cout << "Name: " << name << " Test score: " << Test_score << " (" << percentage << "%)" << "\n";
    }
};

class Category {
    string category_name;
    vector<Test> tests;

public:
    Category() {
        category_name = " ";
    }

    Category(string name) : category_name(name) {}

    void addTest(const Test& test) {
        tests.push_back(test);
    }

    void runTests(string name, const char* path) {
        FILE* file = fopen(path, "a");
        int totalQuestions = 0;
        int correctAnswers = 0;
        char userAnswer;
        double max_score = 12.0;

        cout << "Category: " << category_name << "\n";

        for (auto test : tests) {
            cout << "Test: " << test.get_testName() << "\n";

            int numCorrect = 0;

            for (int i = 0; i < test.get_questions().size(); i++) {
                cout << "Question " << i + 1 << ": " << test.get_questions()[i] << "\n";

                for (int j = i * 3; j < (i * 3) + 3; j++) {
                    cout << test.get_possible_answers()[j] << "\n";
                }

                cout << "Your answer (Choose A, B, or C): ";
                cin >> userAnswer;

                if (userAnswer == test.get_answers()[i]) {
                    cout << "Correct!" << "\n";
                    numCorrect += 6;
                    correctAnswers++;
                }
                else {
                    cout << "Incorrect!" << "\n";
                }

                totalQuestions++;
            }

            double percentage = (numCorrect / max_score) * 100;
            cout << "Test Score: " << numCorrect << " (" << percentage << "%)" << "\n";
            cout << "------------------------------------------\n";


            fprintf(file, "%s:    %s, Test score: %d (%d%%)\n", name.c_str(), test.get_testName().c_str(), numCorrect, (int)percentage);
            fclose(file);
        }
    }

    void write_tests_to_file(char* path) {
        FILE* file = fopen(path, "a");
        if (!file) cout << "File error!\n";
        else {
            for (const Test& test : tests) {
                fprintf(file, "Category: %s\n", test.get_category().c_str());
                fprintf(file, "Questions:\n");
                const vector<string>& questions = test.get_questions();
                for (const string& question : questions) {
                    fprintf(file, "%s\n", question.c_str());
                }
                fprintf(file, "Possible Answers:\n");
                const vector<string>& possible_answers = test.get_possible_answers();
                for (const string& answer : possible_answers) {
                    fprintf(file, "%s\n", answer.c_str());
                }
                fprintf(file, "Answers:\n");
                const vector<char>& answers = test.get_answers();
                for (const char& answer : answers) {
                    fprintf(file, "%c\n", answer);
                }
                fprintf(file, "\n");
            }
        }
        fclose(file);
    }

    void write_test_to_file(const Test& test, const char* path) {
        FILE* file = fopen(path, "a");
        if (!file) {
            cout << "File error!\n";
        }
        else {
            fprintf(file, "Category: %s\n", test.get_category().c_str());
            fprintf(file, "Questions:\n\n");

            const vector<string>& questions = test.get_questions();
            const vector<string>& possible_answers = test.get_possible_answers();
            const vector<char>& answers = test.get_answers();

            for (size_t i = 0; i < questions.size(); i++) {
                fprintf(file, "Question %zu: %s\n", i + 1, questions[i].c_str());
                fprintf(file, "Possible Answers:\n");
                for (int j = i * 3; j < min((i * 3) + 3, possible_answers.size()); j++) {
                    fprintf(file, "Possible answer %d: %s\n", j - (i * 3) + 1, possible_answers[j].c_str());
                }
                fprintf(file, "Answers:\n");
                fprintf(file, "%c\n", answers[i]);
                fprintf(file, "\n");
            }
        }
        fclose(file);
    }

};

vector<Test> read_tests_from_file(const char* path) {
    vector<Test> tests;
    FILE* file = fopen(path, "r");
    if (!file) {
        cout << "File error!\n";
        return tests;
    }

    Test current_test;
    char buffer[256];
    string section;

    while (fgets(buffer, sizeof(buffer), file)) {
        string line(buffer);
        line.erase(line.find_last_not_of("\r\n") + 1);

        if (line.find("Category:") == 0) {
            if (!current_test.get_category().empty()) {
                tests.push_back(current_test);
                current_test = Test();
            }
            current_test.set_category(line.substr(10));
        }
        else if (line == "Questions:") {
            section = "questions";
        }
        else if (line == "Possible Answers:") {
            section = "possible_answers";
        }
        else if (line == "Answers:") {
            section = "answers";
        }
        else if (section == "questions" && !line.empty()) {
            current_test.add_question(line);
        }
        else if (section == "possible_answers" && !line.empty()) {
            current_test.add_possible_answer(line);
        }
        else if (section == "answers" && !line.empty()) {
            current_test.add_answer(line[0]);
        }
    }

    if (!current_test.get_category().empty()) {
        tests.push_back(current_test);
    }

    fclose(file);
    return tests;
}

void read_tests_results_from_file(const char* path) {
    FILE* file = fopen(path, "r");

    if (!file) cout << "File error!\n";

    bool isEmpty = true;
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file)) {
        cout << buffer;
        isEmpty = false;
    }

    if (isEmpty) {
        cout << "No one has taken the test yet." << "\n";
    }

    fclose(file);
}

class Admin {
    string username;
    string password;
public:
    Admin() {
        username = " ";
        password = " ";
    }

    Admin(string username, string password) {
        this->username = username;
        this->password = password;
    }

    string get_username() { return username; }
    string get_password() { return password; }
    void set_username(string username) { this->username = username; }
    void set_password(string password) { this->password = password; }

};

bool check_admin(Admin& a, string username, string password) {
    if (a.get_username() == username && a.get_password() == password) return true;
    return false;
}

void scan_admin(Admin& a, const char* path) {
    FILE* file = fopen(path, "r");
    if (!file) {
        cout << "File error!\n";
    }
    else {
        char username[50];
        char password[50];
        fscanf(file, "%[^,], %s", username, password);
        a.set_username(username);
        a.set_password(password);
        fclose(file);
    }
}

int admin_menu() {
    int choice;
    cout << "0 - Exit\n";
    cout << "1 - Print all users info\n";
    cout << "2 - Add user\n";
    cout << "3 - Delete user\n";
    cout << "4 - Edit user\n";
    cout << "5 - Show user`s tests results\n";
    cout << "6 - Add test\n";

    cout << "Enter choice: ";
    cin >> choice;
    return choice;
}

void print_users_info(vector<User> users_info) {
    for (int i = 0; i < users_info.size(); i++)
        users_info[i].print();
}

void print_tests(vector<Test> tests) {
    for (int i = 0; i < tests.size(); i++)
    {
        tests[i].print();
    }

}

int main() {
    Users_info users_info;
    users_info.set_users_info(read_users_info_from_file("D:\\testers_login_info.txt"));
    vector<Test> tests = read_tests_from_file("D:\\tests.txt");
    vector<test_results> tests_results;

    int choice, log_sign_choice, test_choice, spec_test_choice, questions_count, possible_answers_count;
    string user_name, password, name, admin_user_name, admin_password, category;
    do
    {
        cout << "\nTesting system\n\n";
        cout << "Enter mode (0 - Exit, 1 - admin, 2 - test): ";
        cin >> choice;
        if (!choice) {
            cout << "Bye!\n";
            break;
        }
        else if (choice == 1) {
            Admin a;
            scan_admin(a, "D:\\admin_login.txt");
            cout << "Enter admin user name: ";
            cin >> admin_user_name;
            cout << "Enter admin password: ";
            cin >> admin_password;
            if (check_admin(a, admin_user_name, admin_password)) {
                do
                {
                    int admin_choice = admin_menu();
                    if (!admin_choice) {

                        cout << "Saved\n";
                        break;
                    }

                    switch (admin_choice)
                    {
                    case 1:
                        users_info.print_users_info();
                        break;
                    case 2: {
                        User add_user;
                        add_user.set();
                        users_info.add_user(add_user);
                        write_user_info_to_file(add_user, "D:\\testers_login_info.txt");
                        cout << "Added!\n";
                        break;
                    }
                    case 3:
                        cout << "Enter name of user to delete: ";
                        cin >> name;
                        users_info.delete_user(name);
                        users_info.write_users_info_to_file("D:\\testers_login_info.txt");
                        cout << "Deleted!\n";
                        break;
                    case 4: {
                        cout << "Enter name to edit user by: ";
                        cin >> name;
                        User edit_user;
                        edit_user.set();
                        users_info.edit_user(edit_user, name);
                        users_info.write_users_info_to_file("D:\\testers_login_info.txt");
                        cout << "Edited!\n";
                        break;
                    }
                    case 5:
                        read_tests_results_from_file("D:\\tests_results_for_admin.txt");
                        break;
                    case 6: {
                        Category categ;
                        Test t = set_test();
                        categ.addTest(t);
                        categ.write_test_to_file(t, "D:\\tests.txt");
                        cout << "Test added!\n";
                        break;
                    }
                    default:
                        cout << "Error choice!\n";
                        break;
                    }
                } while (true);
            }
            else cout << "Admin info incorrect!\n";
        }
        else if (choice == 2) {
            do
            {
                cout << "0 - Back, 1 - Sign up to test, 2 - Sign in to test: ";
                cin >> log_sign_choice;
                if (!log_sign_choice) break;
                else if (log_sign_choice == 1) {
                    User u;
                    u.set();
                    if (!users_info.check_if_logged_in(u.get_user_name())) {
                        users_info.add_user(u);
                        write_user_info_to_file(u, "D:\\testers_login_info.txt");
                    }
                    else cout << "You already have an account! You need to log in\n";

                }
                else if (log_sign_choice == 2) {
                    cout << "Enter name: ";
                    cin >> name;
                    cout << "Enter user name: ";
                    cin >> user_name;
                    cout << "Enter password: ";
                    cin >> password;
                    if (users_info.check_if_valid_username_and_password(user_name, password, name)) {
                        do
                        {
                            if (users_info.check_name(name)) {
                                cout << "Enter test category (0 - Back(save result), 1 - Math, 2 - Physics): ";
                                cin >> test_choice;
                                if (!test_choice) {
                                    cout << "Your result saved!\n";
                                    break;
                                }
                                if (test_choice == 1) {
                                    cout << "Enter specific test (1 - Discrete math, 2 - Mathematical analysis): ";
                                    cin >> spec_test_choice;
                                    if (spec_test_choice == 1) {
                                        Category math_category("Math");
                                        vector<string> questions = {
                                            "\nWhat is a set?",
                                            "\nDefine the cardinality of a set."
                                        };
                                        vector<string> possible_answers = {
                                            "\n(Correct) A) A set is a well-defined collection of distinct objects.",
                                            "B) A set is a mathematical operation involving addition and subtraction",
                                            "C) A set is a subset of another set.",
                                            "\nA) The cardinality of a set is the sum of all its elements.",
                                            "(Correct) B) The cardinality of a set is the number of elements in the set.",
                                            "C) Cardinality refers to the order or arrangement of elements in a set."
                                        };
                                        vector<char> answers = { 'A', 'B' };
                                        Test discrete_Math_Test("Math", "Discrete Math", questions, possible_answers, answers);
                                        math_category.addTest(discrete_Math_Test);
                                        math_category.runTests(name, "D:\\tests_results_for_admin.txt");
                                    }
                                    else if (spec_test_choice == 2) {
                                        Category math_category("Math");
                                        vector<string> questions = {
                                            "\nWhat is the definition of a limit of a function?",
                                            "\nWhat is the derivative of the function f(x) = 3x^2 + 2x - 1?"
                                        };
                                        vector<string> possible_answers = {
                                            "\nA) The slope of the tangent line to the function at a given point.",
                                            "(Correct) B) The value that a function approaches as the input approaches a certain value",
                                            "C) The maximum value of the function over a specific interval.",
                                            "\nA) f'(x) = 6x - 1",
                                            "B) f'(x) = 3x^2 + 2x",
                                            "(Correct) C) f'(x) = 6x + 2"

                                        };
                                        vector<char> answers = { 'B', 'C' };
                                        Test Mathematical_analysis("Math", "Mathematical analysis", questions, possible_answers, answers);
                                        math_category.addTest(Mathematical_analysis);
                                        math_category.runTests(name, "D:\\tests_results_for_admin.txt");
                                    }
                                    else cout << "Incorrect test!\n";
                                }
                                else if (test_choice == 2) {
                                    cout << "Enter specific test (1 - Quantum physics, 2 - Mechanistic physics): ";
                                    cin >> spec_test_choice;
                                    if (spec_test_choice == 1) {
                                        Category physics_category("Physics");
                                        vector<string> questions = {
                                            "\nWhat is the Heisenberg uncertainty principle?",
                                            "\nWhat is quantum tunneling?"
                                        };
                                        vector<string> possible_answers = {
                                            "\n(Correct) A) The principle that states the position and momentum of a particle cannot be simultaneously known with absolute precision.",
                                            "B) The principle that describes the energy levels of electrons in an atom.",
                                            "C) The principle that explains the behavior of waves in quantum mechanics",
                                            "\nA) The process of particles colliding and merging to form a new particle.",
                                            "(Correct) B) The phenomenon where particles can pass through potential energy barriers even when they do not have enough energy to overcome them classically.",
                                            "C) The behavior of particles as both particles and waves."
                                        };
                                        vector<char> answers = { 'A', 'B' };
                                        Test Quantum_physics("Physics", "Quantum physics", questions, possible_answers, answers);
                                        physics_category.addTest(Quantum_physics);
                                        physics_category.runTests(name, "D:\\tests_results_for_admin.txt");
                                    }
                                    else if (spec_test_choice == 2) {
                                        Category physics_category("Physics");
                                        vector<string> questions = {
                                            "\nWhat is Newton's second law of motion?",
                                            "\nWhat is the formula to calculate kinetic energy?"
                                        };
                                        vector<string> possible_answers = {
                                            "\nA) The force acting on an object is equal to its mass divided by its acceleration.",
                                            "B) The force acting on an object is equal to its mass multiplied by its velocity.",
                                            "(Correct) C) The force acting on an object is equal to the product of its mass and acceleration.",
                                            "\n(Correct) A) KE = (1/2)mv^2",
                                            "B) KE = mgh",
                                            "C) KE = Fd"
                                        };
                                        vector<char> answers = { 'C', 'A' };
                                        Test Mechanic_physics("Physics", "Mechanic physics", questions, possible_answers, answers);
                                        physics_category.addTest(Mechanic_physics);
                                        physics_category.runTests(name, "D:\\tests_results_for_admin.txt");
                                    }
                                    else cout << "Incorrect test!\n";
                                }
                                else cout << "Incorrect category!\n";
                            }
                            else cout << "You are not registered to the test!\n";

                        } while (true);

                    }
                    else cout << "You don`t have an account, you need to sign up. Or check info repeatedly\n";
                }
            } while (true);

        }
        else cout << "Incorrect mode!\n";

    } while (true);

    return 0;
}
