#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <memory>
#include <map>

using namespace std;

struct State;

struct Transition {
    char symbol; // lehet 'ε' = 0
    shared_ptr<State> to;
};

struct State {
    vector<Transition> transitions;
    bool is_accept = false;
};

using StatePtr = shared_ptr<State>;

// ε-lezárás: összes állapot, amit elérhetünk ε-lépéssel
void epsilonClosure(StatePtr state, set<StatePtr>& result) {
    if (result.count(state)) return;
    result.insert(state);
    for (auto& t : state->transitions) {
        if (t.symbol == 0)
            epsilonClosure(t.to, result);
    }
}

// előrelépés egy szimbólummal
set<StatePtr> move(const set<StatePtr>& states, char symbol) {
    set<StatePtr> result;
    for (auto& s : states) {
        for (auto& t : s->transitions) {
            if (t.symbol == symbol || t.symbol == '.') {
                epsilonClosure(t.to, result);
            }
        }
    }
    return result;
}

// NFA-t reprezentáló kezdő- és elfogadó állapot
struct NFA {
    StatePtr start;
    StatePtr accept;
};

// Reguláris kifejezésből NFA létrehozása (csak *, |, ., karakterek)
class RegexParser {
public:
    RegexParser(const string& regex) : regex(regex), pos(0) {}

    NFA parse() {
        return parseExpr();
    }

private:
    string regex;
    size_t pos;

    char peek() {
        return pos < regex.size() ? regex[pos] : '\0';
    }

    char get() {
        return pos < regex.size() ? regex[pos++] : '\0';
    }

    NFA parseExpr() {
        NFA term = parseTerm();
        while (peek() == '|') {
            get(); // consume '|'
            NFA right = parseTerm();
            StatePtr start = make_shared<State>();
            StatePtr accept = make_shared<State>();
            start->transitions.push_back({0, term.start});
            start->transitions.push_back({0, right.start});
            term.accept->transitions.push_back({0, accept});
            right.accept->transitions.push_back({0, accept});
            term = {start, accept};
        }
        return term;
    }

    NFA parseTerm() {
        NFA result = parseFactor();
        while (peek() && peek() != ')' && peek() != '|') {
            NFA next = parseFactor();
            result.accept->transitions.push_back({0, next.start});
            result.accept = next.accept;
        }
        return result;
    }

    NFA parseFactor() {
        NFA base = parseBase();
        while (peek() == '*') {
            get(); // consume '*'
            StatePtr start = make_shared<State>();
            StatePtr accept = make_shared<State>();
            start->transitions.push_back({0, base.start});
            start->transitions.push_back({0, accept});
            base.accept->transitions.push_back({0, base.start});
            base.accept->transitions.push_back({0, accept});
            base = {start, accept};
        }
        return base;
    }

    NFA parseBase() {
        if (peek() == '(') {
            get(); // consume '('
            NFA sub = parseExpr();
            get(); // consume ')'
            return sub;
        } else {
            char c = get();
            StatePtr start = make_shared<State>();
            StatePtr accept = make_shared<State>();
            start->transitions.push_back({c, accept});
            return {start, accept};
        }
    }
};

// Végrehajtja az illesztést az NFA-val
bool matches(const NFA& nfa, const string& text) {
    set<StatePtr> current;
    epsilonClosure(nfa.start, current);
    for (char c : text) {
        current = move(current, c);
    }
    for (auto& s : current) {
        if (s->is_accept) return true;
    }
    return false;
}

int main() {
    string pattern = "a*b";
    string text = "aaab";

    RegexParser parser(pattern);
    NFA nfa = parser.parse();
    nfa.accept->is_accept = true;

    if (matches(nfa, text))
        cout << "Illeszkedik.\n";
    else
        cout << "Nem illeszkedik.\n";

    return 0;
}