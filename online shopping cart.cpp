#include <iostream>
#include <fstream>
#include <string>
#include <limits>
using namespace std;

struct Product {
    int id;
    string category;
    string device;
    int price;
    Product* next;
};

Product* cart = NULL;
Product* Order = new Product;
Product* Favourites = NULL;// cart favourits
Product* fav_node=new Product;
int total = 0;

bool isEmpty() {
    if (cart == NULL)
        return true;
    else
        return false;
}

void placeFavourites(int id){
Product* newfavo = new Product;
    if (Favourites==NULL) {
        newfavo->id = id;
        newfavo->next = NULL;
        Favourites = newfavo;
    }
    else {
        newfavo->id = id;
        newfavo->next = Favourites;
        Favourites = newfavo;
    }
}
int Fav_get_category(int cat) {
    if (cat == 1) {
        cout << "1. Dell" << endl;
        cout << "2. HP" << endl;
        cout << "3. MSI" << endl;
        return cat;
    }
    else if (cat == 2) {
        cout << "1. Samsung" << endl;
        cout << "2. Iphone" << endl;
        cout << "3. Oppo" << endl;
        return cat;
    }
    else if (cat == 3) {
        cout << "1. LG" << endl;
        cout << "2. Samsung" << endl;
        cout << "3. Sony" << endl;
        return cat;
    }
    else if (cat == 4) {
        cout << "1. AirPods" << endl;
        cout << "2. EarPods" << endl;
        cout << "3. Oraimo" << endl;
        cout << "4. Anker" << endl;
    }
    else {
        cout << "Invalid" << endl;
    }
}

void Fav_get_devices(int cat, int device) {
    Product* fav_node = Favourites;
    while (fav_node != NULL) {
        if (cat == 1) {
            fav_node->category = "Laptops";
            if (device == 1) {
                fav_node->device = "Dell";
                fav_node->price = 15000;
            }
            else if (device == 2) {
                fav_node->device = "HP";
                fav_node->price = 10000;
            }
            else if (device == 3) {
                fav_node->device = "MSI";
                fav_node->price = 13000;
            }
            else {
                cout << "Invalid" << endl;
                return; // Return early in case of an invalid device_number
            }
        }
        else if (cat == 2) {
            fav_node->category = "Mobile";
            if (device == 1) {
                fav_node->device = "Samsung";
                fav_node->price = 1000;
            }
            else if (device == 2) {
                fav_node->device = "Iphone";
                fav_node->price = 60000;
            }
            else if (device == 3) {
                fav_node->device = "Oppo";
                fav_node->price = 30000;
            }
            else {
                cout << "Invalid" << endl;
                return; // Return early in case of an invalid device_number
            }
        }
        else if (cat == 3) {
            fav_node->category = "TV";
            if (device == 1) {
                fav_node->device = "LG";
                fav_node->price = 20000;
            }
            else if (device == 2) {
                fav_node->device = "Samsung";
                fav_node->price = 30000;
            }
            else if (device == 3) {
                fav_node->device = "Sony";
                fav_node->price = 40000;
            }
            else {
                cout << "Invalid" << endl;
                return; // Return early in case of an invalid device_number
            }
        }
        else if (cat == 4) {
            fav_node->category = "Head Phones";
            if (device == 1) {
                fav_node->device = "AirPods";
                fav_node->price = 5000;
            }
            else if (device == 2) {
                fav_node->device = "EarPods";
                fav_node->price = 3000;
            }
            else if (device == 3) {
                fav_node->device = "Oraimo";
                fav_node->price = 1000;
            }
            else if (device == 4) {
                fav_node->device = "Anker";
                fav_node->price = 700;
            }
            else {
                cout << "Invalid" << endl;
                return; // Return early in case of an invalid device_number
            }
        }
        else {
            cout << "Invalid" << endl;
            return; // Return early in case of an invalid category_number
        }
                    fav_node = fav_node->next;
    }
    cout << endl;
}

void favDisplay() {
    if (Favourites == NULL) {
        cout << "There is no order" << endl;
        return;
    }

    Product* currentOrder=new Product;
    currentOrder = Favourites;

    cout << "*********" << endl;
    cout << "Receipt" << endl;
    cout << "*********" << endl;
    while (currentOrder != NULL) {
        cout << "ID: " << currentOrder->id << endl;
        cout << "Type: " << currentOrder->category << endl;
        cout << "Device: " << currentOrder->device << endl;
        cout << "Price: $" << currentOrder->price<< endl;
        currentOrder = currentOrder->next;
    }
    cout<<endl;
}
void favouritesToOrder(int id) {
    Product* currentFavourites = Favourites;
    if (Favourites == NULL) {
        cout << "Favourites is empty" << endl;
    } else {
        while (currentFavourites != NULL && currentFavourites->id != id) {
            currentFavourites = currentFavourites->next;
        }
        if (currentFavourites != NULL && currentFavourites->id == id) {
            Product* newDevice = new Product;
            newDevice->id = id++;
            newDevice->category = currentFavourites->category;
            newDevice->device = currentFavourites->device;
            newDevice->price = currentFavourites->price;
            newDevice->next = NULL;
            if (cart == NULL) {
                cart = newDevice;
            } else {
                newDevice->next = cart;
                cart = newDevice;
            }
            cout << "Device added from favorites to the order." << endl;
            return;
        }
        cout << "Device with ID " << id << " not found in favorites." << endl;
    }
}

