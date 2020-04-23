#include<iostream>
using namespace std;

char MatchingBracket(char b){
    switch (b){
        case ')': return '(';
        case ']': return '[';
        case '}': return '{';
        default: return b;
    }
}

int main(){
    
    int i = 0;
    char x = '0';
    char A[25] = {0};

    cin >> x;
    bool tooManyClosed = false;
    bool crossingBrackets = false;

    while(x != '0' && !tooManyClosed && !crossingBrackets){
        switch (x){
            case '(':
            case '[':
            case '{':
                A[i] = x;
                i++;
                break;
            default:
                if(i == 0) tooManyClosed = true;
                else if (A[i-1] == MatchingBracket(x)) A[--i] = 0;
                else crossingBrackets = true;
        }
        cin >> x;
    }

    if(tooManyClosed) cout << "Troppe parentesi chiuse\n";
    else if(crossingBrackets) cout << "Parentesi accavallate\n";
    else if(i>0) cout << "Troppe parentesi aperte\n";
    else cout << "Sequenza bilanciata";

}