// map 풀이
#include <bits/stdc++.h>
using namespace std;
map<string, int> m;
int main()
{
    string s;
    int cnt = 0;

    while(1){
        getline(cin,s);
        if(!s.length()) break;
        cnt++;
        m[s]++;
    }

    cout << fixed;
    cout.precision(4);

    for(auto it=m.begin() ; it!=m.end() ; it++){
        double temp = ((double)it->second / cnt);
        cout << it->first << " " << temp * 100 << "\n";
    }

    return 0;
}

// Trie 풀이
#include <bits/stdc++.h>
using namespace std;

struct Trie {
    Trie *nextTrie[100];
    int cnt;
    Trie() {
        for(int i=0 ; i<100 ; i++) nextTrie[i] = nullptr;
        cnt = 0;
    }
    ~Trie() {
        for(int i=0 ; i<100 ; i++)
            if(nextTrie[i]) nextTrie[i] = NULL;
    }
    void insert(char* word) {
        if(*word == '\0'){
            cnt++;
            return ;
        }
        int nextNum = *word - ' ';
        if(nextTrie[nextNum] == NULL)
            nextTrie[nextNum] = new Trie();
        nextTrie[nextNum]->insert(word + 1);
    }
};

void solve(Trie* trie, char* word, int n, char* str){
    if(trie->cnt){
        *word = '\0';
        cout << str << " " << double(trie->cnt) / n * 100 << "\n";
        return;
    }
    else {
        for(int i=0 ; i<100 ; i++){
            if(trie->nextTrie[i]){
                *word = i + ' ';
                solve(trie->nextTrie[i], word+1, n , str);
            }
        }
    }
}

int main()
{
    cout << fixed;
    cout.precision(4);
    Trie* trie = new Trie();
    int n = 0;
    char str[31];
    while(scanf(" %[^\n]s", str) != EOF){
        trie->insert(str);
        n++;
    }
    for(int i=0 ; i<100 ; i++){
        if(trie->nextTrie[i]){
            char word[31];
            word[0] = i + ' ';
            solve(trie->nextTrie[i], word+1 , n , word);
        }
    }
    delete trie;
    return 0;
}

/*
trie를 사용했을 때가 그렇지 않은 경우보다 시간이 절반정도 덜 걸렸다.
trie는 문자열 탐색 시 유용한데, 특정 단어를 찾을 때 O(문자열 길이) 의 시간만에 찾을 수 있기에 map을 사용하는 것보다 적은 시간이 걸린다.
하지만 다음 노드를 가리키는 포인터의 개수에 따라 메모리가 아주 커질 수 있기 때문에 공간 복잡도에서는 좋지 않은 효율을 보인다.
*/
