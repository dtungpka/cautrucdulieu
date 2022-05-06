// Slide 28
#define MAX 100 // Khai báo ngăn chứa tối đa 100 phần tử
typedef struct  // Khai báo kiểu dữ liệu stack
{
    int top;      // Khai báo vị trí đầu stack
    int nut[MAX]; // Khai báo mảng chứa các phần tử trong stack
} stack;

// Slide 29
void StackInitialize(stack *s) // Khai báo hàm khởi tạo stack, truyền vào stack s
{
    s->top = -1; // Khởi tạo vị trí đầu stack
    return;
}
// Slide 30
int StackEmpty(stack s) // Khai báo hàm kiểm tra stack rỗng, truyền vào stack s
{
    return (s.top == -1); // Nếu vị trí đầu stack = -1 thì stack rỗng, trả về 1, ngược lại trả về 0
}
// Slide 31
int StackFull(stack s) // Khai báo hàm kiểm tra stack đầy, truyền vào stack s
{
    return (s.top == MAX - 1); // Nếu vị trí đầu stack = MAX - 1 thì stack đầy, trả về 1, ngược lại trả về 0
}
// Slide 32
void Push(stack *s, int x) // Khai báo hàm thêm phần tử vào stack, truyền vào stack s và phần tử x
{
    if (StackFull(*s)) // Nếu stack đầy
    {
        printf("Ngan xep day !\n"); // In ra thông báo
        return;                     // Trả về
    }
    else // Nếu stack chưa đầy
    {
        s->top++;           // Tăng vị trí đầu stack lên 1
        s->nut[s->top] = x; // Gán giá trị x vào vị trí đầu stack
        return;
    }
}
// Slide 33
int Pop(stack *s) // Khai báo hàm xóa phần tử khỏi stack, truyền vào stack s
{
    if (StackEmpty(*s)) // Nếu stack rỗng
    {
        printf("Ngan xep rong !");
    }
    else // Nếu stack không rỗng
    {
        int value = s->nut[s->top]; // Lấy giá trị phần tử đầu stack
        s->top = s->top--;          // Giảm vị trí đầu stack xuống 1
        return value;               // Trả về giá trị phần tử đầu stack
    }
}

// Slide 37
struct node
{
    int item;                   // Khai báo item chứa dữ liệu trong node
    struct node *next;          // Khai báo pointer tới node tiếp theo
};                              // Khởi tạo cấu trúc node
typedef struct node *stacknode; // Khai báo kiểu dữ liệu stacknode là pointer của node
typedef struct
{
    stacknode top; // Khai báo top là pointer đến node đầu stack
} stack;           // Khai báo kiểu dữ liệu stack là cấu trúc stacknode
// Slide 38
void StackInitialize(stack *s) // Khai báo hàm khởi tạo stack, truyền vào stack s
{
    s->top = NULL; // Khởi tạo vị trí đầu stack
    return;
}
// SLide 39
int StackEmpty(stack s) { return (s.top == NULL); } // Khai báo hàm kiểm tra stack rỗng, truyền vào stack s, trả về 1 nếu rỗng, trả về 0 nếu không rỗng

// Slide 40
void Push(stack *s, int x) // Khai báo hàm thêm phần tử vào stack, truyền vào stack s và phần tử x
{
    stacknode p;// Khai báo stacknode p
    p = (stacknode)malloc(sizeof(struct node)); // Cấp phát bộ nhớ cho p
    p->item = x; // Gán giá trị x vào item của p
    p->next = s->top;// Gán node đầu stack vào next của p
    s->top = p;// Gán p vào đầu của stack
    return;
}

// Slide 43
int Pop(stack *s)// Khai báo hàm xóa phần tử khỏi stack, truyền vào stack s
{
    stacknode p;// Khai báo stacknode p
    if (StackEmpty(*s))// Nếu stack rỗng
    {
        printf("Ngan xep rong !");// In ra thông báo
    }
    else
    {
        p = s->top;// Lấy node đầu stack
        s->top = s->top->next;// Gán node thứ 2 sau node đầu stack vào đầu stack
        return p->item;// Trả về giá trị của node đầu stack
    }
}