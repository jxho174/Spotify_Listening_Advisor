#include <iostream>
#include <limits>
#include <string>

using namespace std;

int readChoice(const string& prompt, int minimum, int maximum) {
    int choice;

    while (true) {
        cout << prompt;
        cin >> choice;

        if (cin.fail() || choice < minimum || choice > maximum) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number from "
                 << minimum << " to " << maximum << ".\n\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return choice;
        }
    }
}

void showMenu(const string& title, const string options[], int count) {
    cout << "\n" << title << "\n";
    for (int i = 0; i < count; ++i) {
        cout << "  " << (i + 1) << ". " << options[i] << "\n";
    }
}

int main() {
    const string roles[] = {
        "Student or beginner creator",
        "Freelancer or small studio",
        "Large professional studio",
        "Education or training team"
    };

    const string tasks[] = {
        "Video editing",
        "Photo/design editing",
        "Mixed media campaign",
        "Learning and practice"
    };

    const string internetLevels[] = {
        "Weak or unstable",
        "Average",
        "Strong"
    };

    cout << "Creative Cloud Editing Advisor\n";
    cout << "This program connects to the Part 1 topic: Adobe Creative Cloud as a disruptive innovation.\n";
    cout << "It recommends an editing workflow based on user needs, cost sensitivity, internet access, and collaboration.\n";

    showMenu("User type", roles, 4);
    int role = readChoice("Choose user type (1-4): ", 1, 4);

    showMenu("Main creative task", tasks, 4);
    int task = readChoice("Choose task (1-4): ", 1, 4);

    showMenu("Internet quality", internetLevels, 3);
    int internet = readChoice("Choose internet quality (1-3): ", 1, 3);

    int budgetSensitive = readChoice("\nIs lower upfront cost important? (1 = yes, 2 = no): ", 1, 2);
    int collaboration = readChoice("Do you need real-time collaboration? (1 = yes, 2 = no): ", 1, 2);

    int cloudScore = 0;
    int traditionalScore = 0;
    int hybridScore = 0;

    switch (role) {
        case 1:
            cloudScore += 3;
            break;
        case 2:
            cloudScore += 2;
            hybridScore += 1;
            break;
        case 3:
            traditionalScore += 2;
            hybridScore += 2;
            break;
        case 4:
            cloudScore += 2;
            hybridScore += 1;
            break;
    }

    switch (task) {
        case 1:
            hybridScore += 2;
            break;
        case 2:
            cloudScore += 2;
            break;
        case 3:
            cloudScore += 2;
            #include <iostream>
#include <limits>
#include <string>

using namespace std;

int readChoice(const string& prompt, int minimum, int maximum) {
    int choice;

    while (true) {
        cout << prompt;
        cin >> choice;

        if (cin.fail() || choice < minimum || choice > maximum) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number from "
                 << minimum << " to " << maximum << ".\n\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return choice;
        }
    }
}

void showMenu(const string& title, const string options[], int count) {
    cout << "\n" << title << "\n";
    for (int i = 0; i < count; ++i) {
        cout << "  " << (i + 1) << ". " << options[i] << "\n";
    }
}

int main() {
    const string roles[] = {
        "Student or beginner creator",
        "Freelancer or small studio",
        "Large professional studio",
        "Education or training team"
    };

    const string tasks[] = {
        "Video editing",
        "Photo/design editing",
        "Mixed media campaign",
        "Learning and practice"
    };

    const string internetLevels[] = {
        "Weak or unstable",
        "Average",
        "Strong"
    };

    cout << "Creative Cloud Editing Advisor\n";
    cout << "This program connects to the Part 1 topic: Adobe Creative Cloud as a disruptive innovation.\n";
    cout << "It recommends an editing workflow based on user needs, cost sensitivity, internet access, and collaboration.\n";

    showMenu("User type", roles, 4);
    int role = readChoice("Choose user type (1-4): ", 1, 4);

    showMenu("Main creative task", tasks, 4);
    int task = readChoice("Choose task (1-4): ", 1, 4);

    showMenu("Internet quality", internetLevels, 3);
    int internet = readChoice("Choose internet quality (1-3): ", 1, 3);

    int budgetSensitive = readChoice("\nIs lower upfront cost important? (1 = yes, 2 = no): ", 1, 2);
    int collaboration = readChoice("Do you need real-time collaboration? (1 = yes, 2 = no): ", 1, 2);

    int cloudScore = 0;
    int traditionalScore = 0;
    int hybridScore = 0;

    switch (role) {
        case 1:
            cloudScore += 3;
            break;
        case 2:
            cloudScore += 2;
            hybridScore += 1;
            break;
        case 3:
            traditionalScore += 2;
            hybridScore += 2;
            break;
        case 4:
            cloudScore += 2;
            hybridScore += 1;
            break;
    }

    switch (task) {
        case 1:
            hybridScore += 2;
            break;
        case 2:
            cloudScore += 2;
            break;
        case 3:
            cloudScore += 2;
            hybridScore += 2;
            break;
        case 4:
            cloudScore += 3;
            break;
    }

    if (internet == 1) {
        traditionalScore += 3;
        hybridScore += 2;
    } else if (internet == 2) {
        hybridScore += 2;
        cloudScore += 1;
    } else {
        cloudScore += 3;
    }

    if (budgetSensitive == 1) {
        cloudScore += 2;
    } else {
        traditionalScore += 1;
        hybridScore += 1;
    }

    if (collaboration == 1) {
        cloudScore += 3;
        hybridScore += 1;
    } else {
        traditionalScore += 1;
    }

    cout << "\nRecommendation\n";
    cout << "--------------\n";

    if (cloudScore >= traditionalScore && cloudScore >= hybridScore) {
        cout << "Use a Creative Cloud-first workflow.\n";
        cout << "Reason: Your profile benefits from accessibility, subscription access, regular updates, and collaboration.\n";
    } else if (hybridScore >= cloudScore && hybridScore >= traditionalScore) {
        cout << "Use a hybrid workflow.\n";
        cout << "Reason: Cloud tools are useful, but some offline control is still important for your situation.\n";
    } else {
        cout << "Use a traditional/offline editing workflow.\n";
        cout << "Reason: Your situation values stability, local control, and lower dependence on internet access.\n";
    }

    cout << "\nScores\n";
    cout << "Creative Cloud workflow: " << cloudScore << "\n";
    cout << "Hybrid workflow: " << hybridScore << "\n";
    cout << "Traditional workflow: " << traditionalScore << "\n";

    cout << "\nConnection to disruption model\n";
    cout << "Adobe Creative Cloud began as a more accessible and flexible alternative to expensive professional workflows.\n";
    cout << "As cloud sync, collaboration, and cross-platform access improved, it moved upward into professional use.\n";

    return 0;
}