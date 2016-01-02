struct HuffmanBinaryTreeNode {
    int left = 0;
    int right = 0;
    int payload = 0;
    bool filled = false;
};

class HuffmanBinaryTree {
public:
    void insert(int value, std::string key);
    int at(std::string key);
private:
    const static int treeSize = 256;
    HuffmanBinaryTreeNode tree[treeSize];
    int add(int index, int value, std::string key);
    int get(int index, std::string key);
    int nextIndex{0};
    int getNextIndex();
};
