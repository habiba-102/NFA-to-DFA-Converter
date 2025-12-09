# NFA to DFA Converter

A C++ program that converts Nondeterministic Finite Automata (NFA) to Deterministic Finite Automata (DFA) using the Subset Construction Method.

## Overview

This program implements the Subset Construction Algorithm to convert an NFA into an equivalent DFA. The algorithm creates DFA states as subsets of NFA states and computes transitions by taking the union of all possible NFA transitions.

## Usage

The program prompts for:
1. Number of NFA states
2. Number of input symbols and the symbols themselves
3. Transitions in format: `state symbol nextState` (enter -1 to stop)
4. Start state
5. Final states

### Example Input

```
Enter number of NFA states: 4
Enter number of input symbols: 2
Enter the symbols (e.g., a b): a b

Enter NFA transitions (state symbol nextState), enter -1 to stop:
0 a 0
0 b 0
0 b 1
1 a 2
1 b 2
2 a 3
2 b 3
-1

Enter start state: 0
Enter number of final states: 1
Enter final states: 3
```

### Output

The program displays:
- Subset construction table showing all DFA states and transitions
- List of DFA final states

## Algorithm

1. Start with the NFA start state as a set: {q0}
2. For each DFA state (subset of NFA states):
   - For each input symbol, compute the union of all NFA transitions
   - Add new states to the queue if not yet visited
3. Mark DFA states as final if they contain any NFA final state

## Data Structures

- `vector<map<char, set<int>>> nfa` - NFA transition table
- `set<set<int>> visited` - Tracks processed DFA states
- `queue<set<int>> q` - BFS queue for state exploration
