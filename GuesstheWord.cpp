#include "stdafx.h"

//This is an interactive problem.
//You are given an array of unique strings wordlist where wordlist[i] is 6
//letters long, and one word in this list is chosen as secret.
//You may call Master.guess(word) to guess a word. The guessed word should have
//type string and must be from the original list with 6 lowercase letters.
//This function returns an integer type, representing the number of exact matches
//(value and position) of your guess to the secret word. Also, if your guess is
//not in the given wordlist, it will return -1 instead.
//For each test case, you have exactly 10 guesses to guess the word. At the end
//of any number of calls, if you have made 10 or fewer calls to Master.guess and
//at least one of these guesses was secret, then you pass the test case.
// 
//
//Example 1:
//Input: secret = "acckzz", wordlist = ["acckzz","ccbazz","eiowzz","abcczz"],
//numguesses = 10
//Output: You guessed the secret word correctly.
//Explanation:
//master.guess("aaaaaa") returns -1, because "aaaaaa" is not in wordlist.
//master.guess("acckzz") returns 6, because "acckzz" is secret and has all 6
//matches.
//master.guess("ccbazz") returns 3, because "ccbazz" has 3 matches.
//master.guess("eiowzz") returns 2, because "eiowzz" has 2 matches.
//master.guess("abcczz") returns 4, because "abcczz" has 4 matches.
//We made 5 calls to master.guess and one of them was the secret, so we pass the
//test case.
//
//Example 2:
//Input: secret = "hamada", wordlist = ["hamada","khaled"], numguesses = 10
//Output: You guessed the secret word correctly.
// 
//Constraints:
//1 <= wordlist.length <= 100
//wordlist[i].length == 6
//wordlist[i] consist of lowercase English letters.
//All the strings of wordlist are unique.
//secret exists in wordlist.
//numguesses == 10

namespace Solution2022
{
	namespace GuesstheWord
	{
		// This is the Master's API interface.
		// You should not implement it, or speculate about its implementation
		class Master {
		public:
			int guess(string word) { return 0; };
		};

		namespace UseHistogram {
			int match(string& a, string& b) {
				int result = 0;
				for (int i = 0; i < 6; i++) {
					if (a[i] == b[i]) { result++; }
				}
				return result;
			}

			string bestCandidate(list<string>& words, vector<vector<int>>& probs) {
				string result = "";
				int maxScore = 0;
				for (string& w : words) {
					int score = 1;
					for (int i = 0; i < 6; i++) {
						score *= probs[i][w[i] - 'a'];
					}
					if (score > maxScore) {
						maxScore = score;
						result = w;
					}
				}
				return result;
			}

			void findSecretWord(vector<string>& wordlist, Master& master) {
				vector<vector<int>> probs(6, vector<int>(26, 0));
				list<string> remainWords;
				for (string w : wordlist) {
					remainWords.push_back(w);
					for (int i = 0; i < 6; i++) {
						probs[i][w[i] - 'a']++;
					}
				}
				int matches = 0;
				while (matches < 6) {
					string candidate = bestCandidate(remainWords, probs);
					matches = master.guess(candidate);
					auto it = remainWords.begin();
					while (it != remainWords.end()) {
						string cur = *it;
						if (match(cur, candidate) != matches) {
							for (int i = 0; i < 6; i++) {
								probs[i][cur[i] - 'a']--;
							}
							it = remainWords.erase(it);
						}
						else { it++; }
					}
				}
			}
		}

		namespace GuesstheWord
		{
			namespace minimax {
				int match(string& a, string& b) {
					int result = 0;
					for (int i = 0; i < a.size(); i++) {
						if (a[i] == b[i]) { result++; }
					}
					return result;
				}

				void findSecretWord(vector<string>& wordlist, Master& master) {
					int x = 0;
					for (int i = 0; i < 10 && x < 6; i++) {
						unordered_map<string, int> count;
						for (string w1 : wordlist) {
							for (string w2 : wordlist) {
								if (match(w1, w2) == 0) {
									count[w1] ++;
								}
							}
						}

						pair<string, int> minimax = make_pair(wordlist[0], 1000);
						for (string w : wordlist) {
							if (count[w] <= minimax.second) {
								minimax = make_pair(w, count[w]);
							}
						}
						x = master.guess(minimax.first);
						vector<string> wordlist2;
						for (string w : wordlist) {
							if (match(minimax.first, w) == x) {
								wordlist2.push_back(w);
							}
						}
						wordlist = wordlist2;
					}
				}
			}

			void Main() {
				string test = "tst test test";
				print(test);
			}
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
