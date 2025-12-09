#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n, numSymbols;

    cout << "Enter number of NFA states: ";
    cin >> n;

    cout << "Enter number of input symbols: ";
    cin >> numSymbols;

    vector<char> symbols(numSymbols);
    cout << "Enter the symbols (e.g., a b): ";
    for (int i = 0; i < numSymbols; i++) {
        cin >> symbols[i];
    }

    map<int,map<char, set<int>>> nfa;

    cout << "\nEnter NFA transitions (state symbol nextState), enter -1 to stop:\n";
    cout << "Example: 0 a 1\n";

    while (true) {
        int state;
        cin >> state;
        if (state == -1) break;

        char symbol;
        int nextState;
        cin >> symbol >> nextState;
        nfa[state][symbol].insert(nextState);
    }

    int startState;
    cout << "\nEnter start state: ";
    cin >> startState;

    int numFinal;
    cout << "Enter number of final states: ";
    cin >> numFinal;

    set<int> nfaFinalStates;
    cout << "Enter final states: ";
    for (int i = 0; i < numFinal; i++) {
        int f;
        cin >> f;
        nfaFinalStates.insert(f);
    }

    set<set<int>> visited;
    queue<set<int>> q;

    set<int> startSet = { startState };
    q.push(startSet);
    visited.insert(startSet);

    cout << "\n--- SUBSET CONSTRUCTION TABLE ---\n";
    cout << "DFA State\t\t";
    for (char sym : symbols) {
        cout << "δ(" << sym << ")\t\t";
    }
    cout << endl;

    while (!q.empty()) {
        set<int> current = q.front();
        q.pop();

        cout << "{";
        for (auto s : current) cout << s << " ";
        cout << "}\t\t";                                                                                                                                                                             

        for (char sym : symbols) {
            set<int> next;

            for (int state : current) {
                if (nfa[state].count(sym)) {
                    for (int ns : nfa[state][sym]) {
                        next.insert(ns);
                    }
                }
            }

            if (!next.empty()) {
                cout << "{";
                for (auto s : next) cout << s << " ";
                cout << "}\t\t";

                if (visited.find(next) == visited.end()) {
                    visited.insert(next);
                    q.push(next);
                }
            }
            else {
                cout << "∅\t\t";
            }
        }
        cout << endl;
    }

    cout << "\n--- DFA FINAL STATES ---\n";
    for (auto& dfaState : visited) {
        bool isFinal = false;

        for (int s : dfaState) {
            if (nfaFinalStates.count(s)) {
                isFinal = true;
                break;
            }
        }

        if (isFinal) {
            cout << "{";
            for (auto s : dfaState) cout << s << " ";
            cout << "} is FINAL\n";
        }
    }

    return 0;
}