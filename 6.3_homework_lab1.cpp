#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

class AuthenticationManager {
private:
    unordered_map<string, int> tokens; // Lưu trữ tokenId và thời gian hết hạn
    int timeToLive;

public:
    AuthenticationManager(int timeToLive) {
        this->timeToLive = timeToLive;
    }

    // Tạo token mới
    void generate(string tokenId, int currentTime) {
        tokens[tokenId] = currentTime + timeToLive;
    }

    // Gia hạn token nếu chưa hết hạn
    void renew(string tokenId, int currentTime) {
        if (tokens.find(tokenId) != tokens.end() && tokens[tokenId] > currentTime) {
            tokens[tokenId] = currentTime + timeToLive;
        }
    }

    // Đếm số token chưa hết hạn
    int countUnexpiredTokens(int currentTime) {
        int count = 0;
        for (auto it = tokens.begin(); it != tokens.end(); ) {
            if (it->second > currentTime) {
                count++;
                ++it;
            } else {
                it = tokens.erase(it); // Xóa token đã hết hạn
            }
        }
        return count;
    }
};

int main() {
    // Input theo cách của bạn
    vector<string> commands = {"AuthenticationManager", "renew", "generate", "countUnexpiredTokens", "generate", "renew", "renew", "countUnexpiredTokens"};
    vector<vector<string>> args = {{"5"}, {"aaa", "1"}, {"aaa", "2"}, {"6"}, {"bbb", "7"}, {"aaa", "8"}, {"bbb", "10"}, {"15"}};

    vector<string> result;
    AuthenticationManager* manager = nullptr;

    for (size_t i = 0; i < commands.size(); ++i) {
        if (commands[i] == "AuthenticationManager") {
            manager = new AuthenticationManager(stoi(args[i][0]));
            result.push_back("null");
        } else if (commands[i] == "generate") {
            manager->generate(args[i][0], stoi(args[i][1]));
            result.push_back("null");
        } else if (commands[i] == "renew") {
            manager->renew(args[i][0], stoi(args[i][1]));
            result.push_back("null");
        } else if (commands[i] == "countUnexpiredTokens") {
            int count = manager->countUnexpiredTokens(stoi(args[i][0]));
            result.push_back(to_string(count));
        }
    }

    // In kết quả theo định dạng yêu cầu
    cout << "[";
    for (size_t i = 0; i < result.size(); ++i) {
        cout << "\"" << result[i] << "\"";
        if (i != result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
