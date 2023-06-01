#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main() {
    vector<int> ropes = { 3, 5, 2, 7, 1, 4, 6 };
    priority_queue<int, vector<int>, greater<int>> heap(ropes.begin(), ropes.end());
    int total_cost = 0;
    // Порядок для наименьших затрат
    while (heap.size() > 1) {
        // Извлекаем два наименьших каната
        int rope1 = heap.top();
        heap.pop();
        int rope2 = heap.top();
        heap.pop();
        // Соединяем их вместе и добавляем длину нового каната в общие затраты
        int new_rope = rope1 + rope2;
        total_cost += new_rope;
        // Добавляем новый канат в кучу
        heap.push(new_rope);
    }
    setlocale(LC_ALL, "rus");
    cout << "Порядок связывания канатов: ";
    while (!heap.empty()) {
        cout << heap.top() << " ";
        heap.pop();
    }
    cout << endl;
    cout << "Суммарные затраты: " << total_cost << endl;
    return 0;
}