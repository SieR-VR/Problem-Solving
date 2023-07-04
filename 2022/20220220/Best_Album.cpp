#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Song {
    int num;
    string genre;
    int plays;
};

vector<int> solution(vector<string> genres, vector<int> plays) {
    map<string, int> m;
    for(int i = 0; i < genres.size(); i++) {
        m[genres[i]] += plays[i];
    }

    vector<Song> songs;
    for(int i = 0; i < genres.size(); i++) {
        songs.push_back(Song({ i, genres[i], plays[i] }));
    }

    sort(songs.begin(), songs.end(), [&](Song a, Song b) {
        if (m[a.genre] > m[b.genre]) return true;
        if (m[a.genre] < m[b.genre]) return false;

        if (a.plays > b.plays) return true;
        if (a.plays < b.plays) return false;

        if (a.num < b.num) return true;
        else return false;
    });

    vector<int> answer;
    string prev;
    int genre_inserted = 0;
    for(int i = 0; i < songs.size(); i++) {
        if (prev != songs[i].genre) {
            answer.push_back(songs[i].num);
            genre_inserted = 1;
        }
        else {
            if (genre_inserted == 1) {
                answer.push_back(songs[i].num);
                genre_inserted == 2;
            }
        }
    }

    return answer;
}