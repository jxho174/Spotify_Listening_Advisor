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

void showSongSuggestions(int genre) {
    cout << "\nRecommended songs / playlist style\n";
    cout << "----------------------------------\n";

    switch (genre) {
        case 1:
            cout << "Genre: Pop\n";
            cout << "- Espresso - Sabrina Carpenter\n";
            cout << "- As It Was - Harry Styles\n";
            cout << "- Blinding Lights - The Weeknd\n";
            break;
        case 2:
            cout << "Genre: Hip-hop / Rap\n";
            cout << "- HUMBLE. - Kendrick Lamar\n";
            cout << "- God's Plan - Drake\n";
            cout << "- See You Again - Tyler, The Creator ft. Kali Uchis\n";
            break;
        case 3:
            cout << "Genre: K-pop\n";
            cout << "- Dynamite - BTS\n";
            cout << "- Super Shy - NewJeans\n";
            cout << "- How You Like That - BLACKPINK\n";
            break;
        case 4:
            cout << "Genre: Rock\n";
            cout << "- Bohemian Rhapsody - Queen\n";
            cout << "- Smells Like Teen Spirit - Nirvana\n";
            cout << "- Viva La Vida - Coldplay\n";
            break;
        case 5:
            cout << "Genre: Lo-fi / Study\n";
            cout << "- Lo-fi study beats playlist\n";
            cout << "- Chillhop essentials playlist\n";
            cout << "- Peaceful piano playlist\n";
            break;
        default:
            cout << "No genre selected.\n";
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

    const string genres[] = {
        "Pop",
        "Hip-hop / Rap",
        "K-pop",
        "Rock",
        "Lo-fi / Study"
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

    showMenu("Favourite music genre", genres, 5);
    int genre = readChoice("Choose genre (1-5): ", 1, 5);

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

    if (genre == 5) {
        premiumScore += 1;
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

    showSongSuggestions(genre);

    cout << "\nConnection to disruption model\n";
    cout << "Spotify disrupted music by making legal streaming easier and cheaper than buying every song.\n";
    cout << "As features improved, streaming moved from an alternative into the mainstream music market.\n";

    return 0;
}
