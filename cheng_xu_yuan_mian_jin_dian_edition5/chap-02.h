#ifndef CHAP02_H
#define CHAP02_H

#include <iostream>
#include <ext/hash_map> // for hash_map

typedef struct _node
{
    int data;
    _node *p_next;
}NODE,*P_NODE;

NODE* link_list_create(int *p_data, int len)
{
    NODE *head = (NODE*)malloc(sizeof(NODE));
    head->data = len;
    head->p_next = nullptr;
    for(int i = 0; i < len; i++)
    {
        P_NODE p = (P_NODE)malloc(sizeof(NODE));
        if(nullptr == p)
        {
            return nullptr;
        }
        p->data = *p_data;
        p->p_next = head->p_next;
        head->p_next = p;
        p_data++;
    }
    return head;
}

void link_list_print(P_NODE head)
{
    if(nullptr == head) return ;
    std::cout << "list(len=" << head->data << "):";
    P_NODE p = head->p_next;
    while(p)
    {
        std::cout << p->data << "->";
        p = p->p_next;
    }
    std::cout << std::endl;
}

// 2.1
void link_list_distinct(P_NODE head)
{
    if(nullptr == head || 1 >= head->data) return ;

    P_NODE iterator,pre, cursor;
    iterator = pre = head->p_next;
    cursor = pre->p_next;
    while(nullptr != iterator->p_next)
    {
        if( nullptr == cursor)
        {
            return;
        }
        while( nullptr != cursor)
        {
            while( iterator->data == cursor->data)
            {
                pre->p_next = cursor->p_next;
                delete cursor;
                cursor = pre->p_next;
            }
            pre = pre->p_next;
            cursor = pre->p_next;
        }
        iterator = iterator->p_next;
        pre = iterator;
        cursor = pre->p_next;
    }
}
//void link_list_distinct_v2(P_NODE head)
//{
//    using namespace __gnu_cxx; // for hash_map
//    hashtable<int> table = new hashtable<int>();
//    P_NODE pre = head;
//    while( head != nullptr)
//    {
//        if(table.find(head->data))
//        {
//            pre->p_next = head->p_next;
//        }
//        else
//        {
//            table.insert_equal(head->data);
//            pre = head->p_next;
//        }
//        head = head->p_next;
//    }
//}

// 2.2
P_NODE link_list_find_tail_k(P_NODE head, int k)
{
    if(nullptr == head || head->data < k)
    {
        return nullptr;
    }

    P_NODE p_delete , p_front_k;
    p_delete = p_front_k = head;
    int step_count = 0;
    while(p_front_k != nullptr)
    {
        if(step_count >= k)
        {
            p_delete = p_delete->p_next;
        }
        p_front_k = p_front_k->p_next;
        step_count++;
    }
    return p_delete;
}
P_NODE link_list_find_tail_k_v2(P_NODE head, int k, int& i)
{
    if(nullptr == head)
    {
        return nullptr;
    }
    P_NODE p = link_list_find_tail_k_v2(head->p_next, k, i);
    i = i + 1;
    if( i == k)
    {
        return head;
    }
    return p;
}

// 2.4
P_NODE link_list_device_by_x(P_NODE head, int x)
{
    P_NODE p_list_before = nullptr;
    P_NODE p_list_after = nullptr;
    P_NODE p_before = nullptr;
    P_NODE p_after = nullptr;

    P_NODE p_head = head;

    P_NODE p_next = nullptr;
    head = head->p_next;
    while(head != nullptr)
    {
        p_next = head->p_next;

        if(head->data < x)
        {
            if(p_list_before == nullptr)
            {
                p_list_before = head;
                p_before = head;
            }
            else
            {
                p_before->p_next = head;
                p_before = p_before->p_next;
            }
        }
        if(head->data >= x)
        {
            if(p_list_after == nullptr)
            {
                p_list_after = head;
                p_after = head;
            }
            else
            {
                p_after->p_next = head;
                p_after = p_after->p_next;
            }
        }

        head = p_next;
    }
    p_before->p_next =  p_after->p_next = nullptr;

    if(p_list_before != nullptr)
    {
        p_before->p_next = p_list_after;
    }


    p_head->p_next = p_list_before;
    return p_head;
}
P_NODE link_list_device_by_x_v2(P_NODE head, int x)
{
    P_NODE p_list_before = nullptr;
    P_NODE p_list_after = nullptr;

    P_NODE p_head = head;
    P_NODE p_next = nullptr;
    head = head->p_next;
    while(head != nullptr)
    {
        p_next = head->p_next;

        if(head->data < x)
        {
            head->p_next = p_list_before;
            p_list_before = head;
        }
        if(head->data >= x)
        {
            head->p_next = p_list_after;
            p_list_after = head;
        }

        head = p_next;
    }

    p_head->p_next = p_list_before;
    while(p_list_before->p_next != nullptr)
    {
        p_list_before = p_list_before->p_next;
    }
    p_list_before->p_next = p_list_after;

    return p_head;
}

