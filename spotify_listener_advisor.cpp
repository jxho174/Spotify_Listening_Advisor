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
    const string listenerTypes[] = {
        "Student or casual listener",
        "Daily commuter",
        "Music collector",
        "Playlist/discovery fan"
    };

    const string situations[] = {
        "Mostly online listening",
        "Often offline or weak internet",
        "Long study/work sessions",
        "Parties or shared playlists"
    };

    const string budgets[] = {
        "Free only",
        "Low monthly budget",
        "Comfortable paying for convenience"
    };

    cout << "Spotify Listening Advisor\n";
    cout << "This program connects to the Part 1 topic: Spotify as a disruptive innovation.\n";
    cout << "It recommends Spotify Free, Spotify Premium, or music ownership based on user needs.\n";

    showMenu("Listener type", listenerTypes, 4);
    int listenerType = readChoice("Choose listener type (1-4): ", 1, 4);

    showMenu("Listening situation", situations, 4);
    int situation = readChoice("Choose situation (1-4): ", 1, 4);

    showMenu("Budget", budgets, 3);
    int budget = readChoice("Choose budget (1-3): ", 1, 3);

    int acceptsAds = readChoice("\nCan you accept advertisements? (1 = yes, 2 = no): ", 1, 2);
    int wantsDiscovery = readChoice("Do you want playlist/music discovery features? (1 = yes, 2 = no): ", 1, 2);

    int freeScore = 0;
    int premiumScore = 0;
    int ownershipScore = 0;

    switch (listenerType) {
        case 1:
            freeScore += 3;
            premiumScore += 1;
            break;
        case 2:
            premiumScore += 3;
            break;
        case 3:
            ownershipScore += 4;
            break;
        case 4:
            freeScore += 1;
            premiumScore += 3;
            break;
    }

    switch (situation) {
        case 1:
            freeScore += 2;
            premiumScore += 2;
            break;
        case 2:
            ownershipScore += 3;
            premiumScore += 2;
            break;
        case 3:
            premiumScore += 2;
            break;
        case 4:
            premiumScore += 2;
            freeScore += 1;
            break;
    }

    if (budget == 1) {
        freeScore += 4;
    } else if (budget == 2) {
        premiumScore += 2;
        freeScore += 1;
    } else {
        premiumScore += 3;
        ownershipScore += 1;
    }

    if (acceptsAds == 1) {
        freeScore += 2;
    } else {
        premiumScore += 3;
    }

    if (wantsDiscovery == 1) {
        premiumScore += 2;
        freeScore += 1;
    } else {
        ownershipScore += 2;
    }

    cout << "\nRecommendation\n";
    cout << "--------------\n";

    if (premiumScore >= freeScore && premiumScore >= ownershipScore) {
        cout << "Recommended choice: Spotify Premium.\n";
        cout << "Reason: You benefit from convenience, fewer interruptions, discovery, and offline listening.\n";
    } else if (freeScore >= premiumScore && freeScore >= ownershipScore) {
        cout << "Recommended choice: Spotify Free.\n";
        cout << "Reason: You value low cost and legal access more than full control or ad-free listening.\n";
    } else {
        cout << "Recommended choice: Buy/download music or use CDs for key albums.\n";
        cout << "Reason: You value ownership, offline reliability, and control over access.\n";
    }

    cout << "\nScores\n";
    cout << "Spotify Free: " << freeScore << "\n";
    cout << "Spotify Premium: " << premiumScore << "\n";
    cout << "Music ownership: " << ownershipScore << "\n";

    cout << "\nConnection to disruption model\n";
    cout << "Spotify disrupted music by making legal streaming easier and cheaper than buying every song.\n";
    cout << "As features improved, streaming moved from an alternative into the mainstream music market.\n";

    return 0;
}
