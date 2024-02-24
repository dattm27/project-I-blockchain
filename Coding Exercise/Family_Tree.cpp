#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, string> familyTree;

int countDescendants(string name) {
    int descendants = 0;
    for (const auto& pair : familyTree) {
        if (pair.second == name) {
            descendants++;
            descendants += countDescendants(pair.first);
        }
    }
    return descendants;
}

int countGenerations(string name) {
    int generations = 0;
    for (const auto& pair : familyTree) {
        if (pair.second == name) {
            generations = max(generations, 1 + countGenerations(pair.first));
        }
    }
    return generations;
}

int main() {
    string child, parent;
    
    while (true) {
        cin >> child;
        if (child == "***") {
            break;
        }
        cin >> parent;
        familyTree[child] = parent;
    }
    
    while (true) {
        string query, name;
        cin >> query;
        if (query == "***") {
            break;
        }
        cin >> name;
        
        if (query == "descendants") {
            cout << countDescendants(name) << endl;
        } else if (query == "generation") {
            cout << countGenerations(name) << endl;
        }
    }
    
    return 0;
}