void placeorder(int id) {
    Product* neworder = new Product;
    if (isEmpty()) {
        neworder->id = id;
        neworder->next = NULL;
        cart = neworder;
    }
    else {
        neworder->id = id;
        neworder->next = cart;
        cart = neworder;
    }
}

void show_category() {
    cout << "Available categories:" << endl;
    cout << "1) Laptops" << endl;
    cout << "2) Phones" << endl;
    cout << "3) Televisions" << endl;
    cout << "4) Headphones" << endl;
    cout << endl;
}

int get_category(int category) {
    Order = cart;
    if (category == 1) {
        cout << "1. Dell" << endl;
        cout << "2. HP" << endl;
        cout << "3. MSI" << endl;
        return category;
    }
    else if (category == 2) {
        cout << "1. Samsung" << endl;
        cout << "2. Iphone" << endl;
        cout << "3. Oppo" << endl;
        return category;
    }
    else if (category == 3) {
        cout << "1. LG" << endl;
        cout << "2. Samsung" << endl;
        cout << "3. Sony" << endl;
        return category;
    }
    else if (category == 4) {
        cout << "1. AirPods" << endl;
        cout << "2. EarPods" << endl;
        cout << "3. Oraimo" << endl;
        cout << "4. Anker" << endl;
    }
    else {
        cout << "Invalid" << endl; // Return an invalid value in case of an invalid category
    }
}


void get_devices(int category, int device_number) {
    Order = cart;
    if (category == 1) {
        Order->category = "Laptops";
        if (device_number == 1) {
            Order->device = "Dell";
            Order->price = 15000;
        }
        else if (device_number == 2) {
            Order->device = "HP";
            Order->price = 10000;
        }
        else if (device_number == 3) {
            Order->device = "MSI";
            Order->price = 500000;
        }
        else {
            cout << "Invalid" << endl;
            return; // Return early in case of an invalid device_number
        }
        Order = Order->next;
    }
    else if (category == 2) {
        Order->category = "Mobile";
        if (device_number == 1) {
            Order->device = "Samsung";
            Order->price = 8000;
        }
        else if (device_number == 2) {
            Order->device = "Iphone";
            Order->price = 60000;
        }
        else if (device_number == 3) {
            Order->device = "Oppo";
            Order->price = 50000;
        }
        else {
            cout << "Invalid" << endl;
            return; // Return early in case of an invalid device_number
        }
        Order = Order->next;
    }
    else if (category == 3) {
        Order->category = "TV";
        if (device_number == 1) {
            Order->device = "LG";
            Order->price = 20000;
        }
        else if (device_number == 2) {
            Order->device = "Samsung";
            Order->price = 30000;
        }
        else if (device_number == 3) {
            Order->device = "Sony";
            Order->price = 90000;
        }
    }
    else if (category == 4) {
        Order->category = "Head Phones";
        if (device_number == 1) {
            Order->device = "AirPods";
            Order->price = 5000;
        }
        else if (device_number == 2) {
            Order->device = "EarPods";
            Order->price = 7000;
        }
        else if (device_number == 3) {
            Order->device = "Oraimo";
            Order->price = 3000;
        }
        else if (device_number == 4) {
            Order->device = "Anker";
            Order->price = 2000;
        }
        else {
            cout << "Invalid" << endl;
            return; // Return early in case of an invalid device_number
        }
        Order = Order->next;
    }
    cout << endl;
}

