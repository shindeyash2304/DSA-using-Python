class AutoCompleteSystem:
    def __init__(self, sentences, times):
        # Initialize the data structures
        self.history = {}
        for sentence, time in zip(sentences, times):
            self.history[sentence] = self.history.get(sentence, 0) + time
        self.current_query = ""
    
    def input(self, c):
        if c == '#':
            # End of query, save it in the history and reset current query
            if self.current_query:
                self.history[self.current_query] = self.history.get(self.current_query, 0) + 1
            self.current_query = ""
            return []
        else:
            # Add the character to the current query
            self.current_query += c
            # Find the top 3 suggestions
            suggestions = []
            for sentence in self.history:
                if sentence.startswith(self.current_query):
                    suggestions.append((self.history[sentence], sentence))
            # Sort by frequency, then by ASCII order
            suggestions.sort(key=lambda x: (-x[0], x[1]))
            # Return top 3 suggestions
            return [sentence for _, sentence in suggestions[:3]]
 # Driver Code Starts
if __name__ == "__main__":
    t = int(input())
    while t > 0:
        n = int(input())
        sentences = []
        times = []
        for _ in range(n):
            sentence = input()
            sentences.append(sentence)
            time = int(input())
            times.append(time)

        obj = AutoCompleteSystem(sentences, times)

        q = int(input())
        for _ in range(q):
            query = input()
            qq = ""
            for x in query:
                qq += x
                suggestions = obj.input(x)
                if x == '#':
                    continue
                print('Typed : "' + qq + '" , Suggestions:')
                for y in suggestions:
                    print(y)

        t -= 1

# } Driver Code Ends