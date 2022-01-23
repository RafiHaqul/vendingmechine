#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

struct Product
{
    short id{};
    string nama{};
    double harga{};
};

void menu()
{
    cout << " ______________________________________ " << endl;
    cout << "|           Vending Machine            |" << endl;
    cout << "|______________________________________|" << endl;
    cout << "|     Menu              |      Harga   |" << endl;
    cout << "|                       |              |" << endl;
    cout << "|   1. Coca-cola        |  Rp.  4.000  |" << endl;
    cout << "|   2. Pepsi            |  Rp.  4.000  |" << endl;
    cout << "|   3. Air mineral      |  Rp.  2.000  |" << endl;
    cout << "|   4. Kopi Good Day    |  Rp.  5.000  |" << endl;
    cout << "|   5. Fanta            |  Rp.  4.000  |" << endl;
    cout << "|   6. Mizone           |  Rp.  4.000  |" << endl;
    cout << "|   7. Exit Menu        |              |" << endl;
    cout << "|______________________________________|" << endl;
}

int main()
{

MENU:
    system("cls");
    Product drink[7];
    drink[0] = { 1, "Cola",4000 };
    drink[1] = { 2, "Pepsi",4000 };
    drink[2] = { 3, "Air Mineral",2000 };
    drink[3] = { 4, "Kopi Good day",5000 };
    drink[4] = { 5, "Fanta",4000 };
    drink[5] = { 6, "MIZONE",4000 };
    drink[6] = { 7, "Exit Menu",0 };

    cout << endl;
    menu();


    int choice;
    double payment;
    int quantity;
    double total_payment;
    double tax_ammount;
    double change;
    char lanjut;
    while (true)
    {
        cout << "Pilih menunya: ";
        cin >> choice;
        if (choice == 7)
        {
            break;
        }
        else if ((choice > 7) || (choice < 1))
        {
            cout << "Input Salah" << endl;
            Sleep(1000);
            goto MENU;
        }
        cout << "Berapa yang kamu inginkan ? ";
        cin >> quantity;

        cout << "Berapa yang kamu bayar  ? ";
        cin >> payment;

        total_payment = drink[choice - 1].harga * quantity;
        if (payment < total_payment)
        {
            cout << "Uang anda tidak cukup" << endl;
            cout << "Lanjutkan?(y/n) : ";
            cin >> lanjut;
            if ((lanjut == 'y') || (lanjut == 'Y')) {
                goto MENU;
            }
            else if ((lanjut == 'n') || (lanjut == 'N')) {
                break;
            }
            else {
                goto MENU;
            }
        }

        cout << "_________________________________________________\n";
        tax_ammount = 500;
        cout << "Pajak Pembelian : Rp " << tax_ammount << endl;


        total_payment += tax_ammount;
        change = payment - total_payment;
        cout << "Total pembelian : Rp " << total_payment << endl;
        cout << "Kembalian : Rp " << change << endl;
        cout << "_________________________________________________\n";
    }
    return 0;
}