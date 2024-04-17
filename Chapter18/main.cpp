#include <iostream>
#include <vector>
#include <array>
#include <map>
#include <unordered_map>
#include <ranges>
#include <span>
#include <bitset>
#include "Vector/Process.h"
#include "Queue/PacketBuff.h"
#include "Priority_queue/Error.h"
#include "Associated/BankDB.h"
#include "Associated/Buddy.h"
#include "Bitset/CableCompany.h"

/* Basically, normal containers can be divided into these type:
 * Sequence containers: vector, list, deque, array, forward_list, which storage 1 data sequence
 * Associated containers: map, set, multimap, multiset, unordered_map, unordered_set, unordered_multimap/set, which storage <key,value> pair.
 * Containers adapter: queue, stack, priority_queue,<ranges>
 * Others: string, bitset.
 * */

/* Some related tools lib:
 * <tuple>, <variant>,
 *
 * */

void useVector() {
    /* Vector is the most used container, which storages elements in consequent memory,
     * So, options change or find element is O(1), but options insert or delete is O(n). Elements can be random access.
     * Vector always applies bigger size memory than it needs. So it involves option copy and move, and the iterators invalided.
     * */

    std::cout << "####Vector#####" << std::endl;
    std::cout << "Memory reclamation" << std::endl; // vecotr always free the memory it used;
    std::vector<int> vecInt{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // also can use reserve to allocate memory

    std::vector<int>().swap(vecInt);
    if (!vecInt.empty()) {
        std::cout << "Hadn't be freed memory" << std::endl;
    } else { std::cout << "Had freed memory" << std::endl; }

    std::string str{"Hello World!"};
    std::vector<std::reference_wrapper<std::string> > vecRef{
            std::ref(str)};  // container storage reference using 'std::reference_wrapper<>'.
    vecRef[0].get() += " Modified by reference\n";
    std::cout << str;

    std::vector<int> tmp{11, 22, 33, 44};
    vecInt.insert(std::cend(vecInt), std::cbegin(tmp), std::cend(tmp));

    for (const auto &ele: vecInt) {
        std::cout << ele << " ";
    }
    std::cout << std::endl;

    std::cout << "###########Vector timeSlice##########" << std::endl;
    std::vector<Process> vecProc{Process{"First"}, Process{"Second"}, Process{"Third"}};
    Scheduler sc{vecProc};

    for (int i = 0; i < 4; i++) {
        sc.timeSlice();
    }
    sc.removeProcess(vecProc[1]);
    std::cout << "Removed Second" << std::endl;
    for (int i = 0; i < 4; i++) {
        sc.timeSlice();
    }
}

//###########SPAN
void print(std::span<int> c) {
    for (const auto &ele: c) {
        std::cout << ele << " ";
    }
    std::cout << std::endl;
}

//#######################Queue
class IPPacket final {
public:
    explicit IPPacket(int id) : m_id(id) {}

    int getIP() const { return m_id; }

private:
    int m_id;
};

void useQueue() {
    /* Chapter18 adapter is a wrapper for sequence containers, also allowed changed
     * base container
     * */
    // Queue, FIFO, default implement by deque. Require that base container support 'push_back' and 'pop_front'
    std::cout << "#######Queue#######" << std::endl;
    PacketBuff<IPPacket> ipPack{3};
    for (int i = 0; i < 4; i++) {
        if (!ipPack.bufferPacket(IPPacket{i})) {
            std::cout << "Packet " << i << " is dropped" << std::endl;
        }
    }

    while (true) {

        try {
            IPPacket tmp = {ipPack.getNextPacket()};
            std::cout << "Processing Packet: " << tmp.getIP() << std::endl;
        } catch (const std::out_of_range ex) {
            std::cout << "Exception: " << ex.what() << std::endl;
            break;
        }
    }

}

void usePriority_queue() {
    /* Remember:
     * If 'priority_queue' storages customer type, had to implement 'operator<'
     * */

    std::cout << "###Priority_queue###" << std::endl;

    ErrorCorrelator ec;
    ec.addError(Error{3, "Unable to read file"});
    ec.addError(Error{1, "Incorrect entry from user"});
    ec.addError(Error{10, "Unable to allocate memory"});

    while (true) {
        try {
            Error e{ec.getEror()};
            std::cout << e << std::endl;
        } catch (const std::out_of_range &ex) {
            std::cout << "Finished Exception: " << ex.what() << std::endl;
            break;
        }
    }

}


void useMap() {
    std::cout << "###Map Basic###" << std::endl;
    std::map<int, std::string> data;
    // Add pair
    // 'insert' can also use to judge the element existed.
    // 'insert' return type <iterator,bool>, 'bool' for the key is existed or not.
    auto ret{data.insert({1, "first"})};
    if (auto [iter, success] {data.insert({3, "Third"})}; success) {    // After C++17: could use if-initializer
        // judge insert suecces
        std::cout << "Insert valid" << std::endl;
    } else {
        std::cout << "Insert invalid" << std::endl;
    }
    if (auto [iter, sucess] {data.insert_or_assign(1,
                                                   "OverWritten TEST")}; sucess) {  //'insert_or_assign' could change key-value that key was existed.
        std::cout << "Inserted new key" << std::endl;
    } else {
        std::cout << "Overwritten key" << std::endl;
    }
    std::cout << "##IF use operator[], it always success" << std::endl;

    // Find element, find() will return iterator
    std::cout << "1 count(): " << std::boolalpha << data.count(1) << std::endl;
    // All associated containers are based on  type 'node', since C++17 could visited node using extract().
    auto tmpNdoe{data.extract(1)}; // most used to move node between container

    BankDB bd;

    bd.addAccount(Account{100, "Nicholas Solter"});
    bd.addAccount(Account{200, "Scott Koper"});

    try {
        auto &ac{bd.find(100)};
        std::cout << "Found account 100" << std::endl;

        auto &ac2{bd.find(1000)};
        std::cout << "Found account 1000" << std::endl;
    } catch (const std::out_of_range &ex) {
        std::cout << "Unable find account: " << ex.what();
    }

}

void useMulity_map() {
    std::cout << "###Multi_map Basic###" << std::endl;
    Buddy BuddyList;
    BuddyList.addBuddy("Potter", "Ron Wealsy");
    BuddyList.addBuddy("Potter", "Graner");
    BuddyList.addBuddy("Potter", "Hargir");
    BuddyList.addBuddy("Potter", "Draco");
    BuddyList.addBuddy("Potter", "Drik");
    BuddyList.addBuddy("Hargir", "Potter");
    BuddyList.addBuddy("Hargir", "Tick");
    BuddyList.addBuddy("Hargir", "Ron Wealsy");


    auto PotterFriend{BuddyList.getBuddies("Potter")};
    std::cout << "Potter friend" << std::endl;

    for (const auto &ele: PotterFriend) {
        std::cout << "\t" << ele << std::endl;
    }
    std::cout.flush();
}


// Unordered map
void printMap(const auto &m) {   //C++20 abbreviated function template
    for (auto &[key, value]: m) {
        std::cout << key << " (Phone: " << value << " )" << std::endl;
    }
    std::cout << "----------" << std::endl;
}

void useUnorderedMap() {
    /* Unordered associative container is also called hash-function
     * Storage element using bucket.
     * key -- hash func --> hash-value --> bucket-index --> bucket list
     *
     * */
    std::unordered_map<std::string, std::string> phoneBook{
            {"Marc G", "123-341413"},


            {"Scott K", "321-4341431"}
    };
    printMap(phoneBook);

    phoneBook.insert({"Jhon G", "321-43421413"});
    phoneBook["Johon D"] = "231-34515";
    printMap(phoneBook);

    const size_t bucket{phoneBook.bucket("Marc G")};
    std::cout << "Marc G is in bucket " << bucket << " containing the following " << phoneBook.bucket_size(bucket)
              << std::endl;

    auto begin{phoneBook.cbegin(bucket)};
    auto end{phoneBook.cend(bucket)};

    for (auto it = begin; it != end; ++it) {
        std::cout << "\t " << it->first << " (Phone: " << it->second << " )" << std::endl;
    }
    std::cout<<"---------"<<std::endl;

    std::cout<<"There are "<<phoneBook.bucket_count()<<" buckets "<<std::endl;
    std::cout<<"Average element in buckets: "<<phoneBook.load_factor()<<std::endl;

}


void useBitset(){

    /* Example is that using std::bitset<> to track users' TV channels, the bit represent specific channel
     * example also support channels packages
     * */

    CableCompany myCC;
    myCC.addPackage("basic","1111000000");
    myCC.addPackage("premium","1111111111");
    myCC.addPackage("sports","0000100111");

    myCC.newCustomer("Ma","basic");
    myCC.addPackageToCustomer("Ma","sports");

    std::cout<<"Marc G Channels: "<<myCC.getCustomerChannel("Ma")<<std::endl;

}

int main() {
    std::cout << "################VECTOR######################" << std::endl;
    useVector();
    std::cout << "##################SPAN############################" << std::endl;
    /* span is used to handle the overload of vector, C format array, array
     * <span> copy cost is low, it contains one pointer to data's first element
     * */

    std::vector<int> vecInt{412, 435, 546, 57, 2, 646};
    auto ra{vecInt | std::views::take(10)};
    std::array<int, 10> arrInt{24, 13, 5, 46, 3, 4};
    int arr[]{12, 3, 52, 6, 462, 7, 372, 2};
    print(ra);  // also can pass ranges
    print(vecInt);
    print(arrInt);
    print(arr);

    std::cout << "###################Chapter18 Adapter#################" << std::endl;
    useQueue();
    usePriority_queue();

    std::cout << "######################Associated Chapter18######################" << std::endl;
    useMap();
    useMulity_map();

    std::cout << "#####################Unordered associative container#################################" << std::endl;
    useUnorderedMap();

    std::cout<<"###############################Bitset#############################################"<<std::endl;
    std::bitset<10>  b1{"1011011"};
    std::bitset<10>  b2 {"11101011000"};

    std::cout<<b1<<" AND "<<b2<<" : "<<(b1&b2)<<std::endl;
    std::cout<<"-------"<<std::endl;
    useBitset();


    return 0;
}
