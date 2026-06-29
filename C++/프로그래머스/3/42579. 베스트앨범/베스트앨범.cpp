#include <string>
#include <vector>
#include <unordered_map>
#include <utility>
#include <algorithm>

using namespace std;

bool compare(pair<int,int> a, pair<int,int> b){
    if(a.first != b.first){
        return a.first > b.first;
    }
    return a.second < b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, int> genre_playcount;
    unordered_map<string, vector<pair<int, int>>> genre_songs;

    // 1. make hash table for genre : total plays
    int genres_length = genres.size();
    for(int i = 0; i < genres_length; i++){
        genre_playcount[genres[i]] += plays[i];
        genre_songs[genres[i]].push_back(make_pair(plays[i], i));
    }

    vector<pair<int,string>> ordered_genre;

    for(auto& g: genre_playcount){
        ordered_genre.push_back(make_pair(g.second, g.first));
    }

    sort(ordered_genre.begin(), ordered_genre.end(), greater<>());

    int ordered_length = ordered_genre.size();

    for(auto& s : genre_songs){
        sort(s.second.begin(), s.second.end(), compare);
    }

    // 4. find top 2
    int count;
    for(auto& genre : ordered_genre){
        count = 0;
        for(auto& song : genre_songs[genre.second]){
            if(count == 2){
                break;
            }
            answer.push_back(song.second);
            count++;
        }
    }
    return answer;
}