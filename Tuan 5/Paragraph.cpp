#include <iostream>
#include<vector>
#include<fstream>
#include<string>
#include <map>
#include <algorithm>
using namespace std;
class StatisticParagraph
{
private:
    string LinkFile;
    vector<string> Paragraph;
    int NumberOfLine;
public:
    StatisticParagraph(string File);
    StatisticParagraph();
    ~StatisticParagraph();
    void ReadFile();
    int CountSentences(); //end by .,!,?
    int CountWordInParagraph(string word);
    void CountWordEachSentences(ofstream& file);//separated by space
    void FindWordAppearMax(ofstream& file); // it can there are many word
    void SortAscendingSentence(); // ascending with alphabet
};
StatisticParagraph::StatisticParagraph() {
    this->LinkFile = "";
    this->NumberOfLine = 0;
}
StatisticParagraph::StatisticParagraph(string File) {
    this->NumberOfLine = 0;
    this->LinkFile = File;
    ifstream File_read(File);
    if (File_read.is_open()) {
        string line;
        while (getline(File_read, line)) {
            this->Paragraph.resize(NumberOfLine + 1);
            this->Paragraph[this->NumberOfLine] = line;
            this->NumberOfLine++;
        }
    }
    File_read.close();
}
StatisticParagraph::~StatisticParagraph() {
}
void StatisticParagraph::ReadFile() {
    for (int i = 0; i < this->NumberOfLine; i++) {
        cout << this->Paragraph[i] << endl;
    }
}
//end by .,!,?
int StatisticParagraph::CountSentences() {
    int CountSentence = 0;

    for (int i = 0; i < this->NumberOfLine; i++) {
        for (int j = 0; j < this->Paragraph[i].length(); j++) {
            if (this->Paragraph[i][j] == '.' || this->Paragraph[i][j] == '!' || this->Paragraph[i][j] == '?')
                CountSentence++;
        }
    }
    return CountSentence;
}
//separated by space
void StatisticParagraph::CountWordEachSentences(ofstream& file) {
    int sentences = 0;
    for (int i = 0; i < this->NumberOfLine; i++) {
        int CountWord = 0;
        for (int j = 0; j < this->Paragraph[i].length(); j++) {
            if (this->Paragraph[i][j] == ' ')
                CountWord++;
            else if (this->Paragraph[i][j] == '.' || this->Paragraph[i][j] == '!' || this->Paragraph[i][j] == '?') {
                CountWord++;
                sentences++;
                file << "\t-Sentences " << sentences << " has " << CountWord << " words." << endl;
                CountWord = 0;
                j++;
            }
        }
    }
}
int StatisticParagraph::CountWordInParagraph(string word) {
    int count = 0;
    for (int i = 0; i < this->NumberOfLine; i++) {
        string TempStr = this->Paragraph[i];
        while (TempStr.find(word) != string::npos) {
            if (TempStr[TempStr.find(word) + word.length()] == ' ' || TempStr[TempStr.find(word) + word.length()] == '.' || TempStr[TempStr.find(word) + word.length()] == '?' || TempStr[TempStr.find(word) + word.length()] == '!' || TempStr[TempStr.find(word) + word.length()] == ',') {
                count++;
                if (TempStr.find(word) != 0 && TempStr[TempStr.find(word) - 1] != ' ') {
                    count--;
                }
            }
            TempStr.replace(TempStr.find(word), word.length(), "");
        }
    }
    return count;
}
// it can there are many word
void StatisticParagraph::FindWordAppearMax(ofstream& file) {
    map<string, int> WordAppearMax;
    for (int i = 0; i < this->NumberOfLine; i++) {
        string TempString = this->Paragraph[i];
        for (int j = 0; j < TempString.length(); j++) {
            string Word = "";
            while (j <= TempString.length() - 1 && TempString[j] != ' ') {
                Word += TempString[j];
                j++;
            }
            if (Word[Word.length() - 1] == '.' || Word[Word.length() - 1] == '!' || Word[Word.length() - 1] == '?' || Word[Word.length() - 1] == ',') {
                Word.pop_back();
            }
            string Word2 = Word;
            if (Word2[0] >= 'a' && Word2[0] <= 'z') {

                Word2[0] = (char)(Word2[0] - 32);
            }
            WordAppearMax.insert(pair<string, int>(Word, CountWordInParagraph(Word) + CountWordInParagraph(Word2)));
        }
    }
    int max = 0;
    for (auto it = WordAppearMax.cbegin(); it != WordAppearMax.cend(); it++) {
        if (it->second > max) {
            max = it->second;
        }
    }
    for (auto it = WordAppearMax.cbegin(); it != WordAppearMax.cend(); it++) {
        if (it->second == max) {
            file << "-Word " << "\"" << it->first << "\"" << " appear max with " << it->second << " time." << endl;
        }
    }
}
// ascending with alphabet
void StatisticParagraph::SortAscendingSentence() {
    vector<string> SortParagraph;
    SortParagraph.resize(this->NumberOfLine);
    for (int i = 0; i < this->NumberOfLine; i++) {
        SortParagraph.push_back("");
    }
    for (int i = 0; i < this->NumberOfLine; i++) {
        string TempString = this->Paragraph[i];
        vector<string> Sentences;
        for (int j = 0; j < TempString.length(); j++) {
            string Word = "";
            while (j <= TempString.length() - 1 && TempString[j] != ' ') {
                Word += TempString[j];
                j++;
            }
            Sentences.push_back(Word + ' ');
            if (Word[Word.length() - 1] == '.' || Word[Word.length() - 1] == '!' || Word[Word.length() - 1] == '?') {
                Sentences.shrink_to_fit();
                do {
                    if (Sentences[0][0] >= 'A' && Sentences[0][0] <= 'Z') {
                        Sentences[0][0] = (char)(Sentences[0][0] + 32);
                    }
                    sort(Sentences.begin(), Sentences.end());
                } while (Sentences[0][0] >= 'A' && Sentences[0][0] <= 'Z');
                for (auto it = Sentences.begin(); it != Sentences.end(); it++) {
                    SortParagraph[i] += *it;
                }
                Sentences.erase(Sentences.begin(), Sentences.end());
                Sentences.resize(0);
            }

        }
    }
    ofstream file("res.txt");

    if (file.is_open()) {
        file << "-Numbers of sentences: " << this->CountSentences() << endl;
        CountWordEachSentences(file);
        FindWordAppearMax(file);
    }
    file << "-Sort ascending with alphabet: " << endl;
    for (int i = 0; i < SortParagraph.size(); i++) {
        file << SortParagraph[i] << endl;
    }
}
int main() {
    StatisticParagraph Paragraph("text.txt");
    Paragraph.ReadFile();
    Paragraph.SortAscendingSentence();
    return 0;
}
