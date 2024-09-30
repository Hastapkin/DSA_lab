#include <iostream>
#include <list>
#include <string>
#include <algorithm> // Thêm dòng này để sử dụng std::find
using namespace std;

int main() {
    int n;
    cin >> n;
    list<string> playlist;
    list<string>::iterator current = playlist.end();  // Sử dụng iterator để giữ vị trí bài hát hiện tại

    for (int i = 0; i < n; ++i) {
        string command;
        cin >> command;

        if (command == "ADD") {
            string song_name;
            cin >> song_name;
            playlist.push_back(song_name);
            if (playlist.size() == 1) {
                current = playlist.begin();  // Nếu là bài hát đầu tiên, đặt iterator ở đầu danh sách
            }
        } else if (command == "NEXT") {
            if (!playlist.empty()) {
                current++;
                if (current == playlist.end()) {
                    current = playlist.begin();  // Quay lại bài đầu tiên nếu đến cuối danh sách
                }
            }
        } else if (command == "PREV") {
            if (!playlist.empty()) {
                if (current == playlist.begin()) {
                    current = playlist.end();  // Quay lại bài cuối cùng nếu ở bài đầu tiên
                }
                current--;
            }
        } else if (command == "REMOVE") {
            string song_name;
            cin >> song_name;
            if (!playlist.empty()) {
                auto it = find(playlist.begin(), playlist.end(), song_name);
                if (it != playlist.end()) {  // Nếu tìm thấy bài hát cần xóa
                    if (it == current) {     // Nếu bài hát đang phát hiện tại bị xóa
                        if (next(current) != playlist.end()) {
                            current++;
                        } else if (current != playlist.begin()) {
                            current--;
                        } else {
                            current = playlist.end();  // Nếu là bài hát duy nhất
                        }
                    }
                    playlist.erase(it);
                }
            }
        } else if (command == "DISPLAY") {
            if (!playlist.empty()) {
                for (const auto &song : playlist) {
                    cout << song << " ";
                }
                cout << endl;
            }
        }
    }
    return 0;
}
