#include <iostream>
using namespace std;
void printPlayground (int dim) {

  for (int k = 0 ; k < dim ; k = k +1 ) {
    cout<<"  ";
    for (int i = 0; i< dim-1 ; i= i+1){
        cout<< "    |";
    }
    cout<< endl;
    //2-line
    cout<<"   ";
    for (int l = 0; l < dim ; l = l +1) {
      //switch (array[k*dim+l])
      if (l != dim-1) {
        cout<<"_  | ";
      } else {
        cout<<"_  ";
      }

    }
    cout << endl;
    //3-line
    cout<<"__";
    for (int i = 0; i< dim ; i= i+1){
      if (i != dim-1) {
        cout<<"____|";
      } else {
        cout<<"____";
      }
    }
    cout<<"___"<<endl;
  }

}

int main() {
  cout<<"Welcome to the game, we need 2 players here, what is your name player 1 ?" << endl;
  string pname1;

  cin>>pname1;
  cout<<"Hi " << pname1 << "! You will have the O"<< endl << "Player 2, what is your name ?" << endl;
  string pname2;

  //printPlayground(3);
}
