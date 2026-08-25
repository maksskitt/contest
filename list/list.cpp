#include <iostream>

template <typename T> class List {
    struct Node {
        Node *prev = nullptr;
        Node *next = nullptr;
        T val{};
        Node(const T &value) : val(value) {}
        Node() = default;
    };

    Node head;

  public:
    List() = default;
    ~List() {
        Node *cur = head.next;
        while (cur != nullptr) {
            Node *next = cur->next;
            delete cur;
            cur = next;
        }
    }
    void add_after(T v, int idx) {
        Node *h = &head;
        while (idx > 0 && h->next != nullptr) {
            h = h->next;
            idx--;
        }

        Node *n = new Node(v);
        n->next = h->next;
        n->prev = h;
        if (h->next != nullptr)
            h->next->prev = n;
        h->next = n;
    }
    void del(int idx) {
        Node *h = &head;
        while (idx > 0 && h->next != nullptr) {
            h = h->next;
            idx--;
        }

        if (h == &head)
            return;

        h->prev->next = h->next;
        if (h->next != nullptr)
            h->next->prev = h->prev;

        delete h;
    }
    T get(int idx) {
        Node *h = &head;
        while (idx > 0 && h->next != nullptr) {
            h = h->next;
            idx--;
        }

        return h->val;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    List<int> l;
    int q, t, x, y;

    std::cin >> q;

    while (q--) {
        std::cin >> t >> x;
        if (t == 1) {
            std::cin >> y;
            l.add_after(y, x);
        } else if (t == 2) {
            std::cout << l.get(x) << "\n";
        } else if (t == 3) {
            l.del(x);
        }
    }

    return 0;
}