#include <iostream>
#include <functional>
#include <stack>
#include <queue>
#include <deque>
using namespace std;

int main() {
   /*
   Stack~~~~~~
   */
   stack<int> s;  // Stack 생성

   s.push(1);
   s.push(2);
   s.push(3);  // 원소 삽입  1-2-3

   cout << "Top Element: " << s.top() << endl;  // 최상단 원소 Pass by Reference로 반환
   cout << "Is Empty: " << (s.empty() ? "Yes" : "No") << endl;  // 빈 스택인지
   cout << "Size: " << s.size() << endl;  // 사이즈

   s.pop();
   s.pop();
   s.pop();

   cout << "Is Empty: " << (s.empty() ? "Yes" : "No") << endl;

   /*
   Queue~~~~~~
   */
   queue<int> q;  // Queue 생성

   q.push(1);
   q.push(2);
   q.push(3);
   q.push(4);  // 원소 삽입

   q.pop();  // 원소 삭제

   cout << "Front Element: " << q.front() << endl;  // 맨 앞 원소 반환
   cout << "Back Element: " << q.back() << endl;  // 맨 뒤 원소 반환
   cout << "Queue Size: " << q.size() << endl;  // 큐 사이즈 반환
   cout << "Is it empty?: " << (q.empty() ? "Yes" : "No") << endl;  // 빈 큐인지

   q.pop();
   q.pop();
   q.pop();

   cout << "Is it empty?: " << (q.empty() ? "Yes" : "No") << endl;

   /*
   Deque~~~~
   */
   deque<int> d;
   // deque<int> d(10); : 0으로 초기화 된 원소 10개
   // deque<int> d(10, 3); : 3으로 초기화 된 원소 10개
   // deque<int> d2(d) : d 복사

   d.push_back(4);  // 뒤로 원소 삽입
   d.push_back(5);
   d.push_back(6);

   d.push_front(3);  // 앞으로 원소 삽입
   d.push_front(2);
   d.push_front(1);

   cout << "Front, Back: " << d.front() << ", " << d.back() << endl;  // 앞뒤 원소 확인
   cout << "d[3]: " << d[3] << endl;  // 원소 참조, 좀 느림

   d.pop_back();  // 맨 뒤 원소 제거
   d.pop_front();  // 맨 앞 원소 제거

   cout << "Front, Back: " << d.front() << ", " << d.back() << endl;  // 앞뒤 원소 확인
   cout << "Size: " << d.size() << endl;  // 사이즈 확인
   cout << "It Is Empty?: " << (d.empty() ? "Yes" : "No") << endl;  // 빈 원소 인지 확인

   d.pop_back();
   d.pop_front();
   d.pop_back();
   d.pop_front();

   cout << "It Is Empty?: " << (d.empty() ? "Yes" : "No") << endl;

   /*
   Heap(Priority Queue)~~~
   */
   
   priority_queue<int, vector<int>, less<int> > pq;  // Priority Queue 선언, Container와 Compare(비교함수 클래스)가 필요
   
   pq.push(5);
   pq.push(1);
   pq.push(4);
   pq.push(2);
   pq.push(3);

   cout << "Top: " << pq.top() << endl;  // 맨 위 원소 반환
   cout << "It is Empty?: " << (pq.empty() ? "Yes" : "No") << endl;  // 빈 큐인지
   cout << "Size: " << pq.size() << endl;  // 사이즈
   
   while (!pq.empty()) {
      cout << pq.top() << " " << endl;  // 원소 제거
      pq.pop();
   }


   return 0;
}