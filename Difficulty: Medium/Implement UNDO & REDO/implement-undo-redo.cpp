class Solution {
    string word = "";
    stack<char>recent;
  public:
    void append(char x) {
        // append x into document
        word+=x;
    }

    void undo() {
        // undo last change
        recent.push(word[word.length()-1]);
        word.erase(word.end()-1);
    }

    void redo() {
        // redo changes
        char ch = recent.top();
        recent.pop();
        word+=ch;
    }

    string read() {
        // read the document
        return word;
    }
};