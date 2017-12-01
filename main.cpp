#include <iostream>
#include "cheng_xu_yuan_mian_jin_dian_edition5/chap-01.h"
#include "cheng_xu_yuan_mian_jin_dian_edition5/chap-02.h"

using namespace std;

int main()
{
    //    P_NODE single_link_list = nullptr;
    //    int arr[10] = {10, 9, 8, 99, 6, 5, 4, 33, 22, 11};
    //    single_link_list = link_list_create(arr, 10);
    //    link_list_print(single_link_list);
    ////    link_list_distinct(single_link_list);
    ////    link_list_print(single_link_list);

    ////    cout << link_list_find_tail_k(single_link_list, 4)->data << endl;
    ////    int i = 0;
    ////    cout << link_list_find_tail_k_v2(single_link_list, 4, i)->data << endl;
    ////     link_list_print(link_list_device_by_x(single_link_list, 33));
    ////     link_list_print(link_list_device_by_x_v2(single_link_list, 11));


//    int num1[10] = {1, 2, 3};
//    int num2[10] = {1, 2, 3, 6};
//    P_NODE num1_link_list = link_list_create(num1, 3);
//    P_NODE num2_link_list = link_list_create(num2, 3);
//    link_list_print(num1_link_list);
//    link_list_print(num2_link_list);
////    link_list_print(link_list_sum(num1_link_list, num2_link_list));
//    link_list_print(link_list_sum_v2(num1_link_list, num2_link_list));

    int arr_loop[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 1};
    P_NODE loop_link_list = link_list_with_loop_create(arr_loop, 10);
    link_list_with_loop_print(loop_link_list);
    cout << link_list_find_loop(loop_link_list) << endl;
    cout << loop_link_list << endl;

    return 0;
}
