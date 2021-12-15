// coroutine-generator.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include <variant>
#include <memory>
#include <stack>
#include <experimental/coroutine>

using namespace std;
using namespace std::experimental;

template <typename T>
struct generator
{
    struct promise_type 
    { 
        std::variant<T const*, std::exception_ptr> value;
    
        promise_type& get_return_object()
        {
            return *this;
        }
        std::experimental::suspend_always initial_suspend()
        {
            return {};
        }
        std::experimental::suspend_always final_suspend() noexcept
        {
            return {};
        }
        std::experimental::suspend_always yield_value(T const& other)
        {
            value = std::addressof(other);
            return {};
        }

        void return_void() { }

        template <typename Expression>
        Expression&& await_transform(Expression&& expression)
        {
            static_assert(sizeof(expression) == 0,
                "co_await is not supported in coroutines of type generator");
            return std::forward<Expression>(expression);
        }

        void unhandled_exception()
        {
            value = std::current_exception();
        }

        void rethrow_if_failed()
        {
            if (value.index() == 1)
                std::rethrow_exception(std::get<1>(value));
        }
    };

    using handle_type = std::experimental::coroutine_handle<promise_type>;

    handle_type handle{ nullptr };

    struct iterator {

        using iterator_category = std::input_iterator_tag;
        using value_type = T;
        using difference_type = ptrdiff_t;
        using pointer = T const*;
        using reference = T const&;

        handle_type handle;

        iterator(handle_type handle) : handle{handle} {}
        iterator(nullptr_t) : handle{ nullptr } {}

        iterator& operator++()
        {
            handle.resume();

            if (handle.done())
            {
                promise_type& promise = handle.promise();
                handle = nullptr;
                promise.rethrow_if_failed();
            }

            return *this;
        }

        bool operator!=(iterator that) const { return handle != that.handle; /* **this != *that; */ }

        iterator operator++(int) = delete;
 
        T const& operator*() const
        {
            return *std::get<0>(handle.promise().value);
        }
    };

    generator() = default;
    generator(generator const&) = delete;
    generator& operator=(generator const&) = delete;

    generator(generator&& other) : handle(other.handle)
    {
        other.handle = nullptr;
    }

    generator(promise_type& promise) :
        handle(handle_type::from_promise(promise))
    {}

    ~generator()
    {
        if (handle)
            handle.destroy();
    }

    generator& operator=(generator&& other)
    {
        if (this != &other) {
            handle = other.handle;
            other.handle = nullptr;
        }

        return *this;
    }

    iterator begin()
    {
        if (handle == nullptr)
            return nullptr;
        handle.resume();

        if (handle.done()) {
            handle.promise().rethrow_if_failed();
            return nullptr;
        }
        return handle;
    }

    iterator end()
    {
        return nullptr;
    }
};

#if 0
template <typename T>
generator<int> crange(T first, T last)
{
    while (first != last) {
        // cout << "crange: first = " << first << endl;
        co_yield first++;
    }
}
#endif

generator<int> crange(int first, int last)
{
    while (first != last)
        co_yield first++;
}

struct tree_entry
{
    tree_entry(int v) : left{}, right{}, value{v} {}

    unique_ptr<tree_entry> left, right;
    int                    value;
};

struct tree
{
    void insert(int v, tree_entry* node)
    {
        if (v < node->value) {
            if (node->left)
                insert(v, node->left.get());
            else
                node->left= make_unique<tree_entry>(v);
        }
        else {
            if (node->right)
                insert(v, node->right.get());
            else
                node->right = make_unique<tree_entry>(v);
        }
    }

    void insert(int v) 
    {  
        if (not head)
            head = make_unique<tree_entry>( v );
        else
            insert(v, head.get());
    }

    unique_ptr<tree_entry> head;
};

void fill_tree(tree& t)
{
    t.insert(5);
    t.insert(3);
    t.insert(1);
    t.insert(4);
    t.insert(7);
    t.insert(6);
    t.insert(9);
}

struct preorder_t {} const preorder;
struct inorder_t {} const inorder;
struct postorder_t {} const postorder;


//https://www.geeksforgeeks.org/iterative-postorder-traversal/
//1. Push root to first stack.
//2. Loop while first stack is not empty
//2.1 Pop a node from first stack and push it to second stack
//2.2 Push left and right children of the popped node to first stack
//3. Print contents of second stack

generator<int> traverse(const tree& t, postorder_t) 
{
    stack<tree_entry*> s, p;
    tree_entry *current = t.head.get();

    if (current != nullptr)
        s.push(current);
    while (not s.empty()) {
        current = s.top(); s.pop();
        tree_entry* tmp = current->left.get();
        if (tmp != nullptr)
            s.push(tmp);
        tmp = current->right.get();
        if (tmp != nullptr)
            s.push(tmp);
        p.push(current);
    }
    while (not p.empty()) {
        co_yield p.top()->value;
        p.pop();
    }
}

template <typename Order>
generator<int> traverse(const tree& t, Order)
{
    stack<tree_entry*> s;
    tree_entry* current = t.head.get();

    while (current != nullptr || not s.empty()) {
        while (current != nullptr) {
            if constexpr (is_same_v<Order, preorder_t>)
                co_yield current->value;
            s.push(current);
            current = current->left.get();
        }
        current = s.top(); s.pop();
        if constexpr (is_same_v<Order, inorder_t>)
            co_yield current->value;
        current = current->right.get();
    }
}

int main()
{
for (auto i : crange(3, 11)) 
    cout << i << endl;
cout << endl;

tree t;
fill_tree(t);

for (auto i : traverse(t, inorder))
    cout << i << endl;
cout << endl;

for (auto i : traverse(t, preorder))
    cout << i << endl;
cout << endl;

for (auto i : traverse(t, postorder))
    cout << i << endl;
cout << endl;
}

