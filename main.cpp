#include <iostream>
using namespace std;

void showMenu()
{
    cout << "======== 通讯录菜单 ========" << endl;
    cout << "      1. 添加联系人" << endl;
    cout << "      2. 显示联系人" << endl;
    cout << "      3. 删除联系人" << endl;
    cout << "      4. 查找联系人" << endl;
    cout << "      5. 修改联系人" << endl;
    cout << "      6. 清空联系人" << endl;
    cout << "      0. 退出通讯录" << endl;
    cout << "==========================" << endl;
};

struct Person
{
    string name;
    int age;
    int sex; // 1 男 2 女
    string phone;
    string address;
};

struct AddressBook
{
    struct Person personArray[1000];
    int m_Size = 0; // 当前通讯录中记录的联系人个数
};

void addPerson(AddressBook *abs)
{
    if (abs->m_Size >= 1000)
    {
        cout << "通讯录已满，无法添加更多联系人！" << endl;
        return;
    }
    
    string name;
    cout << "请输入姓名: " << endl;
    cin >> name;
    abs->personArray[abs->m_Size].name = name;
    
    cout << "请输入年龄: " << endl;
    int age;
    cin >> age;
    abs->personArray[abs->m_Size].age = age;
    
    cout << "请输入性别(1-男 2-女): " << endl;
    int sex = 0;
    while (true)
    {
        cin >> sex;
        if (sex == 1 || sex == 2)
        {
            abs->personArray[abs->m_Size].sex = sex;
            break;
        };
        cout << "输入有误，请重新输入" << endl;
    }
    
    cout << "请输入电话号码: " << endl;
    string phone;
    cin >> phone;
    abs->personArray[abs->m_Size].phone = phone;
    
    cout << "请输入地址: " << endl;
    string address;
    cin >> address;
    abs->personArray[abs->m_Size].address = address;

    abs->m_Size++;
    cout << "联系人添加成功！" << endl;

    system("pause");
    system("cls");
};

void showPerson(AddressBook* abs)
{
    if (abs->m_Size == 0)
    {
        cout << "当前通讯录无联系人记录！" << endl;
        return;
    }
    else 
    {
        for (int i = 0; i < abs->m_Size; i++)
        {
            cout << "姓名: " << abs->personArray[i].name << "\t";
            cout << "年龄: " << abs->personArray[i].age << "\t";
            cout << "性别: " << (abs->personArray[i].sex == 1 ? "男" : "女") << "\t";
            cout << "电话: " << abs->personArray[i].phone << "\t";
            cout << "地址: " << abs->personArray[i].address << endl;
        }
    }
    system("pause");
    system("cls");
};

int isExist(AddressBook* abs, string name)
{
    for (int i = 0; i < abs->m_Size; i++)
    {
        if (abs->personArray[i].name == name)
        {
            return i;
        }
    }
    return -1;
};

void deletePerson(AddressBook* abs)
{
    cout << "请输入要删除的联系人姓名: " << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);
    if (ret != -1)
    {
        for (int i = ret; i < abs->m_Size - 1; i++)
        {
            abs->personArray[i] = abs->personArray[i + 1];
        }
        abs->m_Size--;
        cout << "联系人删除成功！" << endl;
    }
    else
    {
        cout << "未找到该联系人！" << endl;
    }
    system("pause");
    system("cls");
};

void findPerson(AddressBook* abs)
{
    cout << "请输入要查找的联系人姓名: " << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);
    if (ret != -1)
    {
        cout << "姓名: " << abs->personArray[ret].name << "\t";
        cout << "年龄: " << abs->personArray[ret].age << "\t";
        cout << "性别: " << (abs->personArray[ret].sex == 1 ? "男" : "女") << "\t";
        cout << "电话: " << abs->personArray[ret].phone << "\t";
        cout << "地址: " << abs->personArray[ret].address << endl;
    }
    else 
    {
        cout << "未找到该联系人！" << endl;
    }
    system("pause");
    system("cls");
}

void modifyPerson(AddressBook* abs)
{
    cout << "请输入要修改的联系人姓名: " << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);
    if (ret != -1)
    {
        cout << "请输入新的年龄: " << endl;
        int age;
        cin >> age;
        abs->personArray[ret].age = age;

        cout << "请输入新的性别(1-男 2-女): " << endl;
        int sex = 0;
        while (true)
        {
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                abs->personArray[ret].sex = sex;
                break;
            };
            cout << "输入有误，请重新输入" << endl;
        }

        cout << "请输入新的电话号码: " << endl;
        string phone;
        cin >> phone;
        abs->personArray[ret].phone = phone;

        cout << "请输入新的地址: " << endl;
        string address;
        cin >> address;
        abs->personArray[ret].address = address;
        
        cout << "联系人修改成功！" << endl;
    }
    else
    {
        cout << "未找到该联系人！" << endl;
    }
    system("pause");
    system("cls");
};

void clearPerson(AddressBook* abs)
{
    abs->m_Size = 0;
    cout << "已清空所有联系人！" << endl;
    system("pause");
    system("cls");
};

int main()
{
    AddressBook abs;
    abs.m_Size = 0; // 初始化通讯录中没有任何联系人
    int choice = 0;
    while (true)
    {
        showMenu();
        cin >> choice;
        if (choice == 0)
        {
            cout << "退出通讯录" << endl;
            break;
        }
        switch (choice)
        {
        case 1:
            addPerson(&abs);
            break;
        case 2:
            showPerson(&abs);
            break;
        case 3:
            deletePerson(&abs);
            break;
        case 4:
            findPerson(&abs);
            break;
        case 5:
            modifyPerson(&abs);
            break;
        case 6:
            clearPerson(&abs);
            break;
        default:
            cout << "无效的选择，请重新输入" << endl;
            break;
        }
        system("pause");
    }
    
    system("pause");
    system("clean");
    return 0;
}