void display() {
    Product* currentOrder = cart;
    if (cart == NULL) {
        cout << "There is no order" << endl;
    }
    else {
        cout << "*********" << endl;
        cout << "Receipt" << endl;
        cout << "*********" << endl;
        while (currentOrder != NULL) {
            cout << "ID: " << currentOrder->id << endl;
            cout << "Type: " << currentOrder->category << endl;
            cout << "Device: " << currentOrder->device << endl;
            cout << "Price: $" << currentOrder->price<< endl;
            currentOrder = currentOrder->next;
        }
        cout<<endl;
    }
}
void modifyOrder(int id) {
    Product* currentOrder = cart;
    int category,device;
    if(currentOrder==NULL){
        cout<<"The cart is empty "<<endl;
    }
    while(currentOrder!=NULL&&currentOrder->id!=id){
        currentOrder=currentOrder->next;
    }
         if (currentOrder != NULL) {
        cout << "Current Order Details:" << endl;
        cout << "Type: " << currentOrder->category << endl;
        cout << "Device: " << currentOrder->device << endl;
        cout << "Price: $" << currentOrder->price << endl;

        // Prompt the user for modified details
        show_category();
        cin >> category;
        get_category(category);
        cout<<"Which device you want to get? "<<endl;
        cin >> device;
        get_devices(category, device);
    } else {
        cout << "Invalid order ID!" << endl;
    }

}
void sum_Oforders() {
    Product* curr_Order = cart;
 // Initialize total to 0

    while (curr_Order != NULL) {
        total += curr_Order->price;
        curr_Order = curr_Order->next;
    }

    cout << endl;
}
void remove(int id) {
    Product* delOrder;
    Product* currentOrder;

    if (cart == NULL) {
        cout << "Cart is empty!" << endl;
        return;
    }

    if (cart->id == id) {
        delOrder = cart;
        cart = cart->next;
        delete delOrder;
        cout << "Product with ID " << id << " has been removed from the cart." << endl;
        return;
    }

    currentOrder = cart;
    while (currentOrder->next != NULL && currentOrder->next->id != id) {
        currentOrder = currentOrder->next;
    }

    if (currentOrder->next != NULL) {
        delOrder = currentOrder->next;
        currentOrder->next = delOrder->next;
        delete delOrder;
        cout << "Product with ID " << id << " has been removed from the cart." << endl;
    }
    else {
        cout << "Product with ID " << id << " not found in the cart." << endl;
    }
}
void discount() {
    Product* discount = cart;
    int ttl_dis = 0;
    while (discount != NULL) {
        ttl_dis += discount->price;
        discount = discount->next;
    }
    float discount_percentage;
    if (ttl_dis >= 70000)
        discount_percentage = 20; //discount precentage=20%;//
    else if (ttl_dis >= 50000)
        discount_percentage = 5; //discount precentage=5%;//
    else
        discount_percentage = 0;

    float discount_amount = ttl_dis * discount_percentage / 100; //total price *precentage of discount=discount amount//
    float discounted_price = ttl_dis - discount_amount; //total price - discount amount=new total price//

    cout << "*********" << endl;
    cout << "Total Price: $" << ttl_dis << endl;
    cout << "Discount: " << discount_percentage << "%" << endl;
    cout << "Price after discount : $" << discounted_price << endl;
    cout << endl;

/*  if (ttl_dis >= 70000) {
        ttl_dis *= (20 / 100);
        cout << "You Got 20% Discount : " << ttl_dis << endl;
        cout << endl;
    }
    else if (ttl_dis < 70000 && ttl_dis >= 50000) {
        ttl_dis *= (5 / 100);
        cout << "You Got 5% Discount : " << ttl_dis  << endl;
        cout << endl;
    }
    else
        cout << "Sorry You didn't get any discounts " << endl;
    cout << endl;*/
}

int main() {
    int id = 1; // id of the counter to the order
    int choice = 0, category, device, id_device;
    int cat_fav,dev_fav;
    char choose;
    cout << "******************" << endl;
    cout << "Welcome to the Electro Shop" << endl;
    cout << "******************" << endl;
    while (choice != 8) {
        cout << "Select an option:" << endl;
        cout << "1. Add to Cart" << endl;
        cout << "2. Display from Cart" << endl;
        cout << "3. Remove from Cart" << endl;
        cout<< "4. Modify order" <<endl;
        cout<< "5. Add to favourites" <<endl;
        cout<< "6. Display favourites" <<endl;
        cout<< "7. Place form favourites" <<endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;
        switch (choice) {
        case 1:
            placeorder(id);
            show_category();
            cout << "Which category do you want?" << endl;
            cin >> category;
            get_category(category);
            cout << "Which device do you want?" << endl;
            cin >> device;
            get_devices(category, device);
            id++;

            break;
        case 2:
            display();
            sum_Oforders();
            discount();
            break;
        case 3:
            cout << "Enter id of the device that you want to remove " << endl;
            cin >> id_device;
            remove(id_device);
            id--;
            break;
        case 4:
            cout << "Enter the ID of the order you want to modify: ";
            cin>>id_device;
            modifyOrder(id_device);
            display();
            break;
        case 5:
            placeFavourites(id);
            show_category();
            cout << "Which category do you want?" << endl;
            cin >> cat_fav;
            Fav_get_category(cat_fav);
            cout << "Which device do you want?" << endl;
            cin >> dev_fav;
            Fav_get_devices(cat_fav,dev_fav);
            id++;
            break;
        case 6:
            favDisplay();
            break;
        case 7:
            cout<<"Enter Id of the device that you want to place in order "<<endl;
            cin>>id;
            favouritesToOrder(id);
            break;
      }
    }
}
