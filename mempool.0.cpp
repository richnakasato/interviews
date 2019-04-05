#include <iostream>
#include <stdexcept>
#include <vector>

/*
 * ctor - initialize memory pool but sz_bytes / elem and num elem
 * dtor - delete entire memory pool
 * get - retrieve from mem pool
 * put - put back part of memory pool
 */

class MemoryPool {
public:
    struct MemoryPoolNode {
        char* node_data;
    };

    MemoryPool(int count, int elem_size_bytes) :
                   pool_num_elem_{count},
                   elem_sz_bytes_{elem_size_bytes},
                   pool_sz_bytes_{count*elem_size_bytes},
                   pool_mem_{new char[count*elem_size_bytes]}
    {
        for (int offset=0; offset<pool_sz_bytes_; offset+=elem_sz_bytes_) {
            MemoryPoolNode mem_pool_node;
            mem_pool_node.node_data = pool_mem_ + offset;
            pool.push_back(mem_pool_node);
        }
    }

    ~MemoryPool() { if (pool_mem_) delete[] pool_mem_; }

    bool empty() const { return pool.empty(); }
    int remaining() const { return pool.size(); }

    MemoryPoolNode get_node()
    {
        if (empty()) { throw std::runtime_error("empty memory pool"); }
        MemoryPoolNode ret = pool.back();
        pool.pop_back();
        return ret;
    }

    void return_node(MemoryPoolNode node) { pool.push_back(node); }

    std::string print_pool()
    {
        if (empty()) { throw std::runtime_error("empty memory pool"); }
        std::string ret;
        for (int i=0; i<pool_sz_bytes_; ++i) {
            ret += pool_mem_[i];
        }
        return ret;
    }

    std::string print_vec()
    {
        std::string ret;
        if (empty()) { throw std::runtime_error("empty memory pool"); }
        for (const auto& e : pool) {
            ret += "[";
            ret += *(e.node_data);
            ret += "]";
        }
        return ret;
    }

private:
    int pool_num_elem_;
    int elem_sz_bytes_;

    int pool_sz_bytes_;
    char* pool_mem_;
    std::vector<MemoryPoolNode> pool;
};

int main()
{
    MemoryPool mp = MemoryPool(10, 1);
    std::cout << mp.remaining() << std::endl;
    std::cout << mp.print_vec() << std::endl;

    MemoryPool::MemoryPoolNode mpn1 = mp.get_node();
    *(mpn1.node_data) = 'a';
    MemoryPool::MemoryPoolNode mpn2 = mp.get_node();
    *(mpn2.node_data) = '%';
    MemoryPool::MemoryPoolNode mpn3 = mp.get_node();
    *(mpn3.node_data) = 'p';
    MemoryPool::MemoryPoolNode mpn4 = mp.get_node();
    *(mpn4.node_data) = '0';
    MemoryPool::MemoryPoolNode mpn5 = mp.get_node();
    *(mpn5.node_data) = 'b';
    MemoryPool::MemoryPoolNode mpn6 = mp.get_node();
    *(mpn6.node_data) = '^';
    std::cout << mp.print_pool() << std::endl;
    std::cout << mp.remaining() << std::endl;
    mp.return_node(mpn6);
    mp.return_node(mpn1);
    mp.return_node(mpn3);
    std::cout << mp.print_vec() << std::endl;
    std::cout << mp.remaining() << std::endl;

    return 0;
}
