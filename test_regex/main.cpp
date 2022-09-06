//
// Created by zhanghao on 22-7-25.
//
#include <iostream>
#include <string>
#include <regex>

using namespace std;

bool ParseMode(const std::string &mode, std::string *alg_mode, std::string *work_mode) {
    std::smatch results;
    std::regex re("([A-Z]{3}|[A-Z]{2}\\d)-([A-Z]{3})");
    if (!(std::regex_match(mode.c_str(), re) && std::regex_search(mode, results, re))) {
        cout << "Mode " << mode << " is invalid.";
        return false;
    }
    *alg_mode = results[1];
    *work_mode = results[2];
    return true;
}

int main(){
    cout<<"hello world"<<endl;
    std::string alg_mode;
    std::string work_mode;
    string enc_mode = "AES-CBC";
    bool flag = ParseMode(enc_mode,&alg_mode,&work_mode);
    cout<<"加密算法:"<<alg_mode<<endl<<"加密模式："<<work_mode<<endl;
    if(flag == true){
        cout<<"正确"<<endl;
    }else{
        cout<<"错误"<<endl;
    }
//    string str = "Hello 2018, Bye 2017";
//    std::smatch result;
//    std::regex pattern("\\d{4}");	//匹配四个数字
//
////迭代器声明
//    string::const_iterator iterStart = str.begin();
//    string::const_iterator iterEnd = str.end();
//    string temp;
//    while (regex_search(iterStart, iterEnd, result, pattern))
//    {
//        temp = result[0];
//        cout << temp << " ";
//        iterStart = result[0].second;	//更新搜索起始位置,搜索剩下的字符串
//    }
    return 0;
}

