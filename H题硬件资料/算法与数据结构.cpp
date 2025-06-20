#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string name;
    int position;
    Node* next;
};

Node* createList(int n) // 构建单循环链表
{
    if (n % 2 != 0 || n <= 0|| n != static_cast<int>(n))
    {
        cout << "请输入正偶数作为乘客数" << endl;
        return NULL;
    }
    else
    {
        Node* head = new Node;
        cout << "请输入第1个乘客姓名: ";
        cin >> head->name;
        head->position = 1;
        Node* current = head;
        for (int i = 2; i <= n; i++)
        {
            current->next = new Node;
            current = current->next;
            cout << "请输入第" << i << "个乘客姓名: ";
            cin >> current->name;
            current->position = i;
        }
        current->next = head;
        return head;
    }
}

void PlayGame(Node* head, int& n)//游戏实现函数
{
    int i = n / 2;
    int j = 0;
    Node* current = head;
    Node* previous = head; // 跟踪前一个节点
    while (n > i)
    {
        // 数到第9个节点
        for (int i = 1; i < 9; i++)
        {
            previous = current;
            current = current->next;
        }
        cout << "把名字为：" << current->name << " 在位置：" << current->position << " 的乘客投入大海中" << endl;

        // 删除节点
        Node* temp = current;
        if (current == head) 
        {
            head = current->next; // 更新头节点
        }
        previous->next = current->next; // 更新链表连接
        current = current->next; // 移动到下一个节点
        delete temp;
        n--;
        j++;
    }
    cout << "共投入大海:"<<j<<"位乘客" << endl;
    // 输出剩余的乘客
    cout << "剩余的乘客(共：" << 2*i - j << "位):" << endl;
    current = head;
    for (int i = 0; i < n; i++)
    {
        cout << "名字为：" << current->name << " 在位置：" << current->position << endl;
        current = current->next;
    }
}

int main()
{
    int n;
    cout << "请输入乘客总人数n(n为正偶数): ";
    cin >> n;
    Node* head = createList(n);
    PlayGame(head, n);
    return 0;
}
