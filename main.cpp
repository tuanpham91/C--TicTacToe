#include <iostream>
using namespace std;
void printPlayground (int *array,int dim) {
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
      string charac="_";
      switch (array[k*dim+l]) {

        case 1 :
          charac = "O";
          break;
        case 2 :
          charac = "X";
          break;
        default:
          break;
      }
      if (l != dim-1) {
        cout<< charac <<"  | ";
      } else {
        cout<< charac << "  ";
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

bool horizonWin (int *board, int dim, int position) {
  //to make position starts with 0;
  int pos = position -1;
  int x1,x2(0);

  x1 = pos%dim;
  x2 = pos%dim;
  int y = pos/dim;
  int player = board[pos];
  bool foundLeft(false);
  bool foundRight(false);
  int count(1);
  while (!foundLeft && x1>0) {
      x1 = x1-1;
      if (board[y*dim + x1]==player) {
        count = count+1;
      } else {
        foundLeft == true;
      }
  }
  while (!foundRight && x2<dim-1) {
      x2 = x2+1;
      if (board[y*dim + x2]==player) {
        count = count+1;
      } else {
        foundRight == true;
      }
  }
  if (count >= 3) {
    return true;
  } else {
    //debug
    cout<<count<<endl;
    return false;
  }
}

bool diagonalWinRight (int *board, int dim, int position) {
  //to make position starts with 0;
  int pos = position -1;
  int x1,x2,y1,y2 =0;
  y1 = pos/dim;
  y2 = pos/dim;
  x1 = pos%dim;
  x2 = pos%dim;

  int player = board[pos];
  bool foundLeft(false);
  bool foundRight(false);
  int count(1);
  while (!foundLeft && y1>0 && x1>0 ) {
      y1 = y1-1;
      x1 = x1-1;
      if (board[y1*dim + x1]==player) {
        count = count+1;
      } else {
        foundLeft == true;
      }
  }
  while (!foundRight && y2<dim-1 && x2<dim-1) {
      y2 = y2+1;
      x2 = x2+1;
      if (board[y2*dim + x2]==player) {
        count = count+1;
      } else {
        foundRight == true;
      }
  }
  if (count >= 3) {
    return true;
  } else {
    //debug
    cout<<count<<endl;
    return false;
  }
}

bool diagonalWinLeft (int *board, int dim, int position) {
  //to make position starts with 0;
  int pos = position -1;
  int x1,x2,y1,y2 =0;
  y1 = pos/dim;
  y2 = pos/dim;
  x1 = pos%dim;
  x2 = pos%dim;

  cout<< "Find diagonal winner  at pos"<< pos << " and cor " << x1 << " " << y1 << endl;
  int player = board[pos];
  bool foundLeft(false);
  bool foundRight(false);
  int count(1);
  while (!foundLeft && y1<dim-1 && x1>0 ) {
      y1 = y1+1;
      x1 = x1-1;
      if (board[y1*dim + x1]==player) {
        count = count+1;
      } else {
        foundLeft == true;
      }
  }
  while (!foundRight && y2>0 && x2<dim-1) {
      y2 = y2-1;
      x2 = x2+1;
      if (board[y2*dim + x2]==player) {
        count = count+1;
      } else {
        foundRight == true;
      }
  }
  if (count >= 3) {
    return true;
  } else {
    //debug
    cout<<count<<endl;
    return false;
  }
}

bool verticalWin (int *board, int dim, int position) {
  //to make position starts with 0;
  int pos = position -1;

  int y1,y2 =0;

  y1 = pos/dim;
  y2 = pos/dim;
  int x = pos%dim;

  //cout<< "Find vertical winner  at pos"<< pos << " and cor " << x << " " << y1 << endl;
  int player = board[pos];
  bool foundLeft(false);
  bool foundRight(false);
  int count(1);
  while (!foundLeft && y1>0) {
      y1 = y1-1;
      if (board[y1*dim + x]==player) {
        count = count+1;
      } else {
        foundLeft == true;
      }
  }
  while (!foundRight && y2<dim-1) {
      y2 = y2+1;
      if (board[y2*dim + x]==player) {
        count = count+1;
      } else {
        foundRight == true;
      }
  }
  if (count >= 3) {
    return true;
  } else {
    //debug
    cout<<count<<endl;
    return false;
  }
}

bool getWinner(int *board, int dim, int pos, int player) {

  if (horizonWin(board,dim,pos) || verticalWin(board,dim, pos) || diagonalWinRight(board,dim, pos) || diagonalWinLeft(board,dim,pos)) {
    return true;
  }
  return false;
}



int main() {

  cout<<"Welcome to the game, we need 2 players here, what is your name player 1 ?" << endl;
  string pname1;
  bool won = false;

  int dim(3);

  int board[dim*dim] = {};
  cin>>pname1;
  cout<<"Hi " << pname1 << "! You will have the O"<< endl << "Player 2, what is your name ?" << endl;
  string pname2;
  cin>>pname2;
  cout<<"Hi " << pname2 << "! You will have the X"<< endl;
  printPlayground(board,dim);
  while (won != true) {
    cout<< pname1 << ", you are next, enter coordinate of your move !:"<<endl;
    int x,y(0);
    cin>> x;
    cin>> y;
    cout<< pname1 << ", your move is  "<<x<<","<<y<<endl;
    bool rightInput = false;

    board[(y-1)*dim+x-1] = 1;
    printPlayground(board,dim);
    if (getWinner(board,dim,(y-1)*3+x,1)== true) {
      cout<<"Player "<<pname1<< " has won"<<endl;
      won = true;
      continue;
    }
    cout<< pname2 << ", you are next, enter coordinate of your move !:"<<endl;
    cin>> x;
    cin>> y;
    cout<< pname2 << ", your move is  "<<x<<","<<y<<endl;
    board[(y-1)*dim+x-1] = 2;
    printPlayground(board,dim);
    if (getWinner(board,dim,(y-1)*3+x,2)== true) {
      cout<<"Player "<<pname2<< " has won"<<endl;
      won = true;
      continue;
    }
  }


  //printPlayground(3);
}
