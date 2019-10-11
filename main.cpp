//Amit Charran
//Huffman Encoding and Decoding

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;


//Class
class Node{
private:
    string chstr;
    int prob;
    string code;
    Node* next;
    Node* left;
    Node* right;

public:
     Node(){
        chstr = "";
        prob = -1;
        code = "";
        next = NULL;
        left = NULL;
        right = NULL;
    }
    Node(string ch, int p, string c, Node* n, Node* l, Node* r){
         chstr = ch;
         prob = p;
         code = c;
         next = n;
         left = l;
         right = r;
     }
    virtual ~Node(){
         delete next;
         delete left;
         delete right;

     }
     Node(string c, int p, Node* n){
         chstr = c;
         prob = p;
         code = "";
         next = n;
         left = NULL;
         right = NULL;
     }
    Node(string c, int p){
        chstr = c;
        prob = p;
        code = "";
        next = NULL;
        left = NULL;
        right = NULL;
    }


    const string &getChstr() const {
        return chstr;
    }
    void setChstr(const string &chstr) {
        Node::chstr = chstr;
    }
    int getProb() const {
        return prob;
    }
    void setProb(int prob) {
        Node::prob = prob;
    }
    const string &getCode() const {
        return code;
    }
    void setCode(const string &code) {
        Node::code = code;
    }
    Node *getNext() const  {
        return next;
    }
    void setNext(Node *next) {
        Node::next = next;
    }
    Node *getLeft() const {
        return left;
    }
    void setLeft(Node *left) {
        Node::left = left;
    }
    Node *getRight() const {
        return right;
    }
    void setRight(Node *right) {
        Node::right = right;
    }
    bool isLeaf(){
         if(this->getLeft() == NULL && this->getRight() == NULL){
             return true;
         }
         return false;
     }


    string printNode(){
        if(this->getNext() != NULL && !this->isLeaf()) {
            return "( " + this->getChstr() + "," + to_string(this->getProb()) + "," +
                   this->getNext()->getChstr() +","+ this->getCode()+ ","+ this->getLeft()->getChstr()+"," + this->getRight()->getChstr() +")";
        }
        else if(this->getNext() == NULL && this->isLeaf()){
            return + "( " + this->getChstr() + "," + to_string(this->getProb()) + "," + "NULL" + "," + this->getCode()+ ","+ "NULL" +
                   "," + "NULL" + ")";
        }
        else if(this->getNext() == NULL && !this->isLeaf()){
            return + "( " + this->getChstr() + "," + to_string(this->getProb()) + "," + "NULL" +
                   ","+ this->getCode()+ ","+this->getLeft()->getChstr()+"," + this->getRight()->getChstr()+")";
        }
        else if(this->isLeaf() && this->getNext() != NULL){
            return + "( " + this->getChstr() + "," + to_string(this->getProb()) + "," + this->getNext()->getChstr() + "," + this->getCode()+ ","+ "NULL" +
                   "," + "NULL" + ")";
        }
        return "";
    }
};
class linkedList{
private:
    Node* listHead;
public:
    linkedList(){
        listHead = new Node("listHead", -1, NULL);
    }
    ~linkedList(){
        delete listHead;
    }
    void insertNewNode(Node* newNode){
        Node* spot = findSpot(listHead, newNode->getProb());
        if(spot->getNext() != NULL){
            newNode->setNext( (spot->getNext()) );
        }
        spot->setNext(newNode);
    }

    Node* findSpot(Node* listHead, int prob){
        Node* loopElement = listHead;

        while(true){
            if(loopElement->getNext() == NULL){
                return loopElement;
            }
            else if(loopElement->getNext()->getProb() > prob){
                return loopElement;
            }
            loopElement = loopElement->getNext();

        }
    }

    Node* getListHead(){
        return listHead;
    }

    Node* getLastNode(){
        Node* iterativeNode = listHead;

        while(iterativeNode->getNext() != NULL){

            iterativeNode = iterativeNode->getNext();
        }
        return iterativeNode;
    }
    void printList(){
        Node* iterativeNode = listHead;
       while(true){
           if(iterativeNode->getNext() == NULL){
               cout << iterativeNode->printNode() << endl;
               break;
           }
           cout << iterativeNode->printNode() << " --> ";

           iterativeNode = iterativeNode->getNext();
       }
       cout << endl;

    }
};

class Tree{
private:
    Node* root;
public:
    Tree(){
        root = new Node();
    }
    ~Tree(){
        delete root;
    }

    Node *getRoot() const {
        return root;
    }

    void setRoot(Node *r) {
        root = r;
    }

    void createTree(linkedList* lL){
        Node* iterativeNode = lL->getListHead()->getNext();


        while(iterativeNode != NULL){
            Node* firstNode = iterativeNode;
            if(iterativeNode->getNext() == NULL){
                break;
            }
            Node* secondNode = iterativeNode->getNext();
            string chstr = firstNode->getChstr() + secondNode->getChstr();
            int prob = firstNode->getProb() + secondNode->getProb();
            Node* newNode = new Node(chstr, prob, "", NULL, secondNode, firstNode);
            lL->insertNewNode(newNode);
            if(iterativeNode->getNext() != NULL){
                iterativeNode = iterativeNode->getNext()->getNext();
            }
            else if(iterativeNode->getNext() == NULL){
                break;
            }
        }
        root = lL->getLastNode();
    }

