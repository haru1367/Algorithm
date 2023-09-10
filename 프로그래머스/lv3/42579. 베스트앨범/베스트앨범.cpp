#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <tuple>

using namespace std;

bool compare(tuple<string, int, int, int>a, tuple<string, int, int, int>b) {
	if (get<1>(a) >= get<1>(b)) {
		if (get<1>(a) == get<1>(b)) {
			if (get<2>(a) > get<2>(b)) {
				return true;
			}
			else if(get<2>(a) == get<2>(b)) {
				if (get<3>(a) < get<3>(b)) {
					return true;
				}
				else {
					return false;
				}

			}
			else {
				return false;
			}
		}
		return true;
	}
	else {
		return false;
	}
}

vector<int>solution(vector<string> genres, vector<int>plays) {
	vector<int>answer;
	vector<tuple<string, int, int, int>>M; // 장르, 장르별 플레이 된 횟수, 해당 곡이 플레이 된 횟수, 고유번호
	vector<string>genres_check = genres;
	vector<int>genres_play;
	vector<int>genres_play1;
	sort(genres_check.begin(), genres_check.end());
	genres_check.erase(unique(genres_check.begin(), genres_check.end()), genres_check.end());
	for (int i = 0; i < genres_check.size(); i++) {
		int play_count=0;
		for (int j= 0; j < genres.size(); j++) {
			if (genres_check[i] == genres[j]) {
				play_count += plays[j];
			}
		}
		genres_play.push_back(play_count);
	}
	vector<pair<string, int>>sss;
	for (int i = 0; i < genres_check.size(); i++) {
		sss.push_back(make_pair(genres_check[i], genres_play[i]));
	}
	for (int i = 0; i < genres.size(); i++) {
		for (int j = 0; j < sss.size(); j++) {
			if (sss[j].first == genres[i]) {
				genres_play1.push_back(sss[j].second);
			}
		}
	}
	for (int i = 0; i < genres.size(); i++) {
		M.push_back(make_tuple(genres[i], genres_play1[i], plays[i], i));
	}

	sort(M.begin(), M.end(), compare);
	vector<string>M_genre;
	for (int i = 0; i < M.size(); i++) {
		M_genre.push_back(get<0>(M[i]));
	}
	M_genre.erase(unique(M_genre.begin(), M_genre.end()), M_genre.end());
	for (int i = 0; i < M_genre.size(); i++) {
		int cnt = 0;
		for (int j = 0; j < M.size(); j++) {
			if (M_genre[i] == get<0>(M[j])) {
				cnt += 1;
				answer.push_back(get<3>(M[j]));
				if (cnt >= 2) {
					break;
				}
			}
		}
	}
	
	return answer;
}