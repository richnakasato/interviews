#include <stdio.h>
#include <stdlib.h>

struct Node {
    size_t data_sz;
    char* data_ptr;
    struct Node* next;
};

struct Pool {
    size_t curr_sz;
    struct Node* head;

    size_t _node_count;
    char* _pool_datas;
    struct Node* _pool_nodes;
};

struct Pool* create_pool(size_t node_sz, size_t pool_sz) {
    char* pool_datas = malloc(node_sz * pool_sz);
    struct Node* pool_nodes = malloc(sizeof(struct Node) * pool_sz);
    struct Pool* pool = malloc(sizeof(struct Pool));

    char* curr_data = pool_datas;
    struct Node* curr_node = pool_nodes;

    for (int count=0; count < pool_sz; ++count) {
        curr_node->data_sz = node_sz;
        curr_node->data_ptr = curr_data;
        if (count < pool_sz - 1) {
            curr_data+=1;
            curr_node->next = curr_node+1;
            curr_node = curr_node->next;
        }
        else {
            curr_node->next = NULL;
        }
    }
    pool->curr_sz = pool->_node_count;
    pool->head = pool_nodes;

    pool->_node_count = pool_sz;
    pool->_pool_datas = pool_datas;
    pool->_pool_nodes = pool_nodes;
    return pool;
}

void destroy_pool(struct Pool* pool);

struct Node* get_pool_node(struct Pool* pool) {
    if (pool != NULL && pool->curr_sz > 0) {
        struct Node* temp = pool->head;
        pool->head = pool->head->next;
        --pool->curr_sz;
        return temp;
    }
    return NULL;
}

void put_pool_node(struct Pool* pool);

int main(void)
{
    return 0;
}
