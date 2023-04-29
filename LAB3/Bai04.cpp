#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class List
{
private:
    Node *head;

public:
    List();                                           // 1. constructor
    void addFirst(int data);                          // 2. Thêm dữ liệu vào đầu danh sách
    void addLast(int data);                           // 3. Thêm dữ liệu vào cuối danh sách.
    void display();                                   // 4. Xuất danh sách hiện tại.
    int length();                                     // 5. Tính độ dài danh sách.
    bool contains(int value);                         // 6. Tìm giá trị có trong danh sách hay không.
    void insertAfter(int x, int y);                   // 7. Chèn một giá trị x sau giá trị y trong danh sách.
    void countEvenOdd(int &evenCount, int &oddCount); // 8. Đếm số lượng giá trị chẵn, lẻ trong danh sách (viết 1 phương thức).
    void remove(int value);                           // 9. Xóa một phần tử.
};

// 1. constructor
List ::List()
{
    head = NULL;
}

// 2. Thêm dữ liệu vào đầu danh sách
void List ::addFirst(int data)
{
    Node *node = new Node;
    node->data = data;
    node->next = head;
    head = node;
}

// 3. Thêm dữ liệu vào cuối danh sách.
void List ::addLast(int data)
{
    Node *node = new Node;
    node->data = data;
    node->next = NULL;
    if (head == NULL)
    {
        head = node;
    }
    else
    {
        Node *current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = node;
    }
}

// 4. Xuất danh sách hiện tại.
void List ::display()
{
    if (head == NULL)
    {
        cout << "Danh sach trong" << endl;
    }
    else
    {
        Node *current = head;
        while (current != NULL)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
}

/* 5. Tính độ dài danh sách.
Input: 
    + thuoc tinh head
Output:
    + return len => do dai cua danh sach
*/
int List ::length()
{
    int len = 0;
    Node *current = head;
    while (current != NULL)
    {
        len++;
        current = current->next;
    }
    return len;
}

/* 6. Tìm giá trị có trong danh sách hay không.
Input:
    + Gia tri can tim
Output:
    + true (co), false (khong co)
*/
bool List ::contains(int value)
{
    Node *current = head;
    while (current != NULL)
    {
        if (current->data == value)
        {
            return true;
        }
        current = current->next;
    }
    return false;
}

//7. Chèn một giá trị x sau giá trị y trong danh sách.
void List ::insertAfter(int x, int y)
{
    Node *current = head;
    while (current != NULL)
    {
        if (current->data == y)
        {
            Node *node = new Node;
            node->data = x;
            node->next = current->next;
            current->next = node;
            return;
        }
        current = current->next;
    }
    cout << y << " khong tim thay trong danh sach" << endl;
}

// 8. Đếm số lượng giá trị chẵn, lẻ trong danh sách (viết 1 phương thức).
void List ::countEvenOdd(int &evenCount, int &oddCount)
{
    evenCount = 0;
    oddCount = 0;
    Node *current = head;
    while (current != NULL)
    {
        if (current->data % 2 == 0)
        {
            evenCount++;
        }
        else
        {
            oddCount++;
        }
        current = current->next;
    }
}

// 9. Xóa một phần tử.
void List ::remove(int value)
{
    Node *prev = NULL;
    Node *current = head;
    while (current != NULL)
    {
        if (current->data == value)
        {
            if (prev == NULL)
            {
                head = current->next;
            }
            else
            {
                prev->next = current->next;
            }
            delete current;
            return;
        }

        prev = current;
        current = current->next;
    }
    cout << value << " khong tim thay trong danh sach" << endl;
}

int main()
{
    List list;
    int choice, data, x, y, evenCount, oddCount;
    do
    {
        cout << "1. Tao danh sach" << endl;
        cout << "2. Them du lieu vao dau danh sach" << endl;
        cout << "3. Them du lieu vao cuoi danh sach" << endl;
        cout << "4. xuat danh sach hien tai" << endl;
        cout << "5. Tinh do dai danh sach" << endl;
        cout << "6. Tim gia tri co trong danh sach hay khong" << endl;
        cout << "7. Chen mot gia tri x sau gia tri y trong danh sach" << endl;
        cout << "8. Dem so luong chan, le trong danh sach" << endl;
        cout << "9. Xoa mot phan tu" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Nhap du lieu: (-1 de ket thuc)";
            cin >> data;
            while (data != -1)
            {
                list.addLast(data);
                cin >> data;
            }
            break;

        case 2:
            cout << "Nhap du lieu: ";
            cin >> data;
            list.addFirst(data);
            break;

        case 3:
            cout << "Nhap du lieu: ";
            cin >> data;
            list.addLast(data);
            break;

        case 4:
            list.display();
            break;

        case 5:
            cout << "Do dai cua danh sach la " << list.length() << endl;
            break;

        case 6:
            cout << "Nhap so can tim: ";
            cin >> data;
            if (list.contains(data))
            {
                cout << "Gia tri " << data << " co trong danh sach" << endl;
            }
            else
            {
                cout << "Gia tri " << data << " khong co trong danh sach" << endl;
            }
            break;

        case 7:
            cout << "Nhap gia tri x can chen: ";
            cin >> x;
            cout << "Nhap gia tri y : ";
            cin >> y;
            list.insertAfter(x, y);
            break;

        case 8:
            list.countEvenOdd(evenCount, oddCount);
            cout << "So luong gia tri chan: " << evenCount << endl;
            cout << "So luong gia tri le: " << oddCount << endl;
            break;

        case 9:
            cout << "Nhap gia tri can xoa: ";
            cin >> data;
            list.remove(data);
            break;

        case 0:
            break;

        default:
            cout << "Lua chon khong hop le" << endl;
        }
    } while (choice != 0);

    return 0;
}
