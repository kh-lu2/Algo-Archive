//Code by Katarzyna Ludwa

#include <iostream>
#include <stack>
 
using namespace std;
 
bool closed(const char& c) {
      return (c == '}' || c == ']' || c == ')');
};
 
int main() {
      int z;
      cin >> z;
      while (z--) {
              stack <char> S;
              bool d=0;
              char temp;
              cin >> temp;
 
              if (closed(temp))
                      d = 1;
              char c;
              c = temp;
              S.push(temp);
              while (1) {
                      cin.get(temp);
                      if (temp == '\n')
                              break;
 
                      S.push(temp);
                      if (closed(S.top())) {
                              if (c == S.top() - 1 || c == S.top() - 2) {
                                      S.pop();
                                      S.pop();
                              }
                              else
                                      d = 1;
                      }
                      if (!S.empty())
                              c = S.top();
                      else
                              c = ' ';
              }
 
              if (d)
                      cout << "NIE" << "\n";
              else if (S.empty())
                      cout << "TAK" << "\n";
              else {
                      while (!S.empty()) {
                              if (S.top() == '{')
                                      cout << '}';
                              else if (S.top() == '[')
                                      cout << ']';
                              else
                                      cout << ')';
                              S.pop();
                      }
                      cout << "\n";
              }
      }
}