    void createCodeForNode(){
        string code = "";
        createCodeForNode(root,code);
    }
    void createCodeForNode(Node* node, string code){
        if(node == NULL) return;

        node->setCode(code);
        if(node == root){
            node->setCode("root");
        }
        createCodeForNode(node->getLeft(), (code + "0"));
        createCodeForNode(node->getRight(), (code+ "1"));
    }
    void postOrder(){
        cout << "Post-Order:" << endl;
        postOrder(root);
        cout << endl;
    }
    void postOrder(Node* node) {
        if (node == NULL) { return; }
        postOrder(node->getLeft());
        postOrder(node->getRight());
        if(node->isLeaf()){
        cout << node->getChstr() << " " << node->getCode() << endl;
        }

    }
};









//Function Headers
int* charCount(ifstream* infile);
bool compressedFileOutput();
string askForCompressedFileName();
//input file, output fully completed tree and linked list
Tree* createTreeFromFile(ifstream* infile, linkedList* list);
void createANewNodeAndAddToList(string c, int prob, linkedList* list);
ofstream* encodeWithFileOutput(ifstream* infile,string infileName, linkedList* list);
void encodeWithFileOutputNoOutfile(ifstream* infile, linkedList* list);
void decodeFile(ifstream* infile,ofstream* outfile, Tree* tree);
string removeTxt(string infileName);



//Main
int main(int argc, char **argv) {
    linkedList list;
    string compressedFileName = askForCompressedFileName();
    if(compressedFileName == "NoFile-1-1"){
        return 0;
    }

    string nameOrg = "a.txt";
    string nameCompressed = (compressedFileName+ "_compressed.txt");
    string nameDecompressed = (compressedFileName +"_decompressed.txt");
    ifstream infile(nameOrg);

    Tree* tree = createTreeFromFile(&infile, &list);
    infile.close();


    infile.open(nameOrg);
    //Need to create one of these without outputing the file, probably place it in a long string
    ofstream* outfile = encodeWithFileOutput(&infile, nameCompressed,&list);

    infile.close();
    outfile->close();

    ifstream encodedInfile((nameCompressed));

    //Now we have encoded file, just need to decode
    ofstream outfile2(nameDecompressed);
    decodeFile(&encodedInfile,&outfile2, tree);
    outfile2.close();
    encodedInfile.close();
    return 0;
}







//Function Defintion
string removeTxt(string infileName){
    bool haveSeenPeriod = false;
    string ans = "";
    for(char const &c: infileName){
        if(!haveSeenPeriod){
            if(c == '.') haveSeenPeriod = true;
            else ans += c;
        }
    }
    return ans;
}

void decodeFile(ifstream* infile,ofstream* outfile , Tree* tree){
    string data;
    while(*infile >> data){
        Node* traversingNode = tree->getRoot();
        for(char const& d: data){
                if(d == '0'){
                    traversingNode = traversingNode->getLeft();
                    if(traversingNode->isLeaf()){
                        *outfile << traversingNode->getChstr();
                        traversingNode = tree->getRoot();
                    }

                }else if(d == '1'){
                    traversingNode = traversingNode->getRight();
                    if(traversingNode->isLeaf()){
                        *outfile << traversingNode->getChstr();
                        traversingNode = tree->getRoot();
                    }
                }
                else {
                    cout << "the compressed file contains invalid characters" << endl;
                    exit(0);
                }

            }
        *outfile << " ";
    }
    cout << endl;

}
ofstream* encodeWithFileOutput(ifstream* infile,string nameCompressed, linkedList* list){
    ofstream* outfile = new ofstream(nameCompressed);

    char data;

    while(*infile >> noskipws >> data){
        string s(1,data);
        Node* iterativeNode = list->getListHead();

        if(s != " " && data != ' '){
        while(iterativeNode != NULL){
            if(iterativeNode->getChstr() == s){
                *outfile << iterativeNode->getCode();
            }
            iterativeNode = iterativeNode->getNext();
        }
        }else{
            *outfile<< " ";
        }

    }

    return outfile;
}
void encodeWithFileOutputNoOutfile(ifstream* infile, linkedList* list){
    char data;
    while(*infile >> noskipws >> data){
        string s(1,data);
        Node* iterativeNode = list->getListHead();

        if(s != " " && data != ' '){
            while(iterativeNode != NULL){
                if(iterativeNode->getChstr() == s){
                    cout << iterativeNode->getCode();
                }
                iterativeNode = iterativeNode->getNext();
            }
        }else{
            cout<< " ";
        }

    }
}
Tree* createTreeFromFile(ifstream* infile, linkedList* list){
    int* ptr = charCount(infile);


    for(int i = 0;i < 256; i++){
        if(ptr[i] != 0){
            string c(1,char(i));
            Node* newNode = new Node(c,ptr[i]);
            list->insertNewNode(newNode);
        }

    }
    Tree* tree = new Tree();
    tree->createTree(list);
    tree->createCodeForNode();

   return tree;
}

string askForCompressedFileName(){
    cout << "Would you like to see the compressed file? \n"
            "Enter Y for yes\n"
            "Enter N for no.\n";
    char yn;
   cin >> yn;
   if(yn == 'Y' || yn == 'y'){
       cout << "what is the name of the text file to be compressed" << endl;
       string ans;
       cin >> ans;
       return ans;
   }
   return "NoFile-1-1";
}

int* charCount(ifstream* infile){
    char data;

    int* arr = new int[256];

    for(int i = 0;i < 256; i++){
        arr[i] = 0;
    }
    while(*infile >> data){
            arr[data]++;
    }

    return arr;

}