
class Node {

private:

	int data;
	Node* left;
	Node* right;
	Node* mid;
	int degree;

public:

	//constructors
	Node(const int data);
	
	~Node();

	//getters
	int getData() { return data; }
	int getDegree() { return degree; }
	Node* getLeft() { return left; }
	Node* getRight() { return right; }
	Node* getMid() { return mid; }

	//setters
	void setData(int data);
	void setLeft(Node* left);
	void setRight(Node* right);
	void setMid(Node* mid);


};
