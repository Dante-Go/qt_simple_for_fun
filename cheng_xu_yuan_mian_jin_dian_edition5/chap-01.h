#ifndef CHAP01_H
#define CHAP01_H

#include <iostream>
#include <ext/hash_map> // for hash_map
#include <string>
#include <string.h>
#include <iomanip>

using namespace std;
using namespace __gnu_cxx; // for hash_map
// 1.5
string compress_string_v1(string str)
{
    string ret_str = "";
    int count = 1;
    char cur_char = str.at(0);
    for(int i = 1; i < str.length(); i++)
    {
        if(str.at(i) == cur_char)
        {
            count++;
        }
        else
        {
            ret_str += (cur_char + to_string(count));
            cur_char = str.at(i);
            count = 1;
        }
    }
    ret_str += (cur_char + to_string(count));
    return ret_str;
}
int compress_size(string str)
{
    if(str.empty())
        return 0;

    int size_after_compress = 0;
    int count = 1;
    char cur_char = str.at(0);
    for(int i = 1; i < str.length(); i++)
    {
        if(str.at(i) == cur_char)
        {
            count++;
        }
        else
        {
            cur_char = str.at(i);
            size_after_compress += 1 + to_string(count).length();
            count = 1;
        }
    }
    size_after_compress += 1 + to_string(count).length();
    return size_after_compress;
}
string compress_string_v2(string str)
{
    if(compress_size(str) >= str.length())
    {
        return str;
    }
    string ret_str = "";
    int count = 1;
    char cur_char = str.at(0);
    for(int i = 1; i < str.length(); i++)
    {
        if(str.at(i) == cur_char)
        {
            count++;
        }
        else
        {
            ret_str.append(1,cur_char);
            ret_str.append(to_string(count));
            cur_char = str.at(i);
            count = 1;
        }
    }
    ret_str.append(1,cur_char);
    ret_str.append(to_string(count));
    return ret_str;
}
// 1.6
void matrix_rotate(int *matrix, int n)
{
    for(int layout = 0; layout < n/2; layout++)
    {
        int first = layout;
        int last = n - 1 -layout;
        for(int i = first; i < last; i++)
        {
            int offset = i - first;

            // top = matrix[first][i]
            int top = *(matrix + first*n + i);
            // matrix[first][i] = matrix[last-offset][first]
            *(matrix + first*n + i) = *(matrix + (last-offset)*n + first);
            // matrix[last-offset][first] = matrix[last][last-offset]
            *(matrix + (last-offset)*n + first) = *(matrix + last*n + (last-offset));
            // matrix[last][last-offset] = matrix[i][last]
            *(matrix + last*n + last-offset) = *(matrix + i*n + last);
            // matrix[i][last] = top
            *(matrix + i*n + last) = top;

        }
    }
}
// 1.7
void reset_zero(int *e,int m, int n)
{
    bool rows[m] = {0};
    bool cols[n] = {0};

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(0 == *(e+i*m+j))
            {
                rows[i] = true;
                cols[j] = true;
            }
        }
    }

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if( rows[i] || cols[j])
            {
                *(e+i*m+j) = 0;
            }
        }
    }
}
void print_m(int *e,int m, int n)
{

    for(int i = 0; i < m; i++)
    {
        for( int j = 0; j < m; j++)
        {
            cout << setw(3) << *(e+i*m+j) << ",";
        }
        cout << endl;
    }
    cout << endl;
}

// 1.8
bool isSubString(string str, string sub_str)
{
    if(str.empty() || sub_str.empty() || str.length() < sub_str.length())
    {
        return false;
    }

    int start_pos = 0;
    while(start_pos < str.length())
    {
        if(str.at(start_pos) == sub_str.at(0))
        {
            int i = 0;
            for( /* */; i < sub_str.length() && (i+start_pos) < str.length(); i++)
            {
                if(str.at(i+start_pos) != sub_str.at(i))
                {
                    break;
                }
            }
            if(i  >= sub_str.length())
            {
                return true;
            }

        }
        start_pos++;
    }
    if(start_pos > str.length())
    {
        return false;
    }
}
bool isRotationString(string s1, string s2)
{
    if(s1.length() != s2.length())
    {
        return false;
    }

    string str_tmp = s1 + s1;
    bool ret = isSubString(str_tmp, s2);
    return ret;
}

//int main()
//{

//    //    string str = "aaabb";
//    //    string str2 = compress_string_v2(str);
//    //    cout << str2 << endl;

//    //    int matrix[4][4] = { 1, 2, 3, 4, 5, 1, 0, 8, 9, 10, 11, 12, 13, 14, 15, 16};
//    //    print_m((int*)matrix, 4, 4);

//    //    matrix_rotate((int*)matrix, 4);
//    //    print_m((int*)matrix, 4, 4);

//    //    reset_zero((int*)matrix, 4, 4);
//    //    print_m((int*)matrix, 4, 4);

//    string s1 = "abc";
//    string s2 = "bca";
//    cout << isSubString(s1, s2) << endl;
//    cout << isRotationString(s1, s2) << endl;

//    return 0;
//}


#endif // CHAP01_H
