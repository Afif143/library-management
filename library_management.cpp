#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string.h>
#include <ctype.h>
using namespace std;
class Product
{
private:
    int id;
    char name[50];
    char Name[50];

public:
    Product()
    {

        id = 0;
        strcpy(name, "");
        strcpy(Name, "");
    }
    Product(int I, char N[50], char AN[50])
    {

        id = I;
        strcpy(name, N);
        strcpy(Name, AN);
    }
    void displayProduct()
    {
        cout << setw(8) << id;
        cout << setw(23) << name;
        cout << setw(33) << Name;
        cout << endl;
    }
    int identification()
    {
        return id;
    }
};
struct issueresult
{
    char username[50];
    int productid;
};

class Inventory
{
private:
    int maxProducts;
    int productCount;
    Product products[100];
    int choose;
    int dell;
    int re_book;

public:
    Inventory()
    {
        maxProducts = 100;
        productCount = 0;
    }
    void addProduct(int id, char name[50], char Name[50])
    {
        if (productCount < maxProducts)
        {
            products[productCount++] = Product(id, name, Name);

            cout << "    Book added successfully.(\'_\')" << endl;
        }
        else
        {
            cout << "Error: Library is full." << endl;
        }
    }
    void displayInventory();
    void choice();
    void deleteobj();
    issueresult issue_book();
    void show(issueresult p)
    {

        cout << setw(8) << p.productid;
        cout << setw(33) << p.username;
        cout << endl;
    }
};
void Inventory ::displayInventory()
{
    if (productCount == 0)
    {
        cout << "inventory is empty";
    }
    else
    {
        for (int i = 0; i < productCount; i++)
        {
            products[i].displayProduct();
        }
    }
}
void Inventory ::choice()
{
    cout << "Enter the book ID you want to search:" << endl;
    cin >> choose;
    for (int i = 0; i < productCount; i++)
    {

        if (choose == products[i].identification())
        {
            cout << endl
                 << setw(10) << "Book ID |";
            cout << setw(20) << "Book Name |";
            cout << setw(30) << "Author Name |" << endl;
            products[i].displayProduct();
        }
    }
    cout << "Book not found.";
}
void Inventory ::deleteobj()
{
    int dell;
    cout << "Enter the index number of the book you want to delete:";
    cin >> dell;

    int found = 0;
    for (int i = 0; i < productCount; i++)
    {
        if (i == dell)
        {
            found = 1;
            for (; i < productCount - 1; i++)
            {
                products[i] = products[i + 1];
            }
            productCount--;
            break;
        }
    }

    if (found != 1)
    {
        cout << "Book not found";
    }
    else
    {
        for (int j = 0; j < productCount; j++)
        {
            products[j].displayProduct();
        }
    }
}
issueresult Inventory::issue_book()
{
    issueresult r1;
    int found1 = 0;
    cout << "Enter the name of user you want to issue book to: ";
    cin >> r1.username;
    cout << "Enter the book id you want to issue: ";
    cin >> r1.productid;
    for (int i = 0; i < productCount; i++)
    {
        if (r1.productid == products[i].identification())
        {
            cout << "book issued successfully";
            found1 = 1;
            break;
        }
    }
    if (found1 == 0)
    {
        cout << "book not found";
        r1.productid = 0;
      //  strcpy(r1.username = "0");
        r1.username[0] = '\0';
    }
    return r1;
}
int main()

{

    Inventory a1;
    // issueresult r1 = a1.issue_book();
    issueresult r2[100];
    int issuedbookcount = 0;
    int choice;
    int I_R;
       cout << endl
             << " ======================================================================" << endl;
        cout << endl
             << "               ************Library Management*" << endl;
        cout << " ======================================================================" << endl;
        cout << "1.Book detail entry." << endl;
        cout << "2.Display all books." << endl;
        cout << "3.Search book detail." << endl;
        cout << "4.Delete book detail." << endl;
        cout << "5.Issue and return section." << endl;
        cout << "6.Exit Program." << endl;

    do
    {
     

        // int choice;
        cout << endl
             << "Enter your choice (1-6)." << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            int i;
            char bookName[50];
            char authorName[50];
            char ch[10];
            int q;
            cout << "                   [Book detail entery section]" << endl;
            do
            {
                cout << "Enter book id in integers and the value will be between 0 to 999:" << endl;
                cin >> i;
                while (cin.fail())
                {
                    cin.clear();
                    cin >> ch;
                    cout << "invalid";
                    cin >> i;
                }
            } while (i >= 1000);
            cin.ignore();
            int hasDigit;
            do
            {
                hasDigit = 0;
                cout << "Enter book name: ";
                cin.getline(bookName, 50);

                for (i = 0; bookName[i] != '\0'; i++)
                {
                    if (isdigit(bookName[i]))
                    {
                        hasDigit = 1;
                        break;
                    }
                }

                if (hasDigit == 1)
                {
                    cout << "Invalid input. Name should not contain numbers.\n";
                }
            } while (hasDigit != 0 || bookName[0] == '\0');
            do
            {
                hasDigit = 0;
                cout << "Enter author name: ";
                cin.getline(authorName, 50);

                for (i = 0; bookName[i] != '\0'; i++)
                {
                    if (isdigit(authorName[i]))
                    {
                        hasDigit = 1;
                        break;
                    }
                }

                if (hasDigit == 1)
                {
                    cout << "Invalid input. Name should not contain numbers.\n";
                }
            } while (hasDigit != 0 || authorName[0] == '\0');
            a1.addProduct(i, bookName, authorName);
        }
        break;
        case 2:
            cout << "                    [All Books]" << endl;
            cout << setw(1) << "Book ID |";
            cout << setw(4) << "                Book Name |";
            cout << setw(4) << "                Author Name |" << endl;
            a1.displayInventory();
            break;
        case 3:
            cout << "                   [Search book detail]" << endl;
            a1.choice();
            break;
        case 4:
            cout << "                    [Delete Book Detail]" << endl;
            a1.deleteobj();
            break;
        case 5:
            do
            {
                cout << endl;
                cout << "                   [Issue And Return Section]" << endl;

                cout << "1.Issue Book." << endl;
                cout << "2.Return Book." << endl;
                cout << "3.Issue and Return status." << endl;
                cout << "4.Exit" << endl;
                cout << "Enter your choice:" << endl;

                cin >> I_R;
                switch (I_R)
                {
                case 1:
                    cout << endl
                         << "[Issue book]" << endl;
                    r2[issuedbookcount++] = a1.issue_book();

                    break;
                case 2:
                    cout << "[Return book]" << endl;
                    int re_book;
                    cout << "Enter the index number of book from issue return section which is to be returned:";
                    cin >> re_book;
                    for (int i = re_book; i < issuedbookcount; i = i + 1)
                    {
                        r2[i] = r2[i + 1];
                    }
                    cout << "Book is returned successfully." << endl;
                    for (int j = 0; j < issuedbookcount - 1; j++)
                    {
                        // r2[j] = a1.issue_book();

                        a1.show(r2[j]);
                    }
                    issuedbookcount--;
                    break;
                case 3:
                    cout << "[Issue and return status]" << endl;
                    cout << "Book Id |                      User Name|" << endl;
                    for (int k = 0; k < issuedbookcount; k++)
                        a1.show(r2[k]);
                    break;
                case 4:
                    cout << "Program end";
                    break;
                default:
                    cout << "Invalid choice";
                }
            } while (I_R != 4);
            break;
        case 6:

            cout << "      ----------exit program------------";
            break;
        default:
            cout << "Invalid Choice";
        }

    } while (choice != 6);
}