// 2.5
P_NODE link_list_sum(P_NODE num1, P_NODE num2)
{
    if(num1 == nullptr)
    {
        return num2;
    }
    else if( num2 == nullptr)
    {
        return num1;
    }

    num1 = num1->p_next;
    num2 = num2->p_next;
    NODE head;
    head.data = 0;
    head.p_next = nullptr;
    P_NODE ret_list = &head;
    int inc = 0;
    while(num1 != nullptr && num2 != nullptr)
    {
        int tmp = 0;
        tmp = num1->data + num2->data + inc;
        inc = tmp / 10;
        tmp = tmp % 10;

        P_NODE p_node = (P_NODE)malloc(sizeof(NODE));
        p_node->data = tmp;
        p_node->p_next = nullptr;

        ret_list->data++;
        p_node->p_next = ret_list->p_next;
        ret_list->p_next = p_node;

        num1 = num1->p_next;
        num2 = num2->p_next;
    }
    while(num1 != nullptr)
    {
        int tmp = 0;
        tmp = num1->data + inc;
        inc = tmp / 10;
        tmp = tmp % 10;

        P_NODE p_node = (P_NODE)malloc(sizeof(NODE));
        p_node->data = tmp;
        p_node->p_next = nullptr;

        ret_list->data++;
        p_node->p_next = ret_list->p_next;
        ret_list->p_next = p_node;

        num1 = num1->p_next;
    }
    while(num2 != nullptr)
    {
        int tmp = 0;
        tmp = num2->data + inc;
        inc = tmp / 10;
        tmp = tmp % 10;

        P_NODE p_node = (P_NODE)malloc(sizeof(NODE));
        p_node->data = tmp;
        p_node->p_next = nullptr;

        ret_list->data++;
        p_node->p_next = ret_list->p_next;
        ret_list->p_next = p_node;

        num2 = num2->p_next;
    }

    if(inc > 0)
    {
        P_NODE p_node = (P_NODE)malloc(sizeof(NODE));
        p_node->data = inc;
        p_node->p_next = nullptr;

        ret_list->data++;
        p_node->p_next = ret_list->p_next;
        ret_list->p_next = p_node;
    }

    return ret_list;
}
int list_add(P_NODE head, P_NODE num1, P_NODE num2)
{
    if(num1 == nullptr || num2 == nullptr)
    {
        return 0;
    }
    int carry = list_add(head, num1->p_next, num2->p_next);
    int tmp = num1->data + num2->data + carry;
    P_NODE p_new_node = (P_NODE)malloc(sizeof(NODE));
    p_new_node->data = (tmp%10);
    p_new_node->p_next = head->p_next;
    head->p_next = p_new_node;
    head->data++;
    return (tmp/10);
}
P_NODE link_list_sum_v2(P_NODE num1, P_NODE num2)
{
    if(num1 == nullptr || num2 == nullptr)
    {
        return nullptr;
    }
    if( num1->data < num2->data)
    {
        while( num2->data - num1->data)
        {
            P_NODE p_zero_node = (P_NODE)malloc(sizeof(NODE));
            p_zero_node->data = 0;
            p_zero_node->p_next = num1->p_next;
            num1->p_next = p_zero_node;
            num1->data++;
        }
    }
    else if(num1->data > num2->data)
    {
        while(num1->data - num2->data)
        {
            P_NODE p_zero_node = (P_NODE)malloc(sizeof(NODE));
            p_zero_node->data = 0;
            p_zero_node->p_next = num2->p_next;
            num2->p_next = p_zero_node;
            num2->data++;
        }
    }

    P_NODE ret_list = (P_NODE)malloc(sizeof(NODE));
    ret_list->data = 0;
    ret_list->p_next = nullptr;

    int carry = list_add(ret_list, num1->p_next, num2->p_next);
    if( carry > 0)
    {
        P_NODE last_carry = (P_NODE)malloc(sizeof(NODE));
        last_carry->data = carry;
        last_carry->p_next = ret_list->p_next;
        ret_list->p_next = last_carry;
        ret_list->data++;
    }
    return ret_list;
}

// 2.6
NODE* link_list_with_loop_create(int *p_data, int len)
{
    NODE *head = (NODE*)malloc(sizeof(NODE));
    head->data = len;
    head->p_next = nullptr;
    P_NODE tail = head;
    for(int i = 0; i < len; i++)
    {
        P_NODE p = (P_NODE)malloc(sizeof(NODE));
        if(nullptr == p)
        {
            return nullptr;
        }
        p->data = *p_data;
        p->p_next = head;
        tail->p_next = p;
        tail = p;
        p_data++;
    }
    return head;
}
void link_list_with_loop_print(P_NODE head)
{
    if(nullptr == head) return ;
    std::cout << "list(len=" << head->data << "):";
    P_NODE p = head->p_next;
    while(p != head)
    {
        std::cout << p->data << "->";
        p = p->p_next;
    }
    std::cout << std::endl;
}
P_NODE link_list_find_loop(P_NODE head)
{
    P_NODE fastRunner = head;
    P_NODE slowRunner = head;
    while(fastRunner != nullptr && fastRunner->p_next != nullptr)
    {
        slowRunner = slowRunner->p_next;
        fastRunner = fastRunner->p_next->p_next;
        if(slowRunner == fastRunner)
        {
            break;
        }
    }
    if(fastRunner == nullptr || fastRunner->p_next == nullptr)
    {
        return nullptr;
    }

    slowRunner = head;
    while(slowRunner != fastRunner)
    {
        slowRunner = slowRunner->p_next;
        fastRunner = fastRunner->p_next;
    }
    return fastRunner;
}


// 2.7

#endif // CHAP02_H
