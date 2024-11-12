#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Cấu trúc để lưu thông tin bài viết
struct Post {
    string content;
    int likes;
    int shares;
    int comments;
};

// Hàm đọc dữ liệu từ file CSV và lưu vào vector
void readCSV(const string& filename, vector<Post>& posts) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Không thể mở file: " << filename << endl;
        return;
    }

    string line;
    // Bỏ qua dòng tiêu đề
    getline(file, line);

    // Đọc từng dòng dữ liệu
    while (getline(file, line)) {
        stringstream ss(line);
        Post post;
        string likesStr, sharesStr, commentsStr;

        getline(ss, post.content, ',');   // Đọc nội dung bài viết
        getline(ss, likesStr, ',');       // Đọc số lượt thích
        getline(ss, sharesStr, ',');      // Đọc số lượt chia sẻ
        getline(ss, commentsStr, ',');    // Đọc số bình luận

        // Chuyển đổi chuỗi thành số
        post.likes = stoi(likesStr);
        post.shares = stoi(sharesStr);
        post.comments = stoi(commentsStr);

        posts.push_back(post);
    }
}

// Hàm so sánh để sắp xếp theo lượt thích (giảm dần)
bool compareByLikes(const Post& a, const Post& b) {
    return a.likes > b.likes;
}

// Hàm so sánh để sắp xếp theo lượt chia sẻ (giảm dần)
bool compareByShares(const Post& a, const Post& b) {
    return a.shares > b.shares;
}

// Hàm so sánh để sắp xếp theo bình luận (giảm dần)
bool compareByComments(const Post& a, const Post& b) {
    return a.comments > b.comments;
}

int main() {
    vector<Post> posts;
    readCSV("sentimentdataset.csv", posts);

    if (posts.empty()) {
        cerr << "Không có dữ liệu để sắp xếp." << endl;
        return 1;
    }

    // Sắp xếp bài viết theo lượt thích
    sort(posts.begin(), posts.end(), compareByLikes);
    cout << "Bài viết sắp xếp theo lượt thích (giảm dần):\n";
    for (const auto& post : posts) {
        cout << "Nội dung: " << post.content << " - Thích: " << post.likes
            << ", Chia sẻ: " << post.shares << ", Bình luận: " << post.comments << "\n";
    }

    // Sắp xếp bài viết theo lượt chia sẻ
    sort(posts.begin(), posts.end(), compareByShares);
    cout << "\nBài viết sắp xếp theo lượt chia sẻ (giảm dần):\n";
    for (const auto& post : posts) {
        cout << "Nội dung: " << post.content << " - Thích: " << post.likes
            << ", Chia sẻ: " << post.shares << ", Bình luận: " << post.comments << "\n";
    }

    // Sắp xếp bài viết theo bình luận
    sort(posts.begin(), posts.end(), compareByComments);
    cout << "\nBài viết sắp xếp theo bình luận (giảm dần):\n";
    for (const auto& post : posts) {
        cout << "Nội dung: " << post.content << " - Thích: " << post.likes
            << ", Chia sẻ: " << post.shares << ", Bình luận: " << post.comments << "\n";
    }

    return 0;
}
