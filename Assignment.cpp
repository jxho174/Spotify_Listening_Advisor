#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Feedback {
    string recommendation;
    int rating;
    string review;
};

void showSection(const string& title) {
    cout << "\n========================================\n";
    cout << title << "\n";
    cout << "========================================\n";
}

int readChoice(const string& prompt, int minimum, int maximum) {
    string input;

    while (true) {
        cout << prompt << " (or q to quit): ";
        getline(cin, input);

        if (input == "q" || input == "Q") {
            return -1;
        }

        bool isNumber = !input.empty();
        for (char c : input) {
            if (c < '0' || c > '9') {
                isNumber = false;
            }
        }

        if (!isNumber) {
            cout << "Invalid input. Please enter a number from "
                 << minimum << " to " << maximum << ", or q to quit.\n\n";
            continue;
        }

        int choice = stoi(input);
        if (choice < minimum || choice > maximum) {
            cout << "Invalid input. Please enter a number from "
                 << minimum << " to " << maximum << ", or q to quit.\n\n";
        } else {
            return choice;
        }
    }
}

void saveFeedbackToFile(const Feedback& feedback) {
    ofstream outFile("spotify_feedback_reviews.txt", ios::app);

    if (!outFile) {
        cout << "Warning: feedback file could not be opened.\n";
        return;
    }

    outFile << "Recommendation: " << feedback.recommendation << "\n";
    outFile << "Rating: " << feedback.rating << "/5\n";
    outFile << "Review: " << feedback.review << "\n";
    outFile << "------------------------------\n";
}

void showStoredFeedback(const vector<Feedback>& feedbackList) {
    showSection("Feedback stored this session");

    if (feedbackList.empty()) {
        cout << "No feedback was entered.\n";
        return;
    }

    for (int i = 0; i < static_cast<int>(feedbackList.size()); ++i) {
        cout << "Feedback " << (i + 1) << "\n";
        cout << "Recommendation: " << feedbackList[i].recommendation << "\n";
        cout << "Rating: " << feedbackList[i].rating << "/5\n";
        cout << "Review: " << feedbackList[i].review << "\n\n";
    }
}

void showMenu(const string& title, const string options[], int count) {
    showSection(title);
    for (int i = 0; i < count; ++i) {
        cout << "  " << (i + 1) << ". " << options[i] << "\n";
    }
}

void showSongSuggestions(int genre) {
    showSection("Recommended songs / playlist style");

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

void showListeningSummary(int hoursPerWeek) {
    int monthlyHours = hoursPerWeek * 4;
    int estimatedSongs = monthlyHours * 15;

    showSection("Listening summary");
    cout << "Estimated listening time per month: " << monthlyHours << " hours\n";
    cout << "Estimated songs played per month: " << estimatedSongs << " songs\n";

    if (hoursPerWeek >= 15) {
        cout << "Listening habit: Heavy listener\n";
    } else if (hoursPerWeek >= 6) {
        cout << "Listening habit: Regular listener\n";
    } else {
        cout << "Listening habit: Light listener\n";
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

    vector<Feedback> feedbackList;
    int runAgain = 1;
    bool quitProgram = false;

    showSection("Spotify Listening Advisor");
    cout << "It recommends Spotify Free, Spotify Premium, or music ownership based on user needs.\n";

    while (runAgain == 1 && !quitProgram) {
        showMenu("Listener type", listenerTypes, 4);
        int listenerType = readChoice("Choose listener type (1-4)", 1, 4);
        if (listenerType == -1) {
            quitProgram = true;
            break;
        }

        showMenu("Listening situation", situations, 4);
        int situation = readChoice("Choose situation (1-4)", 1, 4);
        if (situation == -1) {
            quitProgram = true;
            break;
        }

        showMenu("Budget", budgets, 3);
        int budget = readChoice("Choose budget (1-3)", 1, 3);
        if (budget == -1) {
            quitProgram = true;
            break;
        }

        int acceptsAds = readChoice("\nCan you accept advertisements? (1 = yes, 2 = no)", 1, 2);
        if (acceptsAds == -1) {
            quitProgram = true;
            break;
        }

        int wantsDiscovery = readChoice("Do you want playlist/music discovery features? (1 = yes, 2 = no)", 1, 2);
        if (wantsDiscovery == -1) {
            quitProgram = true;
            break;
        }

        showMenu("Favourite music genre", genres, 5);
        int genre = readChoice("Choose genre (1-5)", 1, 5);
        if (genre == -1) {
            quitProgram = true;
            break;
        }

        showSection("Listening time");
        int hoursPerWeek = readChoice("How many hours do you listen per week? (0-80)", 0, 80);
        if (hoursPerWeek == -1) {
            quitProgram = true;
            break;
        }

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

        if (hoursPerWeek >= 15) {
            premiumScore += 3;
        } else if (hoursPerWeek >= 6) {
            premiumScore += 1;
            freeScore += 1;
        } else {
            freeScore += 1;
        }

        string recommendation;
        string reason;

        if (premiumScore >= freeScore && premiumScore >= ownershipScore) {
            recommendation = "Spotify Premium";
            reason = "You benefit from convenience, fewer interruptions, discovery, and offline listening.";
        } else if (freeScore >= premiumScore && freeScore >= ownershipScore) {
            recommendation = "Spotify Free";
            reason = "You value low cost and legal access more than full control or ad-free listening.";
        } else {
            recommendation = "Buy/download music or use CDs for key albums";
            reason = "You value ownership, offline reliability, and control over access.";
        }

        showSection("Recommendation");
        cout << "Recommended choice: " << recommendation << ".\n";
        cout << "Reason: " << reason << "\n";

        showSection("Scores");
        cout << "Spotify Free: " << freeScore << "\n";
        cout << "Spotify Premium: " << premiumScore << "\n";
        cout << "Music ownership: " << ownershipScore << "\n";

        showListeningSummary(hoursPerWeek);
        showSongSuggestions(genre);

        int rating = readChoice("\nRate this recommendation (1 = poor, 5 = excellent)", 1, 5);
        if (rating == -1) {
            quitProgram = true;
            break;
        }

        string review;

        cout << "Write your feedback/review (or q to quit): ";
        getline(cin, review);

        if (review == "q" || review == "Q") {
            quitProgram = true;
            break;
        }

        if (review.empty()) {
            review = "No written review provided.";
        }

        Feedback feedback = {recommendation, rating, review};
        feedbackList.push_back(feedback);
        saveFeedbackToFile(feedback);

        cout << "\nThank you. Your feedback has been stored.\n";
        cout << "It was also saved to spotify_feedback_reviews.txt.\n";

        runAgain = readChoice("\nDo you want to use the advisor again? (1 = yes, 2 = no)", 1, 2);
        if (runAgain == -1) {
            quitProgram = true;
        }
    }

    if (quitProgram) {
        cout << "\nProgram quit by user.\n";
    }

    showStoredFeedback(feedbackList);

    return 0;
}
