#include <iostream>
#include <vector>
#include <string>
using namespace std;

class BrowserHistory {
public:
    vector<string> history;
    int currentIndex;

    BrowserHistory(string homepage) {
        history.push_back(homepage);
        currentIndex = 0;
    }

    void visit(string url) {
        history.resize(currentIndex + 1); // Xóa forward history
        history.push_back(url);
        currentIndex++;
    }

    string back(int steps) {
        currentIndex = max(0, currentIndex - steps);
        return history[currentIndex];
    }

    string forward(int steps) {
        currentIndex = min((int)history.size() - 1, currentIndex + steps);
        return history[currentIndex];
    }
};

int main() {
    // Dữ liệu đầu vào
    vector<string> commands = {"BrowserHistory", "visit", "visit", "visit", "back", "back", "forward", "visit", "forward", "back", "back"};
    vector<vector<string>> args = {{"uit.edu.vn"}, {"google.com"}, {"facebook.com"}, {"youtube.com"}, {"1"}, {"1"}, {"1"}, {"linkedin.com"}, {"2"}, {"2"}, {"7"}};

    vector<string> result;
    BrowserHistory* browser = nullptr;

    // Xử lý các lệnh và đối số
    for (size_t i = 0; i < commands.size(); ++i) {
        if (commands[i] == "BrowserHistory") {
            browser = new BrowserHistory(args[i][0]);
            result.push_back("null"); // Lệnh này không trả về giá trị
        } else if (commands[i] == "visit") {
            browser->visit(args[i][0]);
            result.push_back("null"); // Lệnh này không trả về giá trị
        } else if (commands[i] == "back") {
            int steps = stoi(args[i][0]);
            result.push_back(browser->back(steps)); // Trả về URL sau khi back
        } else if (commands[i] == "forward") {
            int steps = stoi(args[i][0]);
            result.push_back(browser->forward(steps)); // Trả về URL sau khi forward
        }
    }

    // In kết quả dưới dạng mảng
    cout << "[";
    for (size_t i = 0; i < result.size(); ++i) {
        cout << "\"" << result[i] << "\"";
        if (i != result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
