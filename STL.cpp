#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm> // Required for sorting, reversing, binary search, bounds
#include <utility>   // Required for std::pair
#include <string>

using namespace std;

// =========================================================================
// PART 11: CUSTOM COMPARATOR TEMPLATE
// =========================================================================
// Sorts pairs based on their SECOND element in ascending order.
// If there is a tie, it breaks the tie by sorting the FIRST element in ascending order.
bool customComparator(const pair<int, int>& p1, const pair<int, int>& p2) {
    if (p1.second < p2.second) return true;   // Correct order
    if (p1.second > p2.second) return false;  // Incorrect order, needs swap
    
    // Tie-breaker zone (p1.second == p2.second)
    return p1.first < p2.first; 
}

int main() {
    // Fast I/O Optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << "=== C++ STL MASTER SYSTEM RUNTIME ===\n\n";

    // =========================================================================
    // PART 1 & 2: VECTORS, LISTS, AND DEQUES
    // =========================================================================
    cout << "--- 1. Sequential Containers ---\n";
    vector<int> vec = {10, 20, 30};
    vec.push_back(40); // Insert back
    
    list<int> my_list = {50, 60};
    my_list.push_front(40); // Constant time push front

    deque<int> dq = {2, 3, 4};
    dq.push_front(1);
    dq.push_back(5);

    cout << "Vector tail: " << vec.back() << " | List head: " << my_list.front() << "\n";
    cout << "Deque bounds: " << dq.front() << " to " << dq.back() << "\n\n";


    // =========================================================================
    // PART 3, 4, 5 & 6: STACK, QUEUE, AND PRIORITY QUEUE
    // =========================================================================
    cout << "--- 2. Adaptor Streams ---\n";
    
    // Stack (LIFO)
    stack<int> st;
    st.push(100); st.push(200);
    cout << "Stack Top (LIFO): " << st.top() << "\n"; // 200
    st.pop();

    // Queue (FIFO)
    queue<int> q;
    q.push(1); q.push(2);
    cout << "Queue Front (FIFO): " << q.front() << "\n"; // 1
    q.pop();

    // Priority Queue Max-Heap (Default)
    priority_queue<int> max_heap;
    max_heap.push(5); max_heap.push(25); max_heap.push(12);
    cout << "Max-Heap Top (Highest): " << max_heap.top() << "\n"; // 25

    // Priority Queue Min-Heap
    priority_queue<int, vector<int>, greater<int>> min_heap;
    min_heap.push(5); min_heap.push(25); min_heap.push(12);
    cout << "Min-Heap Top (Lowest): " << min_heap.top() << "\n\n"; // 5


    // =========================================================================
    // PART 7 & 8: ASSOCIATIVE CONTAINERS (MAP & MULTIMAP)
    // =========================================================================
    cout << "--- 3. Maps (Key-Value Structures) ---\n";
    map<string, int> ordered_map;
    ordered_map["Laptop"] = 1200;
    ordered_map["Phone"] = 800;
    ordered_map["Tablet"] = 400; // Keys are automatically kept sorted alphabetically!

    // Searching safely without creating empty items using .find()
    auto map_it = ordered_map.find("Phone");
    if (map_it != ordered_map.end()) {
        cout << "Safe Find -> Key: " << map_it->first << " | Value: " << map_it->second << "\n";
    }

    // Multimap (Allows Duplicates, No Brackets Allowed)
    multimap<string, int> m_map;
    m_map.insert({"Apple", 5});
    m_map.insert({"Apple", 10});
    cout << "Multimap 'Apple' entry occurrence count: " << m_map.count("Apple") << "\n\n";


    // =========================================================================
    // PART 9: ASSOCIATIVE CONTAINERS (SET VARIATIONS)
    // =========================================================================
    cout << "--- 4. Sets (Unique Keys Only) ---\n";
    set<int> unique_set;
    unique_set.insert(30);
    unique_set.insert(10);
    unique_set.insert(20);
    unique_set.insert(10); // Duplicate ignored automatically

    cout << "Ordered Unique Set Sequence: ";
    for (int val : unique_set) cout << val << " "; // Output: 10 20 30
    cout << "\n\n";


    // =========================================================================
    // PART 10 & 12: CORE ALGORITHMS (SORT, REVERSE, PERMUTATIONS)
    // =========================================================================
    cout << "--- 5. Global Range Algorithms ---\n";
    vector<int> target_vec = {40, 10, 50, 20, 30};

    // Sorting Ascending
    sort(target_vec.begin(), target_vec.end()); // [10, 20, 30, 40, 50]
    
    // Reversing In-Place
    reverse(target_vec.begin(), target_vec.end()); // [50, 40, 30, 20, 10]
    cout << "Reversed Vector Head: " << target_vec.front() << "\n";

    // Next Permutation
    vector<int> perm_vec = {1, 2, 3};
    next_permutation(perm_vec.begin(), perm_vec.end()); // Changes layout to [1, 3, 2]
    cout << "Next Permutation Generation: " << perm_vec[0] << " " << perm_vec[1] << " " << perm_vec[2] << "\n\n";


    // =========================================================================
    // PART 11 RUNTIME: CUSTOM COMPLEX COMPONENT SORTING
    // =========================================================================
    cout << "--- 6. Custom Comparator Array Sort ---\n";
    vector<pair<int, int>> pairs_vec = {{3, 1}, {2, 1}, {7, 1}, {5, 2}};
    
    sort(pairs_vec.begin(), pairs_vec.end(), customComparator);
    
    cout << "Sorted Pairs Array (Second Key Primary, First Key Tie-Breaker):\n";
    for (const auto& p : pairs_vec) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << "\n\n";


    // =========================================================================
    // PART 13: SEARCH ALGORITHMS & HARDWARE BIT UTILITIES
    // =========================================================================
    cout << "--- 7. Bounds, Binary Search & Hardware Bits ---\n";
    vector<int> sorted_data = {10, 20, 30, 30, 30, 40, 50};

    // Binary Search
    bool exists = binary_search(sorted_data.begin(), sorted_data.end(), 30);
    cout << "Does 30 exist? " << (exists ? "TRUE" : "FALSE") << "\n";

    // Iterators Upper and Lower Bound Processing
    auto lb_it = lower_bound(sorted_data.begin(), sorted_data.end(), 30);
    auto ub_it = upper_bound(sorted_data.begin(), sorted_data.end(), 30);
    
    // Pointer subtraction math converts raw iterator tracking addresses into integer indexes!
    cout << "Lower Bound index of 30 (>=30): " << (lb_it - sorted_data.begin()) << "\n"; // 2
    cout << "Upper Bound index of 30 (>30):  " << (ub_it - sorted_data.begin()) << "\n"; // 5

    // Hardware Bit Manipulations (GCC Built-in Engine Optimization)
    int binary_target = 7; // Binary representation tracking field: 0111
    cout << "Set Bits (active 1s) inside number 7: " << __builtin_popcount(binary_target) << "\n\n";

    cout << "=======================================\n";
    return 0;
}