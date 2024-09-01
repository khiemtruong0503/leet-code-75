#include <iostream>

using namespace std;

// Time left 0:44:50
// Question 1
// Not complete
// Flag question
// Question text
// Cho node root của một danh sách liên kết đơn, hiện thực hàm sau đây:
class Node
{
    int data;
    Node* next;
public:
    Node(): data(0), next(nullptr){}

    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }

    int getData()
    {
        return this->data;
    }

    void setData(int data)
    {
        this->data = data;
    }

    Node* getNext()
    {
        return this->next;
    }

    void setNext(Node* next)
    {
        this->next = next;
    }
};

void reduceDuplicate(Node* head) { 
    if(head == NULL || head->getNext() == NULL){
            return;
        }

        int temp = head->getData();
        Node* tempHead = head->getNext();
        Node* prev = head;
        while(tempHead != NULL){
            if(tempHead->getData() != temp){
                temp = tempHead->getData();
                prev = tempHead;
                tempHead = tempHead->getNext();
            }
            else{
                prev->setNext(tempHead->getNext());
                tempHead = prev->getNext();
            }
        }
}
// để giảm các phần tử trùng lặp liên tiếp trong danh sách. Nếu có các phần tử liên tiếp giống nhau, ta chỉ giữ lại 1 phần tử.
// Ví dụ, ta có 1 danh sách 122234452, sau khi thực hiện hàm reduceDuplicate ta thu được danh sách 123452. (số 2 cuối cùng giữ nguyên do nó không liên tiếp với dãy 222 phía trước)

// Lưu ý: Các bạn có thể include thêm thư viện nếu cần thiết

// Cấu trúc của một node được cho bên dưới. Các bạn chỉ cần viết nội dung hàm reduceDuplicate, các cấu trúc khác đã được import sẵn.



int main() { 
    Node *a = new Node(1, nullptr);
    Node *b = new Node(3, nullptr);
    Node *c = new Node(3, nullptr);
    Node *d = new Node(3, nullptr);
    Node *e = new Node(3, nullptr);
    Node *f = new Node(4, nullptr);
    Node *g = new Node(4, nullptr);
    Node *h = new Node(2, nullptr);
    Node *i = new Node(2, nullptr);

    a->setNext(b);
    b->setNext(c);
    c->setNext(d);
    d->setNext(e);
    e->setNext(f);
    f->setNext(g);
    g->setNext(h);
    h->setNext(i);

    reduceDuplicate(a);

    Node *walker = a;
    while(walker) { 
        cout << walker->getData() << " ";
        walker = walker->getNext();
    }

    return 0;
}